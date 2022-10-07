#include "../includes/cub3d.h"

void	carre(t_mlx *mlx, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < 5)
	{
		mlx_pixel_put(mlx->ptr, mlx->win, x + i, y + j, color);
		i++;
		if (i == 5)
		{
			i = 0;
			j++;
		}
	}
}

void	minimap(t_mlx *mlx, t_data *data)
{
	// my_mlx_pixel_put(mlx->img, 5, 5, 0x00FF0000);
	// carre(mlx, 0, 0, 0x00FF0000);
	int i = 0;
	int j = 0;
	int test = create_rgb(255, 0, 0);
	int test2 = create_rgb(0, 255, 0);
	while (i < data->height)
	{
		// printf("i = %d j = %d\n", i, j);
		if (data->map[i][j] == '1')
			carre(mlx, (j * 5) + 5, (i * 5) + 150, test);
		else
			carre(mlx, (j * 5) + 5, (i * 5) + 150, test2);
		j++;
		if (j == data->len)
		{
			j = 0;
			i++;
		}
	}
	// carre(mlx, 0, 0, 0x0000FF00);
	// mlx_pixel_put(mlx->ptr, mlx->win, 0, 0, 0x00FF0000);
	// mlx_put_image_to_window(mlx, mlx->win, mlx->img, 1, 1);
}
