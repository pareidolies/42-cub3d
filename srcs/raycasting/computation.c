/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:35:50 by smostefa          #+#    #+#             */
/*   Updated: 2022/10/07 14:35:52 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void compute_deltadist(t_ray *ray)
{
	if (ray->raydir.x == 0)
		ray->deltadist.x = 2147483647;
	else
		ray->deltadist.x = fabs(1 / ray->raydir.x);
    if (ray->raydir.y == 0)
		ray->deltadist.y = 2147483647;
	else
		ray->deltadist.y = fabs(1 / ray->raydir.y);
}

void compute_sidedist(t_ray *ray, t_data *data)
{
    if (ray->raydir.x < 0)
	{
		ray->step.x = -1;
		ray->sidedist.x = (ray->pos.x - ray->map.x) * ray->deltadist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->sidedist.x = (ray->map.x + 1.0 - ray->pos.x) * ray->deltadist.x;
	}
	if (ray->raydir.y < 0)
	{
		ray->step.y = -1;
		ray->sidedist.y = (ray->pos.y - ray->map.y) * ray->deltadist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->sidedist.y = (ray->map.y + 1.0 - ray->pos.y) * ray->deltadist.y;
	}
}

void    compute_perpwalldist(t_ray *ray, t_data *data)
{
	//printf("TEST\n");
	while (ray->hit == EMPTY)
	{
		if (ray->sidedist.x < ray->sidedist.y)
		{
			ray->sidedist.x += ray->deltadist.x;
			ray->map.x += ray->step.x;
			ray->side = HORIZONTAL;
		}
		else
		{
			ray->sidedist.y += ray->deltadist.y;
			ray->map.y += ray->step.y;
			ray->side = VERTICAL;
		}
		//printf("x : %d\n", ray->map.x);
		//printf("y : %d\n", ray->map.y);
		//printf("case : %c\n", data->map[ray->map.y][ray->map.x]);
		if (ray->revert_map[ray->map.x][ray->map.y] == '1')
			ray->hit = WALL;
		//printf("test\n");
	}
    if (ray->side == HORIZONTAL)
		//ray->perpwalldist = ((double)ray->map.x - ray->pos.x + (1 - (double)ray->step.x) / 2) / ray->raydir.x;
		ray->perpwalldist = ray->sidedist.x - ray->deltadist.x;
	else
		//ray->perpwalldist = ((double)ray->map.y - ray->pos.y + (1 - (double)ray->step.y) / 2) / ray->raydir.y;
		ray->perpwalldist = ray->sidedist.y - ray->deltadist.y;
}

void    compute_line_attributes(t_ray *ray)
{
    ray->lineheight = (int)(ray->height / ray->perpwalldist);
	ray->drawstart = -ray->lineheight / 2 + ray->height / 2;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = ray->lineheight / 2 + ray->height / 2;
	if (ray->drawend >= ray->height || ray->drawend < 0)
		ray->drawend = ray->height - 1;
}
