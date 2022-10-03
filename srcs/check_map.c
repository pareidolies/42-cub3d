/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:19:48 by jdubilla          #+#    #+#             */
/*   Updated: 2022/10/03 16:54:20 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

static void	check_name(char *map)
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

static void	get_data(t_data *root, char *line, char **arr, char *map)
{
	if (is_data(arr[0]) == 1 && !root->no)
		root->no = ft_strdup(arr[1]);
	else if (is_data(arr[0]) == 2 && !root->so)
		root->so = ft_strdup(arr[1]);
	else if (is_data(arr[0]) == 3 && !root->we)
		root->we = ft_strdup(arr[1]);
	else if (is_data(arr[0]) == 4 && !root->ea)
		root->ea = ft_strdup(arr[1]);
	else if ((is_data(arr[0]) == 5 && root->f.empty)
		|| (is_data(arr[0]) == 6 && root->c.empty))
		cpy_rgb(root, is_data(arr[0]), arr, line);
	else
	{
		if (!root->err)
		{
			root->err = true;
			ft_putstr_fd("Error\n", 2);
		}
		ft_printf("Wrong information on %s at line %d, data : %s is already\
 configured\n", map, root->nbr_line_data, arr[0]);
	}
}

static void	check_data_line(char *line, t_data *root, char *map)
{
	int		data;
	char	**arr;

	// arr = ft_split(line, "' '\t\r\n\v\f");
	arr = ft_split(line, " ");
	data = is_data(arr[0]);
	if ((arr[0] && !data) || (data && !check_format(arr))
		|| whitespace_on_line(arr))
	{
		if (!root->err)
		{
			root->err = true;
			ft_putstr_fd("Error\n", 2);
		}
		if (whitespace_on_line(arr))
			ft_printf("Whitespace detected on %s at line %d (only space is \
accepted)\n", map, root->nbr_line_data);
		else
			ft_printf("Wrong information on %s at line %d\n", map,
				root->nbr_line_data);
	}
	else if (data)
		get_data(root, line, arr, map);
	free_double_array(arr);
}

static void	check_data(char *map, t_data *root)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nEchec lors de l'ouverture du fichier\n", 2);
		exit(1);
	}
	while (!all_data_set(root))
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		root->nbr_line_data++;
		check_data_line(line, root, map);
		free(line);
	}
	if (line)
		go_end_file(fd);
	close(fd);
}

int	check_error(int argc, char **argv, t_data *root)
{
	if (argc == 1 || argc > 2)
	{
		if (argc == 1)
			ft_putstr_fd("Error !\nPas assez d'arguments\nUsage : ./cub3D \
./name.cub\n", 2);
		else
			ft_putstr_fd("Error !\nTrop d'arguments\nUsage : ./cub3D \
./name.cub\n", 2);
		exit(1);
	}
	check_name(argv[1]);
	check_data(argv[1], root);

	// TEST
	// printf("\n");
	// show_data(root);

	if (!all_data_set(root))
		error_missing_data(root);
	// Ici, ajouter la fct check de la map.
	if (root->err)
		return (1);
	return (0);
}
