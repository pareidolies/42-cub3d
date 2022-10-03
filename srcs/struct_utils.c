/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 21:58:51 by jdubilla          #+#    #+#             */
/*   Updated: 2022/10/03 15:20:22 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_struct(t_data *root)
{
	root->nbr_line_data = 0;
	root->len_max = 0;
	root->no = NULL;
	root->so = NULL;
	root->we = NULL;
	root->ea = NULL;
	root->f.empty = true;
	root->c.empty = true;
	root->err = false;
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
	exit(1);
}

bool	all_data_set(t_data *root)
{
	if (root->no && root->so && root->we && root->ea
		&& !root->f.empty && !root->c.empty)
		return (true);
	return (false);
}


// A Supprimer
void	show_data(t_data *root)
{
	printf("nbr_line = %d\n", root->nbr_line_data);
	printf("len_max = %d\n", root->len_max);
	printf("no = %s\n", root->no);
	printf("so = %s\n", root->so);
	printf("we = %s\n", root->we);
	printf("ea = %s\n", root->ea);
	printf("f = %d %d %d %d\n", root->f.empty, root->f.r, root->f.g, root->f.b);
	printf("c = %d %d %d %d\n", root->c.empty, root->c.r, root->c.g, root->c.b);
	printf("err = %d\n", root->err);
}