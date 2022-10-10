/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 13:49:28 by jdubilla          #+#    #+#             */
/*   Updated: 2022/10/10 15:27:26 by jdubilla         ###   ########.fr       */
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
	(a voir si pb sacha sinon je peux regler le pb sur la minimap)

	Latence en plein ecran (2560 x 1440)

	Spawn de travers avec les lettres 'N' et 'S' et pas les
	bonnes  direction de spawn avec 'E' et 'W' 
	
	Segfault move_mouse	*/