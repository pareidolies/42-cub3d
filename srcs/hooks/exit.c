/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:27:03 by jdubilla          #+#    #+#             */
/*   Updated: 2022/10/15 20:19:23 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_textures(t_ray *ray)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		free(ray->texture[i].tab);
		i++;
	}
	
}

void	free_all(t_ray * ray)
{
	free_all_imgs(ray);
	free_list(ray->door);
	free_textures(ray);
	free_double_array_int(ray->xpm->buffer);
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

void	free_list(t_door *first)
{
	t_door	*current;
	t_door	*tmp;

	current = first;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
}

void	free_double_array_int(int **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
