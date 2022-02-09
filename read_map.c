/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 02:28:40 by msaouab           #+#    #+#             */
/*   Updated: 2022/02/09 03:40:09 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	invalid_char(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (++i < map->lnbr)
	{
		j = 0;
		while (++j < ft_strlen(map->map[i]))
		{
			if (map->map[i][j] == 'C')
				map->c++;
			if (map->map[i][j] == 'E')
				map->e++;
			if (map->map[i][j] == 'P')
				map->p++;
			if (map->map[i][j] != '1' && map->map[i][j] != '0')
				if (map->map[i][j] != 'C' && map->map[i][j] != 'E')
					if (map->map[i][j] != 'P')
						error_map(5);
		}
	}
	if (map->p != 1 || map->c < 1 || map->e < 1)
		error_map(4);
}

void	check_elements_map(t_map *map)
{
	int	count;
	int	i;
	int	j;
	int	k;

	i = 0;
	k = ft_strlen(map->map[i]);
	while (++i < map->lnbr - 1)
	{
		j = -1;
		count = 0;
		while (++j < k)
			if (map->map[i][j] == '1')
				count++;
		if (count == j)
			error_map(4);
	}
	map->c = 0;
	map->e = 0;
	map->p = 0;
	invalid_char(map);
}

void	check_walls(t_map *map)
{
	int	i;
	int	j;
	int	k;

	i = map->lnbr - 1;
	while (--i >= 0)
		assign(&map->map[i], ft_substr
			(map->map[i], 0, ft_strlen(map->map[i]) - 1), map->map[i]);
	while (++i < map->lnbr - 1)
		if (ft_strlen(map->map[i]) != ft_strlen(map->map[i + 1]))
			error_map(1);
	i = -1;
	j = map->lnbr - 1;
	k = ft_strlen(map->map[0]);
	while (++i < k)
		if (map->map[0][i] != '1' || map->map[j][i] != '1')
			error_map(2);
	i = -1;
	j = ft_strlen(map->map[0]) - 1;
	while (++i < map->lnbr)
		if (map->map[i][0] != '1' || map->map[i][j] != '1')
			error_map(2);
	check_elements_map(map);
}

void	count_mapln(t_map *map, int fd)
{
	char	*buff;

	map->lnbr = 0;
	while (1)
	{
		buff = get_next_line(fd);
		free (buff);
		if (buff == NULL)
			break ;
		map->lnbr++;
	}
	close(fd);
}

void	read_map(char *av, t_map *map)
{
	int		i;
	int		fd;

	i = 0;
	fd = open(av, O_RDONLY);
	count_mapln(map, fd);
	fd = open(av, O_RDONLY);
	map->map = malloc(sizeof(char *) * map->lnbr + 1);
	while (1)
	{
		map->map[i] = get_next_line(fd);
		if (map->map[i] == NULL)
			break ;
		i++;
	}
	close(fd);
	if (map->map == NULL)
		error_map(-1);
	check_walls(map);
}
