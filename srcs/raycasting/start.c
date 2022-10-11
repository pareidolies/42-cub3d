/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:37:03 by smostefa          #+#    #+#             */
/*   Updated: 2022/10/11 16:47:21 by jdubilla         ###   ########.fr       */
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
	// print_map_ray(&ray, data);
	launch_raycasting(&ray, ray.mlx);
	mlx_hook(ray.mlx->win, 2, 1L << 0, keys_handler, &ray);
	mlx_hook(mlx.win, 17, 1L << 8, mlx_loop_end, mlx.ptr);
	// mlx_mouse_hide(mlx.ptr, mlx.win); // Effectivement la fonction cree des leaks
	mlx_hook(ray.mlx->win, 6, 1L << 6, mouse_move, &ray);
	mlx_loop(ray.mlx->ptr);
	mlx_destroy_window(ray.mlx->ptr, ray.mlx->win);
	mlx_destroy_display(ray.mlx->ptr);
	free(ray.mlx->ptr);
	free_double_array(ray.revert_map);
	return (0);
}

/*TO DO :
- vérifier float / int des valeurs récupérées dans compute_line_attributes
*/
