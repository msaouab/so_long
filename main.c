/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 09:39:20 by msaouab           #+#    #+#             */
/*   Updated: 2022/02/01 20:53:44 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	size_win(t_mlx *mlx, t_gnl *gnl)
{
	mlx->x = 1000 / ((gnl->count_line / gnl->i) - 1);
	mlx->y = 550 / gnl->i;
}

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

	i = 0;
	while (i < gnl->i)
	{
		j = 0;
		printf("%d\t%d\n", mlx->x, mlx->y);
		while (j < (gnl->count_line / gnl->i))
		{
			if (gnl->map[i][j] == '1')
				print_windows(mlx, "./img/AnyConv.com__837058.xpm");
			if (gnl->map[i][j] == 'C')
				print_windows(mlx, "./img/jocker.xpm");
			if (gnl->map[i][j] == 'E')
				print_windows(mlx, "./img/car.xpm");
			if (gnl->map[i][j] == 'P')
				print_windows(mlx, "./img/batman.xpm");
			mlx->x += 75;
			j++;
		}
		mlx->x = 0;
		mlx->y += 48;
		i++;
	}
}

int	main(int ac, char **av)
{
	t_mlx	mlx;
	t_gnl	gnl;

	if (ac < 2)
		error_map(0);
	if (ft_strncmp(ft_strrchr(av[1], '.'), ".ber", 4) != 0)
		error_map(-1);
	read_map(av[1], &gnl);
	mlx.ptr = mlx_init();
	// size_win(&mlx, &gnl);
	mlx.win = mlx_new_window(mlx.ptr, 975, 310, "so_long");
	print_windows(&mlx, "./img/gotham.xpm");
	print_wall(&mlx, &gnl);
	mlx_loop(mlx.ptr);
}
