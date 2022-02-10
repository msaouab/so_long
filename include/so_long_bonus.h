/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 09:44:47 by msaouab           #+#    #+#             */
/*   Updated: 2022/02/10 12:47:06 by msaouab          ###   ########.fr       */
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
# include "so_long.h"

# define BUFFER_SIZE 1

typedef struct s_game
{
	char	**map;
	int		count;
	int		out;
	int		lnbr;
	int		wnbr;
	int		c;
	int		e;
	int		p;
	int		n;
	void	*a_1;
	void	*a_0;
	void	*a_e;
	void	*a_p;
	void	*a_coin;
	void	*a_star;
	void	*a_hart;
	void	*a_lion;
	void	*a_bull;
	void	*ptr;
	void	*win;
	int		x;
	int		y;
	int		font_w;
	int		font_h;
	void	*img;
	int		p_x;
	int		p_y;
	char	*move;
	char	*buff;
}	t_game;

void	read_map_bonus(char *av, t_game *map);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strrchr(char *str, int c);
int		ft_strncmp(char *s1, char *s2, size_t n);
// char	*ft_substr(char *s, int start, int len);
int		ft_strlen(char *s);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
int		any_key_bonus(int keycode, t_game *map);
void	ft_free_bonus(t_game *map);
void	error_map(int err);
int		ft_exit(void);
void	xpm_to_img_collectible_bonus(t_game *map);
void	position_p_bonus(t_game *map);
void	assign(char **dest, char *src, char *to_free);
char	*get_next_line(int fd);
void	destroy_game_bonus(t_game *map, int res);
char	*ft_itoa(int n);
void	xpm_to_img_bonus(t_game *map);
int		keys_hook_bonus(int keycode, t_game *map);
void	check_exit_bonus(t_game *map);
void	move_to_left_bonus(t_game *map);
void	move_to_bottum_bonus(t_game *map);
void	move_to_right_bonus(t_game *map);
void	move_to_top_bonus(t_game *map);
void	read_map_bonus(char *av, t_game *map);
void	print_wall_bonus(t_game *map);
void	xpm_to_img_bonus(t_game *map);

#endif
