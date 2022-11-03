/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:56:10 by smostefa          #+#    #+#             */
/*   Updated: 2021/12/08 20:11:36 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isincharset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	find_start(char const	*s1, char const	*set)
{
	int		i;
	int		start;

	i = 0;
	start = 0;
	while (s1[i] && ft_isincharset(s1[i], set))
	{
		start++;
		i++;
	}
	return (start);
}

static int	find_end(char const	*s1, char const	*set)
{
	int		i;
	int		end;

	i = ft_strlen(s1) - 1;
	end = 0;
	while ((i >= 0) && s1[i] && ft_isincharset(s1[i], set))
	{
		end++;
		i--;
	}
	return (ft_strlen(s1) - end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		i;
	int		j;
	int		start;
	int		end;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = find_start(s1, set);
	end = find_end(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	res = malloc((end - start + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (ft_isincharset(s1[i], set))
		i++;
	while (j < (end - start))
		res[j++] = s1[i++];
	res[j] = '\0';
	return (res);
}

/*
#include <stdio.h>
int	main(void)
{
	printf("%s", ft_strtrim("...--...", ".-"));
	return (0);
}
*/
