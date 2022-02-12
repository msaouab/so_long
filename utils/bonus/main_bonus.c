/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 09:39:20 by msaouab           #+#    #+#             */
/*   Updated: 2022/02/11 21:28:38 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	print_windows_bonus(t_game *map, void *path)
{
	mlx_put_image_to_window(map->ptr, map->win, path, map->x, map->y);
}

void	xpm_to_img_bonus(t_game *map)
{
	void	*ph_empty;
	void	*ph_wall;
	void	*ph_player;
	void	*ph_exit;

	ph_empty = "./img/empty.xpm";
	ph_wall = "./img/wall.xpm";
	ph_player = "./img/player.xpm";
	ph_exit = "./img/door.xpm";
	map->a_empty = mlx_xpm_file_to_image
		(map->ptr, ph_empty, &map->font_w, &map->font_h);
	map->a_wall = mlx_xpm_file_to_image
		(map->ptr, ph_wall, &map->font_w, &map->font_h);
	map->a_player = mlx_xpm_file_to_image
		(map->ptr, ph_player, &map->font_w, &map->font_h);
	map->a_exit = mlx_xpm_file_to_image
		(map->ptr, ph_exit, &map->font_w, &map->font_h);
	xpm_to_img_collect_bonus(map);
}

int	keys_hook_bonus(int keycode, t_game *map)
{
	map->out = 0;
	if (keycode == 0)
		move_to_left_bonus(map);
	if (keycode == 1)
		move_to_bottum_bonus(map);
	if (keycode == 2)
		move_to_right_bonus(map);
	if (keycode == 13)
		move_to_top_bonus(map);
	if (keycode == 53)
	{
		ft_free_bonus(map);
		exit(0);
	}
	if (map->out == 1)
		check_exit_bonus(map);
	if (map->out == 2)
		destroy_game_bonus(map, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	map;
	int		x;
	int		y;
	int		pid;

	map.count = 0;
	map.enemy_frame = 0;
	if (ac < 2)
		error_map(0);
	if (ft_strncmp(ft_strrchr(av[1], '.'), ".ber", 5) != 0)
		error_map(-1);
	read_map_bonus(av[1], &map);
	x = ft_strlen(map.map[0]) * 75;
	y = map.lnbr * 75;
	map.ptr = mlx_init();
	map.win = mlx_new_window(map.ptr, x, y, "so_long");
	pid = play_damage_sfx();
	xpm_to_img_bonus(&map);
	print_wall_bonus(&map);
	mlx_loop_hook(map.ptr, &loop_enemy, &map);
	mlx_key_hook(map.win, &keys_hook_bonus, &map);
	mlx_hook(map.win, 17, (1L << 17), ft_exit, &map);
	mlx_loop(map.ptr);
	ft_free_bonus(&map);
	return (0);
}
