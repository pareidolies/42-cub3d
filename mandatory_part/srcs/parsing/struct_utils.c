/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 21:58:51 by jdubilla          #+#    #+#             */
/*   Updated: 2022/11/02 09:05:01 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_struct(t_data *root)
{
	root->nbr_line_data = 0;
	root->no = NULL;
	root->so = NULL;
	root->we = NULL;
	root->ea = NULL;
	root->f.empty = true;
	root->c.empty = true;
	root->map = NULL;
	root->err = false;
	root->player.empty = true;
}

void	free_struct_exit(t_data *root)
{
	if (root->no)
		free(root->no);
	if (root->so)
		free(root->so);
	if (root->we)
		free(root->we);
	if (root->ea)
		free(root->ea);
	if (root->map)
		free_double_array(root->map);
	exit(1);
}

void	free_struct(t_data *root)
{
	if (root->no)
		free(root->no);
	if (root->so)
		free(root->so);
	if (root->we)
		free(root->we);
	if (root->ea)
		free(root->ea);
	if (root->map)
		free_double_array(root->map);
}

bool	all_data_set(t_data *root)
{
	if (root->no && root->so && root->we && root->ea
		&& !root->f.empty && !root->c.empty)
		return (true);
	return (false);
}
