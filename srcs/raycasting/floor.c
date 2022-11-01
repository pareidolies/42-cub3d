#include "cub3d.h"

void    create_floor_and_ceiling(t_ray *ray)
{
    int     y;
    int     p;
    double  posz;
    int     color;
    t_point t;
    int     x;

    //FLOOR CASTING
    y = 0;
    while (y < HEIGHT)
    {
      // rayDir for leftmost ray (x = 0) and rightmost ray (x = w)
      ray->raydir0.x = ray->dir.x - ray->plane.x;
      ray->raydir0.y = ray->dir.y - ray->plane.y;
      ray->raydir1.x = ray->dir.x + ray->plane.x;
      ray->raydir1.y = ray->dir.y + ray->plane.y;

      // Current y position compared to the center of the screen (the horizon)
      p = y - HEIGHT / 2;

      // Vertical position of the camera.
      posz = 0.5 * HEIGHT;

      // Horizontal distance from the camera to the floor for the current row.
      // 0.5 is the z position exactly in the middle between floor and ceiling.
      ray->rowdistance = posz / p;

      // calculate the real world step vector we have to add for each x (parallel to camera plane)
      // adding step by step avoids multiplications with a weight in the inner loop
      ray->floorstep.x = ray->rowdistance * (ray->raydir1.x - ray->raydir0.x) / WIDTH;
      ray->floorstep.y = ray->rowdistance * (ray->raydir1.y - ray->raydir0.y) / WIDTH;

      // real world coordinates of the leftmost column. This will be updated as we step to the right.
      ray->floor.x = ray->pos.x + ray->rowdistance * ray->raydir0.x;
      ray->floor.y = ray->pos.y + ray->rowdistance * ray->raydir0.y;
    x = 0;
      while (x < WIDTH)
      {
        // the cell coord is simply got from the integer parts of floorX and floorY
        ray->cell.x = (int)(ray->floor.x);
        ray->cell.y = (int)(ray->floor.y);

        // get the texture coordinate from the fractional part
        t.x = (int)(ray->texture[7].width * (ray->floor.x - ray->cell.x)) & (ray->texture[7].width - 1);
        t.y = (int)(ray->texture[7].height * (ray->floor.y - ray->cell.y)) & (ray->texture[7].height - 1);

        ray->floor.x += ray->floorstep.x;
        ray->floor.y += ray->floorstep.y;

        // choose texture and draw the pixel
        
        // floor
        color = ray->texture[7].tab[ray->texture[7].width * t.y + t.x];
        color = (color >> 1) & 8355711; // make a bit darker
        ray->xpm->buffer[y][x] = color;

        //ceiling (symmetrical, at screenHeight - y - 1 instead of y)
        color = get_color(ray->ceiling_color, ray, 'c');;
        ray->xpm->buffer[HEIGHT - y - 1][x] = color;
        x++;
      }
      y++;
    }
}