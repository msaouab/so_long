/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 04:31:11 by msaouab           #+#    #+#             */
/*   Updated: 2022/02/09 05:35:20 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"
#include "../include/so_long.h"

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

char	*ft_substr(char *s, int start, int len)
{
	char	*sub;
	int		i;
	int		j;

	i = 0;
	j = start;
	while (s[j] && i < len)
	{
		i++;
		j++;
	}
	sub = malloc(sizeof(char) * (i + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (s[start] && i < len && start <= ft_strlen(s))
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
