/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 09:39:20 by msaouab           #+#    #+#             */
/*   Updated: 2022/02/04 17:49:02 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	*xpm_to_img(t_gnl *gnl, char *path)
// {
// 	void	*a;

// 	a = mlx_xpm_file_to_image(gnl->ptr, path, &gnl->font_w, &gnl->font_h);
// 	return (a);
// }

void	xpm_to_img(t_gnl *gnl)
{
	void	*ph_0;
	void	*ph_1;
	void	*ph_P;
	void	*ph_C;
	void	*ph_E;
	
	ph_0 = "./img/vide.xpm";
	ph_1 = "./img/wall.xpm";
	ph_P = "./img/player.xpm";
	ph_C = "./img/star.xpm";
	ph_E = "./img/door.xpm";
	gnl->a_0 = mlx_xpm_file_to_image(gnl->ptr, ph_0, &gnl->font_w, &gnl->font_h);
	gnl->a_1 = mlx_xpm_file_to_image(gnl->ptr, ph_1, &gnl->font_w, &gnl->font_h);
	gnl->a_P = mlx_xpm_file_to_image(gnl->ptr, ph_P, &gnl->font_w, &gnl->font_h);
	gnl->a_C = mlx_xpm_file_to_image(gnl->ptr, ph_C, &gnl->font_w, &gnl->font_h);
	gnl->a_E = mlx_xpm_file_to_image(gnl->ptr, ph_E, &gnl->font_w, &gnl->font_h);
}


void	print_windows(t_gnl *gnl, void *path)
{
	// gnl->img = xpm_to_img(mlx, path);
	mlx_put_image_to_window(gnl->ptr, gnl->win, path, gnl->x, gnl->y);
}

// void	random_collictble(t_gnl *gnl)
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

void	print_wall(t_gnl *gnl)
{
	int	i;
	int	j;

	
	mlx_clear_window(gnl->ptr, gnl->win);
	gnl->x = 0;
	gnl->y = 0;
	i = -1;
	while (++i < gnl->i)
	{
		j = -1;
		while (++j < (gnl->count_line / gnl->i))
		{
			print_windows(gnl, gnl->a_0);
			if (gnl->map[i][j] == '1')
				print_windows(gnl, gnl->a_1);
			if (gnl->map[i][j] == 'C')
				print_windows(gnl, gnl->a_C);
			if (gnl->map[i][j] == 'E')
				print_windows(gnl, gnl->a_E);
			if (gnl->map[i][j] == 'P')
				print_windows(gnl, gnl->a_P);
			gnl->x += 75;
		}
		gnl->x = 0;
		gnl->y += 75;
	}
	gnl->y = 0;
}

void	movewith_key(t_gnl *gnl, int keycode)
{
	if (keycode == 0)
		move_to_left(gnl);
	if (keycode == 1)
		move_to_bottum(gnl);
	if (keycode == 2)
		move_to_right(gnl);
	if (keycode == 13)
		move_to_top(gnl);
}

int	key_hook(int keycode, t_gnl *gnl)
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
	movewith_key(gnl, keycode);
		//print_wall(mlx, gnl);
	return (0);
}

int	main(int ac, char **av)
{
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
	gnl.ptr = mlx_init();
	gnl.win = mlx_new_window(gnl.ptr, x, y, "so_long");
	xpm_to_img(&gnl);
	print_wall(&gnl);
	mlx_key_hook(gnl.win, &key_hook, &gnl);
	// print_wall(&mlx, &gnl);
	mlx_loop(gnl.ptr);
}
