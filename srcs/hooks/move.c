/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:37:26 by smostefa          #+#    #+#             */
/*   Updated: 2022/10/11 16:29:14 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move(int keycode, t_ray *ray, t_mlx *mlx)
{
	if (keycode == MOVE_FORWARD)
	{
		if (ray->revert_map[(int)(ray->pos.x + (ray->dir.x * MOVE_SPEED * 2))][(int)ray->pos.y] != '1')
			ray->pos.x += ray->dir.x * MOVE_SPEED;
		if (ray->revert_map[(int)(ray->pos.x)][(int)(ray->pos.y + (ray->dir.y * MOVE_SPEED * 2))] != '1')
			ray->pos.y += ray->dir.y * MOVE_SPEED;
	}
	if (keycode == MOVE_BACKWARD)
	{
		if (ray->revert_map[(int)(ray->pos.x - (ray->dir.x * MOVE_SPEED * 2))][(int)(ray->pos.y)] != '1')
			ray->pos.x -= ray->dir.x * MOVE_SPEED;
		if (ray->revert_map[(int)(ray->pos.x)][(int)(ray->pos.y - (ray->dir.y * MOVE_SPEED * 2))] != '1')
			ray->pos.y -= ray->dir.y * MOVE_SPEED;
	}
	if (keycode == MOVE_RIGHTWARD)
	{
		if (ray->revert_map[(int)(ray->pos.x - ray->dir.y * (MOVE_SPEED * 2))][(int)ray->pos.y] != '1')
			ray->pos.x -= ray->dir.y * MOVE_SPEED;
		if (ray->revert_map[(int)ray->pos.x][(int)(ray->pos.y + ray->dir.x * (MOVE_SPEED * 2))] != '1')
			ray->pos.y += ray->dir.x * MOVE_SPEED;
	}
	if (keycode == MOVE_LEFTWARD)
	{
		if (ray->revert_map[(int)(ray->pos.x + ray->dir.y * (MOVE_SPEED * 2))][(int)ray->pos.y] != '1')
			ray->pos.x += ray->dir.y * MOVE_SPEED;
		if (ray->revert_map[(int)ray->pos.x][(int)(ray->pos.y - ray->dir.x * (MOVE_SPEED * 2))] != '1')
			ray->pos.y -= ray->dir.x * MOVE_SPEED;
	}
	launch_raycasting(ray, mlx);
}
