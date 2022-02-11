/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_enemy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 20:57:18 by msaouab           #+#    #+#             */
/*   Updated: 2022/02/11 20:59:46 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	sprite_animation(t_game *map)
{
	static int	frame_gif;

	frame_gif++;
	if (frame_gif > 10)
	{
		map->enemy_frame++;
		if (map->enemy_frame > 3)
			map->enemy_frame = 0;
		frame_gif = 0;
	}
}

void	enemy_patrol(t_game *map)
{
	static int	frame_position;
	int			i;
	int			j;

	i = -1;
	if (frame_position++ == 100)
	{
		while (++i < map->lnbr)
		{
			j = -1;
			while (++j < ft_strlen(map->map[i]))
				move_enemy(map, i, j);
		}
		frame_position = 0;
	}
}

int	loop_enemy(t_game *map)
{
	mlx_clear_window(map->ptr, map->win);
	print_wall_bonus(map);
	sprite_animation(map);
	enemy_patrol(map);
	map->buff = ft_itoa(map->count);
	map->move = ft_strjoin("move : ", map->buff);
	free (map->buff);
	mlx_string_put(map->ptr, map->win, 15, 7, 0x00FFFF00, map->move);
	free (map->move);
	if (map->out == 1)
		check_exit_bonus(map);
	if (map->out == 2)
		destroy_game_bonus(map, 0);
	return (0);
}
