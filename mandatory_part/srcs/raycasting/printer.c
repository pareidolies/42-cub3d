/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:12:59 by smostefa          #+#    #+#             */
/*   Updated: 2022/11/02 08:51:57 by jdubilla         ###   ########.fr       */
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
	printf("x : %d\n", data->player.x);
	printf("y : %d\n", data->player.y);
}


// void	print_doors(t_door *node)
// {
// 	int	i;

// 	i = 0;
// 	printf("\n\n\n---- PRINT DOORS ----\n");
// 	while (node)
// 	{
// 		printf("********\n");
// 		printf("id : %d\n", i);
// 		printf("x : %f\n", node->x);
// 		printf("y : %f\n", node->y);
// 		printf("********\n");
// 		node = node->next;
// 		i++;
// 	}
// }

void	print_buffer(int **buffer)
{
	int	i;
	int	j;

	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			printf("%c", buffer[j][i] = 0);
			i++;
		}
		printf("\n");
		j++;
	}
}
