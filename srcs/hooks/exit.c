#include "../includes/cub3d.h"

void	exit_safe(t_ray *ray)
{
	mlx_destroy_window(ray->mlx->ptr, ray->mlx->win);
	mlx_destroy_display(ray->mlx->ptr);
	exit (1);
}
