/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:01:37 by smostefa          #+#    #+#             */
/*   Updated: 2021/12/08 15:48:32 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		len_s;
	int		i;

	if (!s || !f)
		return (NULL);
	len_s = ft_strlen(s);
	res = malloc((len_s + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len_s)
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
