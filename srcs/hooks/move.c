/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:37:26 by smostefa          #+#    #+#             */
/*   Updated: 2022/10/12 19:13:05 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// void	move(int keycode, t_ray *ray, t_mlx *mlx)
// {
// 	if (keycode == MOVE_FORWARD)
// 	{
// 		if (ray->revert_map[(int)(ray->pos.x + (ray->dir.x * MOVE_SPEED * 2))][(int)ray->pos.y] != '1')
// 			ray->pos.x += ray->dir.x * MOVE_SPEED;
// 		if (ray->revert_map[(int)(ray->pos.x)][(int)(ray->pos.y + (ray->dir.y * MOVE_SPEED * 2))] != '1')
// 			ray->pos.y += ray->dir.y * MOVE_SPEED;
// 	}
// 	if (keycode == MOVE_BACKWARD)
// 	{
// 		if (ray->revert_map[(int)(ray->pos.x - (ray->dir.x * MOVE_SPEED * 2))][(int)(ray->pos.y)] != '1')
// 			ray->pos.x -= ray->dir.x * MOVE_SPEED;
// 		if (ray->revert_map[(int)(ray->pos.x)][(int)(ray->pos.y - (ray->dir.y * MOVE_SPEED * 2))] != '1')
// 			ray->pos.y -= ray->dir.y * MOVE_SPEED;
// 	}
// 	if (keycode == MOVE_RIGHTWARD)
// 	{
// 		if (ray->revert_map[(int)(ray->pos.x - ray->dir.y * (MOVE_SPEED * 2))][(int)ray->pos.y] != '1')
// 			ray->pos.x -= ray->dir.y * MOVE_SPEED;
// 		if (ray->revert_map[(int)ray->pos.x][(int)(ray->pos.y + ray->dir.x * (MOVE_SPEED * 2))] != '1')
// 			ray->pos.y += ray->dir.x * MOVE_SPEED;
// 	}
// 	if (keycode == MOVE_LEFTWARD)
// 	{
// 		if (ray->revert_map[(int)(ray->pos.x + ray->dir.y * (MOVE_SPEED * 2))][(int)ray->pos.y] != '1')
// 			ray->pos.x += ray->dir.y * MOVE_SPEED;
// 		if (ray->revert_map[(int)ray->pos.x][(int)(ray->pos.y - ray->dir.x * (MOVE_SPEED * 2))] != '1')
// 			ray->pos.y -= ray->dir.x * MOVE_SPEED;
// 	}
// 	launch_raycasting(ray, mlx);
// }



int	move(t_ray *ray)
{
	bool	reload;

	reload = false;
	if (ray->key.w)
	{
		if (ray->revert_map[(int)(ray->pos.x + (ray->dir.x * MOVE_SPEED * 2))][(int)ray->pos.y] != '1')
			ray->pos.x += ray->dir.x * MOVE_SPEED;
		if (ray->revert_map[(int)(ray->pos.x)][(int)(ray->pos.y + (ray->dir.y * MOVE_SPEED * 2))] != '1')
			ray->pos.y += ray->dir.y * MOVE_SPEED;
		reload = true;
	}
	if (ray->key.s)
	{
		if (ray->revert_map[(int)(ray->pos.x - (ray->dir.x * MOVE_SPEED * 2))][(int)(ray->pos.y)] != '1')
			ray->pos.x -= ray->dir.x * MOVE_SPEED;
		if (ray->revert_map[(int)(ray->pos.x)][(int)(ray->pos.y - (ray->dir.y * MOVE_SPEED * 2))] != '1')
			ray->pos.y -= ray->dir.y * MOVE_SPEED;
		reload = true;
	}
	if (ray->key.d)
	{
		if (ray->revert_map[(int)(ray->pos.x - ray->dir.y * (MOVE_SPEED * 2))][(int)ray->pos.y] != '1')
			ray->pos.x -= ray->dir.y * MOVE_SPEED;
		if (ray->revert_map[(int)ray->pos.x][(int)(ray->pos.y + ray->dir.x * (MOVE_SPEED * 2))] != '1')
			ray->pos.y += ray->dir.x * MOVE_SPEED;
		reload = true;
	}
	if (ray->key.a)
	{
		if (ray->revert_map[(int)(ray->pos.x + ray->dir.y * (MOVE_SPEED * 2))][(int)ray->pos.y] != '1')
			ray->pos.x += ray->dir.y * MOVE_SPEED;
		if (ray->revert_map[(int)ray->pos.x][(int)(ray->pos.y - ray->dir.x * (MOVE_SPEED * 2))] != '1')
			ray->pos.y -= ray->dir.x * MOVE_SPEED;
		reload = true;
	}
	double	old_plane_x;
	double	old_dir_x;

	old_plane_x = ray->plane.x;
	old_dir_x = ray->dir.x;
	if (ray->key.rl)
	{
		ray->dir.x = ray->dir.x * cos(-ROT_SPEED / 2) - ray->dir.y * sin(-ROT_SPEED / 2);
		ray->dir.y = old_dir_x * sin(-ROT_SPEED / 2) + ray->dir.y * cos(-ROT_SPEED / 2);
		ray->plane.x = ray->plane.x * cos(-ROT_SPEED / 2) - ray->plane.y * sin(-ROT_SPEED / 2);
		ray->plane.y = old_plane_x * sin(-ROT_SPEED / 2) + ray->plane.y * cos(-ROT_SPEED / 2);
		reload = true;
	}
	if (ray->key.rr)
	{
		ray->dir.x = ray->dir.x * cos(ROT_SPEED / 2) - ray->dir.y * sin(ROT_SPEED / 2);
		ray->dir.y = old_dir_x * sin(ROT_SPEED / 2) + ray->dir.y * cos(ROT_SPEED / 2);
		ray->plane.x = ray->plane.x * cos(ROT_SPEED / 2) - ray->plane.y * sin(ROT_SPEED / 2);
		ray->plane.y = old_plane_x * sin(ROT_SPEED / 2) + ray->plane.y * cos(ROT_SPEED / 2);
		reload = true;
	}
	if (reload)
		launch_raycasting(ray, ray->mlx);
	return (0);
}