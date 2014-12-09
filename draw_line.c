/*
** main.c for TP1 in /home/guervi_a/rendu/Igraph
** 
** Made by Alexis Guerville
** Login   <guervi_a@epitech.net>
** 
** Started on  Wed Oct 29 14:07:45 2014 Alexis Guerville
** Last update Fri Nov 21 20:49:26 2014 Alexis Guerville
*/

#include <stdlib.h>
#include "mlx.h"
#include "my.h"

void	draw_1(t_line *first, t_line *second, t_map *map)
{
  int	x;
  int	y;

  x = first->x;
  while (x <= second->x)
    {
      y = first->y + ((second->y - first->y) * (x - first->x)) /\
	(second->x - first->x);
      my_pixel_put_to_image(map, x, y);
      x++;
    }
}

void	draw_5(t_line *first, t_line *second, t_map *map)
{
  int	y;
  int	x;

  y = first->y;
  while (y <= second->y)
    {
      x = second->x + ((first->x - second->x) * (y - second->y)) /\
	(first->y - second->y);
      my_pixel_put_to_image(map, x, y);
      y++;
    }
}

void	draw_6(t_line *first, t_line *second, t_map *map)
{
  int	y;

  y = first->y;
  while (y <= second->y)
    {
      my_pixel_put_to_image(map, first->x, y);
      y++;
    }
}

void	draw_7(t_line *first, t_line *second, t_map *map)
{
  int	x;

  x = first->x;
  while (x <= second->x)
    {
      my_pixel_put_to_image(map, x, first->y);
      x++;
    }
}

int	draw_line(t_line *first, t_line *second, t_map *map)
{
  int	x;
  int	y;

  x = ABS(first->x - second->x);
  y = ABS(first->y - second->y);
  if (x >= y)
    {
      if (first->x < second->x)
	draw_1(first, second, map);
      else if (first->x == second->x)
	draw_6(second, first, map);
      else
	draw_1(second, first, map);
      return (0);
    }
  else
    {
      if (first->y < second->y)
	draw_5(first, second, map);
      else if (first->y == second->y)
      	draw_7(second, first, map);
      else
	draw_5(second, first, map);
      return (0);
    }
}
