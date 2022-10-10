/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:37:03 by smostefa          #+#    #+#             */
/*   Updated: 2022/10/10 17:44:38 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	test(int x, int y, t_ray *ray)
{
	int i;
	int j;
	
	mlx_mouse_get_pos(ray->mlx->ptr, ray->mlx->win, &i, &j);
	if (i > 1)
		rotate(ROTATE_RIGHT, ray, ray->mlx, ray->data);
	else if (i < 1)
		rotate(ROTATE_LEFT, ray, ray->mlx, ray->data);
	mlx_mouse_move(ray->mlx->ptr, ray->mlx->win, 1, 1);
	return(1);
}

int start_raycasting(t_data *data)
{
    t_ray   ray;
    t_mlx   mlx;

    ray.data = data;
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
    	launch_raycasting(&ray, data, ray.mlx);
	// else
    	// launch_raycasting_with_map(&ray, data, ray.mlx);

	//mlx_hook(mlx.win, 17, (1L << 17), &quit, &ray);
	//all.ray = &ray;
	//all.mlx = &mlx;
	//all.data = data;
	// mlx_key_hook(mlx.win, &keys_handler, &all);
	mlx_hook(ray.mlx->win, 2, 1L << 0, keys_handler, &ray);
	mlx_hook(ray.mlx->win, 17, 1L << 8, exit_safe_bis, &ray);
	mlx_hook(ray.mlx->win, 6, 1L << 6, test, &ray);
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
