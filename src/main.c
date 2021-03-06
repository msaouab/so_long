/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 09:39:20 by msaouab           #+#    #+#             */
/*   Updated: 2022/04/30 15:50:25 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	xpm_to_img(t_map *map)
{
	void	*ph_0;
	void	*ph_1;
	void	*ph_p;
	void	*ph_e;

	ph_0 = "./img/empty.xpm";
	ph_1 = "./img/wall.xpm";
	ph_p = "./img/player.xpm";
	ph_e = "./img/door.xpm";
	map->a_0 = mlx_xpm_file_to_image
		(map->ptr, ph_0, &map->font_w, &map->font_h);
	map->a_1 = mlx_xpm_file_to_image
		(map->ptr, ph_1, &map->font_w, &map->font_h);
	map->a_p = mlx_xpm_file_to_image
		(map->ptr, ph_p, &map->font_w, &map->font_h);
	map->a_e = mlx_xpm_file_to_image
		(map->ptr, ph_e, &map->font_w, &map->font_h);
	xpm_to_img_collectible(map);
}

int	key_hook(int keycode, t_map *map)
{
	map->out = 0;
	if (keycode == 0)
		move_to_left(map);
	if (keycode == 1)
		move_to_bottum(map);
	if (keycode == 2)
		move_to_right(map);
	if (keycode == 13)
		move_to_top(map);
	if (keycode == 53)
	{
		kill(map->pid, SIGSEGV);
		ft_free(map);
		exit(0);
	}
	if (map->out)
		check_exit(map);
	return (0);
}

int	main(int ac, char **av)
{
	t_map	map;
	int		x;
	int		y;

	map.count = 0;
	if (ac < 2)
		error_map(0);
	if (ft_strncmp(ft_strrchr(av[1], '.'), ".ber", 5) != 0)
		error_map(-1);
	read_map(av[1], &map);
	x = ft_strlen(map.map[0]) * 75;
	y = map.lnbr * 75;
	map.ptr = mlx_init();
	map.win = mlx_new_window(map.ptr, x, y, "so_long");
	play_damage_sfx(&map);
	xpm_to_img(&map);
	print_wall(&map);
	mlx_key_hook(map.win, &key_hook, &map);
	mlx_hook(map.win, 17, (1L << 17), ft_exit, &map);
	mlx_loop(map.ptr);
	ft_free(&map);
	exit(0);
	return (0);
}
