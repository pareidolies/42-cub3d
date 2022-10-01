/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:36:48 by smostefa          #+#    #+#             */
/*   Updated: 2021/12/08 15:35:57 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	return (0);
}

/*#include <stdio.h>
int main ()
{
	printf("%d", ft_isprint(' '));
	printf("%d", isprint(' '));
	printf("%c", '\n');
	printf("%d", ft_isprint('\n'));
	printf("%d", isprint('\n'));
}*/
