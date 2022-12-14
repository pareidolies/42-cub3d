/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:35:18 by jdubilla          #+#    #+#             */
/*   Updated: 2022/10/10 18:47:00 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static bool	check_rgb_format_bis(char *rgb)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (rgb[i])
	{
		if (!ft_isdigit(rgb[i]))
			return (false);
		while (ft_isdigit(rgb[i]))
			i++;
		nbr++;
		while (rgb[i] == ' ')
			i++;
		if (nbr == 3 && rgb[i])
			return (false);
		else if (nbr == 3)
			return (true);
		if (rgb[i] != ',')
			return (false);
		i++;
		while (rgb[i] == ' ')
			i++;
	}
	return (false);
}

static bool	check_rgb_format(char *rgb)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (rgb[i])
	{
		if (rgb[i] == ',')
			j++;
		if (rgb[i] != ' ' && !ft_isdigit(rgb[i]) && rgb[i] != ',')
			return (false);
		i++;
	}
	if (j != 2)
		return (false);
	if (!check_rgb_format_bis(rgb))
		return (false);
	return (true);
}

static bool	cpy_str_to_struct(t_data *root, int i, char *res, char *line)
{
	int	j;

	j = 0;
	while (line[i + j])
	{
		res[j] = line[i + j];
		j++;
	}
	res[j] = '\0';
	j = 0;
	while (line[j] == ' ')
		j++;
	if (!check_rgb_format(res))
	{
		if (!root->err)
		{
			root->err = true;
			ft_putstr_fd("Error\n", 2);
		}
		ft_printf("Wrong information at line %d, Format RGB is incorrect\n",
			root->nbr_line_data);
		return (false);
	}
	return (true);
}

static bool	str_rgb_to_int(char c, char *res, t_data *root)
{
	char	**rgb;

	rgb = ft_split(res, " ,");
	if ((ft_atoi(rgb[0]) < 0 || ft_atoi(rgb[0]) > 255)
		|| (ft_atoi(rgb[1]) < 0 || ft_atoi(rgb[1]) > 255)
		|| (ft_atoi(rgb[2]) < 0 || ft_atoi(rgb[2]) > 255))
	{
		if (!root->err)
		{
			root->err = true;
			ft_putstr_fd("Error\n", 2);
		}
		ft_printf("Wrong information at line %d, values must be \
betwen 0 and 255\n", root->nbr_line_data);
		free_double_array(rgb);
		return (false);
	}
	str_rgb_to_struct(root, c, rgb);
	free_double_array(rgb);
	return (true);
}

void	cpy_rgb(t_data *root, char *line)
{
	int		i;
	int		j;
	char	c;
	char	*res;

	i = 0;
	j = 0;
	while (line[i] == ' ')
		i++;
	c = line[i];
	i++;
	while (line[i] == ' ')
		i++;
	while (line[i + j])
		j++;
	res = malloc(sizeof(char) * (j + 1));
	if (!res)
		free_struct_exit(root);
	if (!cpy_str_to_struct(root, i, res, line))
	{
		free(res);
		return ;
	}
	str_rgb_to_int(c, res, root);
	free(res);
}
