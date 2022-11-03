/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:55:34 by jdubilla          #+#    #+#             */
/*   Updated: 2022/10/05 15:30:45 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	show_data_map(t_map *data_map)
{
	printf("len_line_max = %d\n", data_map->len_line_max);
	printf("start_line = %d\n", data_map->start_line);
	printf("end_line = %d\n", data_map->end_line);
}

void	init_struct_map(t_map *data_map)
{
	data_map->len_line_max = 0;
	data_map->start_line = 0;
	data_map->end_line = 0;
}
