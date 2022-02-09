/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 04:18:14 by msaouab           #+#    #+#             */
/*   Updated: 2022/02/09 05:57:41 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_free_bonus(t_game *map)
{
	int	i;

	i = 0;
	while (i < map->lnbr)
	{
		free (map->map[i]);
		i++;
	}
	free (map->map);
}
