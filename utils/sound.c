/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:58:42 by msaouab           #+#    #+#             */
/*   Updated: 2022/04/30 16:02:20 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	play_damage_sfx(t_map *map)
{
	char	*afplay[3];

	afplay[0] = "/usr/bin/afplay";
	afplay[1] = "./sound/the_pink_panther.mp3";
	afplay[2] = 0;
	afplay[1] = "./sound/the_pink_panther.mp3";
	map->pid = fork();
	if (map->pid == 0)
	{
		execve(afplay[0], afplay, 0);
	}
}
