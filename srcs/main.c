/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 13:49:28 by jdubilla          #+#    #+#             */
/*   Updated: 2022/10/05 17:21:25 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	root;

	init_struct(&root);
	if (check_error(argc, argv, &root))
		free_struct_exit(&root);
	start_cub3d(&root);
	free_struct_exit(&root);
	return (0);
}
