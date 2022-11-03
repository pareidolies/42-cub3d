/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:12:29 by smostefa          #+#    #+#             */
/*   Updated: 2022/10/31 19:21:37 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	compute_deltadist(t_ray *ray)
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

void	compute_sidedist(t_ray *ray)
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

void	compute_perpwalldist2(t_ray *ray)
{
	if (ray->side == HORIZONTAL)
		ray->perpwalldist = ray->sidedist.x - ray->deltadist.x;
	else
		ray->perpwalldist = ray->sidedist.y - ray->deltadist.y;
}

void	compute_perpwalldist(t_ray *ray)
{
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
		if (ray->revert_map[ray->map.x][ray->map.y] == '1'
			|| ray->revert_map[ray->map.x][ray->map.y] == '2')
		{
			ray->hit = WALL;
		}
	}
	compute_perpwalldist2(ray);
}

void	compute_line_attributes(t_ray *ray)
{
	ray->lineheight = (int)(1.5 * HEIGHT / ray->perpwalldist);
	ray->drawstart = -ray->lineheight / 2 + HEIGHT / 2;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = ray->lineheight / 2 + HEIGHT / 2;
	if (ray->drawend >= HEIGHT || ray->drawend < 0)
		ray->drawend = HEIGHT - 1;
}
