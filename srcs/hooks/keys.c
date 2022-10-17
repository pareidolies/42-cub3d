/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:37:21 by smostefa          #+#    #+#             */
/*   Updated: 2022/10/17 16:22:44 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	pos_menu(int keycode, t_ray *ray)
{
	if (keycode == 65364 && ray->key.menu)
	{
		ray->key.pos_menu++;
		if (ray->key.pos_menu == 6)
			ray->key.pos_menu = 0;
		launch_raycasting(ray, ray->mlx);
	}
	else if (keycode == 65362 && ray->key.menu)
	{
		ray->key.pos_menu--;
		if (ray->key.pos_menu == -1)
			ray->key.pos_menu = 5;
		launch_raycasting(ray, ray->mlx);
	}
	if (keycode == 101)
	{
		if (ray->minimap)
			ray->minimap = false;
		else
			ray->minimap = true;
		launch_raycasting(ray, ray->mlx);
	}
}

static void	key_press_bis(int keycode, t_ray *ray)
{
	if (keycode == 109 && HEIGHT >= 800 && WIDTH >= 500)
	{
		if (ray->key.menu)
		{
			ray->key.pos_menu = 0;
			ray->key.menu = false;
		}
		else
			ray->key.menu = true;
		launch_raycasting(ray, ray->mlx);
	}
	else if ((keycode == 65364 || keycode == 65362 || keycode == 101))
		pos_menu(keycode, ray);
	if (keycode == 65293 && ray->key.menu && ray->key.pos_menu == 4)
	{
		ray->key.menu = false;
		launch_raycasting(ray, ray->mlx);
	}
}

int	key_press(int keycode, t_ray *ray)
{
	bool	refresh_menu;

	refresh_menu = false;
	direction(keycode, ray);
	if (keycode == ESC)
		exit_safe(ray);
	if (keycode == 109 || keycode == 101 || keycode == 65364
		|| keycode == 65362 || keycode == 65293)
		key_press_bis(keycode, ray);
	if ((keycode == 65451 || keycode == 65453) && ray->key.pos_menu == 0)
		refresh_menu = move_speed_key(refresh_menu, ray, keycode);
	if ((keycode == 65451 || keycode == 65453) && ray->key.pos_menu == 1)
		refresh_menu = rotation_speed(refresh_menu, ray, keycode);
	if ((keycode == 65451 || keycode == 65453) && ray->key.pos_menu == 2)
		refresh_menu = ceilling_color_key(refresh_menu, ray, keycode);
	if ((keycode == 65451 || keycode == 65453) && ray->key.pos_menu == 3)
		refresh_menu = floor_color_key(refresh_menu, ray, keycode);
	if (keycode == 65293 && ray->key.menu && ray->key.pos_menu == 5)
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
