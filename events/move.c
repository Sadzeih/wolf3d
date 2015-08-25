/*
** move.c for wolf3d in /home/sadzeih/rendu/Igraph/MUL_2014_wolf3d
** 
** Made by Alexis Guerville
** Login   <guervi_a@epitech.net>
** 
** Started on  Mon Dec 15 15:36:45 2014 Alexis Guerville
** Last update Wed Aug 26 00:24:39 2015 Alexis Guerville
*/

#include <math.h>
#include "mlx.h"
#include "my.h"

int	forward(t_game *game)
{
  float	x;
  float	y;
  float angle;

  angle = game->player->angle / 180 * M_PI;
  x = game->player->pos->x + (0.5 * cos(angle));
  y = game->player->pos->y + (0.5 * sin(angle));
  if (game->map[(int)y][(int)x] == 0)
    {
      game->player->pos->x = game->player->pos->x + (0.07 * cos(angle));
      game->player->pos->y = game->player->pos->y + (0.07 * sin(angle));
    }
}

int	backward(t_game *game)
{
  float	x;
  float	y;
  float angle;

  angle = game->player->angle / 180 * M_PI;
  x = game->player->pos->x - (0.5 * cos(angle));
  y = game->player->pos->y - (0.5 * sin(angle));
  if (game->map[(int)y][(int)x] == 0)
    {
      game->player->pos->x = game->player->pos->x - (0.07 * cos(angle));
      game->player->pos->y = game->player->pos->y - (0.07 * sin(angle));
    }
}

int	move(t_game *game)
{
  if (game->keys->up == 1)
    forward(game);
  if (game->keys->down == 1)
    backward(game);
  if (game->keys->left == 1)
    game->player->angle += 1.75;
  if (game->keys->right == 1)
    game->player->angle -= 1.75;
  if (game->keys->up == 1 || game->keys->down == 1 ||\
      game->keys->left == 1 || game->keys->right == 1)
    {
      view(game);
      draw_mini_map(game);
      mlx_put_image_to_window(game->window->mlx_ptr, game->window->mlx_win, \
			      game->window->img, 0, 0);
      mlx_put_image_to_window(game->window->mlx_ptr, game->window->mlx_win,\
			      game->window->mini_map, 30, 30);
    }
}
