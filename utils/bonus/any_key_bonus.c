/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   any_key_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 04:19:29 by msaouab           #+#    #+#             */
/*   Updated: 2022/02/09 06:03:15 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	any_key_bonus(int keycode, t_game *map)
{
	(void)keycode;
	mlx_clear_window(map->ptr, map->win);
	mlx_destroy_window(map->ptr, map->win);
	ft_free_bonus(map);
	exit(0);
	return (0);
}
