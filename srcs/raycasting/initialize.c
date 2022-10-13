/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:36:02 by smostefa          #+#    #+#             */
/*   Updated: 2022/10/13 15:43:48 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int initialize_mlx(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
	{
		printf("Mlx init error.\n");
		return (1);
	}
	mlx->win = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, TITLE);
	if (!mlx->win)
	{
		free(mlx->ptr);
		return (1);
	}
	return (0);
}

void initialize_all_values(t_ray *ray)
{
	ray->dir.x = 0;
	ray->dir.y = 0;
	ray->plane.x = 0;
	ray->plane.y = 0;
	ray->perpwalldist = 0;
	ray->lineheight = 0;
	ray->drawstart = 0;
	ray->drawend = 0;
	ray->minimap = true;
	ray->pos_map.x = 0;
	ray->pos_map.y = 0;

	ray->key.w = false;
	ray->key.a = false;
	ray->key.s = false;
	ray->key.d = false;
	ray->key.rr = false;
	ray->key.rl = false;
	ray->key.mouse_l = false;
	ray->key.mouse_r = false;
	ray->key.menu = false;
}

int initialize_buffer(t_ray *ray)
{
	printf("initialize\n");
	int i;

	ray->xpm->buffer = malloc(sizeof(int *) * (HEIGHT + 1));
	if (!ray->xpm->buffer)
	{
		printf("ERROR\n");
	}
	i = 0;
	while (i < HEIGHT)
	{
		ray->xpm->buffer[i] = malloc(sizeof(int) * (WIDTH + 1));
		if (!ray->xpm->buffer[i])
		{
			printf("ERROR\n");
		}
		i++;
	}
	return (0);
}

void clear_buffer(int **buffer)
{
	int i;
	int j;

	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		printf("%d\n", i);
		while (i < WIDTH)
		{
			buffer[j][i] = 0;
			i++;
		}
		j++;
	}
}

void print_buffer(int **buffer)
{
	int	i;
	int	j;

	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			printf("%c", buffer[j][i] = 0);
			i++;
		}
		printf("\n");
		j++;
	}
}