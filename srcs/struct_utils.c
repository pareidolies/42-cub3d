/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 21:58:51 by jdubilla          #+#    #+#             */
/*   Updated: 2022/10/02 19:14:38 by jdubilla         ###   ########.fr       */
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
	root->f = NULL;
	root->c = NULL;
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
	if (root->f)
		free(root->f);
	if (root->c)
		free(root->c);
	exit(1);
}

bool	all_data_set(t_data *root)
{
	if (root->no && root->so && root->we && root->ea && root->f && root->c)
		return (true);
	return (false);
}
