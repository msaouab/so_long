/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 02:28:40 by msaouab           #+#    #+#             */
/*   Updated: 2022/01/31 20:26:24 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	invalid_char(t_gnl *gnl)
{
	int	i;

	i = 0;
	gnl->c = 0;	
	gnl->e = 0;	
	gnl->p = 0;
	while (i < gnl->count_line)
	{
		if (gnl->s[i] == 'C')
			gnl->c++;
		if (gnl->s[i] == 'E')
			gnl->e++;
		if (gnl->s[i] == 'P')
			gnl->p++;
		printf("%c\n", gnl->s[i]);
		if (gnl->s[i] != '1' || gnl->s[i] != '0')
			error_map(5);
		i++;
	}
	printf("%d\t%d\t%d\n", gnl->c, gnl->e, gnl->p);
}

void	check_elements_map(t_gnl *gnl)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	while (++i < gnl->i - 1)
	{
		j = -1;
		count = 0;
		while (++j < ft_strlen(gnl->map[i]))
			if (gnl->map[i][j] == '1')
				count++;
		if (count == j)
			error_map(4);
	}
	invalid_char(gnl);
}

void	check_map(t_gnl *gnl)
{
	int	i;
	int	j;

	i = -1;
	j = gnl->count_buff - 1;
	while (++i < ft_strlen(gnl->map[0]))
		if (gnl->map[0][i] != '1' || gnl->map[j][i] != '1')
			error_map(2);
	i = 0;
	j = ft_strlen(gnl->map[0]) - 1;
	while (++i < gnl->count_buff)
		if (gnl->map[i][0] != '1' || gnl->map[i][j] != '1')
			error_map(2);
	check_elements_map(gnl);
}

char	*get_next_line(int fd, t_gnl *gnl)
{
	char	save[999999];
	char	buff[1];
	int		i;

	i = 0;
	if (fd < 0)
		return (NULL);
	save[i] = '\0';
	while (read(fd, buff, 1) == 1)
	{
		save[i] = buff[0];
		save[i + 1] = '\0';
		if (save[i + 1] == '\n')
			break ;
		i++;
	}
	if (save[0] == '\0')
		return (NULL);
	gnl->buff = ft_strdup(save);
	if (gnl->buff)
		gnl->count_line = ft_strlen(gnl->buff);
	return (gnl->buff);
}

void	read_map(char *av)
{
	t_gnl	gnl;
	int		i;

	gnl.fd = open(av, O_RDONLY);
	gnl.s = get_next_line(gnl.fd, &gnl);
	gnl.map = ft_split(gnl.s, '\n');
	if (gnl.map == NULL)
		error_map(-1);
	i = 0;
	while (gnl.map[i])
		i++;
	gnl.i = i;
	if ((gnl.count_line / i) == i)
		error_map(3);
	gnl.count_buff = i;
	while (--i > 0)
		if (ft_strlen(gnl.map[i]) != ft_strlen(gnl.map[i - 1]))
			error_map(1);
	check_map(&gnl);
}
