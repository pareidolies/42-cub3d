/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:37:30 by smostefa          #+#    #+#             */
/*   Updated: 2022/10/12 17:14:04 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// void	rotate(int keycode, t_ray *ray, t_mlx *mlx)
// {
// 	double	old_plane_x;
// 	double	old_dir_x;

// 	old_plane_x = ray->plane.x;
// 	old_dir_x = ray->dir.x;
// 	if (keycode == ROTATE_LEFT)
// 	{
// 		ray->dir.x = ray->dir.x * cos(-ROT_SPEED / 2) - ray->dir.y * sin(-ROT_SPEED / 2);
// 		ray->dir.y = old_dir_x * sin(-ROT_SPEED / 2) + ray->dir.y * cos(-ROT_SPEED / 2);
// 		ray->plane.x = ray->plane.x * cos(-ROT_SPEED / 2) - ray->plane.y * sin(-ROT_SPEED / 2);
// 		ray->plane.y = old_plane_x * sin(-ROT_SPEED / 2) + ray->plane.y * cos(-ROT_SPEED / 2);
// 	}
// 	if (keycode == ROTATE_RIGHT)
// 	{
// 		ray->dir.x = ray->dir.x * cos(ROT_SPEED / 2) - ray->dir.y * sin(ROT_SPEED / 2);
// 		ray->dir.y = old_dir_x * sin(ROT_SPEED / 2) + ray->dir.y * cos(ROT_SPEED / 2);
// 		ray->plane.x = ray->plane.x * cos(ROT_SPEED / 2) - ray->plane.y * sin(ROT_SPEED / 2);
// 		ray->plane.y = old_plane_x * sin(ROT_SPEED / 2) + ray->plane.y * cos(ROT_SPEED / 2);
// 	}
// 	launch_raycasting(ray, mlx);
// }

// int	rotate(t_ray *ray)
// {
// 	double	old_plane_x;
// 	double	old_dir_x;

// 	old_plane_x = ray->plane.x;
// 	old_dir_x = ray->dir.x;
// 	if (ray->key.rl)
// 	{
// 		ray->dir.x = ray->dir.x * cos(-ROT_SPEED / 2) - ray->dir.y * sin(-ROT_SPEED / 2);
// 		ray->dir.y = old_dir_x * sin(-ROT_SPEED / 2) + ray->dir.y * cos(-ROT_SPEED / 2);
// 		ray->plane.x = ray->plane.x * cos(-ROT_SPEED / 2) - ray->plane.y * sin(-ROT_SPEED / 2);
// 		ray->plane.y = old_plane_x * sin(-ROT_SPEED / 2) + ray->plane.y * cos(-ROT_SPEED / 2);
// 	}
// 	if (ray->key.rr)
// 	{
// 		ray->dir.x = ray->dir.x * cos(ROT_SPEED / 2) - ray->dir.y * sin(ROT_SPEED / 2);
// 		ray->dir.y = old_dir_x * sin(ROT_SPEED / 2) + ray->dir.y * cos(ROT_SPEED / 2);
// 		ray->plane.x = ray->plane.x * cos(ROT_SPEED / 2) - ray->plane.y * sin(ROT_SPEED / 2);
// 		ray->plane.y = old_plane_x * sin(ROT_SPEED / 2) + ray->plane.y * cos(ROT_SPEED / 2);
// 	}
// 	launch_raycasting(ray, ray->mlx);
// 	return (0);
// }

// int	mouse_move(int x, int y, t_ray *ray)
// {
// 	int	i;
// 	int	j;

// 	i = 50;
// 	j = 50;
// 	(void)x;
// 	(void)y;
// 	mlx_mouse_get_pos(ray->mlx->ptr, ray->mlx->win, &i, &j);
// 	if (i > 50)
// 		rotate(ROTATE_RIGHT, ray, ray->mlx);
// 	else if (i < 50)
// 		rotate(ROTATE_LEFT, ray, ray->mlx);
// 	mlx_mouse_move(ray->mlx->ptr, ray->mlx->win, 50, 50);
// 	return (0);
// }
