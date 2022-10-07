/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:36:02 by smostefa          #+#    #+#             */
/*   Updated: 2022/10/07 14:36:04 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int initialize_mlx(t_mlx *mlx)
{
    printf("salut");
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

void	initialize_all_values(t_ray *ray)
{
	ray->dir.x = 0;
	ray->dir.y = 0;
	ray->plan.x = 0;
	ray->plan.y = 0;
	ray->perpwalldist = 0;
	ray->lineheight = 0;
    ray->drawstart = 0;
    ray->drawend = 0;
}
