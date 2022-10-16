/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 13:49:28 by jdubilla          #+#    #+#             */
/*   Updated: 2022/10/16 16:45:12 by jdubilla         ###   ########.fr       */
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
	free_struct(&root);
	return (0);
}


/*

	Leaks partie sacha

	Segfault si les textures n'existent pas

	Portes, checker qu'elle est entoure de murs ?

	Protection des malloc

*/