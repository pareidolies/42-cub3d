/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:14:39 by smostefa          #+#    #+#             */
/*   Updated: 2022/11/03 15:34:35 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	transpose_parsed_map_to_ray2(t_ray *ray, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->len)
	{
		j = 0;
		while (j < data->height)
		{
			ray->revert_map[i][j] = data->map[j][i];
			j++;
		}
		i++;
	}
}

void	transpose_parsed_map_to_ray(t_ray *ray, t_data *data)
{
	int	i;

	i = 0;
	ray->revert_map = malloc(sizeof(char *) * (data->len + 1));
	if (!ray->revert_map)
	{
		ft_printf(MALLOC_MSSG);
		exit_safe(ray);
	}
	while (i < data->len)
	{
		ray->revert_map[i] = malloc(sizeof(char) * data->height);
		if (!ray->revert_map[i])
		{
			ft_printf(MALLOC_MSSG);
			ray->revert_map[i] = NULL;
			free_double_array(ray->revert_map);
			exit_safe(ray);
		}
		i++;
	}
	ray->revert_map[i] = NULL;
	transpose_parsed_map_to_ray2(ray, data);
}

void	get_dir(t_ray *ray, t_data *data)
{
	if (data->player.dir == 'N')
		ray->dir.y = -1;
	else if (data->player.dir == 'S')
		ray->dir.y = 1;
	else if (data->player.dir == 'E')
		ray->dir.x = 1;
	else
		ray->dir.x = -1;
}

void	get_plane(t_ray *ray, t_data *data)
{
	if (data->player.dir == 'N')
		ray->plane.x = 0.66;
	else if (data->player.dir == 'S')
		ray->plane.x = -0.66;
	else if (data->player.dir == 'E')
		ray->plane.y = 0.66;
	else
		ray->plane.y = -0.66;
}

void	transpose_parsed_data_to_ray(t_ray *ray, t_data *data)
{
	ray->pos.x = (double)data->player.x + 0.5;
	ray->pos.y = (double)data->player.y + 0.5;
	get_dir(ray, data);
	get_plane(ray, data);
}
