/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:22:47 by smostefa          #+#    #+#             */
/*   Updated: 2021/12/08 15:46:10 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		len_s1;
	int		i;

	len_s1 = ft_strlen(s1);
	dst = malloc(sizeof(char) * (len_s1 + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
	printf("%s", ft_strdup("salut"));
}
*/
