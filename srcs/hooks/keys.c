#include "../includes/cub3d.h"

int		keys_handler(int keycode, t_ray *ray)
{
	if (keycode == MOVE_FORWARD)
		move(keycode, ray, ray->mlx, ray->data);
	else if (keycode == MOVE_BACKWARD)
		move(keycode, ray, ray->mlx, ray->data);
	else if (keycode == MOVE_LEFTWARD)
		move(keycode, ray, ray->mlx, ray->data);
	else if (keycode == MOVE_RIGHTWARD)
		move(keycode, ray, ray->mlx, ray->data);
	else if (keycode == ROTATE_LEFT)
		rotate(keycode, ray, ray->mlx, ray->data);
	else if (keycode == ROTATE_RIGHT)
		rotate(keycode, ray, ray->mlx, ray->data);
	else if (keycode == ESC)
		exit_safe(ray);
	return (1);
}
