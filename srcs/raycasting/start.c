#include "../includes/cub3d.h"

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
    launch_raycasting(&ray, data, ray.mlx);

	//mlx_hook(mlx.win, 17, (1L << 17), &quit, &ray);
	//all.ray = &ray;
	//all.mlx = &mlx;
	//all.data = data;
	// mlx_key_hook(mlx.win, &keys_handler, &all);
	mlx_hook(ray.mlx->win, 2, 1L << 0, keys_handler, &ray);
	// mlx_hook(mlx.win, 17, 1L << 8, mlx_loop_end, &all);
	minimap(ray.mlx, data);
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