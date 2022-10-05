/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:19:48 by jdubilla          #+#    #+#             */
/*   Updated: 2022/10/05 13:18:07 by jdubilla         ###   ########.fr       */
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

	if (only_space(line, root, map))
		return ;
	arr = ft_split(line, " ");
	data = is_data(arr[0]);
	if ((arr[0] && !data) || (data && !check_format(arr))
		|| whitespace_on_line(arr))
	{
		check_first_error(root);
		if (whitespace_on_line(arr))
			ft_printf("Whitespace detected on %s at line %d (only space is \
accepted)\n", map, root->nbr_line_data);
		else
			ft_printf("Wrong information on %s at line %d\n", map,
				root->nbr_line_data);
	}
	// else if (data)
	else if (data && !whitespace_on_line(arr))
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
		/* Ici voir pour renvoyer avec perror la bonne erreur */
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
}





bool	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}

bool	is_space_or_player(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}

int	len_double_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

/*	Dans le parsing, il faut rmplacer les espaces et terminer les lignes 
	< a la la len max par un autre char que 1 sinon des erreurs peuvent
	ne pas etres detectes */
void	check_around(int i, int j, t_data *root, t_map *data_map)
{
	if ((i - 1 == -1 || i + 2 > len_double_array(root->map))
		|| (j - 1 == -1 || j + 1 > data_map->len_line_max))
	{
		check_first_error(root);
		ft_printf("At line %d, pos %d, map must be enclosed by walls\n", data_map->start_line + i, j + 1);
	}
	else if (is_player(root->map[i][j]))
	{
		if (!root->pos_player.empty)
		{
			check_first_error(root);
			ft_printf("At line %d, pos %d, there is many players on ths map\n", data_map->start_line + i, j + 1);
		}
		else
		{
			root->pos_player.empty = false;
			root->pos_player.x = j;
			root->pos_player.y = i;
			root->pos_player.dir = root->map[i][j];
			// TEST
			// printf("x = %d\ny = %d\nchar = %c\n", root->pos_player.x, root->pos_player.y, root->pos_player.dir);
		}
	}
}

void	check_array(t_data *root, t_map *data_map)
{
	int	i;
	int	j;

	i = 0;
	while (root->map[i])
	{
		j = 0;
		while (root->map[i][j])
		{
			if (is_space_or_player(root->map[i][j]))
				check_around(i, j, root, data_map);
			j++;
		}
		i++;
	}
}

/*	Peut etre voir pour muter le erreurs de maps si toutes le data ne
	son pas entrees par l'utilisateur (pour ne pas avoir trop d'errurs)*/
int	check_error(int argc, char **argv, t_data *root)
{
	t_map	data_map;

	init_struct_map(&data_map);
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
	if (!all_data_set(root))
		error_missing_data(root);
	check_map(&data_map, root, argv[1]);
	if (root->err)
		return (1);
	map_file_to_array(&data_map, argv[1], root);
	check_array(root, &data_map);
	return (0);
}
