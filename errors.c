/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:39:28 by msaouab           #+#    #+#             */
/*   Updated: 2022/02/08 23:23:53 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(void)
{
	exit(0);
}

int	any_key(int keycode, t_map *map)
{
	(void)keycode;
	mlx_clear_window(map->ptr, map->win);
	mlx_destroy_window(map->ptr, map->win);
	exit(0);
	return (0);
}

void	destroy_game(t_map *map)
{
	int	x;
	int	y;

	x = (ft_strlen(map->map[0]) * 75) / 2;
	y = (map->lnbr * 75) / 2;
	mlx_clear_window(map->ptr, map->win);
	mlx_string_put(map->ptr, map->win, x, y, 0x00FFFFFF, "you win");
	mlx_key_hook(map->win, any_key, map);
}

void	error_map(int err)
{
	ft_putstr_fd("error\n", 2);
	if (err == 0)
		ft_putstr_fd("you have minumum argements\n", 2);
	if (err == 1)
		ft_putstr_fd("error length of line map\n", 2);
	if (err == 2)
		ft_putstr_fd("Invalid Wall\n", 2);
	if (err == 3)
		ft_putstr_fd("your map must be rectangular\n", 2);
	if (err == 4)
		ft_putstr_fd("error map\n", 2);
	if (err == 5)
		ft_putstr_fd("Invalid Characters\n", 2);
	if (err == 6)
		ft_putstr_fd("wtf\n", 2);
	exit(0);
}
