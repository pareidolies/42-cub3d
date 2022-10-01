/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:14:14 by smostefa          #+#    #+#             */
/*   Updated: 2021/12/08 19:34:34 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	d = (unsigned char *)dst;
	while (i < n)
	{
		((unsigned char *)d)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

/*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    int array [] = { 54, 85, 20, 63, 21 };
    int * copy = NULL;
    int length = sizeof( int ) * 5;
       
    // Memory allocation and copy
    copy = (int *) malloc( length );
    ft_memcpy( copy, array, length );
        
    // Display the copied values
    for( length=0; length<5; length++ ) {
        printf( "%d ", copy[ length ] );
    }
    printf( "\n" );
        
    free( copy );
    
    return EXIT_SUCCESS;
}
*/
