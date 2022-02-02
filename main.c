/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 09:39:20 by msaouab           #+#    #+#             */
/*   Updated: 2022/02/02 20:16:08 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*xpm_to_img(t_mlx *mlx, char *path)
{
	void	*a;

	a = mlx_xpm_file_to_image(mlx->ptr, path, &mlx->font_w, &mlx->font_h);
	return (a);
}

void	print_windows(t_mlx *mlx, char *path)
{
	mlx->img = xpm_to_img(mlx, path);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, mlx->x, mlx->y);
}

void	print_wall(t_mlx *mlx, t_gnl *gnl)
{
	int	i;
	int	j;

	i = -1;
	while (++i < gnl->i)
	{
		j = -1;
		while (++j < (gnl->count_line / gnl->i))
		{
			if (gnl->map[i][j] != 'P' && gnl->map[i][j] != 'C'
			&& gnl->map[i][j] != 'E')
				print_windows(mlx, "./img/back.xpm");
			if (gnl->map[i][j] == '1')
				print_windows(mlx, "./img/door.xpm");
			if (gnl->map[i][j] == 'C')
				print_windows(mlx, "./img/zombie.xpm");
			if (gnl->map[i][j] == 'E')
				print_windows(mlx, "./img/door.xpm");
			if (gnl->map[i][j] == 'P')
				print_windows(mlx, "./img/bat.xpm");
			mlx->x += 75;
		}
		mlx->x = 0;
		mlx->y += 75;
	}
}

int	main(int ac, char **av)
{
	t_mlx	mlx;
	t_gnl	gnl;
	int		x;
	int		y;

	if (ac < 2)
		error_map(0);
	if (ft_strncmp(ft_strrchr(av[1], '.'), ".ber", 4) != 0)
		error_map(-1);
	read_map(av[1], &gnl);
	x = (gnl.count_line / gnl.i) * 75;
	y = gnl.i * 75;
	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, x, y, "so_long");
	print_wall(&mlx, &gnl);
	mlx_loop(mlx.ptr);
}
