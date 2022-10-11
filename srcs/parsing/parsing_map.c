/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:59:53 by jdubilla          #+#    #+#             */
/*   Updated: 2022/10/11 15:43:25 by jdubilla         ###   ########.fr       */
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

static void	error_no_map(t_data *root, int fd, char *map)
{
	check_first_error(root);
	ft_printf("No map detected in %s\n", map);
	close(fd);
	free_struct_exit(root);
}

static void	check_line_befor_map(t_map *data, t_data *root, int fd, char *map)
{
	char	*line;

	line = get_next_line(fd);
	increment_data_line(root, data);
	while (line && ((!line_only_char_map(line) || !ft_strlen(line))
			|| line_only_space(line)))
	{
		if (!line_only_char_map(line) || line_only_space(line))
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
		increment_data_line(root, data);
	}
	if (!line)
		error_no_map(root, fd, map);
	free(line);
	go_end_file(fd);
}

static void	parsing_map(t_map *data_map, t_data *root, char *map)
{
	int		fd;
	char	*line;

	data_map->end_line = data_map->start_line;
	fd = open_file(map, root);
	line = go_to_beginning_of_map_bis(fd, data_map);
	while (line)
	{
		if (!line_only_char_map(line) || (line && !ft_strlen(line)))
		{
			check_first_error(root);
			if (!line_only_char_map(line))
				ft_printf("At line %d, map must contain only one of\
 these characters : 0, 1, N, S, E, W or space\n", data_map->end_line);
			else
				ft_printf("At line %d, map is separated by an empty line\
 or finish with many empty lines\n", data_map->end_line);
		}
		if ((int)ft_strlen(line) > data_map->len_line_max)
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

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		check_first_error(root);
		ft_printf("%s: %s\n", map, strerror(errno));
		free_struct_exit(root);
	}
	go_end_data(data_map, root, fd);
	check_line_befor_map(data_map, root, fd, map);
	parsing_map(data_map, root, map);
	if (data_map->end_line - data_map->start_line <= 2
		|| data_map->len_line_max <= 2)
	{
		check_first_error(root);
		if (data_map->end_line - data_map->start_line <= 2)
			ft_printf("The minimum heigh of the map is\n");
		if (data_map->len_line_max <= 2)
			ft_printf("The minimum lenght of the map is\n");
	}
}
