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

static void	ceiling_color_bis(t_ray *ray, int x, int y)
{
	if (ray->ceiling_color == 4 && ray->key.pos_menu == 2)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.ceiling_4s, x, y);
	else if (ray->ceiling_color == 4)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.ceiling_4, x, y);
	else if (ray->ceiling_color == 5 && ray->key.pos_menu == 2)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.ceiling_5s, x, y);
	else if (ray->ceiling_color == 5)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.ceiling_5, x, y);
	else if (ray->ceiling_color == 6 && ray->key.pos_menu == 2)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.ceiling_6s, x, y);
	else if (ray->ceiling_color == 6)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.ceiling_6, x, y);
	else if (ray->ceiling_color == 7 && ray->key.pos_menu == 2)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.ceiling_7s, x, y);
	else if (ray->ceiling_color == 7)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.ceiling_7, x, y);
}

void	ceiling_color(t_ray *ray, int x, int y)
{
	if (ray->ceiling_color == 0 && ray->key.pos_menu == 2)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.ceiling_0s, x, y);
	else if (ray->ceiling_color == 0)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.ceiling_0, x, y);
	else if (ray->ceiling_color == 1 && ray->key.pos_menu == 2)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.ceiling_1s, x, y);
	else if (ray->ceiling_color == 1)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.ceiling_1, x, y);
	else if (ray->ceiling_color == 2 && ray->key.pos_menu == 2)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.ceiling_2s, x, y);
	else if (ray->ceiling_color == 2)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.ceiling_2, x, y);
	else if (ray->ceiling_color == 3 && ray->key.pos_menu == 2)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.ceiling_3s, x, y);
	else if (ray->ceiling_color == 3)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win,
			ray->img_menu.ceiling_3, x, y);
	ceiling_color_bis(ray, x, y);
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

int	get_color(int color, t_ray *ray, char c)
{
	if (color == DEFAULT)
	{
		if (c == 'c')
			return (create_rgb(ray->data->c.r, ray->data->c.g, ray->data->c.b));
		return (create_rgb(ray->data->f.r, ray->data->f.g, ray->data->f.b));
	}
	else if (color == RED)
		return (create_rgb(255, 0, 0));
	else if (color == YELLOW)
		return (create_rgb(255, 255, 0));
	else if (color == GREEN)
		return (create_rgb(0, 255, 0));
	else if (color == BLUE)
		return (create_rgb(0, 0, 255));
	else if (color == GREY)
		return (create_rgb(128, 128, 128));
	else if (color == BLACK)
		return (create_rgb(0, 0, 0));
	return (create_rgb(255, 255, 255));
}
