/*
** draw.c for wolf3d in /home/sadzeih/rendu/Igraph/MUL_2014_wolf3d
** 
** Made by Alexis Guerville
** Login   <guervi_a@epitech.net>
** 
** Started on  Sat Dec 13 18:52:53 2014 Alexis Guerville
** Last update Mon Dec 15 17:19:09 2014 Alexis Guerville
*/

#include "my.h"
#include "mlx.h"

int             draw_roof(t_game *game, int x)
{
  int           y;
  int           y_two;

  y = -1;
  y_two = (WIN_Y / 2) - game->h;
  while (++y <= y_two)
    my_pixel_put_to_image(game, x, y, 0xCCCCFF);
}

int             draw_floor(t_game *game, int x)
{
  int           y;
  int           y_two;

  y = (WIN_Y / 2) + game->h - 1;
  y_two = WIN_Y;
  while (++y <= y_two)
    my_pixel_put_to_image(game, x, y, 0x55CC55);
}

int             draw_walls(t_game *game, int x)
{
  int           y;
  int           y_two;

  y = (WIN_Y / 2) - game->h - 1;
  y_two = (WIN_Y / 2) + game->h;
  while (++y <= y_two)
    {
      if (game->or_color = 0)
	my_pixel_put_to_image(game, x, y, 0xDDDDDD);
      else if (game->or_color = 1)
	my_pixel_put_to_image(game, x, y, 0xCCCCCC);
    }
}
