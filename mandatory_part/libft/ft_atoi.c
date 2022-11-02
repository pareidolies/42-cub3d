/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 10:41:47 by smostefa          #+#    #+#             */
/*   Updated: 2022/04/08 12:09:46 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	minus;
	int	nb;

	i = 0;
	minus = 0;
	nb = 0;
	while ((str[i] == ' ' | str[i] == '\t' | str[i] == '\n' | str[i] == '\v'
			| str[i] == '\f' | str[i] == '\r') && str[i] != '\0')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if ((minus % 2) == 1)
		nb = nb * (-1);
	return (nb);
}

/*#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("%d\n", ft_atoi("-2147483648"));
	printf("%d\n", atoi("-2147483648"));
}*/
