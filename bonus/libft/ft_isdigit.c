/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:36:48 by smostefa          #+#    #+#             */
/*   Updated: 2021/12/08 15:35:50 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*#include <stdio.h>
int main ()
{
	printf("%d", ft_isdigit('a'));
	printf("%d", isdigit('a'));
	printf("%c", '\n');
	printf("%d", ft_isdigit('0'));
	printf("%d", isdigit('0'));
}*/
