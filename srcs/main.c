/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 13:49:28 by jdubilla          #+#    #+#             */
/*   Updated: 2022/10/15 18:55:30 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	root;

	init_struct(&root);
	if (check_error(argc, argv, &root))
		free_struct_exit(&root);
	// printf("D = %s\n", root.d);
	// for(int i = 0; root.map[i]; i++)
		// printf("%s\n", root.map[i]);
	start_raycasting(&root);
	free_struct(&root);
	return (0);
}


/*

	Leaks OK

	Segfault move_mouse OK par contre, effectivement si on cache le curseur,
	la fonction mlx_mouse_hide cree des leaks (elle est en commentaire dans start.c).
	Ce qu'on poura faire pour la correction c'est mettre la fonction en commentaire (a la norme)
	et expliquer aux correcteurs le pb.

	Latence en plein ecran (2560 x 1440)

	Protection des malloc

*/