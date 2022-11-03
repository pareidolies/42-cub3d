/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:27:03 by jdubilla          #+#    #+#             */
/*   Updated: 2022/11/03 20:38:51 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_textures(t_ray *ray)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (ray->texture[i].tab)
			free(ray->texture[i].tab);
		i++;
	}
}

void	free_all(t_ray *ray)
{
	if (!ray->data->err)
		free_double_array_int(ray->xpm->buffer);
	free_textures(ray);
	free(ray->xpm);
	mlx_destroy_window(ray->mlx->ptr, ray->mlx->win);
	mlx_destroy_display(ray->mlx->ptr);
	free(ray->mlx->ptr);
	free_double_array(ray->revert_map);
	free_struct(ray->data);
}

void	exit_safe(t_ray *ray)
{
	free_all(ray);
	exit(0);
}

void	free_double_array_int(int **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
