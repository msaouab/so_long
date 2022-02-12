/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 20:09:12 by msaouab           #+#    #+#             */
/*   Updated: 2022/02/11 20:53:24 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	xpm_to_img_enemy(t_game *map)
{
	void	*ph_enemy[4];

	ph_enemy[0] = "./img/viking_0.xpm";
	ph_enemy[1] = "./img/viking_1.xpm";
	ph_enemy[2] = "./img/viking_2.xpm";
	ph_enemy[3] = "./img/viking_3.xpm";
	map->a_enemy[0] = mlx_xpm_file_to_image
		(map->ptr, ph_enemy[0], &map->font_w, &map->font_h);
	map->a_enemy[1] = mlx_xpm_file_to_image
		(map->ptr, ph_enemy[1], &map->font_w, &map->font_h);
	map->a_enemy[2] = mlx_xpm_file_to_image
		(map->ptr, ph_enemy[2], &map->font_w, &map->font_h);
	map->a_enemy[3] = mlx_xpm_file_to_image
		(map->ptr, ph_enemy[3], &map->font_w, &map->font_h);
}

void	xpm_to_img_collect_bonus(t_game *map)
{
	void	*ph_coin;
	void	*ph_star;
	void	*ph_hart;

	ph_coin = "./img/coin.xpm";
	ph_star = "./img/star.xpm";
	ph_hart = "./img/hart.xpm";
	map->a_coin = mlx_xpm_file_to_image
		(map->ptr, ph_coin, &map->font_w, &map->font_h);
	map->a_star = mlx_xpm_file_to_image
		(map->ptr, ph_star, &map->font_w, &map->font_h);
	map->a_hart = mlx_xpm_file_to_image
		(map->ptr, ph_hart, &map->font_w, &map->font_h);
	xpm_to_img_enemy(map);
}

void	print_enemy(t_game *map)
{
	int	i;
	int	j;
	int	k;

	map->x = 0;
	map->y = 0;
	k = 0;
	i = -1;
	while (++i < map->lnbr)
	{
		j = -1;
		while (++j < ft_strlen(map->map[i]))
		{
			if (map->map[i][j] == 'N')
				print_windows_bonus(map, map->a_enemy[map->enemy_frame]);
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
			print_windows_bonus(map, map->a_empty);
			if (map->map[i][j] == '1')
				print_windows_bonus(map, map->a_wall);
			if (map->map[i][j] == 'E')
				print_windows_bonus(map, map->a_exit);
			if (map->map[i][j] == 'P')
				print_windows_bonus(map, map->a_player);
			map->x += 75;
		}
		map->x = 0;
		map->y += 75;
	}
	random_colloctible_bonus(map);
}
