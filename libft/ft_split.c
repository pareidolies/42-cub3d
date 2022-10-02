/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:56:39 by smostefa          #+#    #+#             */
/*   Updated: 2022/10/02 14:20:38 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_testchar(char *str, char *charset)
{
	while (*charset)
		if (*str == *charset++)
			return (1);
	return (0);
}

int	ft_lenword(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && (ft_testchar(str + i, charset) == 0))
		i++;
	return (i);
}

int	ft_nbrword(char *str, char *charset)
{
	int	i;
	int	word;

	word = 0;
	while (*str)
	{
		while (*str && ft_testchar(str, charset))
			str++;
		i = ft_lenword(str, charset);
		str += i;
		if (i > 0)
			word++;
	}
	return (word);
}

char	*ft_cpyword(char *src, int n)
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

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		i;
	int		len_arr;
	int		lenword;

	len_arr = ft_nbrword(str, charset);
	res = malloc((len_arr + 1) * sizeof(char *));
	if (!(res))
		return (NULL);
	i = -1;
	while (++i < len_arr)
	{
		while (*str && ft_testchar(str, charset))
			str++;
		lenword = ft_lenword(str, charset);
		res[i] = ft_cpyword(str, lenword);
		if (!(res))
			return (NULL);
		str += lenword;
	}
	res[len_arr] = 0;
	return (res);
}

// #include "libft.h"

// static	int	ft_taillemot(const char *str, char c)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] && str[i] != c)
// 		i++;
// 	return (i);
// }

// static	int	ft_nbrmots(const char *str, char c)
// {
// 	int	i;
// 	int	j;
// 	int	mots;

// 	mots = 0;
// 	i = 0;
// 	while (str[i])
// 	{
// 		while (str[i] && str[i] == c)
// 			str++;
// 		j = ft_taillemot(&str[i], c);
// 		if (j > 0)
// 			mots++;
// 		i = i + j;
// 	}
// 	return (mots);
// }

// static	char	*ft_cpymot(const char *src, int n)
// {
// 	char	*dest;

// 	dest = malloc((n + 1) * sizeof(char));
// 	if (!(dest))
// 		return (NULL);
// 	dest[n] = '\0';
// 	while (n--)
// 		dest[n] = src[n];
// 	return (dest);
// }

// char	**ft_boucle(int tailletab, char const *str, char c, char **res)
// {
// 	int	i;
// 	int	j;
// 	int	lenmot;

// 	i = -1;
// 	j = 0;
// 	while (++i < tailletab)
// 	{
// 		while (str[j] && str[j] == c)
// 			j++;
// 		lenmot = ft_taillemot(&str[j], c);
// 		res[i] = ft_cpymot(&str[j], lenmot);
// 		if (!res[i])
// 		{
// 			i = i - 1;
// 			while (i >= 0)
// 			{
// 				free(res[i]);
// 				i--;
// 			}
// 			return (NULL);
// 		}
// 		j = j + lenmot;
// 	}
// 	return (res);
// }

// char	**ft_split(char const *str, char c)
// {
// 	char	**res;
// 	int		tailletab;

// 	if (!str)
// 		return (NULL);
// 	tailletab = ft_nbrmots(str, c);
// 	res = malloc((tailletab + 1) * sizeof(char *));
// 	if (!(res))
// 		return (NULL);
// 	res = ft_boucle(tailletab, str, c, res);
// 	res[tailletab] = 0;
// 	return (res);
// }

// /*
// #include <stdio.h>
// int main()
// {
// char **str = ft_split("", ' ');
// int i = 0;

// while (i < 1)
// {
// printf("%s\n", str[i]);
// i++;
// }
// }
// */
