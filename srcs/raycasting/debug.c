/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:12:59 by smostefa          #+#    #+#             */
/*   Updated: 2022/10/31 17:13:02 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_map_data(t_data *data)
{
	int	i = 0;
	int	j = 0;

	printf("--- parse map ---\n");
	while (j < data->height)
	{
		i = 0;
		while (i < data->len)
		{
			printf("%c", data->map[j][i]);
			i++;
		}
		printf("\n");
		j++;
	}
	printf("x : %d\n", data->player.x);
	printf("y : %d\n", data->player.y);
}

void	print_map_ray(t_ray *ray, t_data *data)
{
	int	i = 0;
	int	j = 0;

	printf("--- revert map ---\n");
	while (j < data->height)
	{
		i = 0;
		while (i < data->len)
		{
			printf("%c", ray->revert_map[i][j]);
			i++;
		}
		printf("\n");
		j++;
	}
	// printf("x : %d\n", data->player.x);
	// printf("y : %d\n", data->player.y);
}
