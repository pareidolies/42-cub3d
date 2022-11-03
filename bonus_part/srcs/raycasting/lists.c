/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:10:29 by smostefa          #+#    #+#             */
/*   Updated: 2022/11/03 16:10:30 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_door	*create_door(double x, double y)
{
	t_door	*node;

	node = malloc(sizeof(t_door));
	{
		if (!node)
			return (NULL);
	}
	node->prev = NULL;
	node->next = NULL;
	node->x = x;
	node->y = y;
	return (node);
}

void	add_door(t_ray *ray, t_door *first, double x, double y)
{
	t_door	*current;
	t_door	*new;

	current = first;
	new = create_door(x, y);
	if (!new)
	{
		ft_printf(MALLOC_MSSG);
		free_list(first);
		exit_safe(ray);
	}
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	new->prev = current;
}
