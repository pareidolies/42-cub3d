/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:37:21 by smostefa          #+#    #+#             */
/*   Updated: 2022/11/02 08:40:32 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_press(int keycode, t_ray *ray)
{
	bool	refresh_menu;

	refresh_menu = false;
	direction(keycode, ray);
	if (keycode == ESC)
		exit_safe(ray);
	if (refresh_menu)
		launch_raycasting(ray, ray->mlx);
	return (0);
}

int	key_release(int keycode, t_ray *ray)
{
	if (keycode == MOVE_FORWARD)
		ray->key.w = false;
	if (keycode == MOVE_BACKWARD)
		ray->key.s = false;
	if (keycode == MOVE_LEFTWARD)
		ray->key.a = false;
	if (keycode == MOVE_RIGHTWARD)
		ray->key.d = false;
	if (keycode == ROTATE_LEFT)
		ray->key.rl = false;
	if (keycode == ROTATE_RIGHT)
		ray->key.rr = false;
	return (0);
}

int	mouse_move(int x, int y, t_ray *ray)
{
	int	i;
	int	j;

	i = 50;
	j = 50;
	(void)x;
	(void)y;
	mlx_mouse_get_pos(ray->mlx->ptr, ray->mlx->win, &i, &j);
	if (i > 50)
		ray->key.mouse_r = true;
	if (i < 50)
		ray->key.mouse_l = true;
	if (ray->key.mouse_l || ray->key.mouse_r)
	{
		move(ray);
		mlx_mouse_move(ray->mlx->ptr, ray->mlx->win, 50, 50);
	}
	return (0);
}
