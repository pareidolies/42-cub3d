/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:56:39 by smostefa          #+#    #+#             */
/*   Updated: 2022/04/03 18:47:48 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_taillemot(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static	int	ft_nbrmots(const char *str, char c)
{
	int	i;
	int	j;
	int	mots;

	mots = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			str++;
		j = ft_taillemot(&str[i], c);
		if (j > 0)
			mots++;
		i = i + j;
	}
	return (mots);
}

static	char	*ft_cpymot(const char *src, int n)
{
	char	*dest;

	dest = malloc((n + 1) * sizeof(char));
	if (!(dest))
		return (NULL);
	dest[n] = '\0';
	while (n--)
		dest[n] = src[n];
	return (dest);
}

char	**ft_boucle(int tailletab, char const *str, char c, char **res)
{
	int	i;
	int	j;
	int	lenmot;

	i = -1;
	j = 0;
	while (++i < tailletab)
	{
		while (str[j] && str[j] == c)
			j++;
		lenmot = ft_taillemot(&str[j], c);
		res[i] = ft_cpymot(&str[j], lenmot);
		if (!res[i])
		{
			i = i - 1;
			while (i >= 0)
			{
				free(res[i]);
				i--;
			}
			return (NULL);
		}
		j = j + lenmot;
	}
	return (res);
}

char	**ft_split(char const *str, char c)
{
	char	**res;
	int		tailletab;

	if (!str)
		return (NULL);
	tailletab = ft_nbrmots(str, c);
	res = malloc((tailletab + 1) * sizeof(char *));
	if (!(res))
		return (NULL);
	res = ft_boucle(tailletab, str, c, res);
	res[tailletab] = 0;
	return (res);
}

/*
#include <stdio.h>
int main()
{
char **str = ft_split("", ' ');
int i = 0;

while (i < 1)
{
printf("%s\n", str[i]);
i++;
}
}
*/
