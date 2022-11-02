/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:23:19 by jdubilla          #+#    #+#             */
/*   Updated: 2022/10/03 16:29:42 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	str_rgb_to_struct(t_data *root, char c, char **rgb)
{
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
}
