/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:21:41 by smostefa          #+#    #+#             */
/*   Updated: 2022/04/08 12:10:41 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	int				i;

	str = b;
	i = 0;
	while (len > 0)
	{
		str[i] = (unsigned char) c;
		i++;
		len--;
	}
	return (b);
}

/*

#include <stdio.h>
#include <string.h>

int main() {

    int array [] = { 54, 85, 20, 63, 21 };
    size_t size = sizeof( int ) * 5;
    int length;

    //Display the initial values
    for( length=0; length<5; length++) {
        printf( "%d ", array[ length ] );
    }
    printf( "\n" );

    //Reset the memory bloc
    ft_memset( array, 0, size );

    //Display the new values
    for( length=0; length<5; length++) {
        printf( "%d ", array[ length ] );
    }
    printf( "\n" );
    
    return 0;
}

*/
