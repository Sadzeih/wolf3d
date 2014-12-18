/*
** vision.c for wolf3d in /home/sadzeih/rendu/Igraph/MUL_2014_wolf3d
** 
** Made by Alexis Guerville
** Login   <guervi_a@epitech.net>
** 
** Started on  Wed Dec 10 09:11:04 2014 Alexis Guerville
** Last update Mon Dec 15 17:16:05 2014 Alexis Guerville
*/

#include	<stdlib.h>
#include	<math.h>
#include	"my.h"

void		calc_xy(t_game *game, int x_draw)
{
  float		x;
  float		y;
  float		a;
  float		tmpx;

  a = game->player->angle * M_PI / 180;
  x = DIST;
  y = (float)(SEGMENT *\
	      (((float)(WIN_X / 2) - (float)x_draw) / WIN_X));
  tmpx = x;
  x = (x * cos(a)) - (y * sin(a));
  y = (tmpx * sin(a)) + (y * cos(a));
  game->vec->x = x + game->player->pos->x;
  game->vec->y = y + game->player->pos->y;
}

int	        k_x(t_game *game)
{
  int		x;
  int		y;
  float		k;

  x = 0;
  while (x < game->map_x)
    {
      k = (x - game->player->pos->x) /	\
	(game->vec->x - game->player->pos->x);
      y = (game->player->pos->y +\
	   (k * (game->vec->y - game->player->pos->y)));
      if (k < game->k && k > 0 && y < game->map_y && y > 0 &&\
	  (game->map[y][x] != 0 ||\
	   game->map[y][x - 1] != 0))
	{
	  game->or_color = 0;
	  game->k = k;
	}
      x++;
    }
}

int		k_y(t_game *game)
{
  int		x;
  int		y;
  float		k;

  y = 0;
  while (y < game->map_y)
    {
      k = (y - game->player->pos->y) /	\
	(game->vec->y - game->player->pos->y);
      x = (game->player->pos->x +\
	   (k * (game->vec->x - game->player->pos->x)));
      if (k < game->k && k > 0 && x < game->map_x && x > 0 &&\
	  (game->map[y][x] != 0 ||\
	   game->map[y - 1][x] != 0))
	{
	  game->or_color = 1;
	  game->k = k;
	}
      y++;
    }
}

int		view(t_game *game)
{
  int		x;

  x = 0;
  while (x < WIN_X)
    {
      game->k = 40;
      calc_xy(game, x);
      k_x(game);
      k_y(game);
      game->h = WIN_Y / (2 * game->k);
      draw_roof(game, x);
      draw_walls(game, x);
      draw_floor(game, x);
      x++;
    }
}
