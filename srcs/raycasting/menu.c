#include "../includes/cub3d.h"

void square(t_ray *ray)
{
	int wi = (WIDTH / 4) * 3;
	int he = (HEIGHT / 4) * 3;
	int i = WIDTH / 4;
	int j = HEIGHT / 4;
	while (j < he)
	{
		// i = WIDTH / 4;
		ray->mlx->addr[(j * WIDTH) + i] = create_rgb(254, 254, 254);
		// ray->mlx->addr[((y + j) * WIDTH) + (x + i)] = color;
		i++;
		if (i == wi)
		{
			i = WIDTH / 4;
			j++;
		}
	}
	mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->mlx->img, 0, 0);
	// printf("TEST\n");
}

void show_menu(t_ray *ray)
{
	square(ray);
	mlx_string_put(ray->mlx->ptr, ray->mlx->win, WIDTH / 2, HEIGHT / 2 + 20, create_rgb(0, 0, 0), "HELLO !");
	mlx_string_put(ray->mlx->ptr, ray->mlx->win, WIDTH / 2, HEIGHT / 2 + 35, create_rgb(0, 0, 0), "HELLO !");
	// mlx_string_put(ray->mlx->ptr, ray->mlx->win, WIDTH / 2, HEIGHT / 2 + 50, create_rgb(0, 0, 0), "HELLO !");
	// mlx_string_put(ray->mlx->ptr, ray->mlx->win, WIDTH / 2, HEIGHT / 2 + 65, create_rgb(0, 0, 0), "HELLO !");
	// mlx_string_put(ray->mlx->ptr, ray->mlx->win, WIDTH / 2, HEIGHT / 2 + 80, create_rgb(0, 0, 0), "HELLO !");
}