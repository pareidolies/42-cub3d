/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:27:03 by jdubilla          #+#    #+#             */
/*   Updated: 2022/10/11 16:27:06 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	exit_safe(t_ray *ray)
{
	mlx_destroy_window(ray->mlx->ptr, ray->mlx->win);
	mlx_destroy_display(ray->mlx->ptr);
	free(ray->mlx->ptr);
	free_double_array(ray->revert_map);
	free_struct(ray->data);
	exit(0);
}
