/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 20:09:12 by msaouab           #+#    #+#             */
/*   Updated: 2022/02/08 22:36:09 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_windows(t_map *map, void *path)
{
	mlx_put_image_to_window(map->ptr, map->win, path, map->x, map->y);
}

void	xpm_to_img_collectible(t_map *map)
{
	void	*ph_coin;
	void	*ph_star;
	void	*ph_hart;

	ph_coin = "./img/coin.xpm";
	ph_star = "./img/star.xpm";
	ph_hart = "./img/hart.xpm";
	map->a_Coin = mlx_xpm_file_to_image
		(map->ptr, ph_coin, &map->font_w, &map->font_h);
	map->a_Star = mlx_xpm_file_to_image
		(map->ptr, ph_star, &map->font_w, &map->font_h);
	map->a_Hart = mlx_xpm_file_to_image
		(map->ptr, ph_hart, &map->font_w, &map->font_h);
}

void	random_colloctible(t_map *map)
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
				print_windows(map, map->a_Coin);
			if (map->map[i][j] == 'C' && num == 2)
				print_windows(map, map->a_Star);
			if (map->map[i][j] == 'C' && num > 2)
				print_windows(map, map->a_Hart);
			map->x += 75;
		}
		map->x = 0;
		map->y += 75;
	}
}

void	print_wall(t_map *map)
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
			print_windows(map, map->a_0);
			if (map->map[i][j] == '1')
				print_windows(map, map->a_1);
			if (map->map[i][j] == 'E')
				print_windows(map, map->a_E);
			if (map->map[i][j] == 'P')
				print_windows(map, map->a_P);
			map->x += 75;
		}
		map->x = 0;
		map->y += 75;
	}
	random_colloctible(map);
}
