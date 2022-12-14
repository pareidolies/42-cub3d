/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:13:54 by smostefa          #+#    #+#             */
/*   Updated: 2022/11/03 16:18:38 by smostefa         ###   ########.fr       */
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
	ray->is_door = 0;
	ray->map.x = (int)ray->pos.x;
	ray->map.y = (int)ray->pos.y;
}

/*//WITHOUT TEXTURES

void	former_print_results_on_screen(t_ray *ray, t_mlx *mlx)
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

void	fill_buffer(t_ray *ray)
{
	int	j;
	int	color;

	ray->xpm->tex.x = (int)(ray->wallx * \
		(double)ray->texture[ray->xpm->id].width);
	if ((ray->side == HORIZONTAL && ray->raydir.x > 0)
		|| (ray->side == VERTICAL && ray->raydir.y < 0))
		ray->xpm->tex.x = ray->texture[ray->xpm->id].width - \
			ray->xpm->tex.x - 1;
	ray->xpm->step = 1.0 * ray->texture[ray->xpm->id].height / ray->lineheight;
	ray->xpm->pos = (ray->drawstart - (double)HEIGHT / 2 + \
		(double)ray->lineheight / 2) * ray->xpm->step;
	j = ray->drawstart;
	while (j < ray->drawend)
	{
		ray->xpm->tex.y = (int)ray->xpm->pos
			& (ray->texture[ray->xpm->id].height - 1);
		ray->xpm->pos += ray->xpm->step;
		color = ray->texture[ray->xpm->id].\
			tab[ray->texture[ray->xpm->id].height * \
			ray->xpm->tex.y + ray->xpm->tex.x];
		ray->xpm->buffer[j][ray->i] = color;
		j++;
	}
}

/*//TUTORIAL LODEV

//texturing calculations
    int texNum = worldMap[mapX][mapY] - 1; 
	//1 subtracted from it so that texture 0 can be used!

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
// Cast the texture coordinate to integer, 
and mask with (texHeight - 1) in case of overflow
        int texY = (int)texPos & (texHeight - 1);
        texPos += step;
        Uint32 color = texture[texNum][texHeight * texY + texX];
        //make color darker for y-sides: R, G and B byte 
		each divided through two with a "shift" and an "and"
        if(side == 1) color = (color >> 1) & 8355711;
        buffer[y][x] = color;
}*/

void	print_results_on_screen(t_ray *ray)
{
	int	i;
	int	j;

	ray->mlx->addr = (int *)mlx_get_data_addr(ray->mlx->img, &ray->mlx->bpp,
			&ray->mlx->line_length, &ray->mlx->endian);
	i = 0;
	j = 0;
	ray->color_ceiling = get_color(ray->ceiling_color, ray, 'c');
	ray->color_floor = get_color(ray->floor_color, ray, 'f');
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			if (ray->xpm->buffer[j][i] > 0)
				ray->mlx->addr[j * WIDTH + i] = ray->xpm->buffer[j][i];
			else if (j < HEIGHT / 2)
				ray->mlx->addr[j * WIDTH + i] = ray->color_ceiling;
			else
				ray->mlx->addr[j * WIDTH + i] = ray->color_floor;
			i++;
		}
		j++;
	}
}

void	raycasting_loop(t_ray *ray)
{
	initialize_ray_i(ray);
	compute_deltadist(ray);
	compute_sidedist(ray);
	compute_perpwalldist(ray);
	ray->zbuffer[ray->i] = ray->perpwalldist;
	compute_line_attributes(ray);
	compute_wallx(ray);
	fill_buffer(ray);
	ray->i++;
}

int	launch_raycasting(t_ray *ray, t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	if (!mlx->img)
	{
		ft_printf(MLX_MSSG);
		exit_safe(ray);
	}
	clear_buffer(ray->xpm->buffer);
	close_opened_doors(ray, ray->data);
	if (ray->door)
		check_doors(ray);
	create_floor_and_ceiling(ray);
	ray->i = 0;
	while (ray->i < WIDTH)
		raycasting_loop(ray);
	add_sprites(ray);
	print_results_on_screen(ray);
	if (ray->minimap)
		minimap(ray);
	if (!ray->key.menu)
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	if (ray->key.menu)
		show_menu(ray);
	mlx_destroy_image(mlx->ptr, mlx->img);
	return (0);
}

/* (c. 185)
	//former_print_results_on_screen(ray, mlx);
*/
