/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:37:30 by smostefa          #+#    #+#             */
/*   Updated: 2022/10/10 18:52:36 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    rotate(int keycode, t_ray *ray, t_mlx *mlx)
{
    double old_plane_x;
	double old_dir_x;

	old_plane_x = ray->plane.x;
	old_dir_x = ray->dir.x;
	if (keycode == ROTATE_RIGHT)
	{
        // printf("rotate right\n");
		ray->dir.x = ray->dir.x * cos(-ROT_SPEED / 2) - ray->dir.y * sin(-ROT_SPEED / 2);
		ray->dir.y = old_dir_x * sin(-ROT_SPEED / 2) + ray->dir.y * cos(-ROT_SPEED / 2);
		ray->plane.x = ray->plane.x * cos(-ROT_SPEED / 2) - ray->plane.y * sin(-ROT_SPEED / 2);
		ray->plane.y = old_plane_x * sin(-ROT_SPEED / 2) + ray->plane.y * cos(-ROT_SPEED / 2);
	}
	if (keycode == ROTATE_LEFT)
	{
        // printf("rotate left\n");
		ray->dir.x = ray->dir.x * cos(ROT_SPEED / 2) - ray->dir.y * sin(ROT_SPEED / 2);
		ray->dir.y = old_dir_x * sin(ROT_SPEED / 2) + ray->dir.y * cos(ROT_SPEED / 2);
		ray->plane.x = ray->plane.x * cos(ROT_SPEED / 2) - ray->plane.y * sin(ROT_SPEED / 2);
		ray->plane.y = old_plane_x * sin(ROT_SPEED / 2) + ray->plane.y * cos(ROT_SPEED / 2);
    }
	launch_raycasting(ray, mlx);
}

int	mouse_move(t_ray *ray)
{
	int i;
	int j;
	
	mlx_mouse_get_pos(ray->mlx->ptr, ray->mlx->win, &i, &j);
	if (i > 1)
		rotate(ROTATE_RIGHT, ray, ray->mlx);
	else if (i < 1)
		rotate(ROTATE_LEFT, ray, ray->mlx);
	mlx_mouse_move(ray->mlx->ptr, ray->mlx->win, 1, 1);
	return (1);
}
