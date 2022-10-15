/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:36:02 by smostefa          #+#    #+#             */
/*   Updated: 2022/10/15 20:10:05 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	ray->img_menu.ceilling_0 = open_img(ray, "./textures/CEILLING_COLOR/0.xpm");
	ray->img_menu.ceilling_0s = open_img(ray, "./textures/CEILLING_COLOR/0s.xpm");
	ray->img_menu.ceilling_1 = open_img(ray, "./textures/CEILLING_COLOR/1.xpm");
	ray->img_menu.floor_6 = open_img(ray, "./textures/FLOOR_COLOR/6.xpm");
	ray->img_menu.floor_6s = open_img(ray, "./textures/FLOOR_COLOR/6s.xpm");
	ray->img_menu.floor_7 = open_img(ray, "./textures/FLOOR_COLOR/7.xpm");
	ray->img_menu.floor_7s = open_img(ray, "./textures/FLOOR_COLOR/7s.xpm");
	ray->img_menu.back_game = open_img(ray, "./textures/BACK_GAME/back_game.xpm");
	ray->img_menu.back_game_s = open_img(ray, "./textures/BACK_GAME/back_game_s.xpm");
}


static void	init_img_menu_c(t_ray *ray)
{
	ray->img_menu.ceilling_1s = open_img(ray, "./textures/CEILLING_COLOR/1s.xpm");
	ray->img_menu.ceilling_2 = open_img(ray, "./textures/CEILLING_COLOR/2.xpm");
	ray->img_menu.ceilling_2s = open_img(ray, "./textures/CEILLING_COLOR/2s.xpm");
	ray->img_menu.ceilling_3 = open_img(ray, "./textures/CEILLING_COLOR/3.xpm");
	ray->img_menu.ceilling_3s = open_img(ray, "./textures/CEILLING_COLOR/3s.xpm");
	ray->img_menu.ceilling_4 = open_img(ray, "./textures/CEILLING_COLOR/4.xpm");
	ray->img_menu.ceilling_4s = open_img(ray, "./textures/CEILLING_COLOR/4s.xpm");
	ray->img_menu.ceilling_5 = open_img(ray, "./textures/CEILLING_COLOR/5.xpm");
	ray->img_menu.ceilling_5s = open_img(ray, "./textures/CEILLING_COLOR/5s.xpm");
	ray->img_menu.ceilling_6 = open_img(ray, "./textures/CEILLING_COLOR/6.xpm");
	ray->img_menu.ceilling_6s = open_img(ray, "./textures/CEILLING_COLOR/6s.xpm");
	ray->img_menu.ceilling_7 = open_img(ray, "./textures/CEILLING_COLOR/7.xpm");
	ray->img_menu.ceilling_7s = open_img(ray, "./textures/CEILLING_COLOR/7s.xpm");
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
	ray->key.mouse_l = false;
	ray->key.mouse_r = false;
	ray->key.menu = false;
	ray->key.pos_menu = 0;
	ray->move_speed = 0.15;
	ray->key.move_s = 2;
	ray->rot_speed = 0.07;
	ray->key.rotation_s = 3;
	ray->ceilling_color = 0;
	ray->floor_color = 0;
}


void initialize_all_values(t_ray *ray)
{
	ray->dir.x = 0;
	ray->dir.y = 0;
	ray->plane.x = 0;
	ray->plane.y = 0;
	ray->perpwalldist = 0;
	ray->lineheight = 0;
	ray->drawstart = 0;
	ray->drawend = 0;
	ray->minimap = true;
	ray->pos_map.x = 0;
	ray->pos_map.y = 0;
	initialize_all_values_bis(ray);
	init_img_menu(ray);
}

int initialize_buffer(t_ray *ray)
{
	// printf("initialize\n");
	int i;

	ray->xpm->buffer = malloc(sizeof(int *) * (HEIGHT + 1));
	if (!ray->xpm->buffer)
	{
		printf("ERROR\n");
	}
	i = 0;
	while (i < HEIGHT)
	{
		ray->xpm->buffer[i] = malloc(sizeof(int) * (WIDTH + 1));
		if (!ray->xpm->buffer[i])
		{
			printf("ERROR\n");
		}
		i++;
	}
	return (0);
}

void clear_buffer(int **buffer)
{
	int i;
	int j;

	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		// printf("%d\n", i);
		while (i < WIDTH)
		{
			buffer[j][i] = 0;
			i++;
		}
		j++;
	}
}

void print_buffer(int **buffer)
{
	int	i;
	int	j;

	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			printf("%c", buffer[j][i] = 0);
			i++;
		}
		printf("\n");
		j++;
	}
}