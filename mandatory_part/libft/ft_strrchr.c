/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:31:47 by smostefa          #+#    #+#             */
/*   Updated: 2022/04/08 12:10:31 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	a;
	int		len;
	char	*str;

	a = (char)c;
	str = (char *)s;
	len = ft_strlen(str);
	while (len >= 0)
	{
		if (str[len] == a)
			return (&str[len]);
		len--;
	}
	return (NULL);
}

/*
#include <stdio.h>

int main()
{
	char str[] = "coucou";
	printf("%s", ft_strrchr(str, 'o'));
}
*/
