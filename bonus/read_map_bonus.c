/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 02:28:40 by msaouab           #+#    #+#             */
/*   Updated: 2022/02/06 18:52:14 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	invalid_char(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (++i < map->i - 1)
	{
		j = 0;
		while (++j < (map->count_line / map->i) - 1)
		{
			if (map->map[i][j] == 'C')
				map->c++;
			if (map->map[i][j] == 'E')
				map->e++;
			if (map->map[i][j] == 'P')
				map->p++;
			if (map->map[i][j] == 'N')
				map->n++;
			if (map->map[i][j] != '1' && map->map[i][j] != '0')
				if (map->map[i][j] != 'C' && map->map[i][j] != 'E')
					if (map->map[i][j] != 'P' && map->map[i][j] != 'N')
						error_map(5);
		}
	}
	if (map->p != 1 || map->c < 1 || map->e < 1 || map->n < 1)
		error_map(4);
}

void	check_elements_map(t_map *map)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	while (++i < map->i - 1)
	{
		j = -1;
		count = 0;
		while (++j < ft_strlen(map->map[i]))
			if (map->map[i][j] == '1')
				count++;
		if (count == j)
			error_map(4);
	}
	map->c = 0;
	map->e = 0;
	map->p = 0;
	map->n = 0;
	invalid_char(map);
}

void	check_map(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	j = map->count_buff - 1;
	while (++i < ft_strlen(map->map[0]))
		if (map->map[0][i] != '1' || map->map[j][i] != '1')
			error_map(2);
	i = 0;
	j = ft_strlen(map->map[0]) - 1;
	while (++i < map->count_buff)
		if (map->map[i][0] != '1' || map->map[i][j] != '1')
			error_map(2);
	check_elements_map(map);
}

char	*get_next_line(int fd, t_map *map)
{
	char	*save;
	char	buff[1];
	int		i;

	i = 0;
	if (fd < 0)
		return (NULL);
	while (read(fd, buff, 1) == 1)
	{
		save = ft_strjoin(save, buff);
		save[i + 1] = '\0';
		if (save[i + 1] == '\n')
			break ;
		i++;
	}
	if (save[0] == '\0')
		return (NULL);
	map->buff = ft_strdup(save);
	if (map->buff)
		map->count_line = ft_strlen(map->buff);
	return (map->buff);
}

void	read_map(char *av, t_map *map)
{
	int		i;

	map->fd = open(av, O_RDONLY);
	map->save = get_next_line(map->fd, map);
	map->map = ft_split(map->save, '\n');
	if (map->map == NULL)
		error_map(-1);
	i = 0;
	while (map->map[i])
		i++;
	map->i = i;
	if ((map->count_line / map->i) == i)
		error_map(3);
	map->count_buff = i;
	while (--i > 0)
		if (ft_strlen(map->map[i]) != ft_strlen(map->map[i - 1]))
			error_map(1);
	check_map(map);
}
