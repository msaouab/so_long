/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 02:28:40 by msaouab           #+#    #+#             */
/*   Updated: 2022/01/21 02:59:05 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_map()
{
	ft_putstr_fd("error\n", 2);
	exit(0);
}

void	check_map(t_gnl *gnl)
{
	int	i;
	int	j;

	i = -1;
	j = gnl->count_buff - 1;
	while (++i < ft_strlen(gnl->map[0]))
		if (gnl->map[0][i] != '1' || gnl->map[j][i] != '1' )
			error_map();
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

void	read_map()
{
	t_gnl	gnl;
	int		i;

	gnl.fd = open("./maps", O_APPEND | O_RDWR);
	gnl.map = ft_split(get_next_line(gnl.fd, &gnl), '\n');
	i = 0;
	while (gnl.map[i])
		i++;
	gnl.count_buff = i;
	while (--i > 0)
		if (ft_strlen(gnl.map[i]) != ft_strlen(gnl.map[i - 1]))
			error_map();
	check_map(&gnl);
}
