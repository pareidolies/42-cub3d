/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:14:25 by smostefa          #+#    #+#             */
/*   Updated: 2022/11/02 08:42:18 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	start_raycasting(t_data *data)
{
	t_ray	ray;
	t_mlx	mlx;

	ray.data = data;
	initialize_mlx(&mlx);
	ray.mlx = &mlx;
	initialize_all_values(&ray);
	transpose_parsed_map_to_ray(&ray, data);
	transpose_parsed_data_to_ray(&ray, data);
	get_textures(&ray); //NEW
	initialize_buffer(&ray); //NEW
	launch_raycasting(&ray, ray.mlx);
	mlx_hook(ray.mlx->win, 2, 1L << 0, key_press, &ray);
	mlx_hook(ray.mlx->win, 3, 1L << 1, key_release, &ray);
	mlx_loop_hook(ray.mlx->ptr, move, &ray);
	mlx_hook(mlx.win, 17, 1L << 8, mlx_loop_end, mlx.ptr);
	mlx_loop(ray.mlx->ptr);
	free_all(&ray);
	return (0);
}

/*WITHDRAW MOUSE (c.34)

mlx_hook(ray.mlx->win, 6, 1L << 6, mouse_move, &ray);
mlx_mouse_hide(mlx.ptr, mlx.win); // La fonction cree des leaks :( */