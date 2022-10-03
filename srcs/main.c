/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 13:49:28 by jdubilla          #+#    #+#             */
/*   Updated: 2022/10/03 16:41:39 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	root;

	init_struct(&root);
	if (check_error(argc, argv, &root))
		free_struct_exit(&root);
	free_struct_exit(&root);
	return (0);
}

/*	A voir avec Sacha :

	- Lignes vides mais avec des espaces = erreur ?
	
	- Petit probleme de Makefile : n'affiche pas les warnings et
	ne les transforment pas en erreur (genre une variable qu'on utilise pas).
	
	- Voir si on compte les whitespaces comme des espaces ou non, car si
	on les considerent comme des espaces (pour les data), on doit aussi le faire a
	l'interieur de la map pour rester coherent mais c'est chelou d'avoir des tabulations
	ou autres a l'interieur de la map.... Sur discord c'est partage mais il est dit que
	dans le sujet on nous parle uniquement d'espaces et pas de whitespace donc a
	voir..
	
	- Est ce que "S    O   ./path_to_the_south_texture" est une erreur ? */