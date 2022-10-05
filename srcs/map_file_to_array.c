/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file_to_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:36:35 by jdubilla          #+#    #+#             */
/*   Updated: 2022/10/05 13:16:06 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static void	cpy_line(char *dest, char *line, t_map *data_map)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			dest[i] = 'x';
		else
			dest[i] = line[i];
		i++;
	}
	while (i < data_map->len_line_max)
		dest[i++] = 'x';
	dest[i] = '\0';
}

static void	go_to_beginning_of_map(int fd, t_map *data_map)
{
	int		i;
	char	*line;

	i = 0;
	while (i < data_map->start_line - 1)
	{
		line = get_next_line(fd);
		free(line);
		i++;
	}
}

static void	file_to_array(int fd, t_data *root, t_map *data_map)
{
	char	*line;
	int		i;

	i = 0;
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		root->map[i] = malloc(sizeof(char) * (data_map->len_line_max + 1));
		if (!root->map[i])
		{
			free(line);
			free_struct_exit(root);
		}
		cpy_line(root->map[i], line, data_map);
		free(line);
		i++;
	}
	root->map[i] = NULL;
	close(fd);
}

void	map_file_to_array(t_map *data_map, char *map, t_data *root)
{
	int		fd;
	char	*line;

	// Pas sur dans le sizeof sion doit mettre char ou char* ici
	root->map = malloc(sizeof(char *) * ((data_map->end_line - data_map->start_line) + 1));
	if (!root->map)
		free_struct_exit(root);
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		/* Ici voir pour renvoyer avec perror la bonne erreur */
		ft_putstr_fd("Error\nEchec lors de l'ouverture du fichier\n", 2);
		exit(1);
	}
	// On passe le infos inutiles pour aller jusqu'au debut de la map
	go_to_beginning_of_map(fd, data_map);
	file_to_array(fd, root, data_map);
	
	// TEST
	// int i = 0;
	// while (root->map[i])
	// 	printf("%s\n", root->map[i++]);
}
