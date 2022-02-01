/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 04:31:11 by msaouab           #+#    #+#             */
/*   Updated: 2022/02/01 12:36:38 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*dst;

	i = ft_strlen(s1);
	dst = malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = (char)s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

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
