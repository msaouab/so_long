/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:39:28 by msaouab           #+#    #+#             */
/*   Updated: 2022/02/07 02:13:07 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	any_key(int keycode, t_map *map)
{
	(void)keycode;
	mlx_clear_window(map->ptr, map->win);
	mlx_destroy_window(map->ptr, map->win);
	exit(0);
	return (0);
}

void	destroy_game(t_map *map)
{
	int	x;
	int	y;

	x = ((map->count_line / map->i) * 75) / 2;
	y = (map->i * 75) / 2;
	mlx_clear_window(map->ptr, map->win);
	mlx_string_put(map->ptr, map->win, x, y, 0x00FFFFFF, "you win");
	mlx_key_hook(map->win, any_key, map);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1)
		return (ft_strdup(s2));
	i = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}

void	error_map(int err)
{
	ft_putstr_fd("error\n", 2);
	if (err == 0)
		ft_putstr_fd("you have minumum argements\n", 2);
	if (err == 1)
		ft_putstr_fd("error length of line map\n", 2);
	if (err == 2)
		ft_putstr_fd("Invalid Wall\n", 2);
	if (err == 3)
		ft_putstr_fd("your map must be rectangular\n", 2);
	if (err == 4)
		ft_putstr_fd("error map\n", 2);
	if (err == 5)
		ft_putstr_fd("Invalid Characters\n", 2);
	exit(0);
}
