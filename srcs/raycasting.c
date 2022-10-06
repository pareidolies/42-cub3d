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
    return (0);
}

void	init_all_values(t_ray *ray)
{
	ray->dir.x = 0;
	ray->dir.y = 0;
	ray->plan.x = 0;
	ray->plan.y = 0;
	ray->perpwalldist = 0;
	ray->lineheight = 0;
    ray->drawstart = 0;
    ray->drawend = 0;
}

void	revert_map(t_ray *ray, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	ray->revert_map = malloc(sizeof(char *) * data->len);
	while (i < data->len)
	{
		ray->revert_map[i] = malloc(sizeof(char) * data->height);
		i++;
	}
	i = 0;
	j = 0;
	while (i < data->len)
	{
		j = 0;
		while (j < data->height)
		{
			ray->revert_map[i][j] = data->map[j][i];
			j++;
		}
		i++;
	}
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
		ray->sidedist.x = (ray->pos.x - ray->map.x) * ray->deltadist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->sidedist.x = (ray->map.x + 1.0 - ray->pos.x) * ray->deltadist.x;
	}
	if (ray->raydir.y < 0)
	{
		ray->step.y = -1;
		ray->sidedist.y = (ray->pos.y - ray->map.y) * ray->deltadist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->sidedist.y = (ray->map.y + 1.0 - ray->pos.y) * ray->deltadist.y;
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
	ray->map.x = (int)ray->pos.x;
	ray->map.y = (int)ray->pos.y;
    init_deltadist(ray);
    init_sidedist(ray, data);
}

//Part 3

void	print_map_data(t_data *data)
{
	int	i = 0;
	int	j = 0;

	printf("--- parse map ---\n");
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

void	print_map_ray(t_ray *ray, t_data *data)
{
	int	i = 0;
	int	j = 0;

	printf("--- revert map ---\n");
	while (j < data->height)
	{
		i = 0;
		while (i < data->len)
		{
			printf("%c", ray->revert_map[i][j]);
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
	//printf("TEST\n");
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
		//printf("x : %d\n", ray->map.x);
		//printf("y : %d\n", ray->map.y);
		//printf("case : %c\n", data->map[ray->map.y][ray->map.x]);
		if (ray->revert_map[ray->map.x][ray->map.y] == '1')
			ray->hit = WALL;
		//printf("test\n");
	}
    if (ray->side == HORIZONTAL)
		//ray->perpwalldist = ((double)ray->map.x - ray->pos.x + (1 - (double)ray->step.x) / 2) / ray->raydir.x;
		ray->perpwalldist = ray->sidedist.x - ray->deltadist.x;
	else
		//ray->perpwalldist = ((double)ray->map.y - ray->pos.y + (1 - (double)ray->step.y) / 2) / ray->raydir.y;
		ray->perpwalldist = ray->sidedist.y - ray->deltadist.y;
}

void    compute_line_attributes(t_ray *ray)
{

    ray->lineheight = (int)(ray->height / ray->perpwalldist);
	ray->drawstart = -ray->lineheight / 2 + ray->height / 2;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = ray->lineheight / 2 + ray->height / 2;
	if (ray->drawend >= ray->height || ray->drawend < 0)
		ray->drawend = ray->height - 1;
}

//Part 4

void    transpose_to_color(t_ray *ray, t_mlx *mlx)
{
	int	j;
	
	mlx->addr = (int*)mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->line_length, &mlx->endian);
	//printf("drawstart : %d\n", ray->drawstart);
	//printf("drawend : %d\n", ray->drawend);
	j = ray->drawstart;
	while(j < ray->drawend)
	{
		//mlx->addr[j * mlx->line_length / 4 + ray->i] = create_trgb(0,0,0,255);
		if (ray->side == HORIZONTAL)
			mlx->addr[j * WIDTH + ray->i] = create_rgb(0,0,255);
		else
			mlx->addr[j * WIDTH + ray->i] = create_rgb(0,0,255) / 2;
		j++;
	}
}

int    launch_raycasting(t_ray *ray, t_data *data, t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	if (!mlx->img)
	{
		//handling error && free
		return (1);
	}
	ray->i = 0;
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
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	mlx_destroy_image(mlx->ptr, mlx->img);
	return (0);
}

/*int    re_launch_raycasting(t_ray *ray, t_data *data, t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	if (!mlx->img)
	{
		//handling error && free
		return (1);
	}
	//init_all_values(ray);
	//init_all_ray_before_launch(ray, data);
	ray->i = 0;
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
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	mlx_destroy_image(mlx->ptr, mlx->img);
	return (0);
}*/


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
	int test = create_trgb(0, 100, 0, 0);
	int test2 = create_trgb(0, 0, 50, 0);
	while (i < data->height)
	{
		// printf("i = %d j = %d\n", i, j);
		if (data->map[i][j] == '1')
			carre(mlx, (j * 5) + 5, (i * 5) + 150, test);
		else
			carre(mlx, (j * 5) + 5, (i * 5) + 150, 0x0000FF00);
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


int start_cub3d(t_data *data)
{
	t_all	all;
    t_ray   ray;
	t_mlx	mlx;
    initialize_mlx(&mlx);
	init_all_values(&ray);
	//debug
	print_map_data(data);
	revert_map(&ray, data);
	print_map_ray(&ray, data);
	//fin debug
    init_all_ray_before_launch(&ray, data);
    launch_raycasting(&ray, data, &mlx);

    //mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img, 0, 0);
	//mlx_destroy_image(mlx.ptr, mlx.img);
	//mlx_loop_hook(mlx.ptr, &rayloop, &ray);
	//mlx_hook(mlx.win, 17, (1L << 17), &quit, &ray);
	all.ray = &ray;
	all.mlx = &mlx;
	all.data = data;
	mlx_key_hook(mlx.win, &keys_handler, &all);
	minimap(&mlx, data);
	mlx_loop(mlx.ptr);
	//while(1)
	//	;
	mlx_destroy_window(mlx.ptr, mlx.win);
	mlx_destroy_display(mlx.ptr);
	free(mlx.ptr);
	//free_data
	//free_mlx
    return (0);
}

/*TO DO :
- récupérer player x et y dans map dans structure pour avoir réinitialisation pour chaque rayon
- retourner la map en inversant x et y
- vérifier float / int des valeurs récupérées dans compute_line_attributes
- verifier orientation EST / WEST avec une boussole
*/