/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 21:58:51 by jdubilla          #+#    #+#             */
/*   Updated: 2022/10/01 22:01:19 by jdubilla         ###   ########.fr       */
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
}