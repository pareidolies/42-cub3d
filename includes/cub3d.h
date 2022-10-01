#ifndef CUB3D_H

# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <X11/keysym.h>
# include <stdlib.h>
# include <math.h>

# define WIDTH				400
# define HEIGHT				400
# define TITLE				"cub3d"

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

typedef struct s_data {
	int		nbr_line_data;
	int		len_max;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
}				t_data;

void	init_struct(t_data *root);
void	check_error(int argc, char **argv, t_data *root);
char	*get_next_line(int fd);
char	*ft_get_line(char *left_str);
char	*ft_strchr_gnl(char *s, int c);
char	*ft_new_left_str(char *left_str);
char	*ft_strjoin_gnl(char *left_str, char *buff);



#endif