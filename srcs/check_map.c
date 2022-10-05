/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:48:48 by jdubilla          #+#    #+#             */
/*   Updated: 2022/10/05 16:02:57 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	len_double_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

static bool	check_around_bis(int i, int j, t_data *root, t_map *data_map)
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
		|| (j - 1 == -1 || j + 1 > data_map->len_line_max)
		|| !check_around_bis(i, j, root, data_map))
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
			root->player.x = i;
			root->player.y = j;
			root->player.dir = root->map[i][j];
		}
		printf("x = %d\ny = %d\n", root->player.x, root->player.y);
	}
}

static void	get_final_arr(t_data *root)
{
	int	i;
	int	j;

	i = 0;
	while (root->map[i])
	{
		j = 0;
		while (root->map[i][j])
		{
			if (root->map[i][j] == 'x')
				root->map[i][j] = '1';
			j++;
		}
		i++;
	}
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
	if (!root->err)
		get_final_arr(root);
}
