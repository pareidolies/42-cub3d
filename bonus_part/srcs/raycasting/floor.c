/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:01:02 by smostefa          #+#    #+#             */
/*   Updated: 2022/11/03 16:07:05 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*TUTO Lodev

//FLOOR CASTING
// rayDir for leftmost ray (x = 0) and rightmost ray (x = w)
// Current y position compared to the center of the screen (the horizon
// Vertical position of the camera.
// Horizontal distance from the camera to the floor for the current row.
// 0.5 is the z position exactly in the middle between floor and ceiling.
// calculate the real world step vector we have to add for each x
	(parallel to camera plane)
// adding step by step avoids multiplications with a weight in the inner loop
// real world coordinates of the leftmost column.
	This will be updated as we step to the right.
// the cell coord is simply got from the integer parts of floorX and floorY
// get the texture coordinate from the fractional part
// choose texture and draw the pixel
// floor
//ceiling (symmetrical, at screenHeight - y - 1 instead of y)

*/

void	create_floor_and_ceiling2(t_ray *ray, int x, int y)
{
	t_point	t;
	int		color;

	ray->cell.x = (int)(ray->floor.x);
	ray->cell.y = (int)(ray->floor.y);
	t.x = (int)(ray->texture[7].width * \
		(ray->floor.x - ray->cell.x)) & (ray->texture[7].width - 1); //question
	t.y = (int)(ray->texture[7].height * \
		(ray->floor.y - ray->cell.y)) & (ray->texture[7].height - 1); //question
	ray->floor.x += ray->floorstep.x;
	ray->floor.y += ray->floorstep.y;
	color = ray->texture[7].tab[ray->texture[7].width * t.y + t.x];
	color = (color >> 1) & 8355711; // make a bit darker // question
	ray->xpm->buffer[y][x] = color;
	color = get_color(ray->ceiling_color, ray, 'c');
	ray->xpm->buffer[HEIGHT - y - 1][x] = color;
}

void	create_floor_and_ceiling3(t_ray *ray, int y)
{
	int		p;
	double	posz;

	ray->raydir0.x = ray->dir.x - ray->plane.x;
	ray->raydir0.y = ray->dir.y - ray->plane.y;
	ray->raydir1.x = ray->dir.x + ray->plane.x;
	ray->raydir1.y = ray->dir.y + ray->plane.y;
	p = y - HEIGHT / 2;
	posz = 0.5 * HEIGHT;
	ray->rowdistance = posz / p;
}

void	create_floor_and_ceiling(t_ray *ray)
{
	int		x;
	int		y;

	y = 0;
	while (y < HEIGHT)
	{
		create_floor_and_ceiling3(ray, y);
		ray->floorstep.x = ray->rowdistance * \
			(ray->raydir1.x - ray->raydir0.x) / WIDTH;
		ray->floorstep.y = ray->rowdistance * \
			(ray->raydir1.y - ray->raydir0.y) / WIDTH;
		ray->floor.x = ray->pos.x + ray->rowdistance * ray->raydir0.x;
		ray->floor.y = ray->pos.y + ray->rowdistance * ray->raydir0.y;
		x = 0;
		while (x < WIDTH)
		{
			create_floor_and_ceiling2(ray, x, y);
			x++;
		}
		y++;
	}
}
