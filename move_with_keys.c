/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_with_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:43:33 by msaouab           #+#    #+#             */
/*   Updated: 2022/02/04 18:06:23 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_exit(t_gnl *gnl, int a, int b)
{
	int	i;
	int	j;
	int	l;

	l = 1;
	i = -1;
	while (++i < gnl->i)
	{
		j = -1;
		while (++j < (gnl->count_line / gnl->i))
		{
			if (gnl->map[i][j] == 'C')
				l = 0;
		}
	}
	if (l == 0)
		return ;
	else
	{
		gnl->map[a][b] = '0';
		exit(0);
	}
}

void	move_to_left(t_gnl *gnl)
{
	int	i;
	int	j;
	int	a;
	int	b;

	i = 0;
	while (++i < gnl->i)
	{
		j = 0;
		while (++j < (gnl->count_line / gnl->i) - 1)
		{
			if (gnl->map[i][j] == 'P')
			{
				a = i;
				b = j;
			}
		}
	}
	if (gnl->map[a][b - 1] == '1')
		return ;
	if (gnl->map[a][b - 1] == 'C' || gnl->map[a][b - 1] == '0')
	{
		gnl->map[a][b] = '0';
		gnl->map[a][b - 1] = 'P';
	}
	if (gnl->map[a][b - 1] == 'E')
		check_exit(gnl, a, b);
	print_wall(gnl);
}

void	move_to_bottum(t_gnl *gnl)
{
	int	i;
	int	j;
	int	a;
	int	b;

	i = 0;
	while (++i < gnl->i)
	{
		j = 0;
		while (++j < (gnl->count_line / gnl->i) - 1)
		{
			if (gnl->map[i][j] == 'P')
			{
				a = i;
				b = j;
			}
		}
	}
	if (gnl->map[a + 1][b] == '1')
		return ;
	if (gnl->map[a + 1][b] == 'C' || gnl->map[a + 1][b] == '0')
	{
		gnl->map[a][b] = '0';
		gnl->map[a + 1][b] = 'P';
	}
	if (gnl->map[a + 1][b] == 'E')
		check_exit(gnl, a, b);
	print_wall(gnl);
}

void	move_to_right(t_gnl *gnl)
{
	int	i;
	int	j;
	int	a;
	int	b;

	i = 0;
	while (++i < gnl->i)
	{
		j = 0;
		while (++j < (gnl->count_line / gnl->i) - 1)
		{
			if (gnl->map[i][j] == 'P')
			{
				a = i;
				b = j;
			}
		}
	}
	if (gnl->map[a][b + 1] == '1')
		return ;
	if (gnl->map[a][b + 1] == 'C' || gnl->map[a][b + 1] == '0')
	{
		gnl->map[a][b] = '0';
		gnl->map[a][b + 1] = 'P';
	}
	if (gnl->map[a][b + 1] == 'E')
		check_exit(gnl, a, b);
	print_wall(gnl);
}

void	move_to_top(t_gnl *gnl)
{
	int	i;
	int	j;
	int	a;
	int	b;

	i = 0;
	while (++i < gnl->i)
	{
		j = 0;
		while (++j < (gnl->count_line / gnl->i) - 1)
		{
			if (gnl->map[i][j] == 'P')
			{
				a = i;
				b = j;
			}
		}
	}
	if (gnl->map[a - 1][b] == '1')
		return ;
	if (gnl->map[a - 1][b] == 'C' || gnl->map[a - 1][b] == '0')
	{
		gnl->map[a][b] = '0';
		gnl->map[a - 1][b] = 'P';
	}
	if (gnl->map[a - 1][b] == 'E')
		check_exit(gnl, a, b);
	print_wall(gnl);
}