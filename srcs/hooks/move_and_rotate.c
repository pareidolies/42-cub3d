#include "../includes/cub3d.h"

void	exit_safe(t_all *all)
{
	mlx_destroy_window(all->mlx->ptr, all->mlx->win);
	mlx_destroy_display(all->mlx->ptr);
	exit (1);
}

int		keys_handler(int keycode, t_all *all)
{
	if (keycode == MOVE_FORWARD)
		move(keycode, all->ray, all->mlx, all->data);
	else if (keycode == MOVE_BACKWARD)
		move(keycode, all->ray, all->mlx, all->data);
	else if (keycode == MOVE_LEFTWARD)
		move(keycode, all->ray, all->mlx, all->data);
	else if (keycode == MOVE_RIGHTWARD)
		move(keycode, all->ray, all->mlx, all->data);
	else if (keycode == ROTATE_LEFT)
		rotate(keycode, all->ray, all->mlx, all->data);
	else if (keycode == ROTATE_RIGHT)
		rotate(keycode, all->ray, all->mlx, all->data);
	else if (keycode == ESC)
		exit_safe(all);
	return (1);
}

void    move(int keycode, t_ray *ray, t_mlx *mlx, t_data *data)
{
    if (keycode == MOVE_FORWARD)
	{
        printf("x : %d\n", (int)(ray->pos.x + (ray->dir.x * MOVE_SPEED * 2)));
        printf("y : %d\n", (int)ray->pos.y);
		if (ray->revert_map[(int)(ray->pos.x + (ray->dir.x * MOVE_SPEED * 2))][(int)ray->pos.y] != '1')
        {

			ray->pos.x += ray->dir.x * MOVE_SPEED;
            printf("forward1\n");
        }
		if (ray->revert_map[(int)(ray->pos.x)][(int)(ray->pos.y + (ray->dir.y * MOVE_SPEED * 2))] != '1')
        {
			ray->pos.y += ray->dir.y * MOVE_SPEED;
            printf("forward2\n");
        }
	}
	if (keycode == MOVE_BACKWARD)
	{
        printf("backward\n");
		if (ray->revert_map[(int)(ray->pos.x - (ray->dir.x * MOVE_SPEED * 2))][(int)(ray->pos.y)] != '1')
			ray->pos.x -= ray->dir.x * MOVE_SPEED;
		if (ray->revert_map[(int)(ray->pos.x)][(int)(ray->pos.y - (ray->dir.y * MOVE_SPEED * 2))] != '1')
			ray->pos.y -= ray->dir.y * MOVE_SPEED;
	}
    if (keycode == MOVE_RIGHTWARD)
	{
        printf("rightward\n");
		if (ray->revert_map[(int)(ray->pos.x + ray->dir.y * (MOVE_SPEED * 2))][(int)ray->pos.y] != '1')
			ray->pos.x += ray->dir.y * MOVE_SPEED;
		if (ray->revert_map[(int)ray->pos.x][(int)(ray->pos.y - ray->dir.x * (MOVE_SPEED * 2))] != '1')
			ray->pos.y -= ray->dir.x * MOVE_SPEED;
	}
	if (keycode == MOVE_LEFTWARD)
	{
        printf("leftward\n");
		if (ray->revert_map[(int)(ray->pos.x - ray->dir.y * (MOVE_SPEED * 2))][(int)ray->pos.y] != '1')
			ray->pos.x -= ray->dir.y * MOVE_SPEED;
		if (ray->revert_map[(int)ray->pos.x][(int)(ray->pos.y + ray->dir.x * (MOVE_SPEED * 2))] != '1')
			ray->pos.y += ray->dir.x * MOVE_SPEED;
	}
    launch_raycasting(ray, data, mlx);
}

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