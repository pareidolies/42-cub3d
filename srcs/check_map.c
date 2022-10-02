/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:19:48 by jdubilla          #+#    #+#             */
/*   Updated: 2022/10/02 19:16:15 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

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

void	get_data(t_data *root, int data, char **arr, char *map)
{
	if (data == 1 && !root->no)
		root->no = ft_strdup(arr[1]);
	else if (data == 2 && !root->so)
		root->so = ft_strdup(arr[1]);
	else if (data == 3 && !root->we)
		root->we = ft_strdup(arr[1]);
	else if (data == 4 && !root->ea)
		root->ea = ft_strdup(arr[1]);
	else if (data == 5 && !root->f)
		root->f = ft_strdup(arr[1]);
	else if (data == 6 && !root->c)
		root->c = ft_strdup(arr[1]);
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

void	check_data_line(char *line, t_data *root, char *map)
{
	int		data;
	char	**arr;

	/*	Pour ici, a voir si on compte les whitespaces comme des espaces ou non, car si
		on les considerent comme des espaces (pour les data), on doit aussi le faire a
		l'interieur de la map pour rester coherent mais c'est chelou d'avoir des tabulations
		ou autres a l'interieur de la map.... Sur discord c'est partage mais il est dit que
		dans le sujet on nous parle uniquement d'espaces et pas de whitespace donc a
		voir.. */
	// arr = ft_split(line, "' '\t\r\n\v\f");
	arr = ft_split(line, " ");
	
	// TEST
	// for (int i = 0; arr[i]; i++)
	// 	printf("arr[%d] = %s\n", i, arr[i]);
	// if (arr)
	// 	printf("\n");
	
	data = is_data(arr[0]);
	if ((arr[0] && !data) || (data && len_double_array(arr) != 2)
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
		get_data(root, data, arr, map);
	free_double_array(arr);
}

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
	// Pour la condition du while, peut etre ca plus des que je detecte que les
	// caracteres corespondent au parsing de a map
	while (!all_data_set(root))
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		root->nbr_line_data++;
		if (ft_strlen(line) > root->len_max)
			root->len_max = ft_strlen(line);
		check_data_line(line, root, map);
		free(line);
	}
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
	// Ici, ajouter la fct check de la map.
	if (root->err)
		return (1);
	return (0);
}
