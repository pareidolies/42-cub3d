/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:36:48 by smostefa          #+#    #+#             */
/*   Updated: 2021/12/08 15:35:11 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

/*#include <stdio.h>
int main ()
{
	printf("%d", ft_isalpha('a'));
	printf("%d", isalpha('a'));
	printf("%c", '\n');
	printf("%d", ft_isalpha('0'));
	printf("%d", isalpha('0'));
}*/
