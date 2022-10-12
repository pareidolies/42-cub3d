/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:37:03 by smostefa          #+#    #+#             */
/*   Updated: 2022/10/12 17:14:42 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


int	key_release(int keycode, t_ray *ray)
{
	// printf("OK\n");
	(void)keycode;
	(void)ray;
		// printf("RELEASE\n");
	if (keycode == MOVE_FORWARD)
		ray->key.w = false;
	if (keycode == MOVE_BACKWARD)
		ray->key.s = false;
	if (keycode == MOVE_LEFTWARD)
		ray->key.a = false;
	if (keycode == MOVE_RIGHTWARD)
		ray->key.d = false;
	if (keycode == ROTATE_LEFT)
		ray->key.rl = false;
	if (keycode == ROTATE_RIGHT)
		ray->key.rr = false;
	return (1);
}


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
	// launch_raycasting(&ray, ray.mlx);
	// mlx_hook(ray.mlx->win, 2, 1L << 0, keys_handler, &ray);
	mlx_hook(ray.mlx->win, 2, 1L << 0, key_press, &ray);
	mlx_hook(ray.mlx->win, 3, 1L << 1, key_release, &ray);
	mlx_loop_hook(ray.mlx->ptr, move, &ray);
	// mlx_loop_hook(ray.mlx->ptr, rotate, &ray);
	mlx_hook(mlx.win, 17, 1L << 8, mlx_loop_end, mlx.ptr);
	// mlx_mouse_hide(mlx.ptr, mlx.win); // La fonction cree des leaks :(
	// mlx_hook(ray.mlx->win, 6, 1L << 6, mouse_move, &ray);
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
