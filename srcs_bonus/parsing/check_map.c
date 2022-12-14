/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:48:48 by jdubilla          #+#    #+#             */
/*   Updated: 2022/11/01 23:04:33 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	len_double_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

static bool	check_around_bis(int i, int j, t_data *root)
{
	if (root->map[i - 1][j - 1] == 'x' || root->map[i - 1][j] == 'x'
		|| root->map[i - 1][j + 1] == 'x')
		return (false);
	else if (root->map[i + 1][j - 1] == 'x' || root->map[i + 1][j] == 'x'
		|| root->map[i + 1][j + 1] == 'x')
		return (false);
	else if (root->map[i][j - 1] == 'x' || root->map[i][j + 1] == 'x')
		return (false);
	return (true);
}

static void	check_around(int i, int j, t_data *root, t_map *data_map)
{
	if ((i - 1 == -1 || i + 2 > len_double_array(root->map))
		|| (j - 1 == -1 || j + 1 >= data_map->len_line_max)
		|| !check_around_bis(i, j, root))
	{
		check_first_error(root);
		ft_printf("At line %d, pos %d, map must be enclosed by walls\n",
			data_map->start_line + i, j + 1);
	}
	else if (is_player(root->map[i][j]))
	{
		if (!root->player.empty)
		{
			check_first_error(root);
			ft_printf("At line %d, pos %d, there is many players on ths map\n",
				data_map->start_line + i, j + 1);
		}
		else
		{
			root->player.empty = false;
			root->player.x = j;
			root->player.y = i;
			root->player.dir = root->map[i][j];
		}
	}
}

static void	get_final_arr(t_data *root)
{
	int	i;
	int	j;
	int	max_width;
	int	max_height;

	i = 0;
	max_width = check_useless_wall_width(root);
	max_height = check_useless_wall_height(root);
	while (i < max_height + 2)
	{
		j = 0;
		while (j < max_width + 2)
		{
			if (root->map[i][j] == 'x')
				root->map[i][j] = '1';
			j++;
		}
		root->map[i][j] = '\0';
		i++;
	}
	free_uselsee_wall(root, max_height);
	root->map[i] = NULL;
	root->len = ft_strlen(root->map[0]);
	root->height = len_double_array(root->map);
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
	if (root->player.empty)
	{
		check_first_error(root);
		ft_printf("No player detected on the map\n");
		free_struct_exit(root);
	}
	if (root->err)
		free_struct_exit(root);
	err_parsing_doors(root, data_map);
	get_final_arr(root);
}
