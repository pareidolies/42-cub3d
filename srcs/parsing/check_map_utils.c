/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:48:37 by jdubilla          #+#    #+#             */
/*   Updated: 2022/10/09 17:46:38 by jdubilla         ###   ########.fr       */
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
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
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
	return(res);
}

