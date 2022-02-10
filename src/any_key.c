/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   any_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 04:19:29 by msaouab           #+#    #+#             */
/*   Updated: 2022/02/10 11:36:49 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	any_key(int keycode, t_map *map)
{
	(void)keycode;
	mlx_clear_window(map->ptr, map->win);
	mlx_destroy_window(map->ptr, map->win);
	ft_free(map);
	exit(0);
	return (0);
}
