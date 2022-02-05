/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_with_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:43:33 by msaouab           #+#    #+#             */
/*   Updated: 2022/02/05 19:51:21 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_exit(t_map *map)
{
	int	i;
	int	j;
	int	l;

	l = 1;
	i = -1;
	while (++i < map->i)
	{
		j = -1;
		while (++j < (map->count_line / map->i))
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
		printf("You Win\n");
		exit(0);
	}
}

void	move_to_left(t_map *map)
{
	position_p(map);
	if (map->map[map->p_x][map->p_y - 1] == '1')
		return ;
	if (map->map[map->p_x][map->p_y - 1] == 'C'
		|| map->map[map->p_x][map->p_y - 1] == '0')
	{
		map->map[map->p_x][map->p_y] = '0';
		map->map[map->p_x][map->p_y - 1] = 'P';
	}
	if (map->map[map->p_x][map->p_y - 1] == 'N')
	{
		printf("You lose");
		exit(0);
	}
	if (map->map[map->p_x][map->p_y - 1] == 'E')
		check_exit(map);
	mlx_clear_window(map->ptr, map->win);
	print_wall(map);
}

void	move_to_bottum(t_map *map)
{
	position_p(map);
	if (map->map[map->p_x + 1][map->p_y] == '1')
		return ;
	if (map->map[map->p_x + 1][map->p_y] == 'C'
		|| map->map[map->p_x + 1][map->p_y] == '0')
	{
		map->map[map->p_x][map->p_y] = '0';
		map->map[map->p_x + 1][map->p_y] = 'P';
	}
	if (map->map[map->p_x + 1][map->p_y] == 'N')
	{
		printf("You lose");
		exit(0);
	}
	if (map->map[map->p_x + 1][map->p_y] == 'E')
		check_exit(map);
	mlx_clear_window(map->ptr, map->win);
	print_wall(map);
}

void	move_to_right(t_map *map)
{
	position_p(map);
	if (map->map[map->p_x][map->p_y + 1] == '1')
		return ;
	if (map->map[map->p_x][map->p_y + 1] == 'C'
		|| map->map[map->p_x][map->p_y + 1] == '0')
	{
		map->map[map->p_x][map->p_y] = '0';
		map->map[map->p_x][map->p_y + 1] = 'P';
	}
	if (map->map[map->p_x][map->p_y + 1] == 'N')
	{
		printf("You lose");
		exit(0);
	}
	if (map->map[map->p_x][map->p_y + 1] == 'E')
		check_exit(map);
	mlx_clear_window(map->ptr, map->win);
	print_wall(map);
}

void	move_to_top(t_map *map)
{
	position_p(map);
	if (map->map[map->p_x - 1][map->p_y] == '1')
		return ;
	if (map->map[map->p_x - 1][map->p_y] == 'C'
		|| map->map[map->p_x - 1][map->p_y] == '0')
	{
		map->map[map->p_x][map->p_y] = '0';
		map->map[map->p_x - 1][map->p_y] = 'P';
	}
	if (map->map[map->p_x - 1][map->p_y] == 'N')
	{
		printf("You lose");
		exit(0);
	}
	if (map->map[map->p_x - 1][map->p_y] == 'E')
		check_exit(map);
	mlx_clear_window(map->ptr, map->win);
	print_wall(map);
}
