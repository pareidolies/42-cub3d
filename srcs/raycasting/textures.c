/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:26:55 by smostefa          #+#    #+#             */
/*   Updated: 2022/10/17 21:02:52 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	*xpm_to_img(t_ray *ray, char *path, t_mlx *mlx)
{
    void    *img;
    int    *addr;
    int     dust;
	int		*res;
	int		x;
	int		y;

    // printf("path : %s\n", path);
	img = mlx_xpm_file_to_image(mlx->ptr, path, &ray->xpm->width, &ray->xpm->height);
	if (!img)
    {
        printf("eRROR\n");
        //ERROR
    }
	addr = (int *)mlx_get_data_addr(img, &dust, &dust, &dust);
	res = malloc(sizeof(int) * ray->xpm->width * ray->xpm->height);
	if (!res)
	{
		//ERROR
	}
	y = 0;
	while (y < ray->xpm->height)
	{
		x = 0;
		while (x < ray->xpm->width)
		{
			res[y * ray->xpm->height + x] = addr[y * ray->xpm->height + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(mlx->ptr, img);
	return (res);
}

int get_textures(t_ray *ray)
{
    ray->xpm = malloc(sizeof(t_xpm));
	if (!ray->xpm)
	{
		//ERR
	}
    ray->textures = malloc(sizeof(int *) * 10);
    ray->textures[0] = xpm_to_img(ray, ray->data->no, ray->mlx);
	ray->textures[1] = xpm_to_img(ray, ray->data->so, ray->mlx);
	ray->textures[2] = xpm_to_img(ray, ray->data->we, ray->mlx);
	ray->textures[3] = xpm_to_img(ray, ray->data->ea, ray->mlx);
	ray->textures[9] = xpm_to_img(ray, "./textures/door.xpm", ray->mlx); //DOORS
    ray->textures[5] = NULL;
	
	return (0);
}
