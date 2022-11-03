/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_doors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:10:52 by jdubilla          #+#    #+#             */
/*   Updated: 2022/11/03 21:01:08 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	check_around_doors(t_data *root, t_map *data_map, int i, int j)
{
	if (i == 0 || j == 0 || j == (int)ft_strlen(root->map[i]) - 1
		|| i == len_double_array(root->map) - 1)
	{
		check_first_error(root);
		ft_printf("At line %d, pos %d, Les portes ne doivent pas etres\
 en extremite de maps\n", data_map->start_line + i, j + 1);
	}
	else if ((root->map[i][j - 1] != '1' || root->map[i][j + 1] != '1')
		&& (root->map[i - 1][j] != '1' || root->map[i + 1][j] != '1'))
	{
		check_first_error(root);
		ft_printf("At line %d, pos %d, Les portes doivent etres entoures\
 par des murs\n", data_map->start_line + i, j + 1);
	}
	else if (root->map[i][j - 1] == 'x' || root->map[i][j + 1] == 'x'
			|| root->map[i - 1][j] == 'x' || root->map[i + 1][j] == 'x')
	{
		check_first_error(root);
		ft_printf("At line %d, pos %d, Les portes ne doivent pas etres\
 en extremite de maps et doivent etres entoures par des\
murs\n", data_map->start_line + i, j + 1);
	}
}

void	err_parsing_doors(t_data *root, t_map *data_map)
{
	int	i;
	int	j;

	i = 0;
	while (root->map[i])
	{
		j = 0;
		while (root->map[i][j])
		{
			if (root->map[i][j] == '2')
				check_around_doors(root, data_map, i, j);
			j++;
		}
		i++;
	}
}
