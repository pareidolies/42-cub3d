/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_utils_bis.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:20:31 by jdubilla          #+#    #+#             */
/*   Updated: 2022/11/01 00:31:39 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	error_missing_data(t_data *root)
{
	if (!root->err)
	{
		root->err = true;
		ft_putstr_fd("Error\n", 2);
	}
	if (!root->no)
		ft_printf("Data : NO is missing\n");
	if (!root->so)
		ft_printf("Data : SO is missing\n");
	if (!root->we)
		ft_printf("Data : WE is missing\n");
	if (!root->ea)
		ft_printf("Data : EA is missing\n");
	if (root->f.empty)
		ft_printf("Data : F is missing\n");
	if (root->c.empty)
		ft_printf("Data : C is missing\n");
	free_struct_exit(root);
}

void	go_end_file(int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
	}
	close(fd);
}

void	check_first_error(t_data *root)
{
	if (!root->err)
	{
		root->err = true;
		ft_putstr_fd("Error\n", 2);
	}
}

bool	only_space(char *line, t_data *root, char *map)
{
	int	i;

	i = 0;
	if (line[i] != ' ')
		return (false);
	while (line[i] == ' ')
		i++;
	if (line[i])
		return (false);
	check_first_error(root);
	ft_printf("Line contains only space on %s at line %d\n",
		map, root->nbr_line_data);
	return (true);
}

bool	line_only_space(char *line)
{
	int	i;

	i = 0;
	if (line[i] != ' ')
		return (false);
	while (line[i] == ' ')
		i++;
	if (line[i])
		return (false);
	return (true);
}
