/*
** main.c for TP1 in /home/guervi_a/rendu/Igraph
** 
** Made by Alexis Guerville
** Login   <guervi_a@epitech.net>
** 
** Started on  Wed Oct 29 14:07:45 2014 Alexis Guerville
** Last update Wed Dec 10 12:05:56 2014 Alexis Guerville
*/

#include "mlx.h"
#include "my.h"

int	draw_line(t_line *first, t_line *second, unsigned int color, \
		  t_game *game)
{
  int	y;

  y = first->y;
  while (y <= second->y)
    {
      my_pixel_put_to_image(game, first->x, y, color);
      y++;
    }
}
