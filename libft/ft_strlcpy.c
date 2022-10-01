/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:26:58 by smostefa          #+#    #+#             */
/*   Updated: 2021/12/08 15:47:18 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[j])
	{
		j++;
	}
	if (dstsize == 0)
		return (j);
	while (src[i] && i < (dstsize - 1))
	{
		dst[i] = src [i];
		i++;
	}
	dst[i] = '\0';
	return (j);
}

/*
#include <string.h>
#include <stdio.h>
int		main(void)
{
	char	dest[50];
	char	*src;
	int		size;

	src = "test";
	size = 10;
	printf("%zu\n", ft_strlcpy(dest, src, size));
	printf("%s\n\n", dest);
	printf("%lu\n", strlcpy(dest, src, size));
	printf("%s\n\n", dest);
}
*/
