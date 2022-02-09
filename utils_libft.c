/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 04:31:11 by msaouab           #+#    #+#             */
/*   Updated: 2022/02/09 03:59:50 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
		write(fd, &s[i++], 1);
}

char	*ft_strrchr(char *str, int c)
{
	int		i;

	i = ft_strlen(str);
	if (c == '\0')
		return ((char *)&str[i]);
	while (--i >= 0)
		if ((char )str[i] == (char)c)
			return ((char *)&str[i]);
	return (NULL);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*sr1;
	unsigned char	*sr2;

	i = 0;
	sr1 = (unsigned char *)s1;
	sr2 = (unsigned char *)s2;
	while (i < n && (sr1[i] || sr2[i]))
	{
		if (sr1[i] != sr2[i])
			return (sr1[i] - sr2[i]);
		i++;
	}
	return (0);
}
