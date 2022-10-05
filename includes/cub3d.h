/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 13:48:55 by jdubilla          #+#    #+#             */
/*   Updated: 2022/10/05 13:05:50 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include "raycasting.h"
# include <stdbool.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

# define WIDTH				800
# define HEIGHT				800
# define TITLE				"cub3D"

# define ANSI_COLOR_BLUE			"\x1b[94m"
# define ANSI_COLOR_LIGHT_WHITE		"\x1b[97m"
# define ANSI_COLOR_LIGHT_RED		"\x1b[91m"
# define ANSI_COLOR_RESET			"\x1b[0m"

# define M1			"\n--------------- MANUAL ---------------\n\n"
# define M11			"--------------------------------------\n\n"

# define GOODBYE	"\nSee you soon !\n\n"

# define ESC_KEY			65307
# define LEFT_KEY			65361
# define RIGHT_KEY			65363
# define UP_KEY				65362
# define DOWN_KEY			65364
# define SPACE_KEY			32
# define TAB_KEY			65289
# define ZOOM_IN_KEY		4
# define ZOOM_OUT_KEY		5

typedef struct s_pos_player {
	bool	empty;
	int		x;
	int		y;
	char	dir;
}				t_pos_player;

typedef	struct s_map {
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

/*	Pour l'instant, je check pas les path des textures (no so) ...
	car je crois que la fonction de la mlx renvoie une erreur si les fichiers
	n'existe pas, sinon je pourrais toujours le faire dans mon parsing */
typedef struct s_data {
	int				nbr_line_data;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	t_rgb			f;
	t_rgb			c;
	char			**map;
	t_pos_player	pos_player;
	bool	err;
}				t_data;

typedef struct s_all {
    t_mlx   *mlx;
    t_ray   *ray;
    t_data  *data;
}               t_all;

int		is_data(char *data);
int		check_error(int argc, char **argv, t_data *root);

char	*get_next_line(int fd);
char	*ft_get_line(char *left_str);
char	*ft_strchr_gnl(char *s, int c);
char	*ft_new_left_str(char *left_str);
char	*ft_strjoin_gnl(char *left_str, char *buff);

void	go_end_file(int fd);
void	show_data(t_data *root);
void	init_struct(t_data *root);
void	free_double_array(char **arr);
void	show_data_map(t_map *data_map);
void	free_struct_exit(t_data *root);
void	check_first_error(t_data *root);
void	init_struct_map(t_map *data_map);
void	error_missing_data(t_data *root);
void	check_map(t_map *data_map, t_data *root, char *map);
void	str_rgb_to_struct(t_data *root, char c, char **rgb);
void	cpy_rgb(t_data *root, int data, char **arr, char *line);
void	map_file_to_array(t_map *data_map, char *map, t_data *root);

bool	check_format(char **arr);
bool	line_only_char_map(char* line);
bool	all_data_set(t_data *root);
bool	whitespace_on_line(char **arr);
bool	only_space(char *line, t_data *root, char *map);

#endif