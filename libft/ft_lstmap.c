/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:17:04 by smostefa          #+#    #+#             */
/*   Updated: 2021/12/08 19:50:54 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_element;

	if (!lst || !f)
		return (NULL);
	new_element = ft_lstnew(f(lst->content));
	new_list = new_element;
	lst = lst->next;
	while (lst)
	{
		new_element = ft_lstnew(f(lst->content));
		if (!new_element)
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&new_list, new_element);
	}
	return (new_list);
}
