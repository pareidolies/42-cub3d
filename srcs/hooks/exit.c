#include "../includes/cub3d.h"

void	exit_safe(t_ray *ray)
{
	mlx_destroy_window(ray->mlx->ptr, ray->mlx->win);
	mlx_destroy_display(ray->mlx->ptr);
	exit (1);
}

int	exit_safe_bis(int keycode, t_ray *ray)
{
	(void)keycode;
	// mlx_destroy_window(ray->mlx->ptr, ray->mlx->win);
	// printf("OK\n");
	// mlx_destroy_display(ray->mlx->ptr);
	exit (1);
	return (1);
}
