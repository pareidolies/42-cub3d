/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:36:08 by smostefa          #+#    #+#             */
/*   Updated: 2022/10/10 18:39:20 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void initialize_ray_i(t_ray *ray)
{
    ray->hit = EMPTY;
    ray->perpwalldist = 0;
    ray->camerax = 2 * ray->i / (double)WIDTH - 1;
    ray->raydir.x = ray->dir.x + ray->plane.x * ray->camerax;
    ray->raydir.y = ray->dir.y + ray->plane.y * ray->camerax;
	ray->map.x = (int)ray->pos.x;
	ray->map.y = (int)ray->pos.y;
}

void    print_results_on_screen(t_ray *ray, t_mlx *mlx)
{
	int	j;
	
	mlx->addr = (int*)mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->line_length, &mlx->endian);
	j = 0;
	while(j < HEIGHT)
	{
		if (j < ray->drawstart)
		{
			mlx->addr[j * WIDTH + ray->i] = create_rgb(ray->data->c.r, ray->data->c.g, ray->data->c.b);
		}
		else if (j > ray->drawend)
		{
			mlx->addr[j * WIDTH + ray->i] = create_rgb(ray->data->f.r, ray->data->f.g, ray->data->f.b);
			//       (y * WIDTH) + x
		}
		else
		{
			if (ray->side == HORIZONTAL)
				mlx->addr[j * WIDTH + ray->i] = create_rgb(0,0,255);
			else
				mlx->addr[j * WIDTH + ray->i] = create_rgb(0,0,255) / 2;
		}
		j++;
	}
}

int    launch_raycasting(t_ray *ray, t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	if (!mlx->img)
	{
		//handling error && free
		return (1);
	}
	ray->i = 0;
    while (ray->i < WIDTH)
    {
        initialize_ray_i(ray);
		compute_deltadist(ray);
    	compute_sidedist(ray);
        compute_perpwalldist(ray);
        compute_line_attributes(ray);
        print_results_on_screen(ray, mlx);
        ray->i++;
    }
	if (ray->minimap)
		minimap(ray);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	mlx_destroy_image(mlx->ptr, mlx->img);
	return (0);
}