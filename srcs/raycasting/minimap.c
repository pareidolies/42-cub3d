#include "../includes/cub3d.h"

// void	carre(t_mlx *mlx, int x, int y, int color)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (j < 10)
// 	{
// 		mlx_pixel_put(mlx->ptr, mlx->win, x + i, y + j, color);
// 		i++;
// 		if (i == 10)
// 		{
// 			i = 0;
// 			j++;
// 		}
// 	}
// }

// void	pos_player(t_mlx *mlx, t_data *data, t_ray *ray)
// {
// 	int	i;
// 	int	j;
// 	int pos_x;
// 	int pos_y;

// 	i = 1;
// 	j = 1;
// 	pos_x = (int)(ray->pos.x + (ray->dir.x * MOVE_SPEED * 2));
// 	pos_y = (int)ray->pos.y;
// 	while (j < 9)
// 	{
// 		mlx_pixel_put(mlx->ptr, mlx->win, (pos_x * 10 + i) + 20, (pos_y * 10 + j) + 20, create_rgb(0, 0, 255));
// 		i++;
// 		if (i == 9)
// 		{
// 			i = 1;
// 			j++;
// 		}
// 	}
// }

// void	minimap(t_mlx *mlx, t_data *data, t_ray *ray)
// {
// 	int i = 0;
// 	int j = 0;
// 	int test = create_rgb(255, 0, 0);
// 	int test2 = create_rgb(0, 255, 0);
// 	while (i < data->height)
// 	{
// 		if (data->map[i][j] == '1')
// 			carre(mlx, (j * 10) + 20, (i * 10) + 20, test);
// 		else
// 			carre(mlx, (j * 10) + 20, (i * 10) + 20, test2);
// 		j++;
// 		if (j == data->len)
// 		{
// 			j = 0;
// 			i++;
// 		}
// 	}
// 	pos_player(mlx, data, ray);
// }









void	carre(t_mlx *mlx, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < 10)
	{
		mlx->addr[((y + j) * WIDTH) + (x + i)] = color;
		i++;
		if (i == 10)
		{
			i = 0;
			j++;
		}
	}
}

void	pos_player(t_mlx *mlx, t_data *data, t_ray *ray)
{
	int	i;
	int	j;
	int pos_x;
	int pos_y;

	i = 1;
	j = 1;
	pos_x = (int)(ray->pos.x + (ray->dir.x * MOVE_SPEED * 2));
	pos_y = (int)ray->pos.y;
	while (j < 9)
	{
		mlx->addr[((j + (pos_y  * 10) + 20) * WIDTH) + (i + 20 + (pos_x * 10))] = create_rgb(255, 255, 0);
	
		i++;
		if (i == 9)
		{
			i = 1;
			j++;
		}
	}
}

void	minimap(t_mlx *mlx, t_data *data, t_ray *ray)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < data->height)
	{
		if (data->map[i][j] == '1')
			carre(mlx, (j * 10) + 20, (i * 10) + 20, create_rgb(128, 128, 128));
		else
			carre(mlx, (j * 10) + 20, (i * 10) + 20, create_rgb(51, 51, 255));
		j++;
		if (j == data->len)
		{
			j = 0;
			i++;
		}
	}
	pos_player(mlx, data, ray);
}
