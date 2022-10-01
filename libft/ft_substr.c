/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:53:16 by smostefa          #+#    #+#             */
/*   Updated: 2021/12/08 18:32:33 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	len_s;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	len_s = ft_strlen(s);
	if (len_s < start)
	{
		res = malloc(sizeof(char));
		res[0] = '\0';
		return (res);
	}
	i = -1;
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (++i < len)
		res[i] = s[start + i];
	res[i] = '\0';
	return (res);
}

/*
#include <stdio.h>
int main()
{
	char* str;

	str = ft_substr("coucou ca va ?", 7, 6);
	printf("%s\n", str);

	return 0;
}
*/
