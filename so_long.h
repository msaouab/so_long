/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 09:44:47 by msaouab           #+#    #+#             */
/*   Updated: 2022/01/21 00:11:46 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mlx.h>
#include <fcntl.h>

typedef struct gnl_variable
{
	char	**map;
	char	*buff;
	int		count_buff;
	int		count_line;
	int		fd;
	int		i;
}	t_gnl;



void	read_map();
int		ft_strlen(char *s);
char	*ft_strdup(char *s1);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char *s, char c);
void	error_map();
#endif