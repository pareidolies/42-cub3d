/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 19:20:52 by jdubilla          #+#    #+#             */
/*   Updated: 2022/11/02 08:40:14 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	direction(int keycode, t_ray *ray)
{
	if (keycode == MOVE_FORWARD)
		ray->key.w = true;
	if (keycode == MOVE_BACKWARD)
		ray->key.s = true;
	if (keycode == MOVE_LEFTWARD)
		ray->key.a = true;
	if (keycode == MOVE_RIGHTWARD)
		ray->key.d = true;
	if (keycode == ROTATE_LEFT)
		ray->key.rl = true;
	if (keycode == ROTATE_RIGHT)
		ray->key.rr = true;
}
