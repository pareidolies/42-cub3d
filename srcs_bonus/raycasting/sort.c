/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:05:41 by smostefa          #+#    #+#             */
/*   Updated: 2022/11/03 15:12:27 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	malloc_sprites(t_ray *ray, t_sprite *sprite)
{
	sprite->tab = malloc(sizeof(t_coordinates) * (sprite->nbr + 1));
	if (!sprite->tab)
	{
		ft_printf(MALLOC_MSSG);
		exit_safe(ray);
	}
	sprite->order = malloc(sizeof(int) * (sprite->nbr + 1));
	if (!sprite->order)
	{
		free(sprite->tab);
		ft_printf(MALLOC_MSSG);
		exit_safe(ray);
	}
	sprite->distance = malloc(sizeof(double) * (sprite->nbr + 1));
	if (!sprite->distance)
	{
		free(sprite->tab);
		free(sprite->order);
		ft_printf(MALLOC_MSSG);
		exit_safe(ray);
	}
}

void	get_sprites_nbr(t_ray *ray, t_sprite *sprite)
{
	int	i;
	int	j;

	i = 0;
	sprite->nbr = 0;
	while (i < ray->data->len)
	{
		j = 0;
		while (j < ray->data->height)
		{
			if (ray->revert_map[i][j] == '3' || ray->revert_map[i][j] == '4')
				sprite->nbr++;
			j++;
		}
		i++;
	}
	malloc_sprites(ray, sprite);
}

void	get_sprites_coordinates(t_ray *ray, t_sprite *sprite)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < ray->data->len)
	{
		j = 0;
		while (j < ray->data->height)
		{
			if (ray->revert_map[i][j] == '3' || ray->revert_map[i][j] == '4')
			{
				sprite->tab[k].x = (double)i + 0.5;
				sprite->tab[k].y = (double)j + 0.5;
				if (ray->revert_map[i][j] == '3')
					sprite->tab[k].texture = 5;
				else
					sprite->tab[k].texture = 6;
				k++;
			}
			j++;
		}
		i++;
	}
}

void	sort_sprites2(t_sprite *sprite, int j)
{
	double	tmp;

	tmp = sprite->distance[j];
	sprite->distance[j] = sprite->distance[j + 1];
	sprite->distance[j + 1] = tmp;
	tmp = sprite->order[j];
	sprite->order[j] = sprite->order[j + 1];
	sprite->order[j + 1] = (int)tmp;
}

void	sort_sprites(t_ray *ray, t_sprite *sprite)
{
	int		i;
	int		j;

	i = 0;
	while (i < sprite->nbr)
	{
		sprite->order[i] = i;
		sprite->distance[i] = ((ray->pos.x - sprite->tab[i].x) * \
			(ray->pos.x - sprite->tab[i].x) + (ray->pos.y - sprite->tab[i].y) * \
			(ray->pos.y - sprite->tab[i].y));
		i++;
	}
	i = 0;
	while (i < sprite->nbr)
	{
		j = 0;
		while (j < sprite->nbr - 1)
		{
			if (sprite->distance[j] < sprite->distance[j + 1])
				sort_sprites2(sprite, j);
			j++;
		}
		i++;
	}
}
