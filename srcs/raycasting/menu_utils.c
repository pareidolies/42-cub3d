/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:29:15 by jdubilla          #+#    #+#             */
/*   Updated: 2022/10/16 17:34:53 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ceilling_color_bis(t_ray *ray, int x, int y)
{
	if (ray->ceilling_color == 4 && ray->key.pos_menu == 2)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.ceilling_4s, x, y);
	else if (ray->ceilling_color == 4)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.ceilling_4, x, y);
	else if (ray->ceilling_color == 5 && ray->key.pos_menu == 2)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.ceilling_5s, x, y);
	else if (ray->ceilling_color == 5)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.ceilling_5, x, y);
	else if (ray->ceilling_color == 6 && ray->key.pos_menu == 2)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.ceilling_6s, x, y);
	else if (ray->ceilling_color == 6)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.ceilling_6, x, y);
	else if (ray->ceilling_color == 7 && ray->key.pos_menu == 2)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.ceilling_7s, x, y);
	else if (ray->ceilling_color == 7)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.ceilling_7, x, y);
}

void	ceilling_color(t_ray *ray, int x, int y)
{
	if (ray->ceilling_color == 0 && ray->key.pos_menu == 2)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.ceilling_0s, x, y);
	else if (ray->ceilling_color == 0)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.ceilling_0, x, y);
	else if (ray->ceilling_color == 1 && ray->key.pos_menu == 2)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.ceilling_1s, x, y);
	else if (ray->ceilling_color == 1)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.ceilling_1, x, y);
	else if (ray->ceilling_color == 2 && ray->key.pos_menu == 2)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.ceilling_2s, x, y);
	else if (ray->ceilling_color == 2)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.ceilling_2, x, y);
	else if (ray->ceilling_color == 3 && ray->key.pos_menu == 2)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.ceilling_3s, x, y);
	else if (ray->ceilling_color == 3)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.ceilling_3, x, y);
	ceilling_color_bis(ray, x, y);
}

static void	floor_color_bis(t_ray *ray, int x, int y)
{
	if (ray->floor_color == 4 && ray->key.pos_menu == 3)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.floor_4s, x, y);
	else if (ray->floor_color == 4)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.floor_4, x, y);
	else if (ray->floor_color == 5 && ray->key.pos_menu == 3)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.floor_5s, x, y);
	else if (ray->floor_color == 5)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.floor_5, x, y);
	else if (ray->floor_color == 6 && ray->key.pos_menu == 3)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.floor_6s, x, y);
	else if (ray->floor_color == 6)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.floor_6, x, y);
	else if (ray->floor_color == 7 && ray->key.pos_menu == 3)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.floor_7s, x, y);
	else if (ray->floor_color == 7)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.floor_7, x, y);
}

void	floor_color(t_ray *ray, int x, int y)
{
	if (ray->floor_color == 0 && ray->key.pos_menu == 3)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.floor_0s, x, y);
	else if (ray->floor_color == 0)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.floor_0, x, y);
	else if (ray->floor_color == 1 && ray->key.pos_menu == 3)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.floor_1s, x, y);
	else if (ray->floor_color == 1)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.floor_1, x, y);
	else if (ray->floor_color == 2 && ray->key.pos_menu == 3)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.floor_2s, x, y);
	else if (ray->floor_color == 2)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.floor_2, x, y);
	else if (ray->floor_color == 3 && ray->key.pos_menu == 3)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.floor_3s, x, y);
	else if (ray->floor_color == 3)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.floor_3, x, y);
	floor_color_bis(ray, x, y);
}
