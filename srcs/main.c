/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 13:49:28 by jdubilla          #+#    #+#             */
/*   Updated: 2022/10/08 14:38:06 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	root;

	init_struct(&root);
	if (check_error(argc, argv, &root))
		free_struct_exit(&root);
	// for(int i = 0; root.map[i]; i++)
	// 	printf("%s\n", root.map[i]);
	start_raycasting(&root);
	free_struct_exit(&root);
	return (0);
}


/*	Il faut appuyer sur 'e' pour afficher la minimap

	Pb minimap, on rentre dans les murs en ouest et est

	Latence en plein ecran (2560 x 1440)

	Spawn de travers avec les lettres 'N' et 'S' */