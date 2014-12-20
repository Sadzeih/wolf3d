/*
** my_put_pixel_to_image.c for FDF in /home/guervi_a/rendu/Igraph/MUL_2014_fdf
** 
** Made by Alexis Guerville
** Login   <guervi_a@epitech.net>
** 
** Started on  Fri Nov 21 20:34:31 2014 Alexis Guerville
** Last update Sat Dec 20 15:37:15 2014 Alexis Guerville
*/

#include "mlx.h"
#include "my.h"

void    my_pixel_put_to_image(t_game *game, int x, int y, unsigned int color)
{
  int   bpp;
  int   sizeline;
  int   endian;
  int	img_color;

  if (x < WIN_X && y < WIN_Y && x > 0 && y > 0)
    {
      img_color =  mlx_get_color_value(game->window->mlx_ptr, color);
      game->window->data = mlx_get_data_addr(game->window->img, &bpp,\
					     &sizeline, &endian);
      game->window->data[(y * sizeline) + x * (bpp / 8)] = img_color & 255;
      game->window->data[(y * sizeline) + x * (bpp / 8) + 1] =\
	img_color >> 8 & 255;
      game->window->data[(y * sizeline) + x * (bpp / 8) + 2] =\
	img_color >> 16 & 255;
    }
}

void    my_pixel_put_to_minimap(t_game *game, int x, int y, unsigned int color)
{
  int   bpp;
  int   sizeline;
  int   endian;
  int	img_color;

  if (x < WIN_X && y < WIN_Y && x > 0 && y > 0)
    {
      img_color =  mlx_get_color_value(game->window->mlx_ptr, color);
      game->window->data = mlx_get_data_addr(game->window->mini_map, &bpp,\
					     &sizeline, &endian);
      game->window->data[(y * sizeline) + x * (bpp / 8)] = img_color & 255;
      game->window->data[(y * sizeline) + x * (bpp / 8) + 1] =\
	img_color >> 8 & 255;
      game->window->data[(y * sizeline) + x * (bpp / 8) + 2] =\
	img_color >> 16 & 255;
    }
}
