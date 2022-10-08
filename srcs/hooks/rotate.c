/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:37:30 by smostefa          #+#    #+#             */
/*   Updated: 2022/10/08 13:53:18 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    rotate(int keycode, t_ray *ray, t_mlx *mlx, t_data *data)
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
	if (!ray->minimap)
		launch_raycasting(ray, data, mlx);
	 else
		launch_raycasting_with_map(ray, data, mlx);
}
