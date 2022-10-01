/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:19:48 by jdubilla          #+#    #+#             */
/*   Updated: 2022/10/01 22:17:48 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	check_name(char *map)
{
	int	len;

	len = ft_strlen(map);
	if (len < 5)
	{
		ft_putstr_fd("Error !\nLe nom du fichier doit finir par \".cub\"\n", 2);
		exit(1);
	}
	if (map[len - 4] == '.' && map[len - 3] == 'c' && map[len - 2] == 'u'
		&& map[len - 1] == 'b')
		return ;
	ft_putstr_fd("Error !\nLe nom du fichier doit finir par \".cub\"\n", 2);
	exit(1);
}

// void	check_data_line(char *line, t_data *root)
// {
	
// }

void	check_data(char *map, t_data *root)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nEchec lors de l'ouverture du fichier\n", 2);
		exit(1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		root->nbr_line_data++;
		if (ft_strlen(line) > root->len_max)
			root->len_max = ft_strlen(line);
		// check_data_line(line, root);
	}
}

void	check_error(int argc, char **argv, t_data *root)
{
	if (argc == 1 || argc > 2)
	{
		if (argc == 1)
			ft_putstr_fd("Error !\nPas assez d'arguments\nUsage : ./cub3D ./name.cub\n", 2);
		else
			ft_putstr_fd("Error !\nTrop d'arguments\nUsage : ./cub3D ./name.cub\n", 2);
		exit(1);
	}
	check_name(argv[1]);
	check_data(argv[1], root);
}