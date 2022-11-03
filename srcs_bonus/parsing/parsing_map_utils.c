/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:39:02 by jdubilla          #+#    #+#             */
/*   Updated: 2022/10/11 15:43:31 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	open_file(char *map, t_data *root)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		check_first_error(root);
		ft_printf("%s: %s\n", map, strerror(errno));
		free_struct_exit(root);
	}
	return (fd);
}

void	increment_data_line(t_data *root, t_map *data)
{
	data->start_line++;
	root->nbr_line_data++;
}
