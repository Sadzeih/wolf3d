/*
** draw_mini_map.c for wolf3d in /home/sadzeih/rendu/Igraph/MUL_2014_wolf3d
** 
** Made by Alexis Guerville
** Login   <guervi_a@epitech.net>
** 
** Started on  Sat Dec 13 19:00:53 2014 Alexis Guerville
** Last update Mon Dec 15 15:31:23 2014 Alexis Guerville
*/

#include "my.h"
#include "mlx.h"

int		fill(t_game *game)
{
  int		x;
  int		y;

  y = -1;
  while (++y <= 50)
    {
      x = -1;
      while (++x <= 50)
	  my_pixel_put_to_minimap(game, x, y, 0xCCCCCC);
    }
}

int		draw_square(unsigned int color, t_game *game)
{
  static int	t = 0;
  int		xp;
  int		yp;

  yp = (t * 30) - 1;
  while (++yp <= (yp + 30))
    {
      xp = (t * 30) - 1;
      while (++xp <= (xp + 30))
	my_pixel_put_to_minimap(game, xp, yp, color);
    }
  t++;
}

int		draw_mini_map(t_game *game)
{
  int		x;
  int		y;

  x = (int)game->player->pos->x - 5;
  y = (int)game->player->pos->y- 5;
  while (y <= ((int)game->player->pos->y + 5))
    {
      while (x <= ((int)game->player->pos->x + 5))
	{
	  if (x >= 0 && y >= 0)
	    {
	      if (game->map[y][x] == 0)
		draw_square(0xFFFFFF, game);
	    }
	  x++;
	}
      y++;
    }
}
