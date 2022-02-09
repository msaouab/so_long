/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 09:44:47 by msaouab           #+#    #+#             */
/*   Updated: 2022/02/09 04:06:06 by msaouab          ###   ########.fr       */
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
	int		lnbr;
	char	**map;
	int		count;
	int		out;
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
	char	*move;
}	t_map;

void	read_map_bonus(char *av, t_map *gnl);
void	movewith_key_bonus(t_map *gnl, int keycode);
void	move_to_left_bonus(t_map *gnl);
void	move_to_bottum_bonus(t_map *gnl);
void	move_to_right_bonus(t_map *gnl);
void	move_to_top_bonus(t_map *gnl);
void	print_wall_bonus(t_map *gnl);
void	check_exit_bonus(t_map *map);
int		ft_strlen(char *s);
char	*ft_strdup(char *s1);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char *s, char c);
void	error_map(int err);
char	*ft_strrchr(char *str, int c);
int		ft_strncmp(char *s1, char *s2, size_t n);
void	random_colloctible(t_map *map);
void	position_p(t_map *gnl);
void	xpm_to_img_collectible(t_map *map);
char	*ft_itoa(int n);
char	*ft_strjoin(char *s1, char *s2);
void	destroy_game(t_map *map, int res);
int		ft_exit(void);

void	ft_free(t_map *map);
char	*get_next_line(int fd);
void	assign(char **dest, char *src, char *to_free);
char	*ft_substr(char *s, int start, int len);
void	ft_free(t_map *map);

#endif
