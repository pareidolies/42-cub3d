/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils_bis.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:20:31 by jdubilla          #+#    #+#             */
/*   Updated: 2022/10/03 14:47:30 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	error_missing_data(t_data *root)
{
	if (!root->err)
	{
		root->err = true;
		ft_putstr_fd("Error\n", 2);
	}
	if (!root->no)
		ft_printf("Data : NO is missing\n");
	if (!root->so)
		ft_printf("Data : SO is missing\n");
	if (!root->we)
		ft_printf("Data : WE is missing\n");
	if (!root->ea)
		ft_printf("Data : EA is missing\n");
	if (root->f.empty)
		ft_printf("Data : F is missing\n");
	if (root->c.empty)
		ft_printf("Data : C is missing\n");
	free_struct_exit(root);
}
