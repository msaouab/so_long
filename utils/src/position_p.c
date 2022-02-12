/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 04:55:54 by msaouab           #+#    #+#             */
/*   Updated: 2022/02/09 05:55:26 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	position_p(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (++i < map->lnbr)
	{
		j = 0;
		while (++j < ft_strlen(map->map[i]) - 1)
		{
			if (map->map[i][j] == 'P')
			{
				map->p_x = i;
				map->p_y = j;
			}
		}
	}
}
