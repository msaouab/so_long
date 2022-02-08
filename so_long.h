/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 09:44:47 by msaouab           #+#    #+#             */
/*   Updated: 2022/02/08 23:31:21 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>

#define BUFFER_SIZE 1

typedef struct map_variable
{
	int		count_line;
	char	**map;
	char	*save;
	char	*buff;
	int		count;
	int		fd;
	int		out;
	int		lnbr;
	int		wnbr;
	int		c;
	int		e;
	int		p;
	void	*a_Coin;
	void	*a_Star;
	void	*a_Hart;
	void	*a_E;
	void	*a_P;
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
void	print_result(void);
char	*ft_strjoin(char *s1, char *s2);
void	check_exit(t_map *map);
void	destroy_game(t_map *map);
int		ft_exit(void);

char	*get_next_line(int fd);
char	*ft_substr(char *s, int start, int len);
// size_t	ft_strlen(char *s);
char	*ft_ret_ft(char **saved);
void	assign(char **dest, char *src, char *to_free);
#endif
