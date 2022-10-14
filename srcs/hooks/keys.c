/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:37:21 by smostefa          #+#    #+#             */
/*   Updated: 2022/10/14 15:12:12 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	key_press_bis(int keycode, t_ray *ray)
{
	if (keycode == 109)
	{
		if (ray->key.menu)
		{
			ray->key.pos_menu = 0;
			ray->key.menu = false;
		}
		else
			ray->key.menu = true;
		// printf("menu = %d\n", ray->key.menu);
		launch_raycasting(ray, ray->mlx);
	}
	else if (keycode == 65364 && ray->key.menu)
	{
		// printf("TEST\n");
		ray->key.pos_menu++;
		if (ray->key.pos_menu == 3)
			ray->key.pos_menu = 0;
		launch_raycasting(ray, ray->mlx);
	}
	else if (keycode == 65362 && ray->key.menu)
	{
		// printf("TEST\n");
		ray->key.pos_menu--;
		// printf("pos_menu = %d\n", ray->key.pos_menu);
		if (ray->key.pos_menu == -1)
			ray->key.pos_menu = 2;
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

	// BACK GAME
	if (keycode == 65293 && ray->key.menu && ray->key.pos_menu == 2)
	{
		ray->key.menu = false;
		launch_raycasting(ray, ray->mlx);
	}
}


// - = keycode = 65453
// + = keycode = 65451


int	key_press(int keycode, t_ray *ray)
{
	// char	s[50];

	// printf("keycode = %d\n", keycode);
	bool refresh_menu = false;
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
	if (keycode == ESC)
		exit_safe(ray);
	if (keycode == 109 || keycode == 101 || keycode == 65364 || keycode == 65362 || keycode == 65293)
		key_press_bis(keycode, ray);

	// MOVE_SPEED
	if (keycode == 65451 && ray->key.menu && ray->key.pos_menu == 0)
	{
		ray->move_speed += 0.05;
		ray->key.move_s++;
		if (ray->move_speed > 0.2)
		{
			ray->key.move_s = 8;
			ray->move_speed = 0.2;
		}
		// printf("test = %f\n", ray->move_speed);
		refresh_menu = true;
	}
	if (keycode == 65453 && ray->key.menu && ray->key.pos_menu == 0)
	{
		ray->move_speed -= 0.025;
		ray->key.move_s--;
		if (ray->move_speed <= 0.01)
		{
			ray->key.move_s = 1;
			ray->move_speed = 0.025;
		}
		// printf("test = %f\n", ray->move_speed);
		refresh_menu = true;
	}

	//ROT_SPEED
	if (keycode == 65451 && ray->key.menu && ray->key.pos_menu == 1)
	{
		ray->rot_speed += 0.01;
		ray->key.rotation_s++;
		if (ray->rot_speed > 0.7)
		{
			ray->key.rotation_s = 70;
			ray->rot_speed = 0.7;
		}
		// printf("test = %f\n", ray->rot_speed);
		refresh_menu = true;
	}
	if (keycode == 65453 && ray->key.menu && ray->key.pos_menu == 1)
	{
		ray->rot_speed -= 0.01;
		ray->key.rotation_s--;
		if (ray->rot_speed <= 0.001)
		{
			ray->key.rotation_s = 1;
			ray->rot_speed = 0.01;
		}
		// printf("test = %f\n", ray->rot_speed);
		refresh_menu = true;
	}
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
