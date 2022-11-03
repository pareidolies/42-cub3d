/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:34:39 by jdubilla          #+#    #+#             */
/*   Updated: 2022/11/03 20:50:58 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	square_minimap(t_ray *ray, int x, int y, int color)
{
	int	i;
	int	j;
	int	sq;

	i = 0;
	j = 0;
	sq = len_square(ray->data);
	while (j < sq)
	{
		ray->mlx->addr[((y + j) * WIDTH) + (x + i)] = color;
		i++;
		if (i == sq)
		{
			i = 0;
			j++;
		}
	}
}

static void	get_pos_player(t_ray *ray, int *pos_x, int *pos_y)
{
	if (ray->revert_map[*pos_x][*pos_y] == '1')
	{
		*pos_x = ray->pos_map.x;
		ray->pos_map.y = *pos_y;
	}
	else
	{
		ray->pos_map.x = *pos_x;
		ray->pos_map.y = *pos_y;
	}
}

static void	pos_player(t_ray *ray, int sq)
{
	int	i;
	int	j;
	int	pos_x;
	int	pos_y;

	i = 1;
	j = 1;
	pos_x = (int)(ray->pos.x + (ray->dir.x * ray->move_speed * 2));
	pos_y = (int)ray->pos.y;
	get_pos_player(ray, &pos_x, &pos_y);
	while (j < sq - 1)
	{
		ray->mlx->addr[((j + (pos_y * sq) + 20) * WIDTH)
			+ (i + 20 + (pos_x * sq))] = create_rgb(210, 105, 30);
		i++;
		if (i == sq - 1)
		{
			i = 1;
			j++;
		}
	}
}

static void	create_minimap(t_ray *ray, int sq, int i, int j)
{
	if (ray->data->map[i][j] == '1')
		square_minimap(ray, (j * sq) + 20, (i * sq) + 20,
			create_rgb(255, 228, 196));
	else if (ray->data->map[i][j] == '2')
		square_minimap(ray, (j * sq) + 20, (i * sq) + 20,
			create_rgb(220, 20, 60));
	else
		square_minimap(ray, (j * sq) + 20, (i * sq) + 20,
			create_rgb(244, 164, 96));
}

void	minimap(t_ray *ray)
{
	int	i;
	int	j;
	int	sq;

	i = 0;
	j = 0;
	sq = len_square(ray->data);
	if (sq < 4)
		return ;
	while (i < ray->data->height)
	{
		create_minimap(ray, sq, i, j);
		j++;
		if (j == ray->data->len)
		{
			j = 0;
			i++;
		}
	}
	pos_player(ray, sq);
}
