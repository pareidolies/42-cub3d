/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:32:18 by smostefa          #+#    #+#             */
/*   Updated: 2022/10/14 20:32:22 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    get_sprites_nbr(t_ray *ray, t_sprite *sprite)
{
    int i;
    int j;

    i = 0;
    sprite->nbr = 0;
    while (i < ray->data->len)
	{
		j = 0;
		while (j < ray->data->height)
		{
			if (ray->revert_map[i][j] == '3' || ray->revert_map[i][j] == '4')
                sprite->nbr++;
			j++;
		}
		i++;
	}
    sprite->tab = malloc(sizeof(t_coordinates) * (sprite->nbr + 1));
    if (!sprite->tab)
    {
        //ERROR
    }
    sprite->order = malloc(sizeof(int) * (sprite->nbr + 1));
    if (!sprite->order)
    {
        //ERROR
    }
    sprite->distance = malloc(sizeof(double) * (sprite->nbr + 1));
    if (!sprite->distance)
    {
        //ERROR
    }
}

void    get_sprites_coordinates(t_ray *ray, t_sprite *sprite)
{
    int i;
    int j;
    int k;

    i = 0;
    k = 0;
    while (i < ray->data->len)
	{
		j = 0;
		while (j < ray->data->height)
		{
			if (ray->revert_map[i][j] == '3' || ray->revert_map[i][j] == '4')
            {
                sprite->tab[k].x = (double)i + 0.5;
                sprite->tab[k].y = (double)j + 0.5;
                if (ray->revert_map[i][j] == '3')
                    sprite->tab[k].texture = 5;
                else
                    sprite->tab[k].texture = 6;
                k++;
            }
			j++;
		}
		i++;
	}
}

void    sort_sprites(t_ray *ray, t_sprite *sprite)
{
    int i;
    int j;
    double  tmp;

    i = 0;
    while (i < sprite->nbr)
    {
        sprite->order[i] = i;
        sprite->distance[i] = ((ray->pos.x - sprite->tab[i].x) * (ray->pos.x - sprite->tab[i].x) + (ray->pos.y - sprite->tab[i].y) * (ray->pos.y - sprite->tab[i].y)); //sqrt not taken, unneeded
        i++;
    }
    i = 0;
    while (i < sprite->nbr)
    {
        j = 0;
		while (j < sprite->nbr - 1)
		{
			if (sprite->distance[j] < sprite->distance[j + 1])
			{
				tmp = sprite->distance[j];
				sprite->distance[j] = sprite->distance[j + 1];
				sprite->distance[j + 1] = tmp;
				tmp = sprite->order[j];
				sprite->order[j] = sprite->order[j + 1];
				sprite->order[j + 1] = (int)tmp;
			}
            j++;
		}
        i++;
    }
}

/*void    draw_sprites(t_ray *ray, t_sprite *sprite)
{


}*/

void    add_sprites(t_ray *ray)
{
    t_sprite sprite;

    get_sprites_nbr(ray, &sprite);
    get_sprites_coordinates(ray, &sprite);
    //CHECK
    printf("sprite number : %d\n", sprite.nbr);
    printf("x : %f\n", sprite.tab[0].x);
    printf("y : %f\n", sprite.tab[0].y);
    printf("x : %f\n", sprite.tab[1].x);
    printf("y : %f\n", sprite.tab[1].y);
    sort_sprites(ray, &sprite);
}