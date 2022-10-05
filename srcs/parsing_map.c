/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:59:53 by jdubilla          #+#    #+#             */
/*   Updated: 2022/10/05 15:28:03 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static void	go_end_data(t_map *data_map, t_data *root, int fd)
{
	char	*line;

	while (data_map->start_line < root->nbr_line_data)
	{
		line = get_next_line(fd);
		free(line);
		data_map->start_line++;
	}
}

static void	error_no_map(t_data *root, int fd)
{
	check_first_error(root);
	ft_printf("Err parsing, pas de map dans le fichier\n", root->nbr_line_data);
	close(fd);
	free_struct_exit(root);
}

static void	check_line_befor_map(t_map *data, t_data *root, int fd, char *map)
{
	char	*line;

	line = get_next_line(fd);
	data->start_line++;
	root->nbr_line_data++;
	while (line && ((!line_only_char_map(line) || !ft_strlen(line))
			|| line_only_space(line, root)))
	{
		if (!line_only_char_map(line) || line_only_space(line, root))
		{
			check_first_error(root);
			if (!line_only_char_map(line))
				ft_printf("Wrong information at line %d\n", root->nbr_line_data);
			else
				ft_printf("Line contains only space on %s at line %d\n",
					map, root->nbr_line_data);
		}
		free(line);
		line = get_next_line(fd);
		data->start_line++;
		root->nbr_line_data++;
	}
	if (!line)
		error_no_map(root, fd);
	free(line);
}

static void	parsing_map(t_map *data_map, t_data *root, int fd, char *map)
{
	char	*line;

	data_map->end_line = data_map->start_line;
	line = get_next_line(fd);
	data_map->end_line++;
	root->nbr_line_data++;
	while (line)
	{
		if (!line_only_char_map(line) || (line && !ft_strlen(line)))
		{
			check_first_error(root);
			if (!line_only_char_map(line))
				ft_printf("Err parsing at line %d, la map doit contenir uniquem\
ent l'un de ces caracteres : 0, 1, N, S, E, W ou espace\n", data_map->end_line);
			else
				ft_printf("Err parsing at line %d, la map est separee par une l\
igne vide ou finit par plusieurs lignes vide\n", data_map->end_line);
		}
		if (ft_strlen(line) > data_map->len_line_max)
			data_map->len_line_max = ft_strlen(line);
		only_space(line, root, map);
		free(line);
		line = get_next_line(fd);
		data_map->end_line++;
		root->nbr_line_data++;
	}
	close(fd);
}

void	check_map(t_map *data_map, t_data *root, char *map)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nEchec lors de l'ouverture du fichier\n", 2);
		exit(1);
	}
	go_end_data(data_map, root, fd);
	check_line_befor_map(data_map, root, fd, map);
	parsing_map(data_map, root, fd, map);
	if (data_map->end_line - data_map->start_line <= 2
		|| data_map->len_line_max <= 2)
	{
		check_first_error(root);
		if (data_map->end_line - data_map->start_line <= 2)
			ft_printf("La carte doit avoir une hauteur minimal de 3\n");
		if (data_map->len_line_max <= 2)
			ft_printf("La carte doit avoir une largeur minimal de 3\n");
	}
}
