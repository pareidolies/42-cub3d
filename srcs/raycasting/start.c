/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:37:03 by smostefa          #+#    #+#             */
/*   Updated: 2022/10/10 17:47:54 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int start_raycasting(t_data *data)
{
    t_ray   ray;
    t_mlx   mlx;

    initialize_mlx(&mlx);
    ray.mlx = &mlx;
	initialize_all_values(&ray);
	//debug
	//print_map_data(data);
	transpose_parsed_map_to_ray(&ray, data);
	//print_map_ray(&ray, data);
	//fin debug
    transpose_parsed_data_to_ray(&ray, data);
	// if (!ray.minimap)
    launch_raycasting(&ray, ray.mlx);
	// else
    	// launch_raycasting_with_map(&ray, data, ray.mlx);

	//mlx_hook(mlx.win, 17, (1L << 17), &quit, &ray);
	//all.ray = &ray;
	//all.mlx = &mlx;
	//all.data = data;
	// mlx_key_hook(mlx.win, &keys_handler, &all);
	mlx_hook(ray.mlx->win, 2, 1L << 0, keys_handler, &ray);
	mlx_hook(ray.mlx->win, 17, 1L << 8, exit_safe_bis, &ray);
	mlx_hook(ray.mlx->win, 6, 1L << 6, mouse_move, &ray);
	// mlx_mouse_move(ray.mlx->ptr, ray.mlx->win, 50, 50);
	// mlx_hook(mlx.win, 17, 1L << 8, mlx_loop_end, &all);
	mlx_loop(ray.mlx->ptr);
	mlx_destroy_window(ray.mlx->ptr, ray.mlx->win);
	mlx_destroy_display(ray.mlx->ptr);
	free(ray.mlx->ptr);
	//free_data
    return (0);
}

/*TO DO :
- récupérer player x et y dans map dans structure pour avoir réinitialisation pour chaque rayon
- retourner la map en inversant x et y
- vérifier float / int des valeurs récupérées dans compute_line_attributes
- verifier orientation EST / WEST avec une boussole
*/
