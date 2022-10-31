/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 19:20:52 by jdubilla          #+#    #+#             */
/*   Updated: 2022/10/16 16:53:01 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	move_speed_key(bool refresh_menu, t_ray *ray, int keycode)
{
	if (keycode == 65451 && ray->key.menu)
	{
		ray->move_speed += 0.05;
		ray->key.move_s++;
		if (ray->move_speed > 0.26)
		{
			ray->key.move_s = 4;
			ray->move_speed = 0.25;
		}
		refresh_menu = true;
	}
	if (keycode == 65453 && ray->key.menu)
	{
		ray->move_speed -= 0.05;
		ray->key.move_s--;
		if (ray->move_speed < 0.1)
		{
			ray->key.move_s = 1;
			ray->move_speed = 0.1;
		}
		refresh_menu = true;
	}
	return (refresh_menu);
}

bool	rotation_speed(bool refresh_menu, t_ray *ray, int keycode)
{
	if (keycode == 65451 && ray->key.menu)
	{
		ray->rot_speed += 0.03;
		ray->key.rotation_s++;
		if (ray->rot_speed > 0.1)
		{
			ray->key.rotation_s = 4;
			ray->rot_speed = 0.10;
		}
		refresh_menu = true;
	}
	if (keycode == 65453 && ray->key.menu)
	{
		ray->rot_speed -= 0.03;
		ray->key.rotation_s--;
		if (ray->rot_speed <= 0.01)
		{
			ray->key.rotation_s = 1;
			ray->rot_speed = 0.01;
		}
		refresh_menu = true;
	}
	return (refresh_menu);
}

bool	ceiling_color_key(bool refresh_menu, t_ray *ray, int keycode)
{
	if (keycode == 65451 && ray->key.menu)
	{
		ray->ceiling_color++;
		if (ray->ceiling_color == 8)
			ray->ceiling_color = 0;
		refresh_menu = true;
	}
	if (keycode == 65453 && ray->key.menu)
	{
		ray->ceiling_color--;
		if (ray->ceiling_color == -1)
			ray->ceiling_color = 7;
		refresh_menu = true;
	}
	return (refresh_menu);
}

bool	floor_color_key(bool refresh_menu, t_ray *ray, int keycode)
{
	if (keycode == 65451 && ray->key.menu)
	{
		ray->floor_color++;
		if (ray->floor_color == 8)
			ray->floor_color = 0;
		refresh_menu = true;
	}
	if (keycode == 65453 && ray->key.menu)
	{
		ray->floor_color--;
		if (ray->floor_color == -1)
			ray->floor_color = 7;
		refresh_menu = true;
	}
	return (refresh_menu);
}

void	direction(int keycode, t_ray *ray)
{
	if (keycode == MOVE_FORWARD)
		ray->key.w = true;
	if (keycode == MOVE_BACKWARD)
		ray->key.s = true;
	if (keycode == MOVE_LEFTWARD)
		ray->key.a = true;
	if (keycode == MOVE_RIGHTWARD)
		ray->key.d = true;
	if (keycode == ROTATE_LEFT)
		ray->key.rl = true;
	if (keycode == ROTATE_RIGHT)
		ray->key.rr = true;
}
