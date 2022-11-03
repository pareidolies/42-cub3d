/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:55:23 by jdubilla          #+#    #+#             */
/*   Updated: 2022/11/03 18:56:35 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_wall(char c)
{
	if (c == '1')
		return (1);
	return (0);
}

bool	key_space(t_ray *ray)
{
	if ((ray->frame_time % 5 == 0) && (ray->up == 0))
		ray->levitation = ray->levitation + 10;
	else if ((ray->frame_time % 5 == 0) && (ray->up == 1))
		ray->levitation = ray->levitation - 10;
	if (ray->frame_time % 200 == 0)
		ray->up = (ray->up == 0);
	return (true);
}
