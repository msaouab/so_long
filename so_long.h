/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 09:44:47 by msaouab           #+#    #+#             */
/*   Updated: 2022/02/01 20:26:51 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>

typedef struct gnl_variable
{
	int		count_buff;
	int		count_line;
	char	**map;
	char	*save;
	char	*buff;
	int		fd;
	int		i;
	int		c;
	int		e;
	int		p;
}	t_gnl;

typedef	struct mlx_variables
{
	void	*ptr;
	void	*win;
	int		x;
	int		y;
	int		font_w;
	int		font_h;
	void	*img;
}	t_mlx;


void	read_map(char *av, t_gnl *gnl);
int		ft_strlen(char *s);
char	*ft_strdup(char *s1);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char *s, char c);
void	error_map(int err);
char	*ft_strrchr(char *str, int c);
int		ft_strncmp(char *s1, char *s2, size_t n);

#endif
