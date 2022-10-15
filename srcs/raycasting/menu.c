#include "../includes/cub3d.h"

void	move_speed(t_ray *ray, int x, int y)
{
	// printf("move_s = %d\npos_menu = %d\n", ray->key.move_s, ray->key.pos_menu);
	if (ray->key.move_s == 1 && ray->key.pos_menu == 0)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.move_speed_1s, x, y);
	else if (ray->key.move_s == 1)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.move_speed_1, x, y);
	else if (ray->key.move_s == 2 && ray->key.pos_menu == 0)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.move_speed_2s, x, y);
	else if (ray->key.move_s == 2)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.move_speed_2, x, y);
	else if (ray->key.move_s == 3  && ray->key.pos_menu == 0)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.move_speed_3s, x, y);
	else if (ray->key.move_s == 3)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.move_speed_3, x, y);
	else if (ray->key.move_s == 4 && ray->key.pos_menu == 0)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.move_speed_4s, x, y);
	else if (ray->key.move_s == 4)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.move_speed_4, x, y);
}

void	rot_speed(t_ray *ray, int x, int y)
{
	if (ray->key.rotation_s == 1 && ray->key.pos_menu == 1)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.rot_speed_1s, x, y);
	else if (ray->key.rotation_s == 1)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.rot_speed_1, x, y);
	else if (ray->key.rotation_s == 2 && ray->key.pos_menu == 1)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.rot_speed_2s, x, y);
	else if (ray->key.rotation_s == 2)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.rot_speed_2, x, y);
	else if (ray->key.rotation_s == 3 && ray->key.pos_menu == 1)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.rot_speed_3s, x, y);
	else if (ray->key.rotation_s == 3)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.rot_speed_3, x, y);
	else if (ray->key.rotation_s == 4 && ray->key.pos_menu == 1)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.rot_speed_4s, x, y);
	else if (ray->key.rotation_s == 4)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.rot_speed_4, x, y);
}

void	back_game(t_ray *ray, int x, int y)
{
	if (ray->key.pos_menu == 4)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.back_game_s, x, y);
	else
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.back_game, x, y);
}

void	ceilling_color(t_ray *ray, int x, int y)
{
	if (ray->ceilling_color == 0 && ray->key.pos_menu == 2)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.ceilling_0s, x, y);
	else if (ray->ceilling_color == 0)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.ceilling_0, x, y);
	else if (ray->ceilling_color == 1 && ray->key.pos_menu == 2)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.ceilling_1s, x, y);
	else if (ray->ceilling_color == 1)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.ceilling_1, x, y);
	else if (ray->ceilling_color == 2 && ray->key.pos_menu == 2)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.ceilling_2s, x, y);
	else if (ray->ceilling_color == 2)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.ceilling_2, x, y);
	else if (ray->ceilling_color == 3 && ray->key.pos_menu == 2)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.ceilling_3s, x, y);
	else if (ray->ceilling_color == 3)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.ceilling_3, x, y);
	else if (ray->ceilling_color == 4 && ray->key.pos_menu == 2)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.ceilling_4s, x, y);
	else if (ray->ceilling_color == 4)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.ceilling_4, x, y);
	else if (ray->ceilling_color == 5 && ray->key.pos_menu == 2)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.ceilling_5s, x, y);
	else if (ray->ceilling_color == 5)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.ceilling_5, x, y);
	else if (ray->ceilling_color == 6 && ray->key.pos_menu == 2)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.ceilling_6s, x, y);
	else if (ray->ceilling_color == 6)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.ceilling_6, x, y);
	else if (ray->ceilling_color == 7 && ray->key.pos_menu == 2)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.ceilling_7s, x, y);
	else if (ray->ceilling_color == 7)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.ceilling_7, x, y);
}

void	floor_color(t_ray *ray, int x, int y)
{
	if (ray->floor_color == 0 && ray->key.pos_menu == 3)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.floor_0s, x, y);
	else if (ray->floor_color == 0)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.floor_0, x, y);
	else if (ray->floor_color == 1 && ray->key.pos_menu == 3)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.floor_1s, x, y);
	else if (ray->floor_color == 1)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.floor_1, x, y);
	else if (ray->floor_color == 2 && ray->key.pos_menu == 3)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.floor_2s, x, y);
	else if (ray->floor_color == 2)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.floor_2, x, y);
	else if (ray->floor_color == 3 && ray->key.pos_menu == 3)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.floor_3s, x, y);
	else if (ray->floor_color == 3)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.floor_3, x, y);
	else if (ray->floor_color == 4 && ray->key.pos_menu == 3)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.floor_4s, x, y);
	else if (ray->floor_color == 4)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.floor_4, x, y);
	else if (ray->floor_color == 5 && ray->key.pos_menu == 3)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.floor_5s, x, y);
	else if (ray->floor_color == 5)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.floor_5, x, y);
	else if (ray->floor_color == 6 && ray->key.pos_menu == 3)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.floor_6s, x, y);
	else if (ray->floor_color == 6)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.floor_6, x, y);
	else if (ray->floor_color == 7 && ray->key.pos_menu == 3)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.floor_7s, x, y);
	else if (ray->floor_color == 7)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.floor_7, x, y);
}

void	exit_game(t_ray *ray, int x, int y)
{
	if (ray->key.pos_menu == 5)
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.exit_game_s, x, y);
	else
		mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->img_menu.exit_game, x, y);
}

void show_menu(t_ray *ray)
{
	move_speed(ray, WIDTH / 4 * 1.65, (HEIGHT / 4 * 1.2));
	rot_speed(ray, WIDTH / 4 * 1.65, (HEIGHT / 4 * 1.5));
	ceilling_color(ray, WIDTH / 4 * 1.65, (HEIGHT / 4 * 1.8));
	floor_color(ray, WIDTH / 4 * 1.65, (HEIGHT / 4 * 2.1));
	back_game(ray, WIDTH / 4 * 1.65, (HEIGHT / 4 * 2.4));
	exit_game(ray, WIDTH / 4 * 1.65, (HEIGHT / 4 * 2.7));
}