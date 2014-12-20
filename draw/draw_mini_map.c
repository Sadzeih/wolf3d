/*
** draw_mini_map.c for wolf3d in /home/sadzeih/rendu/Igraph/MUL_2014_wolf3d
** 
** Made by Alexis Guerville
** Login   <guervi_a@epitech.net>
** 
** Started on  Sat Dec 13 19:00:53 2014 Alexis Guerville
** Last update Sat Dec 20 15:38:48 2014 Alexis Guerville
*/

#include "my.h"
#include "mlx.h"

int		fill(t_game *game)
{
  int		x;
  int		y;

  y = 0;
  while (y <= 150)
    {
      x = 0;
      while (x <= 150)
	{
	  my_pixel_put_to_minimap(game, x, y, 0x000000);
	  x++;
	}
      y++;
    }
}

int		draw_square(t_game *game, unsigned int color)
{
  int		xp;
  int		x_max;
  int		y_max;
  int		yp;

  yp = game->draw_minimap->y;
  y_max = yp + game->draw_minimap->size;
  while (yp <= y_max)
    {
      xp = game->draw_minimap->x;
      x_max = xp + game->draw_minimap->size;
      while (xp <= x_max)
	{
	  my_pixel_put_to_minimap(game, xp, yp, color);
	  xp++;
	}
      yp++;
    }
}

int		init_minimap(t_game *game)
{
  fill(game);
  game->draw_minimap->y = 0;
  game->draw_minimap->size = 30;
}

int		draw_mini_map(t_game *game)
{
  int		x;
  int		y;

  init_minimap(game);
  y = (int)game->player->pos->y - 3;
  while (++y <= ((int)game->player->pos->y + 2))
    {
      x = (int)game->player->pos->x - 3;
      game->draw_minimap->x = 0;
      while (++x <= ((int)game->player->pos->x + 2))
	{
	  if (x >= 0 && y >= 0 && x < game->map_x && y < game->map_y)
	    {
	      if (game->draw_minimap->x == 60 && game->draw_minimap->y == 60)
		draw_square(game, 0xFF0000);
	      else if (game->map[y][x] == 1)
		draw_square(game, 0x000000);
	      else if (game->map[y][x] == 0)
		draw_square(game, 0xFFFFFF);
	    }
	  game->draw_minimap->x += 30;
	}
      game->draw_minimap->y += 30;
    }
}
