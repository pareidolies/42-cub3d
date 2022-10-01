/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:19:48 by jdubilla          #+#    #+#             */
/*   Updated: 2022/10/01 21:08:18 by jdubilla         ###   ########.fr       */
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

void	check_data(char *map)
{
	int fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nEchec lors de l'ouverture du fichier\n", 2);
		exit(1);
	}
	
}

void	check_error(int argc, char **argv)
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
	check_data(argv[1]);
}