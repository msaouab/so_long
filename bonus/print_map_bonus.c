/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 20:09:12 by msaouab           #+#    #+#             */
/*   Updated: 2022/02/09 06:01:31 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	print_windows_bonus(t_game *map, void *path)
{
	mlx_put_image_to_window(map->ptr, map->win, path, map->x, map->y);
}

void	xpm_to_img_collectible_bonus(t_game *map)
{
	void	*ph_coin;
	void	*ph_star;
	void	*ph_hart;
	void	*ph_bull;
	void	*ph_lion;

	ph_coin = "./img/coin.xpm";
	ph_star = "./img/star.xpm";
	ph_hart = "./img/hart.xpm";
	ph_bull = "./img/bull.xpm";
	ph_lion = "./img/jocker_enemy.xpm";
	map->a_coin = mlx_xpm_file_to_image
		(map->ptr, ph_coin, &map->font_w, &map->font_h);
	map->a_star = mlx_xpm_file_to_image
		(map->ptr, ph_star, &map->font_w, &map->font_h);
	map->a_hart = mlx_xpm_file_to_image
		(map->ptr, ph_hart, &map->font_w, &map->font_h);
	map->a_bull = mlx_xpm_file_to_image
		(map->ptr, ph_bull, &map->font_w, &map->font_h);
	map->a_lion = mlx_xpm_file_to_image
		(map->ptr, ph_lion, &map->font_w, &map->font_h);
}

void	print_enemy(t_game *map)
{
	int	i;
	int	j;

	map->x = 0;
	map->y = 0;
	i = -1;
	while (++i < map->lnbr)
	{
		j = -1;
		while (++j < ft_strlen(map->map[i]))
		{
			if (map->map[i][j] == 'N' && (j % 2 == 0))
				print_windows_bonus(map, map->a_lion);
			if (map->map[i][j] == 'N' && (j % 2 != 0))
				print_windows_bonus(map, map->a_bull);
			map->x += 75;
		}
		map->x = 0;
		map->y += 75;
	}
}

void	random_colloctible_bonus(t_game *map)
{
	int	num;
	int	i;
	int	j;

	map->x = 0;
	map->y = 0;
	i = -1;
	while (++i < map->lnbr)
	{
		j = -1;
		while (++j < ft_strlen(map->map[i]))
		{
			num = j % 5;
			if (map->map[i][j] == 'C' && num < 2)
				print_windows_bonus(map, map->a_coin);
			if (map->map[i][j] == 'C' && num == 2)
				print_windows_bonus(map, map->a_star);
			if (map->map[i][j] == 'C' && num > 2)
				print_windows_bonus(map, map->a_hart);
			map->x += 75;
		}
		map->x = 0;
		map->y += 75;
	}
	print_enemy(map);
}

void	print_wall_bonus(t_game *map)
{
	int	i;
	int	j;

	map->x = 0;
	map->y = 0;
	i = -1;
	while (++i < map->lnbr)
	{
		j = -1;
		while (++j < (ft_strlen(map->map[i])))
		{
			print_windows_bonus(map, map->a_0);
			if (map->map[i][j] == '1')
				print_windows_bonus(map, map->a_1);
			if (map->map[i][j] == 'E')
				print_windows_bonus(map, map->a_e);
			if (map->map[i][j] == 'P')
				print_windows_bonus(map, map->a_p);
			map->x += 75;
		}
		map->x = 0;
		map->y += 75;
	}
	random_colloctible_bonus(map);
}
