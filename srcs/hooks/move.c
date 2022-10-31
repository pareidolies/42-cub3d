/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:37:26 by smostefa          #+#    #+#             */
/*   Updated: 2022/10/13 18:23:27 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_wall_or_sprite(char c)
{
	if (c == '1' || c == '3' || c == '4')
	{
		return (1);
	}
	return (0);
}

static bool	key_w(t_ray *ray, bool reload)
{
	if (!is_wall_or_sprite(ray->revert_map[(int)(ray->pos.x
			+ (ray->dir.x * ray->move_speed * 2))][(int)ray->pos.y]))
		ray->pos.x += ray->dir.x * ray->move_speed;
	if (!is_wall_or_sprite(ray->revert_map[(int)(ray->pos.x)][(int)(ray->pos.y
		+ (ray->dir.y * ray->move_speed * 2))]))
		ray->pos.y += ray->dir.y * ray->move_speed;
	reload = true;
	return (reload);
}

static bool	key_s(t_ray *ray, bool reload)
{
	if (!is_wall_or_sprite(ray->revert_map[(int)(ray->pos.x
			- (ray->dir.x * ray->move_speed * 2))][(int)(ray->pos.y)]))
		ray->pos.x -= ray->dir.x * ray->move_speed;
	if (!is_wall_or_sprite(ray->revert_map[(int)(ray->pos.x)][(int)(ray->pos.y
		- (ray->dir.y * ray->move_speed * 2))]))
		ray->pos.y -= ray->dir.y * ray->move_speed;
	reload = true;
	return (reload);
}

static bool	key_d(t_ray *ray, bool reload)
{
	if (!is_wall_or_sprite(ray->revert_map[(int)(ray->pos.x - ray->dir.y
			* (ray->move_speed * 2))][(int)ray->pos.y]))
		ray->pos.x -= ray->dir.y * ray->move_speed;
	if (!is_wall_or_sprite(ray->revert_map[(int)ray->pos.x][(int)(ray->pos.y + ray->dir.x
		* (ray->move_speed * 2))]))
		ray->pos.y += ray->dir.x * ray->move_speed;
	reload = true;
	return (reload);
}

static bool	key_a(t_ray *ray, bool reload)
{
	if (!is_wall_or_sprite(ray->revert_map[(int)(ray->pos.x + ray->dir.y
			* (ray->move_speed * 2))][(int)ray->pos.y]))
		ray->pos.x += ray->dir.y * ray->move_speed;
	if (!is_wall_or_sprite(ray->revert_map[(int)ray->pos.x][(int)(ray->pos.y - ray->dir.x
		* (ray->move_speed * 2))]))
		ray->pos.y -= ray->dir.x * ray->move_speed;
	reload = true;
	return (reload);
}

int	move(t_ray *ray)
{
	bool	reload;

	reload = false;
	if (ray->key.menu)
		return (1);
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
