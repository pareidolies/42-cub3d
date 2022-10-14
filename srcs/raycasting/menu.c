#include "../includes/cub3d.h"

void square(t_ray *ray)
{
	int wi = (WIDTH / 4) * 2.3;
	int he = (HEIGHT / 4) * 2.3;
	int i = WIDTH / 4 * 1.7;
	int j = HEIGHT / 4 * 1.5;
	while (j < he)
	{
		ray->mlx->addr[(j * WIDTH) + i] = create_rgb(73, 150, 236);
		i++;
		if (i == wi)
		{
			i = WIDTH / 4 * 1.7;
			j++;
		}
	}
	mlx_put_image_to_window(ray->mlx->ptr, ray->mlx->win, ray->mlx->img, 0, 0);
	// printf("TEST\n");
}

static void	show_message_menu(int mess, char *mess_m, char *value, t_ray *ray)
{
	int		color;
	char	*message;

	if (mess == ray->key.pos_menu)
		color = create_rgb(0, 255, 0);
	else
		color = create_rgb(0, 0, 0);
	if (!value)
	{
		mlx_string_put(ray->mlx->ptr, ray->mlx->win, WIDTH / 4 * 1.825, (HEIGHT / 4 * 1.7) + (mess * 20), color, mess_m);
		return ;
	}
	message = ft_strjoin(mess_m, value);
	mlx_string_put(ray->mlx->ptr, ray->mlx->win, WIDTH / 4 * 1.825, (HEIGHT / 4 * 1.7) + (mess * 20), color, message);
	free(message);
	free(value);
}

void show_menu(t_ray *ray)
{
	char	*s;
	
	square(ray);
	// printf("pos_menu = %d\n", ray->key.pos_menu);
	// if (ray->key.pos_menu == 0)
	// {
		mlx_string_put(ray->mlx->ptr, ray->mlx->win, WIDTH / 4 * 1.95, (HEIGHT / 4 * 1.6), create_rgb(0, 0, 0), "MENU");
		// sprintf(s, "%f", ray->move_speed);
		s = ft_itoa(ray->key.move_s);
		show_message_menu(0, "MOVE SPEED :       ", s, ray);
		// sprintf(s, "%f", ray->rot_speed);
		s = ft_itoa(ray->key.rotation_s);
		show_message_menu(1, "ROTATION SPEED :   ", s, ray);
		show_message_menu(2, "BACK TO THE GAME", NULL, ray);
		// mlx_string_put(ray->mlx->ptr, ray->mlx->win, WIDTH / 2, HEIGHT / 2 + 20, create_rgb(0, 255, 0), "MOVE SPEED !");
		// mlx_string_put(ray->mlx->ptr, ray->mlx->win, WIDTH / 2 + 90, HEIGHT / 2 + 20, create_rgb(0, 255, 0), s);
	// }
	// else
		// mlx_string_put(ray->mlx->ptr, ray->mlx->win, WIDTH / 2, HEIGHT / 2 + 20, create_rgb(0, 0, 0), "MOVE SPEED !");
	// if (ray->key.pos_menu == 1)
	// 	mlx_string_put(ray->mlx->ptr, ray->mlx->win, WIDTH / 2, HEIGHT / 2 + 35, create_rgb(0, 255, 0), "HELLO !");
	// else
	// 	mlx_string_put(ray->mlx->ptr, ray->mlx->win, WIDTH / 2, HEIGHT / 2 + 35, create_rgb(0, 0, 0), "HELLO !");
	// mlx_string_put(ray->mlx->ptr, ray->mlx->win, WIDTH / 2, HEIGHT / 2 + 50, create_rgb(0, 0, 0), "HELLO !");
	// mlx_string_put(ray->mlx->ptr, ray->mlx->win, WIDTH / 2, HEIGHT / 2 + 65, create_rgb(0, 0, 0), "HELLO !");
	// mlx_string_put(ray->mlx->ptr, ray->mlx->win, WIDTH / 2, HEIGHT / 2 + 80, create_rgb(0, 0, 0), "HELLO !");
}