/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:37:21 by smostefa          #+#    #+#             */
/*   Updated: 2022/10/10 16:35:18 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		keys_handler(int keycode, t_ray *ray)
{
	if (keycode == MOVE_FORWARD)
		move(keycode, ray, ray->mlx);
	else if (keycode == MOVE_BACKWARD)
		move(keycode, ray, ray->mlx);
	else if (keycode == MOVE_LEFTWARD)
		move(keycode, ray, ray->mlx);
	else if (keycode == MOVE_RIGHTWARD)
		move(keycode, ray, ray->mlx);
	else if (keycode == ROTATE_LEFT)
		rotate(keycode, ray, ray->mlx);
	else if (keycode == ROTATE_RIGHT)
		rotate(keycode, ray, ray->mlx);
	else if (keycode == 101)
	{
		if (ray->minimap)
			ray->minimap = false;
		else
			ray->minimap = true;
		launch_raycasting(ray, ray->mlx);
	}
	else if (keycode == ESC)
		exit_safe(ray);
	return (1);
}
