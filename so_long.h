/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 09:44:47 by msaouab           #+#    #+#             */
/*   Updated: 2022/01/31 20:02:14 by msaouab          ###   ########.fr       */
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
	char	*buff;			//line in map (%s)
	int		count_buff;		// total char in one line in map (%s)
	int		count_line;		// total char in map (%d)
	int		fd;				
	int		i;				// number of line in map (%d)
	char	*s;			//total char in map (%s)
	int		c;
	int		e;
	int		p;
}	t_gnl;

void	read_map(char *av);
int		ft_strlen(char *s);
char	*ft_strdup(char *s1);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char *s, char c);
void	error_map(int err);
char	*ft_strrchr(char *str, int c);
int		ft_strncmp(char *s1, char *s2, size_t n);

#endif