/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:14:32 by smostefa          #+#    #+#             */
/*   Updated: 2022/10/31 17:14:34 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture	xpm_to_img(char *path, t_mlx *mlx)
{
    void    *img;
    int    *addr;
    int     dust;
	t_texture		res;
	int		x;
	int		y;

    printf("path : %s\n", path);
	img = mlx_xpm_file_to_image(mlx->ptr, path, &res.width, &res.height);
	if (!img)
    {
        printf("eRROR\n");
        //ERROR
    }
	addr = (int *)mlx_get_data_addr(img, &dust, &dust, &dust);
	printf("test2");
	res.tab = malloc(sizeof(int) * res.width * res.height);
	if (!res.tab)
	{
		//ERROR
	}
	y = 0;
	while (y < res.height)
	{
		x = 0;
		while (x < res.width)
		{
			res.tab[y * res.height + x] = addr[y * res.height + x];
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
    ray->texture = malloc(sizeof(t_texture) * 10); //A MODIFIER
    ray->texture[0] = xpm_to_img(ray->data->no, ray->mlx);
	ray->texture[1] = xpm_to_img(ray->data->so, ray->mlx);
	ray->texture[2] = xpm_to_img(ray->data->we, ray->mlx);
	ray->texture[3] = xpm_to_img(ray->data->ea, ray->mlx);
	ray->texture[4] = xpm_to_img("./textures/television.xpm", ray->mlx); //DOORS
	ray->texture[5] = xpm_to_img("./textures/barrel.xpm", ray->mlx); //SPRITES
	printf("test\n");
	ray->texture[6] = xpm_to_img("./textures/barrel.xpm", ray->mlx); //SPRITES
	ray->texture[7] = xpm_to_img("./textures/floor.xpm", ray->mlx); //FLOOR
    //ray->texture[8] = NULL;
	return (0);
}
