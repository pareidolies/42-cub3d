/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:12:51 by elouisia          #+#    #+#             */
/*   Updated: 2022/10/02 19:11:36 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkptr(va_list arg, t_struct *data)
{
	unsigned long	ptr;

	ptr = va_arg(arg, unsigned long);
	if (!ptr)
		return (ft_print_str(NULL));
	else
	{
		data->len += ft_print_str("0x");
		data->len += ft_print_ptrbase(ptr);
	}
	return (0);
}

static int	ft_whatsnext(char i, va_list arg, t_struct *data)
{
	if (i == 'c')
		data->len += ft_print_char(va_arg(arg, int));
	if (i == 's')
		data->len += ft_print_str(va_arg(arg, char *));
	if (i == 'i' || i == 'd')
		data->len += ft_print_nbr(va_arg(arg, int));
	if (i == 'u')
		data->len += ft_print_unbr(va_arg(arg, unsigned int));
	if (i == 'x' || i == 'X')
		data->len += ft_print_nbrbase(va_arg(arg, unsigned int), i);
	if (i == 'p')
		data->len += ft_checkptr(arg, data);
	if (i == '%')
		data->len += ft_print_char('%');
	return (data->len);
}

int	ft_printf(const char *str, ...)
{
	va_list		arg;
	int			i;
	t_struct	data;

	i = 0;
	data.len = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_print_char(str[i]);
			data.len++;
		}
		else
		{
			i++;
			data.len = ft_whatsnext(str[i], arg, &data);
		}
		i++;
	}
	va_end(arg);
	return (data.len);
}
