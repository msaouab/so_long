/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 04:20:25 by msaouab           #+#    #+#             */
/*   Updated: 2022/02/09 05:35:27 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"
#include "../include/so_long.h"

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
