/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:15:57 by smostefa          #+#    #+#             */
/*   Updated: 2021/12/08 15:39:10 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*elt;

	if (lst)
	{
		while (*lst)
		{
			elt = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = elt;
		}
	}
	*lst = NULL;
}
