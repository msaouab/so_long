/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 09:44:47 by msaouab           #+#    #+#             */
/*   Updated: 2022/02/09 08:22:51 by msaouab          ###   ########.fr       */
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

# define BUFFER_SIZE 1

typedef struct s_map
{
	char	**map;
	char	*move;
	void	*img;
	void	*win;
	int		count;
	int		out;
	int		lnbr;
	int		wnbr;
	int		c;
	int		e;
	int		p;
	void	*a_1;
	void	*a_0;
	void	*a_e;
	void	*a_p;
	void	*a_coin;
	void	*a_star;
	void	*a_hart;
	void	*ptr;
	int		x;
	int		y;
	int		font_w;
	int		font_h;
	int		p_x;
	int		p_y;
}	t_map;

void	read_map(char *av, t_map *map);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strrchr(char *str, int c);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_substr(char *s, int start, int len);
int		ft_strlen(char *s);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
void	destroy_game(t_map *map);
void	move_to_top(t_map *map);
void	move_to_right(t_map *map);
void	move_to_bottum(t_map *map);
void	move_to_left(t_map *map);
void	check_exit(t_map *map);
int		any_key(int keycode, t_map *map);
void	ft_free(t_map *map);
void	error_map(int err);
int		ft_exit(void);
void	xpm_to_img_collectible(t_map *map);
void	print_wall(t_map *map);
void	position_p(t_map *map);
void	assign(char **dest, char *src, char *to_free);
char	*get_next_line(int fd);
char	*ft_itoa(int n);
int		keys_hook(int keycode, t_map *map);

#endif
