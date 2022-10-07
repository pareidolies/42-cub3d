#include "../includes/cub3d.h"

void    rotate(int keycode, t_ray *ray, t_mlx *mlx, t_data *data)
{
    double former_plan_x;
	double former_dir_x;

	former_plan_x = ray->plan.x;
	former_dir_x = ray->dir.x;
	if (keycode == ROTATE_RIGHT)
	{
        printf("rotate right\n");
		ray->dir.x = ray->dir.x * cos(-ROT_SPEED / 2) - ray->dir.y * sin(-ROT_SPEED / 2);
		ray->dir.y = former_dir_x * sin(-ROT_SPEED / 2) + ray->dir.y * cos(-ROT_SPEED / 2);
		ray->plan.x = ray->plan.x * cos(-ROT_SPEED / 2) - ray->plan.y * sin(-ROT_SPEED / 2);
		ray->plan.y = former_plan_x * sin(-ROT_SPEED / 2) + ray->plan.y * cos(-ROT_SPEED / 2);
	}
	if (keycode == ROTATE_LEFT)
	{
        printf("rotate left\n");
		ray->dir.x = ray->dir.x * cos(ROT_SPEED / 2) - ray->dir.y * sin(ROT_SPEED / 2);
		ray->dir.y = former_dir_x * sin(ROT_SPEED / 2) + ray->dir.y * cos(ROT_SPEED / 2);
		ray->plan.x = ray->plan.x * cos(ROT_SPEED / 2) - ray->plan.y * sin(ROT_SPEED / 2);
		ray->plan.y = former_plan_x * sin(ROT_SPEED / 2) + ray->plan.y * cos(ROT_SPEED / 2);
    }
    launch_raycasting(ray, data, mlx);
}
