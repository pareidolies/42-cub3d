/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 13:49:28 by jdubilla          #+#    #+#             */
/*   Updated: 2022/11/02 09:41:30 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	root;

	init_struct(&root);
	if (check_error(argc, argv, &root) || root.err)
		free_struct_exit(&root);
	// printf("D = %s\n", root.d);
	// for(int i = 0; root.map[i]; i++)
		// printf("%s\n", root.map[i]);
	// printf("TEST\n");
	start_raycasting(&root);
	// free_struct(&root);
	return (0);
}


/*

	Leaks partie sacha

	Ecrire sur la sortie erreur

	Segfault si les textures n'existent pas

	Recuperer le PATH des portes depuis le fichier et non directement dans le code comme actuellement

*/