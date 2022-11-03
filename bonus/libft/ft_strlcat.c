/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:24:36 by smostefa          #+#    #+#             */
/*   Updated: 2021/12/08 15:47:01 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;

	i = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (dstsize == 0 | dstsize <= len_dst)
		return (len_src + dstsize);
	while (src[i] && i < (dstsize - len_dst - 1))
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char			dest[50] = "coucou";
	char			src[50] = " ca va ?";
	unsigned int	size;

	size = 15;
	//printf("%zu\n", ft_strlcat(dest, src, size));
	//printf("dest: %s\n", dest);
	printf("%lu\n", strlcat(dest, src, size));
	printf("dest: %s\n", dest);
}
*/
