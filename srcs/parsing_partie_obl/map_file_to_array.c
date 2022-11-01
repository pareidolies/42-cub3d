/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file_to_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:36:35 by jdubilla          #+#    #+#             */
/*   Updated: 2022/10/11 15:34:54 by jdubilla         ###   ########.fr       */
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

void	go_to_beginning_of_map(int fd, t_map *data_map)
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

char	*go_to_beginning_of_map_bis(int fd, t_map *data_map)
{
	int		i;
	char	*line;

	i = 0;
	while (i < data_map->start_line)
	{
		line = get_next_line(fd);
		i++;
		if (i == data_map->start_line)
			return (line);
		free(line);
	}
	return (NULL);
}

static void	file_to_array(int fd, t_data *root, t_map *data_map)
{
	char	*line;
	int		i;

	i = 0;
	while (1)
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

	root->map = malloc(sizeof(char *)
			* ((data_map->end_line - data_map->start_line) + 1));
	if (!root->map)
		free_struct_exit(root);
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		check_first_error(root);
		ft_printf("%s: %s\n", map, strerror(errno));
		free_struct_exit(root);
	}
	go_to_beginning_of_map(fd, data_map);
	file_to_array(fd, root, data_map);
}
