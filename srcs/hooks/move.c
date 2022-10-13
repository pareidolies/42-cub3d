/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:37:26 by smostefa          #+#    #+#             */
/*   Updated: 2022/10/13 15:41:58 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static bool	key_w(t_ray *ray, bool reload)
{
	if (ray->revert_map[(int)(ray->pos.x
			+ (ray->dir.x * MOVE_SPEED * 2))][(int)ray->pos.y] != '1')
		ray->pos.x += ray->dir.x * MOVE_SPEED;
	if (ray->revert_map[(int)(ray->pos.x)][(int)(ray->pos.y
		+ (ray->dir.y * MOVE_SPEED * 2))] != '1')
		ray->pos.y += ray->dir.y * MOVE_SPEED;
	reload = true;
	return (reload);
}

static bool	key_s(t_ray *ray, bool reload)
{
	if (ray->revert_map[(int)(ray->pos.x
			- (ray->dir.x * MOVE_SPEED * 2))][(int)(ray->pos.y)] != '1')
		ray->pos.x -= ray->dir.x * MOVE_SPEED;
	if (ray->revert_map[(int)(ray->pos.x)][(int)(ray->pos.y
		- (ray->dir.y * MOVE_SPEED * 2))] != '1')
		ray->pos.y -= ray->dir.y * MOVE_SPEED;
	reload = true;
	return (reload);
}

static bool	key_d(t_ray *ray, bool reload)
{
	if (ray->revert_map[(int)(ray->pos.x - ray->dir.y
			* (MOVE_SPEED * 2))][(int)ray->pos.y] != '1')
		ray->pos.x -= ray->dir.y * MOVE_SPEED;
	if (ray->revert_map[(int)ray->pos.x][(int)(ray->pos.y + ray->dir.x
		* (MOVE_SPEED * 2))] != '1')
		ray->pos.y += ray->dir.x * MOVE_SPEED;
	reload = true;
	return (reload);
}

static bool	key_a(t_ray *ray, bool reload)
{
	if (ray->revert_map[(int)(ray->pos.x + ray->dir.y
			* (MOVE_SPEED * 2))][(int)ray->pos.y] != '1')
		ray->pos.x += ray->dir.y * MOVE_SPEED;
	if (ray->revert_map[(int)ray->pos.x][(int)(ray->pos.y - ray->dir.x
		* (MOVE_SPEED * 2))] != '1')
		ray->pos.y -= ray->dir.x * MOVE_SPEED;
	reload = true;
	return (reload);
}

int	move(t_ray *ray)
{
	bool	reload;

	reload = false;
	if (ray->key.w)
		reload = key_w(ray, reload);
	if (ray->key.s)
		reload = key_s(ray, reload);
	if (ray->key.d)
		reload = key_d(ray, reload);
	if (ray->key.a)
		reload = key_a(ray, reload);
	reload = rotate(ray, reload);
	if (reload)
		launch_raycasting(ray, ray->mlx);
	return (0);
}
