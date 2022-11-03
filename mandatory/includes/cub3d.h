/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 13:48:55 by jdubilla          #+#    #+#             */
/*   Updated: 2022/11/02 09:16:22 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"

# include <stdbool.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>

/******************************************************************************
 *                                 MACROS                                     *
 *****************************************************************************/

// # define WIDTH 450
// # define HEIGHT 900
// # define WIDTH 2560
// # define HEIGHT 1440
# define WIDTH 1920
# define HEIGHT 1080
# define TITLE "cub3D"

# define FOV 60
# define PI 3.1415926535
// # define MOVE_SPEED 0.1
// # define ROT_SPEED 0.033 * 1.8

# define MOVE_FORWARD 119
# define MOVE_BACKWARD 115
# define MOVE_RIGHTWARD 100
# define MOVE_LEFTWARD 97
# define ROTATE_RIGHT 65363
# define ROTATE_LEFT 65361
# define ESC 65307
# define SPACE 32
# define TAB 65289

# define DEFAULT 0
# define RED 1
# define YELLOW 2
# define GREEN 3
# define BLUE 4
# define GREY 5
# define BLACK 6
# define WHITE 7

# define ANSI_COLOR_BLUE			"\x1b[94m"
# define ANSI_COLOR_LIGHT_WHITE		"\x1b[97m"
# define ANSI_COLOR_LIGHT_RED		"\x1b[91m"
# define ANSI_COLOR_RESET			"\x1b[0m"

# define M1			"\n--------------- MANUAL ---------------\n\n"
# define M11			"--------------------------------------\n\n"

# define GOODBYE	"\nSee you soon !\n\n"

# define MALLOC_MSSG	"Error\nA malloc error occurred.\n"
# define MLX_MSSG	"Error\nAn mlx error occurred.\n"
# define IMG_MSSG	"Error\nWe could not load the image.\n"


/******************************************************************************
*                              ENUMERATIONS                                   *
******************************************************************************/

typedef enum e_hit
{
	WALL,
	EMPTY,
}			t_hit;

typedef enum e_side
{
	HORIZONTAL,
	VERTICAL,
}			t_side;

/******************************************************************************
 *                               STRUCTURES                                   *
 *****************************************************************************/

typedef struct s_point {
	int	x;
	int	y;
}				t_point;

typedef struct s_vector {
	double	x;
	double	y;
}				t_vector;

typedef struct s_player {
	bool	empty;
	int		x;
	int		y;
	char	dir;
}				t_player;

typedef struct s_map {
	int	len_line_max;
	int	start_line;
	int	end_line;
}				t_map;

typedef struct s_rgb {
	bool	empty;
	int		r;
	int		g;
	int		b;
}				t_rgb;

typedef struct s_data {
	int				nbr_line_data;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*d;
	t_rgb			f;
	t_rgb			c;
	char			**map;
	t_player		player;
	int				height;
	int				len;
	bool			err;
}				t_data;

typedef struct s_mlx {
	void	*ptr;
	void	*win;
	void	*img;
	int		*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_mlx;

typedef struct s_key {
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	rr;
	bool	rl;
	bool	mouse_l;
	bool	mouse_r;
	bool	menu;
	bool	space;
	int		pos_menu;
	int		move_s;
	int		rotation_s;
}				t_key;

typedef struct s_xpm {
	int		**buffer;
	int		width; //enlever
	int		height; //enlever
	int		id;
	double	step;
	double	pos;
	t_point	tex;
}		t_xpm;

typedef struct s_coordinates
{
	double	x;
	double	y;
	int		texture;
}				t_coordinates;

typedef struct s_sprite {
	int				*order;
	double			*distance;
	int				nbr;
	t_coordinates	*tab;
	t_vector		transform;
	double			invdet;
	int				screenx;
	int				height;
	int				width;
	t_point			drawstart;
	t_point			drawend;
	t_point			tex;
	int				d;
	int				color;
}				t_sprite;

typedef struct s_texture {
	int	*tab;
	int	width;
	int	height;
}			t_texture;

typedef struct s_ray {
	t_mlx		*mlx;
	t_data		*data;
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
	t_vector	raydir;
	double		camerax;
	t_point		map; //int
	t_vector	sidedist;
	t_vector	deltadist;
	t_point		step; //int
	t_hit		hit;
	t_side		side;
	double		perpwalldist;
	double		wallx; //where exactly the wall was hit
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			i;
	char		**revert_map;
	t_key		key;
	int			ceiling_color;
	int			floor_color;
	// t_img		img_menu;
	double		move_speed;
	double		rot_speed;
	t_texture	texture[10];
	t_xpm		*xpm;
	double		zbuffer[WIDTH]; //for sprites
	//ANIMATION
	double			levitation;
	double			levitationscreen;
	long		frame_time;
	int			up;
	//FLOOR
	t_vector	raydir0;
	t_vector	raydir1;
	double		rowdistance;
	t_vector	floorstep;
	t_vector	floor;
	t_point		cell;
	int			color_ceiling;
	int			color_floor;
}				t_ray;

/******************************************************************************
 *                               FUNCTIONS                                    *
 *****************************************************************************/

//parsing.c
int		is_data(char *data);
int		open_file(char *map, t_data *root);
int		check_useless_wall_width(t_data *root);
int		check_useless_wall_height(t_data *root);
int		check_error(int argc, char **argv, t_data *root);

char	*get_next_line(int fd);
char	*ft_get_line(char *left_str);
char	*ft_strchr_gnl(char *s, int c);
char	*ft_new_left_str(char *left_str);
char	*ft_strjoin_gnl(char *left_str, char *buff);
char	*go_to_beginning_of_map_bis(int fd, t_map *data_map);

void	go_end_file(int fd);
void	show_data(t_data *root);
void	init_struct(t_data *root);
void	free_struct(t_data *root);
void	free_double_array(char **arr);
void	show_data_map(t_map *data_map);
void	free_struct_exit(t_data *root);
void	check_first_error(t_data *root);
void	init_struct_map(t_map *data_map);
void	error_missing_data(t_data *root);
void	cpy_rgb(t_data *root, char *line);
void	free_uselsee_wall(t_data *root, int pos);
void	check_array(t_data *root, t_map *data_map);
void	increment_data_line(t_data *root, t_map *data);
void	go_to_beginning_of_map(int fd, t_map *data_map);
void	check_map(t_map *data_map, t_data *root, char *map);
void	str_rgb_to_struct(t_data *root, char c, char **rgb);
void	map_file_to_array(t_map *data_map, char *map, t_data *root);

bool	is_player(char c);
bool	check_format(char **arr);
bool	is_space_or_player(char c);
bool	all_data_set(t_data *root);
bool	line_only_space(char *line);
bool	line_only_char_map(char *line);
bool	whitespace_on_line(char **arr);
bool	only_space(char *line, t_data *root, char *map);

//start.c
int		start_raycasting(t_data *data);

//initialize.c
void	initialize_all_values(t_ray *ray);
int		initialize_mlx(t_mlx *mlx);
int		initialize_buffer(t_ray *ray);
void	clear_buffer(int **buffer);

//data.c
void	transpose_parsed_map_to_ray(t_ray *ray, t_data *data);
void	get_dir(t_ray *ray, t_data *data);
void	get_plane(t_ray *ray, t_data *data);
void	transpose_parsed_data_to_ray(t_ray *ray, t_data *data);

//raycasting.c
void	initialize_ray_i(t_ray *ray);
// void	print_results_on_screen(t_ray *ray, t_mlx *mlx);
void	print_results_on_screen(t_ray *ray);
int		launch_raycasting(t_ray *ray, t_mlx *mlx);

//computation.c
void	compute_deltadist(t_ray *ray);
void	compute_sidedist(t_ray *ray);
void	compute_perpwalldist(t_ray *ray);
void	compute_line_attributes(t_ray *ray);

//debug.c
void	print_map_data(t_data *data);
void	print_map_ray(t_ray *ray, t_data *data);

//mlx_utils.c
int		create_trgb(int t, int r, int g, int b);
int		create_rgb(int r, int g, int b);

//hooks.c
int		key_press(int keycode, t_ray *ray);
void	exit_safe(t_ray *ray);
int		move(t_ray *ray);
bool	rotate(t_ray *ray, bool reload);
int		key_release(int keycode, t_ray *ray);
int		len_double_array(char **arr);


//textures.c
t_texture	xpm_to_img(t_ray *ray, char *path, t_mlx *mlx);
int		get_textures(t_ray *ray);
void	compute_wallx(t_ray *ray);
void	direction(int keycode, t_ray *ray);


//exit.c
void	free_double_array_int(int **arr);
void	free_all(t_ray * ray);
int	get_color(int color, t_ray *ray, char c);

#endif
