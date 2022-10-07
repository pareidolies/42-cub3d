#include "../includes/cub3d.h"

void	transpose_parsed_map_to_ray(t_ray *ray, t_data *data)
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

void init_dir(t_ray *ray, t_data *data)
{
    if (data->player.dir == 'N')
		ray->dir.x = -1;
	if (data->player.dir == 'S')
		ray->dir.x = 1;
	if (data->player.dir == 'E')
		ray->dir.y = 1;
	else //(data->player.dir == 'W') pour eviter probleme uninitialized values
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

void transpose_parsed_data_to_ray(t_ray *ray, t_data *data)
{
	ray->width = 1280;
	ray->height = 960;
    ray->pos.x = (double)data->player.x + 0.5;
    ray->pos.y = (double)data->player.y + 0.5;
    init_dir(ray, data);
    init_plan(ray, data);
    //map => data->map ne plus utiliser data
}