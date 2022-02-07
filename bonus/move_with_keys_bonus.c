/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_with_keys_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:43:00 by msaouab           #+#    #+#             */
/*   Updated: 2022/02/07 16:46:02 by msaouab          ###   ########.fr       */
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
		printf("check\n");
		destroy_game(map, 1);
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
	else if (map->map[map->p_x][map->p_y - 1] == 'N')
	{
		map->out = 2;
		printf("You lose");
		return ;
	}
	map->map[map->p_x][map->p_y] = '0';
	map->map[map->p_x][map->p_y - 1] = 'P';
	map->count++;
	mlx_clear_window(map->ptr, map->win);
	print_wall(map);
	mlx_string_put(map->ptr, map->win, 15, 7, 0x00000000, ft_itoa(map->count));
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
	else if (map->map[map->p_x + 1][map->p_y] == 'N')
	{
		map->out = 2;
		printf("You lose");
		return ;
	}
	map->map[map->p_x][map->p_y] = '0';
	map->map[map->p_x + 1][map->p_y] = 'P';
	map->count++;
	mlx_clear_window(map->ptr, map->win);
	print_wall(map);
	mlx_string_put(map->ptr, map->win, 15, 7, 0x00000000, ft_itoa(map->count));
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
	else if (map->map[map->p_x][map->p_y + 1] == 'N')
	{
		map->out = 2;
		printf("You lose");
		return ;
	}
	map->map[map->p_x][map->p_y] = '0';
	map->map[map->p_x][map->p_y + 1] = 'P';
	map->count++;
	mlx_clear_window(map->ptr, map->win);
	print_wall(map);
	mlx_string_put(map->ptr, map->win, 15, 7, 0x00000000, ft_itoa(map->count));
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
	else if (map->map[map->p_x - 1][map->p_y] == 'N')
	{
		map->out = 2;
		printf("You lose");
		return ;
	}
	map->map[map->p_x][map->p_y] = '0';
	map->map[map->p_x - 1][map->p_y] = 'P';
	map->count++;
	mlx_clear_window(map->ptr, map->win);
	print_wall(map);
	mlx_string_put(map->ptr, map->win, 15, 7, 0x00000000, ft_itoa(map->count));
}
