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

void    draw_sprites(t_ray *ray, t_sprite *sprite)
{
    int i;
    int stripe;
    int pixel;
    double  x;
    double  y;
    //after sorting the sprites, do the projection and draw them

    i = 0;
    while (i < sprite->nbr)
    {
        //translate sprite position to relative to camera
        x = sprite->tab[sprite->order[i]].x - ray->pos.x;
        y = sprite->tab[sprite->order[i]].y - ray->pos.y;

        //transform sprite with the inverse camera matrix
        // [ planeX   dirX ] -1                                       [ dirY      -dirX ]
        // [               ]       =  1/(planeX*dirY-dirX*planeY) *   [                 ]
        // [ planeY   dirY ]                                          [ -planeY  planeX ]

        sprite->invdet = 1.0 / (ray->plane.x * ray->dir.y - ray->dir.x * ray->plane.y); //required for correct matrix multiplication
        sprite->transform.x = sprite->invdet * (ray->dir.y * x - ray->dir.x * y);
        sprite->transform.y = sprite->invdet * (-ray->plane.y * x + ray->plane.x * y); //this is actually the depth inside the screen, that what Z is in 3D

        sprite->screenx= (int)((WIDTH / 2) * (1 + sprite->transform.x / sprite->transform.y));

        //calculate height of the sprite on screen
        sprite->height = abs((int)(HEIGHT / (sprite->transform.y))); //using 'transformY' instead of the real distance prevents fisheye
        //calculate lowest and highest pixel to fill in current stripe
        sprite->drawstart.y = -sprite->height / 2 + HEIGHT / 2;
        if(sprite->drawstart.y < 0) 
            sprite->drawstart.y = 0;
        sprite->drawend.y = sprite->height / 2 + HEIGHT / 2;
        if(sprite->drawend.y >= HEIGHT)
            sprite->drawend.y = HEIGHT - 1;

        //calculate width of the sprite
        sprite->width = abs((int)(HEIGHT / (sprite->transform.y)));
        sprite->drawstart.x = -sprite->width / 2 + sprite->screenx;
        if(sprite->drawstart.x < 0)
            sprite->drawstart.x = 0;
        sprite->drawend.x = sprite->width / 2 + sprite->screenx;
        if(sprite->drawend.x >= WIDTH)
            sprite->drawend.x = WIDTH - 1;

        //loop through every vertical stripe of the sprite on screen
        stripe = sprite->drawstart.x;
        while (stripe < sprite->drawend.x)
        {
            sprite->tex.x = (int)(256 * (stripe - (-sprite->width / 2 + sprite->screenx)) * ray->texture[sprite->tab[sprite->order[i]].texture].width / sprite->width) / 256;
            //the conditions in the if are:
            //1) it's in front of camera plane so you don't see things behind you
            //2) it's on the screen (left)
            //3) it's on the screen (right)
            //4) ZBuffer, with perpendicular distance
            if(sprite->transform.y > 0 && stripe > 0 && stripe < WIDTH && sprite->transform.y < ray->zbuffer[stripe])
            {
                pixel = sprite->drawstart.y;
                while (pixel < sprite->drawend.y) //for every pixel of the current stripe
                {
                    sprite->d = pixel * 256 - HEIGHT * 128 + sprite->height * 128; //256 and 128 factors to avoid floats
                    sprite->tex.y = ((sprite->d * ray->texture[sprite->tab[sprite->order[i]].texture].height) / sprite->height) / 256;
                    sprite->color = ray->texture[sprite->tab[sprite->order[i]].texture].tab[ray->texture[sprite->tab[sprite->order[i]].texture].width * sprite->tex.y + sprite->tex.x]; //get current color from the texture
                    if((sprite->color & 0x00FFFFFF) != 0 && (sprite->tab[sprite->order[i]].texture == 5))
                        ray->xpm->buffer[pixel + ray->levitation][stripe] = sprite->color; //paint pixel if it isn't black, black is the invisible color
                    else if((sprite->color & 0x00FFFFFF) != 0 && (sprite->tab[sprite->order[i]].texture == 6))
                        ray->xpm->buffer[pixel - ray->levitation][stripe] = sprite->color;
                    pixel++;
                }
            }
            stripe++;
        }
        i++;
    }
}

void    add_sprites(t_ray *ray)
{
    t_sprite sprite;

    get_sprites_nbr(ray, &sprite);
    get_sprites_coordinates(ray, &sprite);
    //CHECK
    // printf("sprite number : %d\n", sprite.nbr);
    // printf("x : %f\n", sprite.tab[0].x);
    // printf("y : %f\n", sprite.tab[0].y);
    // printf("x : %f\n", sprite.tab[1].x);
    // printf("y : %f\n", sprite.tab[1].y);
    sort_sprites(ray, &sprite);
    draw_sprites(ray, &sprite);
}