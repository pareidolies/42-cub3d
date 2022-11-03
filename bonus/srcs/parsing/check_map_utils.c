/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:48:37 by jdubilla          #+#    #+#             */
/*   Updated: 2022/11/01 22:36:30 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}

bool	is_space_or_player(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == '3' || c == '4')
		return (true);
	return (false);
}

int	check_useless_wall_width(t_data *root)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	res = 0;
	while (root->map[i])
	{
		j = 0;
		while (root->map[i][j])
		{
			if (is_space_or_player(root->map[i][j]) && res < j)
				res = j;
			j++;
		}
		i++;
	}
	return (res);
}

int	check_useless_wall_height(t_data *root)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	res = 0;
	while (root->map[i])
	{
		j = 0;
		while (root->map[i][j])
		{
			if (is_space_or_player(root->map[i][j]))
				res = i;
			j++;
		}
		i++;
	}
	return (res);
}

void	free_uselsee_wall(t_data *root, int pos)
{
	pos += 2;
	while (root->map[pos])
		free(root->map[pos++]);
}
