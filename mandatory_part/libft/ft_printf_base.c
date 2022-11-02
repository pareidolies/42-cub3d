/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:45:29 by elouisia          #+#    #+#             */
/*   Updated: 2022/10/02 17:37:52 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_getsizebase(unsigned int nb)
{
	int	i;

	i = 1;
	while (nb > 15)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

int	ft_print_nbrbase(unsigned int nb, char i)
{
	char	*base;

	if (i == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nb < 16)
		ft_print_char(base[nb]);
	else
	{
		ft_print_nbrbase(nb / 16, i);
		ft_print_nbrbase(nb % 16, i);
	}
	return (ft_getsizebase(nb));
}

int	ft_getsizeptr(unsigned long nb)
{
	int	i;

	i = 1;
	while (nb > 15)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

int	ft_print_ptrbase(unsigned long n)
{
	char	*base;

	base = "0123456789abcdef";
	if (n < 16)
		ft_print_char(base[n]);
	else
	{
		ft_print_ptrbase(n / 16);
		ft_print_ptrbase(n % 16);
	}
	return (ft_getsizeptr(n));
}
