/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:26:55 by smostefa          #+#    #+#             */
/*   Updated: 2022/10/13 16:06:48 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	*xpm_to_img(t_ray *ray, char *path, t_mlx *mlx, t_mlx *tmp)
// {
// 	int		*res;
// 	int		x;
// 	int		y;

// 	tmp->img = mlx_xpm_file_to_image(mlx->ptr, path,
// 			&ray->xpm->width, &ray->xpm->height);
// 	if (!tmp->img)
//     {
//         //ERROR
//     }
// 	tmp->addr = (int *)mlx_get_data_addr(tmp->img, &tmp->bpp,
// 			&tmp->line_length, &tmp->endian);
// 	res = malloc(sizeof(int) * ray->xpm->width * ray->xpm->height);
// 	if (!res)
// 	{
// 		//ERROR
// 	}
// 	y = 0;
// 	while (y < ray->xpm->height)
// 	{
// 		x = 0;
// 		while (x < ray->xpm->width)
// 		{
// 			res[y * ray->xpm->height + x] = tmp->addr[y * ray->xpm->height + x];
// 			x++;
// 		}
// 		y++;
// 	}
// 	mlx_destroy_image(mlx->ptr, tmp->img);
// 	return (res);
// }

// int get_textures(t_ray *ray)
// {
//     t_mlx   tmp;

//     ray->textures[0] = xpm_to_img(ray, ray->data.no, ray->mlx, &tmp);
// 	ray->textures[1] = xpm_to_img(ray, ray->data.so, ray->mlx, &tmp);
// 	ray->textures[2] = xpm_to_img(ray, ray->data.we, ray->mlx, &tmp);
// 	ray->textures[3] = xpm_to_img(ray, ray->data.ea, ray->mlx, &tmp);
//     ray->textures[4] = NULL;
// 	ray->xpm = malloc(sizeof(t_xpm));
// 	if (!ray->xpm)
// 	{
// 		//ERR
// 	}
// 	return (0);
// }
