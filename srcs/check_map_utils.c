/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:01:40 by jdubilla          #+#    #+#             */
/*   Updated: 2022/10/02 19:13:53 by jdubilla         ###   ########.fr       */
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

void	free_double_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int	is_data(char *data)
{
	if (!data)
		return (0);
	else if (!ft_strncmp(data, "NO", ft_strlen(data)))
		return (1);
	else if (!ft_strncmp(data, "SO", ft_strlen(data)))
		return (2);
	else if (!ft_strncmp(data, "WE", ft_strlen(data)))
		return (3);
	else if (!ft_strncmp(data, "EA", ft_strlen(data)))
		return (4);
	else if (!ft_strncmp(data, "F", ft_strlen(data)))
		return (5);
	else if (!ft_strncmp(data, "C", ft_strlen(data)))
		return (6);
	return (0);
}

bool	whitespace_on_line(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (ft_isspace_without_space(arr[i][j]))
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

bool	is_char_map(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W' || c == ' ')
		return (true);
	return (false);
}
