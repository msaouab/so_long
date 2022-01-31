/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:45:08 by msaouab           #+#    #+#             */
/*   Updated: 2021/11/07 11:00:55 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
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
/*
#include<stdio.h>
#include<string.h>
int	main()
{
	char s1[] = "";
	char s2[] = "AAAAAAAAA";
	int	n = 30;
	printf("%d\n", ft_strncmp(s1, s2, n));
	printf("%d\n", strncmp(s1, s2, n));
}*/
