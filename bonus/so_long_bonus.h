/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 09:44:47 by msaouab           #+#    #+#             */
/*   Updated: 2022/02/06 02:21:51 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>

typedef struct s_map
{
	int		count_buff;
	int		count_line;
	char	**map;
	char	*save;
	char	*buff;
	int		count;
	int		fd;
	int		i;
	int		c;
	int		e;
	int		p;
	int		n;
	void	*a_coin;
	void	*a_star;
	void	*a_hart;
	void	*a_lion;
	void	*a_bull;
	void	*a_e;
	void	*a_p;
	void	*a_1;
	void	*a_0;
	void	*ptr;
	void	*win;
	int		x;
	int		y;
	int		font_w;
	int		font_h;
	void	*img;
	int		p_x;
	int		p_y;
}	t_map;

void	read_map(char *av, t_map *gnl);
int		ft_strlen(char *s);
char	*ft_strdup(char *s1);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char *s, char c);
void	error_map(int err);
char	*ft_strrchr(char *str, int c);
int		ft_strncmp(char *s1, char *s2, size_t n);
void	movewith_key(t_map *gnl, int keycode);
void	move_to_left(t_map *gnl);
void	move_to_bottum(t_map *gnl);
void	move_to_right(t_map *gnl);
void	move_to_top(t_map *gnl);
void	print_wall(t_map *gnl);
void	position_p(t_map *gnl);
void	random_colloctible(t_map *map);
void	xpm_to_img_collectible(t_map *map);
char	*ft_itoa(int n);

#endif
