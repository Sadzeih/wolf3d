/*
** my_put_pixel_to_image.c for FDF in /home/guervi_a/rendu/Igraph/MUL_2014_fdf
** 
** Made by Alexis Guerville
** Login   <guervi_a@epitech.net>
** 
** Started on  Fri Nov 21 20:34:31 2014 Alexis Guerville
** Last update Fri Nov 21 21:09:28 2014 Alexis Guerville
*/

#include "mlx.h"
#include "my.h"

void    my_pixel_put_to_image(t_map *map, int x, int y)
{
  int   bpp;
  int   sizeline;
  int   endian;
  int	img_color;

  if (x < 1280 && y < 720 && x > 0 && y > 0)
    {
      img_color =  mlx_get_color_value(map->mlx_ptr, 0xFFFFFF);
      map->data = mlx_get_data_addr(map->img, &bpp, &sizeline, &endian);
      map->data[(y * sizeline) + x * (bpp / 8)] = img_color & 255;
      map->data[(y * sizeline) + x * (bpp / 8) + 1] = img_color >> 8 & 255;
      map->data[(y * sizeline) + x * (bpp / 8) + 2] = img_color >> 16 & 255;
    }
}
