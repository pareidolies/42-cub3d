/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:35:18 by jdubilla          #+#    #+#             */
/*   Updated: 2022/10/03 15:42:22 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* On regarde deja si le format est respecte :
	- Nombres espacs par une virgules pour chaque nombre
	
	Puis on fait un split avec comme separateur la virgule + espace
	et on attribue a la struct chaque valeur avec un ft_atoi(). 
*/

bool	check_rgb_format_bis(char *rgb, char data, t_data *root)
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

bool	check_rgb_format(char *rgb, char data, t_data *root)
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
	if (!check_rgb_format_bis(rgb, data, root))
		return (false);
	return (true);
}

bool	cpy_str_to_struct(t_data *root, int i, char *res, char *line)
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
	if (!check_rgb_format(res, line[j], root))
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

bool	str_rgb_to_int(char c, char *res, t_data *root)
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
		ft_printf("Wrong information at line %d, Les valeurs doivent etres \
comprises entre 0 et 255\n", root->nbr_line_data);
		free_double_array(rgb);
		return (false);
	}
	if (c == 'C')
	{
		root->c.empty = false;
		root->c.r = ft_atoi(rgb[0]);
		root->c.g = ft_atoi(rgb[1]);
		root->c.b = ft_atoi(rgb[2]);
	}
	else
	{
		root->f.empty = false;
		root->f.r = ft_atoi(rgb[0]);
		root->f.g = ft_atoi(rgb[1]);
		root->f.b = ft_atoi(rgb[2]);
	}
	free_double_array(rgb);
	return (true);
}

void	cpy_rgb(t_data *root, int data, char **arr, char *line)
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