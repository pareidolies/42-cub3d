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
		return (1);
	mlx->addr = (int*)mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->line_length, &mlx->endian);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
    return (0);
}

/*int init_dir(t_ray *ray)
{
    //if (parsing jb == 'N')
		ray->dir.x = -1;
	//if (parsing jb == 'S')
		ray->dir.x = 1;
	//if (parsing jb == 'E')
		ray->dir.y = 1;
	//if (parsing jb == 'W')
		ray->dir.y = -1;
}

int init_plan(t_ray *ray)
{
    //if (parsing jb == 'N')
		ray->plan.y = 0.66;
	//if (parsing jb == 'S')
		ray->plan.y = -0.66;
	//if (parsing jb == 'E')
		ray->plan.x = 0.66;
	//if (parsing jb == 'W')
		ray->plan.x = -0.66;
}

int init_all_ray_before_launch(t_ray *ray)
{
    ray->i = 0;
    ray->pos.x = //(double)value parsing + 0.5
    ray->pos.y = //(double)value parsing + 0.5
    ray->map.x = (int)ray->pos.x;
    ray->map.y = (int)ray->pos.y;
    init_dir(ray);
    init_plan(ray);
    //map
    return (0);
}

int init_deltadist(t_ray *ray)
{
    if (ray->raydir.y == 0)
		ray->deltadist.x = 0;
	else if (ray->raydir.x == 0)
		ray->deltadist.x = 1;
	else
		ray->deltadist.x = abs(1 / ray->raydir.x);
	if (ray->raydir.x == 0)
		ray->deltadist.y = 0;
	else if (ray->raydir.y == 0)
		ray->deltadist.y = 1;
	else
		ray->deltadist.y = abs(1 / ray->raydir.y);
    return (0);
}

int init_sidedist(t_ray *ray)
{
    if (ray->raydir.x < 0)
	{
		ray->step.x = -1;
		ray->sidedist.x = (ray->pos.x - ray->map.x) * ray->deltadist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->sidedist.x = ray->map.x + 1.0 - ray->pos.x * ray->deltadist.x;
	}
	if (ray->raydir.y < 0)
	{
		ray->step.y = -1;
		ray->sidedist.y = ray->pos.y - ray->map.y * ray->deltadist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->sidedist.y = ray->mapy + 1.0 - ray->posy * ray->deltadist.y;
	}
}

int init_one_ray(t_ray *ray)
{
    ray->hit = EMPTY;
    ray->perpwalldist = 0;
    ray->camera.x = 2 * ray.x / (double)ray->i//WIDTH - 1;
    ray->raydir.x = ray->dir.x + ray->plan.x * ray->camera.x;
    ray->raydir.y = ray->dir.y + ray->plan.y * ray->camera.x;
    init_deltadist(ray);
    init_sidedist(ray);
    return (0);
}

void    compute_perpwalldist(t_ray *ray)
{
    while (ray->hit == EMPTY)
	{
		if (ray->sidedist.x < ray->sidedist.y)
		{
			ray->sidedist.x += ray->deltadist.x;
			ray->map.x += ray->step.x;
			ray->side = HORIZONTAL;
		}
		else
		{
			ray->sidedist.y += ray->deltadist.y;
			ray->map.y += ray->step.y;
			ray->side = VERTICAL;
		}
		if (//jb parsing map[ray->map.x][ray->map.y] == '1')
			ray->hit = HIT;
	}
    if (ray->side == HORIZONTAL)
		ray->perpwalldist = ((double)ray->map.x - ray->pos.x + (1 - (double)ray->step.x) / 2) / ray->raydir.x;
	else
		ray->perpwalldist = ((double)ray->map.y - ray->pos.y + (1 - (double)ray->step.y) / 2) / ray->raydir.y;
}

void    transpose_to_color(t_ray *ray, t_mlx *mlx)
{
    mlx.addr[j * mlx->line_length / 4 + ray->x] = //COLOR;

}

void    compute_line_attributes(t_ray *ray)
{
    ray->lineheight = (int)(ray->ry / ray->perpwalldist);
	ray->drawstart = -ray->lineheight / 2 + ray->ry / 2;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = ray->lineheight / 2 + ray->ry / 2;
	if (ray->drawend >= ray->ry || ray->drawend < 0)
		ray->drawend = ray->ry - 1;
}

void    launch_raycasting(t_ray *ray)
{
    while (ray->x < WIDTH)
    {
        init_one_ray(ray);
        compute_perpwalldist(ray);
        compute_line_attributes(ray);
        transpose_to_color(ray);
        ray->x++;
    }
}*/

int start_cub3d(t_data *root)
{
    t_all   all;
	t_mlx	mlx;
	all.data = root;
    initialize_mlx(&mlx);
    //init_all_ray_before_launch(&ray);
    //launch_raycasting(&ray);

    //mlx_put_image_to_window(all.mlx->ptr, all.mlx->win, all.mlx->img, 0, 0);
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