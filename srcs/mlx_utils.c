#include "../includes/cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}