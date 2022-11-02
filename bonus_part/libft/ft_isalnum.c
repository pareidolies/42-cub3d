/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:36:48 by smostefa          #+#    #+#             */
/*   Updated: 2021/12/08 15:34:56 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

/*#include <stdio.h>
int main ()
{
	printf("%d", ft_isalnum('a'));
	printf("%d", isalnum('a'));
	printf("%c", '\n');
	printf("%d", ft_isalnum('0'));
	printf("%d", isalnum('0'));
	printf("%c", '\n');
        printf("%d", ft_isalnum('\n'));
        printf("%d", isalnum('\n'));
}*/
