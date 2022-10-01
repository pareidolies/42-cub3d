#include "../includes/cub3d.h"

int main(int argc, char **argv)
{
	t_data	root;

	init_struct(&root);
	check_error(argc, argv, &root);
	return (0);
}
