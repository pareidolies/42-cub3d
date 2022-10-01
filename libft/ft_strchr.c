/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:25:14 by smostefa          #+#    #+#             */
/*   Updated: 2021/12/08 19:41:32 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;	

	str = (char *)s;
	i = 0;
	if (c == 0)
		return (str + ft_strlen(str));
	while (str[i])
	{
		if ((char)c == str[i])
			return (&str[i]);
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
int main()
{
	char str[] = "salut";
	printf("%s \n", ft_strchr(str, 'l'));
	printf("%s \n", &str[2]);
}
*/
