/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:48:58 by jdubilla          #+#    #+#             */
/*   Updated: 2022/10/11 16:49:00 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}


	// 0 default
	// 1 rouge
	// 2 jaune
	// 3 vert
	// 4 bleu
	// 5 gris
	// 6 noir
	// 7 blanc

int	get_color(int color, t_ray *ray, char c)
{
	if (color == 0)
	{
		if (c == 'c')
			return (create_rgb(ray->data->c.r, ray->data->c.g, ray->data->c.b));
		return (create_rgb(ray->data->f.r, ray->data->f.g, ray->data->f.b));
	}
	else if (color == 1)
		return (create_rgb(255, 0, 0));
	else if (color == 2)
		return (create_rgb(255, 255, 0));
	else if (color == 3)
		return (create_rgb(0, 255, 0));
	else if (color == 4)
		return (create_rgb(0, 0, 255));
	else if (color == 5)
		return (create_rgb(128, 128, 128));
	else if (color == 6)
		return (create_rgb(0, 0, 0));
	return (create_rgb(255, 255, 255));
}
