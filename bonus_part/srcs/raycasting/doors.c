/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:13:13 by smostefa          #+#    #+#             */
/*   Updated: 2022/11/03 14:54:06 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	parse_doors2(t_ray *ray, t_door *door, int i, int j)
{
	if (!door)
	{
		door = create_door((double)(i) + 0.5, (double)j + 0.5);
		if (!door)
		{
			ft_printf(MALLOC_MSSG);
			exit_safe(ray);
		}
	}
	else
		add_door(ray, door, (double)(i) + 0.5, (double)j + 0.5);
}

void	parse_doors(t_ray *ray)
{
	t_door	*door;
	int		i;
	int		j;

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
						ft_printf(MALLOC_MSSG);
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

void	close_opened_doors(t_ray *ray, t_data *data)
{
	int	i;
	int	j;

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

void	check_doors(t_ray *ray)
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
