/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_with_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:43:33 by msaouab           #+#    #+#             */
/*   Updated: 2022/02/08 22:38:20 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_exit(t_map *map)
{
	int	i;
	int	j;
	int	l;

	l = 1;
	i = -1;
	while (++i < map->lnbr)
	{
		j = -1;
		while (++j < ft_strlen(map->map[i]))
		{
			if (map->map[i][j] == 'C')
				l = 0;
		}
	}
	if (l == 0)
		return ;
	else
	{
		map->map[map->p_x][map->p_y] = '0';
		destroy_game(map);
		printf("You Win\n");
	}
}

void	move_to_left(t_map *map)
{
	position_p(map);
	if (map->map[map->p_x][map->p_y - 1] == '1')
		return ;
	else if (map->map[map->p_x][map->p_y - 1] == 'E')
	{
		map->out = 1;
		return ;
	}
	map->map[map->p_x][map->p_y] = '0';
	map->map[map->p_x][map->p_y - 1] = 'P';
	map->count++;
	printf("Move: %d\n", map->count);
	mlx_clear_window(map->ptr, map->win);
	print_wall(map);
}

void	move_to_bottum(t_map *map)
{
	position_p(map);
	if (map->map[map->p_x + 1][map->p_y] == '1')
		return ;
	else if (map->map[map->p_x + 1][map->p_y] == 'E')
	{
		map->out = 1;
		return ;
	}
	map->map[map->p_x][map->p_y] = '0';
	map->map[map->p_x + 1][map->p_y] = 'P';
	map->count++;
	printf("Move: %d\n", map->count);
	mlx_clear_window(map->ptr, map->win);
	print_wall(map);
}

void	move_to_right(t_map *map)
{
	position_p(map);
	if (map->map[map->p_x][map->p_y + 1] == '1')
		return ;
	else if (map->map[map->p_x][map->p_y + 1] == 'E')
	{
		map->out = 1;
		return ;
	}
	map->map[map->p_x][map->p_y] = '0';
	map->map[map->p_x][map->p_y + 1] = 'P';
	map->count++;
	printf("Move: %d\n", map->count);
	mlx_clear_window(map->ptr, map->win);
	print_wall(map);
}

void	move_to_top(t_map *map)
{
	position_p(map);
	if (map->map[map->p_x - 1][map->p_y] == '1')
		return ;
	else if (map->map[map->p_x - 1][map->p_y] == 'E')
	{
		map->out = 1;
		return ;
	}
	map->map[map->p_x][map->p_y] = '0';
	map->map[map->p_x - 1][map->p_y] = 'P';
	map->count++;
	printf("Move: %d\n", map->count);
	mlx_clear_window(map->ptr, map->win);
	print_wall(map);
}
