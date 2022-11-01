#include "../includes/cub3d.h"

void	*open_img(t_ray *ray, char *path)
{
	void	*res;

	res = mlx_xpm_file_to_image(ray->mlx->ptr, path,
			&ray->img_menu.width, &ray->img_menu.height);
	if (!res)
	{
		ft_printf("Err\nimg: %s is incorrect.\n");
		// free tout ce qu'il faut
	}
	return (res);
}

static void	init_img_menu_b(t_ray *ray)
{
	ray->img_menu.rot_speed_1 = open_img(ray, "./textures/ROT_SPEED/1.xpm");
	ray->img_menu.rot_speed_2 = open_img(ray, "./textures/ROT_SPEED/2.xpm");
	ray->img_menu.rot_speed_3 = open_img(ray, "./textures/ROT_SPEED/3.xpm");
	ray->img_menu.rot_speed_4 = open_img(ray, "./textures/ROT_SPEED/4.xpm");
	ray->img_menu.rot_speed_1s = open_img(ray, "./textures/ROT_SPEED/1s.xpm");
	ray->img_menu.rot_speed_2s = open_img(ray, "./textures/ROT_SPEED/2s.xpm");
	ray->img_menu.rot_speed_3s = open_img(ray, "./textures/ROT_SPEED/3s.xpm");
	ray->img_menu.rot_speed_4s = open_img(ray, "./textures/ROT_SPEED/4s.xpm");
	ray->img_menu.move_speed_1 = open_img(ray, "./textures/MOVE_SPEED/ms1.xpm");
	ray->img_menu.move_speed_1s = open_img(ray, "./textures/MOVE_SPEED/ms1_s.xpm");
	ray->img_menu.move_speed_2 = open_img(ray, "./textures/MOVE_SPEED/ms2.xpm");
	ray->img_menu.move_speed_2s = open_img(ray, "./textures/MOVE_SPEED/ms2_s.xpm");
	ray->img_menu.move_speed_3 = open_img(ray, "./textures/MOVE_SPEED/ms3.xpm");
	ray->img_menu.move_speed_3s = open_img(ray, "./textures/MOVE_SPEED/ms3_s.xpm");
	ray->img_menu.move_speed_4 = open_img(ray, "./textures/MOVE_SPEED/ms4.xpm");
	ray->img_menu.move_speed_4s = open_img(ray, "./textures/MOVE_SPEED/ms4_s.xpm");
	ray->img_menu.ceiling_0 = open_img(ray, "./textures/CEILING_COLOR/0.xpm");
	ray->img_menu.ceiling_0s = open_img(ray, "./textures/CEILING_COLOR/0s.xpm");
	ray->img_menu.ceiling_1 = open_img(ray, "./textures/CEILING_COLOR/1.xpm");
	ray->img_menu.floor_6 = open_img(ray, "./textures/FLOOR_COLOR/6.xpm");
	ray->img_menu.floor_6s = open_img(ray, "./textures/FLOOR_COLOR/6s.xpm");
	ray->img_menu.floor_7 = open_img(ray, "./textures/FLOOR_COLOR/7.xpm");
	ray->img_menu.floor_7s = open_img(ray, "./textures/FLOOR_COLOR/7s.xpm");
	ray->img_menu.back_game = open_img(ray, "./textures/BACK_GAME/back_game.xpm");
	ray->img_menu.back_game_s = open_img(ray, "./textures/BACK_GAME/back_game_s.xpm");
}


static void	init_img_menu_c(t_ray *ray)
{
	ray->img_menu.ceiling_1s = open_img(ray, "./textures/CEILING_COLOR/1s.xpm");
	ray->img_menu.ceiling_2 = open_img(ray, "./textures/CEILING_COLOR/2.xpm");
	ray->img_menu.ceiling_2s = open_img(ray, "./textures/CEILING_COLOR/2s.xpm");
	ray->img_menu.ceiling_3 = open_img(ray, "./textures/CEILING_COLOR/3.xpm");
	ray->img_menu.ceiling_3s = open_img(ray, "./textures/CEILING_COLOR/3s.xpm");
	ray->img_menu.ceiling_4 = open_img(ray, "./textures/CEILING_COLOR/4.xpm");
	ray->img_menu.ceiling_4s = open_img(ray, "./textures/CEILING_COLOR/4s.xpm");
	ray->img_menu.ceiling_5 = open_img(ray, "./textures/CEILING_COLOR/5.xpm");
	ray->img_menu.ceiling_5s = open_img(ray, "./textures/CEILING_COLOR/5s.xpm");
	ray->img_menu.ceiling_6 = open_img(ray, "./textures/CEILING_COLOR/6.xpm");
	ray->img_menu.ceiling_6s = open_img(ray, "./textures/CEILING_COLOR/6s.xpm");
	ray->img_menu.ceiling_7 = open_img(ray, "./textures/CEILING_COLOR/7.xpm");
	ray->img_menu.ceiling_7s = open_img(ray, "./textures/CEILING_COLOR/7s.xpm");
	ray->img_menu.floor_0 = open_img(ray, "./textures/FLOOR_COLOR/0.xpm");
	ray->img_menu.floor_0s = open_img(ray, "./textures/FLOOR_COLOR/0s.xpm");
	ray->img_menu.floor_1 = open_img(ray, "./textures/FLOOR_COLOR/1.xpm");
	ray->img_menu.floor_1s = open_img(ray, "./textures/FLOOR_COLOR/1s.xpm");
	ray->img_menu.floor_2 = open_img(ray, "./textures/FLOOR_COLOR/2.xpm");
	ray->img_menu.floor_2s = open_img(ray, "./textures/FLOOR_COLOR/2s.xpm");
	ray->img_menu.floor_3 = open_img(ray, "./textures/FLOOR_COLOR/3.xpm");
	ray->img_menu.floor_3s = open_img(ray, "./textures/FLOOR_COLOR/3s.xpm");
	ray->img_menu.floor_4 = open_img(ray, "./textures/FLOOR_COLOR/4.xpm");
	ray->img_menu.floor_4s = open_img(ray, "./textures/FLOOR_COLOR/4s.xpm");
	ray->img_menu.floor_5 = open_img(ray, "./textures/FLOOR_COLOR/5.xpm");
	ray->img_menu.floor_5s = open_img(ray, "./textures/FLOOR_COLOR/5s.xpm");
}

void	init_img_menu(t_ray *ray)
{

	init_img_menu_b(ray);
	init_img_menu_c(ray);
	ray->img_menu.exit_game_s = open_img(ray, "./textures/EXIT_GAME/exit_s.xpm");
	ray->img_menu.exit_game = open_img(ray, "./textures/EXIT_GAME/exit.xpm");
}

void initialize_all_values_bis(t_ray *ray)
{
	ray->key.w = false;
	ray->key.a = false;
	ray->key.s = false;
	ray->key.d = false;
	ray->key.rr = false;
	ray->key.rl = false;
	ray->key.space = false;
	ray->key.mouse_l = false;
	ray->key.mouse_r = false;
	ray->key.menu = false;
	ray->key.pos_menu = 0;
	ray->move_speed = 0.15;
	ray->key.move_s = 2;
	ray->rot_speed = 0.07;
	ray->key.rotation_s = 3;
	ray->ceiling_color = 0;
	ray->floor_color = 0;
}