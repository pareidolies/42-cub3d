/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:40:35 by jdubilla          #+#    #+#             */
/*   Updated: 2022/10/16 17:42:10 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	len_square(t_data *data)
{
	int	res;

	res = 10;
	while ((res * data->len) > WIDTH / 4 || (res * data->height) > HEIGHT / 4)
		res--;
	return (res);
}
