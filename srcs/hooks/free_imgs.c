/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:05:58 by jdubilla          #+#    #+#             */
/*   Updated: 2022/10/16 17:08:40 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	free_imgs_b(t_ray *ray)
{
	if (ray->img_menu.rot_speed_1)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.rot_speed_1);
	if (ray->img_menu.rot_speed_2)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.rot_speed_2);
	if (ray->img_menu.rot_speed_3)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.rot_speed_3);
	if (ray->img_menu.rot_speed_4)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.rot_speed_4);
	if (ray->img_menu.rot_speed_1s)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.rot_speed_1s);
	if (ray->img_menu.rot_speed_2s)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.rot_speed_2s);
	if (ray->img_menu.rot_speed_3s)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.rot_speed_3s);
	if (ray->img_menu.rot_speed_4s)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.rot_speed_4s);
	if (ray->img_menu.move_speed_1)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.move_speed_1);
	if (ray->img_menu.move_speed_1s)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.move_speed_1s);
	if (ray->img_menu.move_speed_2)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.move_speed_2);
	if (ray->img_menu.move_speed_2s)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.move_speed_2s);
}

static void	free_imgs_c(t_ray *ray)
{
	if (ray->img_menu.move_speed_3)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.move_speed_3);
	if (ray->img_menu.move_speed_3s)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.move_speed_3s);
	if (ray->img_menu.move_speed_4)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.move_speed_4);
	if (ray->img_menu.move_speed_4s)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.move_speed_4s);
	if (ray->img_menu.ceiling_0)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.ceiling_0);
	if (ray->img_menu.ceiling_0s)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.ceiling_0s);
	if (ray->img_menu.ceiling_1)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.ceiling_1);
	if (ray->img_menu.floor_6)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.floor_6);
	if (ray->img_menu.floor_6s)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.floor_6s);
	if (ray->img_menu.floor_7)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.floor_7);
	if (ray->img_menu.floor_7s)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.floor_7s);
	if (ray->img_menu.back_game)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.back_game);
}

static void	free_imgs_d(t_ray *ray)
{
	if (ray->img_menu.back_game_s)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.back_game_s);
	if (ray->img_menu.ceiling_1s)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.ceiling_1s);
	if (ray->img_menu.ceiling_2)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.ceiling_2);
	if (ray->img_menu.ceiling_2s)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.ceiling_2s);
	if (ray->img_menu.ceiling_3)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.ceiling_3);
	if (ray->img_menu.ceiling_3s)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.ceiling_3s);
	if (ray->img_menu.ceiling_4)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.ceiling_4);
	if (ray->img_menu.ceiling_4s)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.ceiling_4s);
	if (ray->img_menu.ceiling_5)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.ceiling_5);
	if (ray->img_menu.ceiling_5s)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.ceiling_5s);
	if (ray->img_menu.ceiling_6)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.ceiling_6);
	if (ray->img_menu.ceiling_6s)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.ceiling_6s);
}

static void	free_imgs_e(t_ray *ray)
{
	if (ray->img_menu.ceiling_7)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.ceiling_7);
	if (ray->img_menu.ceiling_7s)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.ceiling_7s);
	if (ray->img_menu.floor_0)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.floor_0);
	if (ray->img_menu.floor_0s)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.floor_0s);
	if (ray->img_menu.floor_1)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.floor_1);
	if (ray->img_menu.floor_1s)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.floor_1s);
	if (ray->img_menu.floor_2)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.floor_2);
	if (ray->img_menu.floor_2s)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.floor_2s);
	if (ray->img_menu.floor_3)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.floor_3);
	if (ray->img_menu.floor_3s)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.floor_3s);
	if (ray->img_menu.floor_4)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.floor_4);
	if (ray->img_menu.floor_4s)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.floor_4s);
}

void	free_all_imgs(t_ray *ray)
{
	free_imgs_b(ray);
	free_imgs_c(ray);
	free_imgs_d(ray);
	free_imgs_e(ray);
	if (ray->img_menu.floor_5)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.floor_5);
	if (ray->img_menu.floor_5s)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.floor_5s);
	if (ray->img_menu.exit_game_s)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.exit_game_s);
	if (ray->img_menu.exit_game)
		mlx_destroy_image(ray->mlx->ptr, ray->img_menu.exit_game);
}
