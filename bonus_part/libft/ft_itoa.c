/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:01:09 by smostefa          #+#    #+#             */
/*   Updated: 2021/12/08 15:37:51 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_exceptions(int n)
{
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	return (NULL);
}

static char	*ft_itoa_neg(int n)
{
	char	*res;
	int		nb;
	int		len_res;

	nb = -n;
	len_res = 1;
	while (nb > 0)
	{
		nb = nb / 10;
		len_res++;
	}
	res = malloc((len_res + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[0] = '-';
	res[len_res] = '\0';
	n = -n;
	while (n > 0)
	{
		res[len_res - 1] = n % 10 + '0';
		n = n / 10;
		len_res--;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		nb;
	int		len_res;

	if (n == -2147483648 || n == 0)
		return (ft_itoa_exceptions(n));
	if (n < 0)
		return (ft_itoa_neg(n));
	nb = n;
	len_res = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		len_res++;
	}
	res = malloc((len_res + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len_res] = '\0';
	while (--len_res >= 0)
	{
		res[len_res] = n % 10 + '0';
		n = n / 10;
	}
	return (res);
}

/*
#include <stdio.h>

int main()
{
	printf("%s\n", ft_itoa(12345));
	printf("%s\n", ft_itoa(-123));
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(0));
}
*/
