#ifndef RAYCASTING_H

# define RAYCASTING_H

# include "cub3d.h"

# define FOV 60
# define PI 3.1415926535
# define MOVE_SPEED 0.1
# define ROT_SPEED 0.033 * 1.8

typedef enum	e_hit
{
	WALL,
	EMPTY,
}		        t_hit;

typedef enum    e_side
{
    HORIZONTAL,
    VERTICAL,
}               t_side;

typedef struct s_point {
	int	x;
	int	y;
}				t_point;

typedef struct s_vector {
	double	x;
	double	y;
}				t_vector;

typedef struct s_ray {
	t_vector	pos;
	t_vector	dir;
	t_vector	plan;
	t_vector	raydir;
	double  	camerax;
	t_point     map; //int
	t_vector	sidedist;
	t_vector	deltadist;
	t_point	step; //int
	t_hit	hit;
    t_side  side;
    double  perpwalldist;
    int     lineheight;
    int     drawstart;
    int     drawend;
    int     i;
    double  *buffer;
    int     width;
    int     height;
    char    **revert_map;
}				t_ray;

typedef struct s_mlx {
    void    *ptr;
    void    *win;
    void    *img;
    int     *addr;
    int     bpp;
    int     line_length;
    int     endian;
}               t_mlx;


#endif
