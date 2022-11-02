/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:36:48 by smostefa          #+#    #+#             */
/*   Updated: 2021/12/08 15:35:39 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*#include <stdio.h>
int main ()
{
	printf("%d", ft_isascii('\n'));
	printf("%d", isascii('\n'));
	printf("%c", '\n');
	printf("%d", ft_isascii(128));
	printf("%d", isascii(128));
}*/
