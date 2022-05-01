/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:09:19 by msaouab           #+#    #+#             */
/*   Updated: 2022/05/01 01:40:58 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	move_enemy_to_left(t_game *map, int i, int j)
{
	if (map->map[i][j - 1] == '1' || map->map[i][j - 1] == 'E'
		|| map->map[i][j - 1] == 'C')
		return ;
	if (map->map[i][j - 1] == 'P')
	{
		map->out = 2;
		printf("You lose");
		destroy_game_bonus(map, 0);
		return ;
	}
	map->map[i][j] = '0';
	map->map[i][j - 1] = 'N';
}

void	move_enemy_to_right(t_game *map, int i, int j)
{
	if (map->map[i][j + 1] == '1' || map->map[i][j + 1] == 'E'
		|| map->map[i][j + 1] == 'C')
		return ;
	if (map->map[i][j + 1] == 'P')
	{
		map->out = 2;
		printf("You lose");
		destroy_game_bonus(map, 0);
		return ;
	}
	map->map[i][j] = '0';
	map->map[i][j + 1] = 'N';
}

void	move_enemy_to_buttom(t_game *map, int i, int j)
{
	if (map->map[i + 1][j] == '1' || map->map[i + 1][j] == 'E'
		|| map->map[i + 1][j] == 'C')
		return ;
	if (map->map[i + 1][j] != '0')
	{
		map->out = 2;
		printf("You lose");
		destroy_game_bonus(map, 0);
		return ;
	}
	map->map[i][j] = '0';
	map->map[i + 1][j] = 'N';
}

void	move_enemy_to_top(t_game *map, int i, int j)
{
	if (map->map[i - 1][j] == '1' || map->map[i - 1][j] == 'E'
		|| map->map[i - 1][j] == 'C')
		return ;
	if (map->map[i - 1][j] != '0')
	{
		map->out = 2;
		printf("You lose");
		destroy_game_bonus(map, 0);
		return ;
	}
	map->map[i][j] = '0';
	map->map[i - 1][j] = 'N';
}

void	move_enemy(t_game *map, int i, int j)
{
	int		rand;

	if (map->map[i][j] == 'N')
	{
		rand = arc4random_uniform(4);
		if (rand == 0)
			move_enemy_to_left(map, i, j);
		else if (rand == 1)
			move_enemy_to_right(map, i, j);
		else if (rand == 2)
			move_enemy_to_top(map, i, j);
		else if (rand == 3)
			move_enemy_to_buttom(map, i, j);
	}
}
