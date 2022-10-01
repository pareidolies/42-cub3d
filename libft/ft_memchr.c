/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:08:30 by smostefa          #+#    #+#             */
/*   Updated: 2021/12/08 15:41:51 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	a;
	size_t			i;

	str = (unsigned char *)s;
	a = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == a)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
int main()
{
	char str[] = "salut";
	printf("%s \n", ft_memchr(str, 'l', 1));
}
*/
