/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:01:40 by jdubilla          #+#    #+#             */
/*   Updated: 2022/11/01 00:33:23 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	check_format(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	if ((!ft_strncmp(arr[0], "NO", ft_strlen(arr[0]))
			|| !ft_strncmp(arr[0], "SO", ft_strlen(arr[0]))
			|| !ft_strncmp(arr[0], "WE", ft_strlen(arr[0]))
			|| !ft_strncmp(arr[0], "EA", ft_strlen(arr[0])))
		&& i == 2)
		return (true);
	else if ((!ft_strncmp(arr[0], "F", ft_strlen(arr[0]))
			|| !ft_strncmp(arr[0], "C", ft_strlen(arr[0])))
		&& (i >= 2 && i <= 6))
		return (true);
	return (false);
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

bool	line_only_char_map(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'N'
			&& line[i] != 'S' && line[i] != 'E' && line[i] != 'W'
			&& line[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}
