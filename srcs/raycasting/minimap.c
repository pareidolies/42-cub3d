/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:34:39 by jdubilla          #+#    #+#             */
/*   Updated: 2022/10/13 15:53:55 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	len_square(t_data *data)
{
	int	res;

	res = 10;
	while ((res * data->len) > WIDTH / 4 || (res * data->height) > HEIGHT / 4)
		res--;
	return (res);
}

static void	square(t_ray *ray, int x, int y, int color)
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

static void	get_pos_player(t_ray *ray, int pos_x, int pos_y)
{
	if (ray->revert_map[pos_x][pos_y] == '1')
	{
		pos_x = ray->pos_map.x;
		pos_y = ray->pos_map.y;
	}
	else
	{
		ray->pos_map.x = pos_x;
		ray->pos_map.y = pos_y;
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
	pos_x = (int)(ray->pos.x + (ray->dir.x * MOVE_SPEED * 2));
	pos_y = (int)ray->pos.y;
	get_pos_player(ray, pos_x, pos_y);
	while (j < sq - 1)
	{
		ray->mlx->addr[((j + (pos_y * sq) + 20) * WIDTH)
			+ (i + 20 + (pos_x * sq))] = create_rgb(255, 255, 0);
		i++;
		if (i == sq - 1)
		{
			i = 1;
			j++;
		}
	}
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
		if (ray->data->map[i][j] == '1')
			square(ray, (j * sq) + 20, (i * sq) + 20,
				create_rgb(128, 128, 128));
		else
			square(ray, (j * sq) + 20, (i * sq) + 20, create_rgb(0, 0, 255));
		j++;
		if (j == ray->data->len)
		{
			j = 0;
			i++;
		}
	}
	pos_player(ray, sq);
}
