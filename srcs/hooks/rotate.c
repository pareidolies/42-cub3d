/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:37:30 by smostefa          #+#    #+#             */
/*   Updated: 2022/10/13 19:42:57 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static bool	rotate_left(t_ray *ray, bool reload, double old_p_x, double old_d_x)
{
	ray->dir.x = ray->dir.x * cos(-ray->rot_speed / 2)
		- ray->dir.y * sin(-ray->rot_speed / 2);
	ray->dir.y = old_d_x * sin(-ray->rot_speed / 2)
		+ ray->dir.y * cos(-ray->rot_speed / 2);
	ray->plane.x = ray->plane.x * cos(-ray->rot_speed / 2)
		- ray->plane.y * sin(-ray->rot_speed / 2);
	ray->plane.y = old_p_x * sin(-ray->rot_speed / 2)
		+ ray->plane.y * cos(-ray->rot_speed / 2);
	ray->key.mouse_l = false;
	reload = true;
	return (reload);
}

static bool	rotate_right(t_ray *ray, bool rl, double old_p_x, double old_d_x)
{
	ray->dir.x = ray->dir.x * cos(ray->rot_speed / 2)
		- ray->dir.y * sin(ray->rot_speed / 2);
	ray->dir.y = old_d_x * sin(ray->rot_speed / 2)
		+ ray->dir.y * cos(ray->rot_speed / 2);
	ray->plane.x = ray->plane.x * cos(ray->rot_speed / 2)
		- ray->plane.y * sin(ray->rot_speed / 2);
	ray->plane.y = old_p_x * sin(ray->rot_speed / 2)
		+ ray->plane.y * cos(ray->rot_speed / 2);
	ray->key.mouse_r = false;
	rl = true;
	return (rl);
}

bool	rotate(t_ray *ray, bool reload)
{
	double	old_plane_x;
	double	old_dir_x;

	old_plane_x = ray->plane.x;
	old_dir_x = ray->dir.x;
	if (ray->key.rl || ray->key.mouse_l)
		reload = rotate_left(ray, reload, old_plane_x, old_dir_x);
	if (ray->key.rr || ray->key.mouse_r)
		reload = rotate_right(ray, reload, old_plane_x, old_dir_x);
	return (reload);
}
