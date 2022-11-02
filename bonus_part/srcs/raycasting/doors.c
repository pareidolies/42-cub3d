/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:13:13 by smostefa          #+#    #+#             */
/*   Updated: 2022/10/31 17:13:16 by smostefa         ###   ########.fr       */
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
        printf(MALLOC_MSSG); 
        free_list(first);
        exit_safe(ray);
    }
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	new->prev = current;
}

void    parse_doors(t_ray *ray)
{
    t_door  *door;
    int i;
    int j;

    j = 0;
    door = NULL;
    while (j < ray->data->height)
    {
        i = 0;
        while (i < ray->data->len)
        {
            if (ray->revert_map[i][j] == '2')
            {
                if (!door)
                {
                    door = create_door((double)(i) + 0.5, (double)j + 0.5);
                    if (!door)
                    {
                        printf(MALLOC_MSSG);
                        exit_safe(ray);
                    }
                }
                else
                    add_door(ray, door, (double)(i) + 0.5, (double)j + 0.5);
            }
            i++;
        }
        j++;
    }
    ray->door = door;
}

void    close_opened_doors(t_ray *ray, t_data *data)
{
    int i;
    int j;

    i = 0;
	j = 0;
	while (i < data->len)
	{
		j = 0;
		while (j < data->height)
		{
            if (ray->revert_map[i][j] != data->map[j][i])
			    ray->revert_map[i][j] = data->map[j][i];
			j++;
		}
		i++;
	}
}

void    check_doors(t_ray *ray)
{
    t_door	*current;

    current = ray->door;
    while (current != NULL)
    {
        if (((ray->pos.x >= current->x - 1.0) 
            && (ray->pos.x <= current->x + 1.0)) 
            && ((ray->pos.y >= current->y - 1.0) 
            && (ray->pos.y <= current->y + 1.0)))
            ray->revert_map[(int)current->x][(int)current->y] = '0';
		current = current->next;
    }
}
