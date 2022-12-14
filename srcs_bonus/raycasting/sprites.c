/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:32:18 by smostefa          #+#    #+#             */
/*   Updated: 2022/11/03 16:35:42 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* TUTO Lodev

    //after sorting the sprites, do the projection and draw them
    //translate sprite position to relative to camera
    //transform sprite with the inverse camera matrix
    // [ planeX   dirX ] -1                                 [ dirY      -dirX ]
    // [               ]    = 1/(planeX*dirY-dirX*planeY) * [                 ]
    // [ planeY   dirY ]                                    [ -planeY  planeX ]
    //calculate height of the sprite on screen
    //calculate lowest and highest pixel to fill in current stripe
    //calculate width of the sprite
    //loop through every vertical stripe of the sprite on screen
    //the conditions in the if are:
            //1) it's in front of camera plane so you don't 
		see things behind you
            //2) it's on the screen (left)
            //3) it's on the screen (right)
            //4) ZBuffer, with perpendicular distance
*/

void	compute_sprite_camera_position(t_ray *ray, t_sprite *sprite, int i)
{
	double	x;
	double	y;

	x = sprite->tab[sprite->order[i]].x - ray->pos.x;
	y = sprite->tab[sprite->order[i]].y - ray->pos.y;
	sprite->invdet = 1.0 / (ray->plane.x * \
		ray->dir.y - ray->dir.x * ray->plane.y);
	sprite->transform.x = sprite->invdet * \
		(ray->dir.y * x - ray->dir.x * y);
	sprite->transform.y = sprite->invdet * \
		(-ray->plane.y * x + ray->plane.x * y);
	if (sprite->tab[sprite->order[i]].texture == 5)
		ray->levitationscreen = (ray->levitation + 350.0) / \
			sprite->transform.y;
	else
		ray->levitationscreen = (-ray->levitation + 400.0) / \
			sprite->transform.y;
	sprite->screenx = (int)((WIDTH / 2) * \
		(1 + sprite->transform.x / sprite->transform.y));
}

void	compute_sprite_height_and_width(t_ray *ray, t_sprite *sprite)
{
	sprite->height = abs((int)(HEIGHT / (sprite->transform.y)));
	sprite->drawstart.y = -sprite->height / 2 + \
		HEIGHT / 2 + ray->levitationscreen;
	if (sprite->drawstart.y < 0)
		sprite->drawstart.y = 0;
	sprite->drawend.y = sprite->height / 2 + HEIGHT / 2 + ray->levitationscreen;
	if (sprite->drawend.y >= HEIGHT)
		sprite->drawend.y = HEIGHT - 1;
	sprite->width = abs((int)(HEIGHT / (sprite->transform.y)));
	sprite->drawstart.x = -sprite->width / 2 + sprite->screenx;
	if (sprite->drawstart.x < 0)
		sprite->drawstart.x = 0;
	sprite->drawend.x = sprite->width / 2 + sprite->screenx;
	if (sprite->drawend.x >= WIDTH)
		sprite->drawend.x = WIDTH - 1;
}

void	draw_sprite_pixel(t_ray *ray, t_sprite *sprite, int i)
{
	sprite->d = (ray->pixel - ray->levitationscreen) * \
		256 - HEIGHT * 128 + sprite->height * 128;
	sprite->tex.y = ((sprite->d * \
		ray->texture[sprite->tab[sprite->order[i]].texture].height) / \
			sprite->height) / 256;
	sprite->color = ray->texture[sprite->tab[sprite->order[i]].\
		texture].tab[ray->texture[sprite->tab[sprite->order[i]].\
		texture].width * sprite->tex.y + sprite->tex.x];
	if (((sprite->color & 0x00FFFFFF) != 0))
		ray->xpm->buffer[ray->pixel][ray->stripe] = sprite->color;
	ray->pixel++;
}

void	draw_sprites(t_ray *ray, t_sprite *sprite)
{
	int	i;

	i = 0;
	while (i < sprite->nbr)
	{
		compute_sprite_camera_position(ray, sprite, i);
		compute_sprite_height_and_width(ray, sprite);
		ray->stripe = sprite->drawstart.x;
		while (ray->stripe < sprite->drawend.x)
		{
			sprite->tex.x = (int)(256 * (ray->stripe - (-sprite->width / 2 + \
				sprite->screenx)) * \
				ray->texture[sprite->tab[sprite->order[i]].texture].width / \
					sprite->width) / 256;
			if (sprite->transform.y > 0 && ray->stripe > 0 && ray->stripe \
				< WIDTH && sprite->transform.y < ray->zbuffer[ray->stripe])
			{
				ray->pixel = sprite->drawstart.y;
				while (ray->pixel < sprite->drawend.y)
					draw_sprite_pixel(ray, sprite, i);
			}
			ray->stripe++;
		}
		i++;
	}
}

void	add_sprites(t_ray *ray)
{
	t_sprite	sprite;

	get_sprites_nbr(ray, &sprite);
	get_sprites_coordinates(ray, &sprite);
	sort_sprites(ray, &sprite);
	draw_sprites(ray, &sprite);
	free(sprite.tab);
	free(sprite.order);
	free(sprite.distance);
}
