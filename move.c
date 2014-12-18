/*
** move.c for wolf3d in /home/sadzeih/rendu/Igraph/MUL_2014_wolf3d
** 
** Made by Alexis Guerville
** Login   <guervi_a@epitech.net>
** 
** Started on  Mon Dec 15 15:36:45 2014 Alexis Guerville
** Last update Tue Dec 16 14:16:17 2014 Alexis Guerville
*/

#include <math.h>
#include "my.h"

int	move(t_game *game)
{
  float angle;
  float	x;
  float	y;

  angle = game->player->angle / 180 * M_PI;
  if (game->keys->up == 1)
    {
      x = game->player->pos->x + (0.07 * cos(angle));
      y = game->player->pos->y + (0.07 * sin(angle));
      if(game->map[(int)y][(int)x] == 0)
	{
	  game->player->pos->x = x;
	  game->player->pos->y = y;
	}
    }
  if (game->keys->down == 1)
    {
      game->player->pos->x = game->player->pos->x - (0.07 * cos(angle));
      game->player->pos->y = game->player->pos->y - (0.07 * sin(angle));
    }
  if (game->keys->left == 1)
    game->player->angle += 1.75;
  if (game->keys->right == 1)
    game->player->angle -= 1.75;
}
