/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 09:39:20 by msaouab           #+#    #+#             */
/*   Updated: 2022/02/04 00:06:25 by msaouab          ###   ########.fr       */
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

// void	random_collictble(t_mlx *mlx)
// {
// 	int	tab[3];
// 	int	i;
// 	int	max_num;
// 	int	max_indx;
// 	(void)mlx;

// 	i = 0;
// 	while (i < 3)
// 	{
// 		tab[i] = rand();
// 		i++;
// 	}
// 	i = 0;
// 	max_num = tab[0];
// 	while (i < 3)
// 	{
// 		if (tab[i] > max_num)
// 		{
// 			max_num = tab[i];
// 			max_indx = i;
// 		}
// 		i++;
// 	}
// 	printf("%d\n", max_indx);
// }

void	print_wall(t_mlx *mlx, t_gnl *gnl)
{
	int	i;
	int	j;

	mlx_clear_window(mlx->ptr, mlx->win);
	mlx->x = 0;
	mlx->y = 0;
	i = -1;
	while (++i < gnl->i)
	{
		j = -1;
		while (++j < (gnl->count_line / gnl->i))
		{
			print_windows(mlx, "./img/vide.xpm");
			if (gnl->map[i][j] == '1')
				print_windows(mlx, "./img/wall.xpm");
			if (gnl->map[i][j] == 'C')
			{
				print_windows(mlx, "./img/star.xpm");
				// random_collictble(mlx);
			}
			if (gnl->map[i][j] == 'E')
				print_windows(mlx, "./img/door.xpm");
			if (gnl->map[i][j] == 'P')
				print_windows(mlx, "./img/player.xpm");
			mlx->x += 75;			
		}
		mlx->x = 0;
		mlx->y += 75;
	}
	mlx->y = 0;
}

void	move_to_right(t_mlx *mlx, t_gnl *gnl)
{
	int	i;
	int	j;
	int	k[2];

	(void)mlx;
	i = 0;
	while (++i < gnl->i)
	{
		j = 0;
		while (++j < (gnl->count_line / gnl->i) - 1)
		{
			if (gnl->map[i][j] == 'P')
			{
				k[0] = i;
				k[1] = j;
			}
		}
	}
	if (gnl->map[k[0]][k[1] + 1] == '1')
		return ;
	if (gnl->map[k[0]][k[1] + 1] == 'C' || gnl->map[k[0]][k[1] + 1] == '0')
	{
		gnl->map[k[0]][k[1]] = '0';
		gnl->map[k[0]][k[1] + 1] = 'P';
		// reprint_win(mlx, gnl);
	}
		
}

void	movewith_key(t_mlx *mlx, t_gnl *gnl, int keycode)
{
	// if (keycode == 0)
	// 	move_to_left(gnl);
	// if (keycode == 1)
	// 	move_to_bottum(gnl);
	if (keycode == 2)
		move_to_right(mlx, gnl);
	// if (keycode == 13)
	// 	move_to_top(gnl);
}

int	key_hook(int keycode, t_gnl *gnl, t_mlx *mlx)
{
	if (keycode == 0)
		gnl->count++;
	if (keycode == 1)
		gnl->count++;
	if (keycode == 2)
		gnl->count++;
	if (keycode == 13)
		gnl->count++;
	if (keycode == 53)
	{
		gnl->count++;
		printf("keycode : %d\n", gnl->count);
		exit(0);
	}
	if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13 || keycode == 53)
		printf("keycode : %d\n", gnl->count);
	movewith_key(mlx, gnl, keycode);
		// print_wall(mlx, gnl);
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;
	t_gnl	gnl;
	int		x;
	int		y;

	gnl.count = 0;
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
	mlx_key_hook(mlx.win, &key_hook, &gnl);
	// print_wall(&mlx, &gnl);
	mlx_loop(mlx.ptr);
}
