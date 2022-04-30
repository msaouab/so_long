/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:39:28 by msaouab           #+#    #+#             */
/*   Updated: 2022/04/30 15:57:25 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	destroy_game(t_map *map)
{
	int	x;
	int	y;

	x = (ft_strlen(map->map[0]) * 75) / 2;
	y = (map->lnbr * 75) / 2;
	mlx_clear_window(map->ptr, map->win);
	mlx_string_put(map->ptr, map->win, x, y, 0x00FFFFFF, "you win");
	mlx_key_hook(map->win, any_key, map);
	kill(map->pid, SIGSEGV);
}

int	ft_exit(t_map *map)
{
	kill(map->pid, SIGSEGV);
	exit(0);
}