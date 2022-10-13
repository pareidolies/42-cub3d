/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:36:08 by smostefa          #+#    #+#             */
/*   Updated: 2022/10/13 16:05:25 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	initialize_ray_i(t_ray *ray)
{
	ray->hit = EMPTY;
	ray->perpwalldist = 0;
	ray->camerax = 2 * ray->i / (double)WIDTH - 1;
	ray->raydir.x = ray->dir.x + ray->plane.x * ray->camerax;
	ray->raydir.y = ray->dir.y + ray->plane.y * ray->camerax;
	ray->map.x = (int)ray->pos.x;
	ray->map.y = (int)ray->pos.y;
}

/*void	former_print_results_on_screen(t_ray *ray, t_mlx *mlx)
{
	int		j;
	t_rgb	c;
	t_rgb	f;

	mlx->addr = (int *)mlx_get_data_addr(mlx->img, &mlx->bpp,
			&mlx->line_length, &mlx->endian);
	j = 0;
	c = ray->data->c;
	f = ray->data->f;
	while (j < HEIGHT)
	{
		if (j < ray->drawstart)
			mlx->addr[j * WIDTH + ray->i] = create_rgb(c.r, c.g, c.b);
		else if (j > ray->drawend)
			mlx->addr[j * WIDTH + ray->i] = create_rgb(f.r, f.g, f.b);
		else
		{
			if (ray->side == HORIZONTAL)
				mlx->addr[j * WIDTH + ray->i] = create_rgb(0, 0, 255);
			else
				mlx->addr[j * WIDTH + ray->i] = create_rgb(0, 0, 255) / 2;
		}
		j++;
	}
}*/

void	compute_wallx(t_ray *ray)
{
	if (ray->side == VERTICAL) //HORI
	{
		ray->xpm->id = 0;
		if (ray->dir.x > 0)
			ray->xpm->id = 1;
		ray->wallx = ray->pos.y + ray->perpwalldist * ray->raydir.y;
	}
	else
	{
		ray->xpm->id = 2;
		if (ray->dir.y < 0)
			ray->xpm->id = 3;
		ray->wallx = ray->pos.x + ray->perpwalldist * ray->raydir.x;
	}
	ray->wallx -= floor(ray->wallx);
}

void	fill_buffer(t_ray *ray)
{
	int	j;
	int	color;

	ray->xpm->tex.x = (int)(ray->wallx * ray->xpm->width);
	if ((ray->side == VERTICAL && ray->raydir.x > 0)
		|| (ray->side == HORIZONTAL && ray->raydir.y < 0))
		ray->xpm->tex.x = ray->xpm->width - ray->xpm->tex.x - 1;
	ray->xpm->step = 1.0 * ray->xpm->height / ray->lineheight; //
	ray->xpm->pos = (ray->drawstart - HEIGHT / 2 + ray->lineheight / 2) * ray->xpm->step;
	j = ray->drawstart;
	while (j < ray->drawend)
	{
		ray->xpm->tex.y = (int)ray->xpm->pos & (ray->xpm->height - 1);
		ray->xpm->pos += ray->xpm->step;
		color = ray->textures[ray->xpm->id][ray->xpm->height * ray->xpm->tex.y + ray->xpm->tex.x];
		if (ray->side == HORIZONTAL) // VERT
			color = (color >> 1) & 8355711;
		if (color > 0)
			ray->xpm->buffer[j][ray->i] = color;
		j++;
	}
}

//TUTORIAL LODEV

/*//texturing calculations
    int texNum = worldMap[mapX][mapY] - 1; //1 subtracted from it so that texture 0 can be used!

//calculate value of wallX
	double wallX; //where exactly the wall was hit
 	if (side == 0) wallX = posY + perpWallDist * rayDirY;
 	else           wallX = posX + perpWallDist * rayDirX;
 	wallX -= floor((wallX));

//x coordinate on the texture
 	int texX = int(wallX * double(texWidth));
 	if(side == 0 && rayDirX > 0) texX = texWidth - texX - 1;
 	if(side == 1 && rayDirY < 0) texX = texWidth - texX - 1;


// How much to increase the texture coordinate per screen pixel
double step = 1.0 * texHeight / lineHeight;
// Starting texture coordinate
double texPos = (drawStart - h / 2 + lineHeight / 2) * step;
for(int y = drawStart; y<drawEnd; y++)
{
// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
        int texY = (int)texPos & (texHeight - 1);
        texPos += step;
        Uint32 color = texture[texNum][texHeight * texY + texX];
        //make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
        if(side == 1) color = (color >> 1) & 8355711;
        buffer[y][x] = color;
}*/

void	print_results_on_screen(t_ray *ray)
{
	int		i;
	int		j;
	t_rgb	c;
	t_rgb	f;

	ray->mlx->addr = (int *)mlx_get_data_addr(ray->mlx->img, &ray->mlx->bpp,
			&ray->mlx->line_length, &ray->mlx->endian);
	i = 0;
	j = 0;
	c = ray->data->c;
	f = ray->data->f;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			if (ray->xpm->buffer[j][i] > 0)
				ray->mlx->addr[j * WIDTH + i] = ray->xpm->buffer[j][i];
			else if (j < HEIGHT / 2)
				ray->mlx->addr[j * WIDTH + i] = create_rgb(f.r, f.g, f.b);
			else
				ray->mlx->addr[j * WIDTH + i] = create_rgb(c.r, c.g, c.b);
			i++;
		}
		j++;
	}
}

int	launch_raycasting(t_ray *ray, t_mlx *mlx)
{
	// for (int i = 0; i < 10000000; i++)
	// 	printf("%d\n", i);
	mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	if (!mlx->img)
	{
		//handling error && free
		return (1);
	}
	clear_buffer(ray->xpm->buffer);
	ray->i = 0;
	while (ray->i < WIDTH)
	{
		initialize_ray_i(ray);
		compute_deltadist(ray);
		compute_sidedist(ray);
		compute_perpwalldist(ray);
		compute_line_attributes(ray);
		compute_wallx(ray); //NEW
		//print_results_on_screen(ray, mlx);
		fill_buffer(ray); //NEW
		ray->i++;
	}
	print_results_on_screen(ray); //NEW
	if (ray->minimap)
		minimap(ray);
	if (!ray->key.menu)
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	if (ray->key.menu)
		show_menu(ray);
	// mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	mlx_destroy_image(mlx->ptr, mlx->img);
	return (0);
}
