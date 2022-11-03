/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:25:13 by jdubilla          #+#    #+#             */
/*   Updated: 2022/10/16 17:35:11 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_speed(t_ray *ray, int x, int y)
{
	if (ray->key.move_s == 1 && ray->key.pos_menu == 0)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.move_speed_1s, x, y);
	else if (ray->key.move_s == 1)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.move_speed_1, x, y);
	else if (ray->key.move_s == 2 && ray->key.pos_menu == 0)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.move_speed_2s, x, y);
	else if (ray->key.move_s == 2)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.move_speed_2, x, y);
	else if (ray->key.move_s == 3 && ray->key.pos_menu == 0)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.move_speed_3s, x, y);
	else if (ray->key.move_s == 3)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.move_speed_3, x, y);
	else if (ray->key.move_s == 4 && ray->key.pos_menu == 0)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.move_speed_4s, x, y);
	else if (ray->key.move_s == 4)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.move_speed_4, x, y);
}

void	rot_speed(t_ray *ray, int x, int y)
{
	if (ray->key.rotation_s == 1 && ray->key.pos_menu == 1)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.rot_speed_1s, x, y);
	else if (ray->key.rotation_s == 1)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.rot_speed_1, x, y);
	else if (ray->key.rotation_s == 2 && ray->key.pos_menu == 1)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.rot_speed_2s, x, y);
	else if (ray->key.rotation_s == 2)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.rot_speed_2, x, y);
	else if (ray->key.rotation_s == 3 && ray->key.pos_menu == 1)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.rot_speed_3s, x, y);
	else if (ray->key.rotation_s == 3)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.rot_speed_3, x, y);
	else if (ray->key.rotation_s == 4 && ray->key.pos_menu == 1)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.rot_speed_4s, x, y);
	else if (ray->key.rotation_s == 4)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.rot_speed_4, x, y);
}

void	back_game(t_ray *ray, int x, int y)
{
	if (ray->key.pos_menu == 4)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.back_game_s, x, y);
	else
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.back_game, x, y);
}

void	exit_game(t_ray *ray, int x, int y)
{
	if (ray->key.pos_menu == 5)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.exit_game_s, x, y);
	else
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.exit_game, x, y);
}

void	show_menu(t_ray *ray)
{
	move_speed(ray, WIDTH / 4 * 1.65, (HEIGHT / 4 * 1.2));
	rot_speed(ray, WIDTH / 4 * 1.65, (HEIGHT / 4 * 1.5));
	ceiling_color(ray, WIDTH / 4 * 1.65, (HEIGHT / 4 * 1.8));
	floor_color(ray, WIDTH / 4 * 1.65, (HEIGHT / 4 * 2.1));
	back_game(ray, WIDTH / 4 * 1.65, (HEIGHT / 4 * 2.4));
	exit_game(ray, WIDTH / 4 * 1.65, (HEIGHT / 4 * 2.7));
}
