/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:36:02 by smostefa          #+#    #+#             */
/*   Updated: 2022/10/09 18:36:29 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int initialize_mlx(t_mlx *mlx)
{
    // printf("salut");
    mlx->ptr = mlx_init();
	if (!mlx->ptr)
    {
        printf("Mlx init error.\n");
		return (1);
    }
	mlx->win = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, TITLE);
	if (!mlx->win)
	{
		free(mlx->ptr);
		return (1);
	}
    return (0);
}

void	initialize_all_values(t_ray *ray)
{
	ray->dir.x = 0;
	ray->dir.y = 0;
	ray->plane.x = 0;
	ray->plane.y = 0;
	ray->perpwalldist = 0;
	ray->lineheight = 0;
    ray->drawstart = 0;
    ray->drawend = 0;
	ray->minimap = false;



	// TEST
	ray->img_height = 0;
	ray->img_height = 0;
	ray->img = mlx_xpm_file_to_image(ray->mlx->ptr, "textures/map.xpm", &ray->img_width, &ray->img_height);
	if (!ray->img)
		printf("Error img\n");
}
