/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:36:08 by smostefa          #+#    #+#             */
/*   Updated: 2022/10/09 17:25:17 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void initialize_ray_i(t_ray *ray, t_data *data)
{
	double	width = (double)ray->width;

	//printf("width : %f\n", width);
    ray->hit = EMPTY;
    ray->perpwalldist = 0;
    ray->camerax = 2 * ray->i / width - 1;
    ray->raydir.x = ray->dir.x + ray->plane.x * ray->camerax;
    ray->raydir.y = ray->dir.y + ray->plane.y * ray->camerax;
	ray->map.x = (int)ray->pos.x;
	ray->map.y = (int)ray->pos.y;
}

void    print_results_on_screen(t_ray *ray, t_mlx *mlx)
{
	int	j;
	
	mlx->addr = (int*)mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->line_length, &mlx->endian);
	//printf("drawstart : %d\n", ray->drawstart);
	//printf("drawend : %d\n", ray->drawend);
	j = 0;
	while(j < HEIGHT)
	{
		//mlx->addr[j * mlx->line_length / 4 + ray->i] = create_trgb(0,0,0,255);
		if (j < ray->drawstart)
		{
			mlx->addr[j * WIDTH + ray->i] = create_rgb(37,1,65);
		}
		else if (j > ray->drawend)
		{
			mlx->addr[j * WIDTH + ray->i] = create_rgb(66,5,114);
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

int    launch_raycasting(t_ray *ray, t_data *data, t_mlx *mlx)
{
	//printf("coucou\n");
	mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	if (!mlx->img)
	{
		//handling error && free
		return (1);
	}
	ray->i = 0;
	//printf("coucou10\n");
    while (ray->i < WIDTH)
    {
        initialize_ray_i(ray, data);
		// printf("coucou3\n");
		compute_deltadist(ray);
		//printf("coucou4\n");
    	compute_sidedist(ray, data);
		//printf("coucou5\n");
		//printf("sidedistx : %f\n", ray->sidedist.x);
		//printf("sidedisty : %f\n", ray->sidedist.y);
		//printf("deltadistx : %f\n", ray->deltadist.x);
		//printf("deltadisty : %f\n", ray->deltadist.x);
        compute_perpwalldist(ray, data);
		//printf("coucou6\n");
		//printf("perpwalldist : %f\n", ray->perpwalldist);
        compute_line_attributes(ray);
		//printf("coucou7\n");
        print_results_on_screen(ray, mlx);
		//printf("coucou8\n");
        ray->i++;
    }
	// 	minimap(ray->mlx, data, ray);
	//printf("coucou2\n");
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	mlx_destroy_image(mlx->ptr, mlx->img);
	return (0);
}

int    launch_raycasting_with_map(t_ray *ray, t_data *data, t_mlx *mlx)
{
	//printf("coucou\n");
	mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	if (!mlx->img)
	{
		//handling error && free
		return (1);
	}
	ray->i = 0;
	// printf("coucou10\n");
    while (ray->i < WIDTH)
    {
        initialize_ray_i(ray, data);
		//printf("coucou3\n");
		compute_deltadist(ray);
		//printf("coucou4\n");
    	compute_sidedist(ray, data);
		//printf("coucou5\n");
		//printf("sidedistx : %f\n", ray->sidedist.x);
		//printf("sidedisty : %f\n", ray->sidedist.y);
		//printf("deltadistx : %f\n", ray->deltadist.x);
		//printf("deltadisty : %f\n", ray->deltadist.x);
        compute_perpwalldist(ray, data);
		//printf("coucou6\n");
		//printf("perpwalldist : %f\n", ray->perpwalldist);
        compute_line_attributes(ray);
		//printf("coucou7\n");
        print_results_on_screen(ray, mlx);
		//printf("coucou8\n");
        ray->i++;
    }
	//printf("coucou2\n");
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	minimap(ray->mlx, data, ray);
	mlx_destroy_image(mlx->ptr, mlx->img);
	return (0);
}