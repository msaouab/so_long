/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:58:42 by msaouab           #+#    #+#             */
/*   Updated: 2022/02/11 20:49:56 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	play_damage_sfx(void)
{
	char	*afplay[3];
	int		pid;

	afplay[0] = "/usr/bin/afplay";
	afplay[1] = "./sound/the_pink_panther.mp3";
	afplay[2] = 0;
	afplay[1] = "./sound/the_pink_panther.mp3";
	pid = fork();
	if (pid == 0)
	{
		execve(afplay[0], afplay, 0);
	}
	return (pid);
}
