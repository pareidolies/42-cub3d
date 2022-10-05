#include "../includes/cub3d.h"

int initialize_mlx(t_mlx *mlx)
{
    mlx->ptr = mlx_init();
	if (!mlx->ptr)
    {
        printf("Mlx init error.\n");
		return (1);
    }
	mlx->win = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, TITLE);
	if (!mlx->win)
	{
		free(mlx->ptr);
		return (1);
	}
	mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	if (!mlx->img)
	{
		//handling error
		return (1);
	}
	mlx->addr = (int*)mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->line_length, &mlx->endian);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
    return (0);
}

//Part 1

void init_dir(t_ray *ray, t_data *data)
{
    if (data->player.dir == 'N')
		ray->dir.x = -1;
	if (data->player.dir == 'S')
		ray->dir.x = 1;
	if (data->player.dir == 'E')
		ray->dir.y = 1;
	else //(data->player.dir == 'W')
		ray->dir.y = -1;
}

void init_plan(t_ray *ray, t_data *data)
{
    if (data->player.dir == 'N')
		ray->plan.y = 0.66;
	if (data->player.dir == 'S')
		ray->plan.y = -0.66;
	if (data->player.dir == 'E')
		ray->plan.x = 0.66;
	else //(data->player.dir == 'W')
		ray->plan.x = -0.66;
}

void init_all_ray_before_launch(t_ray *ray, t_data *data)
{
    ray->i = 0;
	ray->width = 640;
	ray->height = 480;
    ray->pos.x = (double)data->player.x + 0.5;
    ray->pos.y = (double)data->player.y + 0.5;
    //ray->map.x = (int)ray->pos.x; => c'est data->player.x
    //ray->map.y = (int)ray->pos.y; => c'est data->player.y
    init_dir(ray, data);
    init_plan(ray, data);
    //map => data->map
}

//Part 2

void init_deltadist(t_ray *ray)
{
    if (ray->raydir.y == 0)
		ray->deltadist.x = 0;
	else if (ray->raydir.x == 0)
		ray->deltadist.x = 1;
	else
		ray->deltadist.x = fabs(1 / ray->raydir.x);
	if (ray->raydir.x == 0)
		ray->deltadist.y = 0;
	else if (ray->raydir.y == 0)
		ray->deltadist.y = 1;
	else
		ray->deltadist.y = fabs(1 / ray->raydir.y);
}

void init_sidedist(t_ray *ray, t_data *data)
{
    if (ray->raydir.x < 0)
	{
		ray->step.x = -1;
		ray->sidedist.x = (ray->pos.x - data->player.x) * ray->deltadist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->sidedist.x = data->player.x + 1.0 - ray->pos.x * ray->deltadist.x;
	}
	if (ray->raydir.y < 0)
	{
		ray->step.y = -1;
		ray->sidedist.y = ray->pos.y - data->player.y * ray->deltadist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->sidedist.y = data->player.y + 1.0 - ray->pos.y * ray->deltadist.y;
	}
}

void init_one_ray(t_ray *ray, t_data *data)
{
	double	width = (double)ray->width;

	//printf("width : %f\n", width);
    ray->hit = EMPTY;
    ray->perpwalldist = 0;
    ray->camerax = 2 * ray->i / width - 1;
    ray->raydir.x = ray->dir.x + ray->plan.x * ray->camerax;
    ray->raydir.y = ray->dir.y + ray->plan.y * ray->camerax;
    init_deltadist(ray);
    init_sidedist(ray, data);
}

//Part 3

void	print_map(t_data *data)
{
	int	i = 0;
	int	j = 0;

	while (j < data->height)
	{
		i = 0;
		while (i < data->len)
		{
			printf("%c", data->map[j][i]);
			i++;
		}
		printf("\n");
		j++;
	}
	printf("x : %d\n", data->player.x);
	printf("y : %d\n", data->player.y);
}

void    compute_perpwalldist(t_ray *ray, t_data *data)
{
	print_map(data);
	//printf("TEST\n");
	while (ray->hit == EMPTY)
	{
		if (ray->sidedist.x < ray->sidedist.y)
		{
			ray->sidedist.x += ray->deltadist.x;
			data->player.x += ray->step.x;
			ray->side = HORIZONTAL;
		}
		else
		{
			ray->sidedist.y += ray->deltadist.y;
			data->player.y += ray->step.y;
			ray->side = VERTICAL;
		}
		printf("x : %d\n", data->player.x);
		printf("y : %d\n", data->player.y);
		printf("case : %c\n", data->map[data->player.y][data->player.x]);
		if (data->map[data->player.y][data->player.x] == '1')
			ray->hit = WALL;
		//printf("test\n");
	}
    if (ray->side == HORIZONTAL)
		ray->perpwalldist = ((double)data->player.x - ray->pos.x + (1 - (double)ray->step.x) / 2) / ray->raydir.x;
	else
		ray->perpwalldist = ((double)data->player.y - ray->pos.y + (1 - (double)ray->step.y) / 2) / ray->raydir.y;
}

void    compute_line_attributes(t_ray *ray)
{
	double	height = (double)ray->height;

    ray->lineheight = (int)(height / ray->perpwalldist);
	ray->drawstart = -ray->lineheight / 2 + height / 2;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = ray->lineheight / 2 + height / 2;
	if (ray->drawend >= height || ray->drawend < 0)
		ray->drawend = height - 1;
}

//Part 4

void    transpose_to_color(t_ray *ray, t_mlx *mlx)
{
	int	j;

	printf("drawstart : %d\n", ray->drawstart);
	printf("drawend : %d\n", ray->drawend);
	j = ray->drawstart;
	while(j < ray->drawend)
	{
		mlx->addr[j * mlx->line_length / 4 + ray->i] = create_trgb(0,0,0,255);
		j++;
	}
}

void    launch_raycasting(t_ray *ray, t_data *data, t_mlx *mlx)
{
    while (ray->i < WIDTH)
    {
        init_one_ray(ray, data);
		//printf("sidedistx : %f\n", ray->sidedist.x);
		//printf("sidedisty : %f\n", ray->sidedist.y);
		//printf("deltadistx : %f\n", ray->deltadist.x);
		//printf("deltadisty : %f\n", ray->deltadist.x);
        compute_perpwalldist(ray, data);
		//printf("perpwalldist : %f\n", ray->perpwalldist);
        compute_line_attributes(ray);
        transpose_to_color(ray, mlx);
        ray->i++;
    }
}

int start_cub3d(t_data *data)
{
    t_ray   ray;
	t_mlx	mlx;
    initialize_mlx(&mlx);
    init_all_ray_before_launch(&ray, data);
    launch_raycasting(&ray, data, &mlx);

    mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img, 0, 0);
	//mlx_loop_hook(mlx.ptr, &rayloop, &ray);
	//mlx_hook(mlx.win, 17, (1L << 17), &quit, &ray);
	//mlx_hook(mlx.win, KeyPress, KeyRelease, &key_handle, &ray);
	//mlx_loop(mlx.win);
	while(1)
		;
	mlx_destroy_window(mlx.ptr, mlx.win);
	mlx_destroy_display(mlx.ptr);
	free(mlx.ptr);
	//free_data
	//free_mlx
    return (0);
}