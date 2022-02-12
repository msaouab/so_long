/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:39:28 by msaouab           #+#    #+#             */
/*   Updated: 2022/02/11 17:26:07 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	destroy_game_bonus(t_game *map, int res)
{
	int	x;
	int	y;

	x = (ft_strlen(map->map[0]) * 75) / 2;
	y = (map->lnbr * 75) / 2;
	mlx_clear_window(map->ptr, map->win);
	if (res == 1)
		mlx_string_put(map->ptr, map->win, x, y, 0x00FFFFFF, "you win");
	else if (res == 0)
		mlx_string_put(map->ptr, map->win, x, y, 0x00FFFFFF, "you lose");
	mlx_key_hook(map->win, any_key_bonus, map);
}
