/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:14:32 by smostefa          #+#    #+#             */
/*   Updated: 2022/11/03 15:50:47 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	xpm_to_img2(t_texture *res, t_mlx *mlx, void *img, t_ray *ray)
{
	int	x;
	int	y;
	int	*addr;
	int	dust;

	addr = (int *)mlx_get_data_addr(img, &dust, &dust, &dust);
	res->tab = malloc(sizeof(int) * res->width * res->height);
	if (!res->tab)
	{
		ft_printf(MALLOC_MSSG);
		mlx_destroy_image(mlx->ptr, img);
		exit_safe(ray);
	}
	y = 0;
	while (y < res->height)
	{
		x = 0;
		while (x < res->width)
		{
			res->tab[y * res->height + x] = addr[y * res->height + x];
			x++;
		}
		y++;
	}
}

t_texture	xpm_to_img(t_ray *ray, char *path, t_mlx *mlx)
{
	void		*img;
	t_texture	res;

	img = mlx_xpm_file_to_image(mlx->ptr, path, &res.width, &res.height);
	if (!img)
	{
		ray->data->err = true;
		ft_printf(IMG_MSSG);
		exit_safe(ray);
	}
	xpm_to_img2(&res, mlx, img, ray);
	mlx_destroy_image(mlx->ptr, img);
	return (res);
}

int	get_textures(t_ray *ray)
{
	ray->xpm = malloc(sizeof(t_xpm));
	if (!ray->xpm)
	{
		ft_printf(MALLOC_MSSG);
		exit_safe(ray);
	}
	ray->texture[0] = xpm_to_img(ray, ray->data->no, ray->mlx);
	ray->texture[1] = xpm_to_img(ray, ray->data->so, ray->mlx);
	ray->texture[2] = xpm_to_img(ray, ray->data->we, ray->mlx);
	ray->texture[3] = xpm_to_img(ray, ray->data->ea, ray->mlx);
	ray->texture[4] = xpm_to_img(ray, ray->data->d, ray->mlx);
	ray->texture[5] = xpm_to_img(ray, "./textures/venus.xpm", ray->mlx);
	ray->texture[6] = xpm_to_img(ray, "./textures/statue1.xpm", ray->mlx);
	ray->texture[7] = xpm_to_img(ray, "./textures/floor.xpm", ray->mlx);
	return (0);
}
