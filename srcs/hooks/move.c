/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:37:26 by smostefa          #+#    #+#             */
/*   Updated: 2022/10/08 13:53:14 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    move(int keycode, t_ray *ray, t_mlx *mlx, t_data *data)
{
    if (keycode == MOVE_FORWARD)
	{
        // printf("x : %d\n", (int)(ray->pos.x + (ray->dir.x * MOVE_SPEED * 2)));
        // printf("y : %d\n", (int)ray->pos.y);
		if (ray->revert_map[(int)(ray->pos.x + (ray->dir.x * MOVE_SPEED * 2))][(int)ray->pos.y] != '1')
        {

			ray->pos.x += ray->dir.x * MOVE_SPEED;
            // printf("forward1\n");
        }
		if (ray->revert_map[(int)(ray->pos.x)][(int)(ray->pos.y + (ray->dir.y * MOVE_SPEED * 2))] != '1')
        {
			ray->pos.y += ray->dir.y * MOVE_SPEED;
            // printf("forward2\n");
        }
	}
	if (keycode == MOVE_BACKWARD)
	{
        // printf("backward\n");
		if (ray->revert_map[(int)(ray->pos.x - (ray->dir.x * MOVE_SPEED * 2))][(int)(ray->pos.y)] != '1')
			ray->pos.x -= ray->dir.x * MOVE_SPEED;
		if (ray->revert_map[(int)(ray->pos.x)][(int)(ray->pos.y - (ray->dir.y * MOVE_SPEED * 2))] != '1')
			ray->pos.y -= ray->dir.y * MOVE_SPEED;
	}
    if (keycode == MOVE_RIGHTWARD)
	{
        // printf("rightward\n");
		if (ray->revert_map[(int)(ray->pos.x + ray->dir.y * (MOVE_SPEED * 2))][(int)ray->pos.y] != '1')
			ray->pos.x += ray->dir.y * MOVE_SPEED;
		if (ray->revert_map[(int)ray->pos.x][(int)(ray->pos.y - ray->dir.x * (MOVE_SPEED * 2))] != '1')
			ray->pos.y -= ray->dir.x * MOVE_SPEED;
	}
	if (keycode == MOVE_LEFTWARD)
	{
        // printf("leftward\n");
		if (ray->revert_map[(int)(ray->pos.x - ray->dir.y * (MOVE_SPEED * 2))][(int)ray->pos.y] != '1')
			ray->pos.x -= ray->dir.y * MOVE_SPEED;
		if (ray->revert_map[(int)ray->pos.x][(int)(ray->pos.y + ray->dir.x * (MOVE_SPEED * 2))] != '1')
			ray->pos.y += ray->dir.x * MOVE_SPEED;
	}
	if (!ray->minimap)
		launch_raycasting(ray, data, mlx);
	 else
		launch_raycasting_with_map(ray, data, mlx);
}
