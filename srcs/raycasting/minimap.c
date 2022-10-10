#include "../includes/cub3d.h"

// void	square(t_mlx *mlx, int x, int y, int color)
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
// 			square(mlx, (j * 10) + 20, (i * 10) + 20, test);
// 		else
// 			square(mlx, (j * 10) + 20, (i * 10) + 20, test2);
// 		j++;
// 		if (j == data->len)
// 		{
// 			j = 0;
// 			i++;
// 		}
// 	}
// 	pos_player(mlx, data, ray);
// }






int	len_square(t_ray *ray)
{
	int	res;

	res = 10;
	// while ((res * data->len) > WIDTH || (res * data->height) > HEIGHT)
	while ((res * ray->width) > WIDTH || (res * ray->height) > HEIGHT)
		res--;
	return(res);
}

void	square(t_ray *ray, int x, int y, int color)
{
	int	i;
	int	j;
	int	sq;

	i = 0;
	j = 0;
	// sq = len_square(ray->data);
	sq = len_square(ray);
	while (j < 10)
	{
		ray->mlx->addr[((y + j) * WIDTH) + (x + i)] = color;
		i++;
		if (i == 10)
		{
			i = 0;
			j++;
		}
	}
}

// int	middle_x(t_data *data, int sq)
// {
// 	// printf("test = %d\n", data->len);
// 	// x = data->len
// 	return ((WIDTH / 2) - ((data->len * sq) / 2));
// }

void	pos_player(t_mlx *mlx, t_ray *ray, int sq)
{
	int	i;
	int	j;
	int pos_x;
	int pos_y;

	i = 1;
	j = 1;
	pos_x = (int)(ray->pos.x + (ray->dir.x * MOVE_SPEED * 2));
	pos_y = (int)ray->pos.y;
	if (ray->revert_map[pos_x][pos_y] == '1')
	{
		pos_x = ray->pos_map.x;
		pos_y = ray->pos_map.y;
	}
	else
	{
		ray->pos_map.x = pos_x;
		ray->pos_map.y = pos_y;
	}
	// printf("x = %d\ny = %d\n", pos_x, pos_y);
	while (j < sq - 1)
	{
		// mlx->addr[((j + (pos_y  * sq) + 20) * WIDTH) + (i + middle_x(data, sq) + (pos_x * sq))] = create_rgb(255, 255, 0);
		mlx->addr[((j + (pos_y  * sq) + 20) * WIDTH) + (i + 20 + (pos_x * sq))] = create_rgb(255, 255, 0);
		i++;
		if (i == sq - 1)
		{
			i = 1;
			j++;
		}
	}
}

void	show_minimap(t_mlx *mlx, t_data *data, t_ray *ray)
{
	int	i;
	int	hei;

	hei = (HEIGHT / 4) * 2.5;
	while (hei < HEIGHT)
	{
		i = WIDTH / 4;
		while (i < ((WIDTH / 4) * 3))
		{
			ray->mlx->addr[(hei * WIDTH) + i] = create_rgb(255, 188, 71);
			i++;
		}
		hei++;
	}
}

void	minimap(t_ray *ray)
{
	int i;
	int j;
	int	sq;

	i = 0;
	j = 0;
	// sq = len_square(data);
	sq = len_square(ray);
	if (sq < 4)
		return ;
	// while (i < data->height)
	while (i < ray->height)
	{
		// if (data->map[i][j] == '1')
		if (ray->revert_map[j][i] == '1')
			square(ray, (j * sq) + 20, (i * sq) + 20, create_rgb(128, 128, 128));
			// square(ray, (j * sq) + middle_x(data, sq), (i * sq) + 20, create_rgb(128, 128, 128));
		else
			square(ray, (j * sq) + 20, (i * sq) + 20, create_rgb(0, 0, 255));
			// square(ray, (j * sq) + middle_x(data, sq), (i * sq) + 20, create_rgb(0, 0, 255));
		j++;
		// if (j == data->len)
		if (j == ray->width)
		{
			j = 0;
			i++;
		}
	}
	pos_player(ray->mlx, ray, sq);
	// show_minimap(mlx, data, ray);
	// TEST
	// mlx_put_image_to_window(mlx->ptr, mlx->win, ray->img, 100, 200);
}
