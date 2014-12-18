/*
** events.c for wolf3d in /home/sadzeih/rendu/Igraph/MUL_2014_wolf3d
** 
** Made by Alexis Guerville
** Login   <guervi_a@epitech.net>
** 
** Started on  Tue Dec  9 17:39:28 2014 Alexis Guerville
** Last update Mon Dec 15 15:37:53 2014 Alexis Guerville
*/

#include <stdlib.h>
#include <stdio.h>
#include <X11/X.h>
#include <math.h>
#include "mlx.h"
#include "my.h"

int     hook_press(int keycode, t_game *game)
{
  if (keycode == ARROW_UP)
    game->keys->up = 1;
  if (keycode == ARROW_DOWN)
    game->keys->down = 1;
  if (keycode == ARROW_LEFT)
    game->keys->left = 1;
  if (keycode == ARROW_RIGHT)
    game->keys->right = 1;
  if (keycode == ESCAPE)
    game->keys->escape = 1;
}

int     hook_release(int keycode, t_game *game)
{
  if (keycode == ARROW_UP)
    game->keys->up = 0;
  if (keycode == ARROW_DOWN)
    game->keys->down = 0;
  if (keycode == ARROW_LEFT)
    game->keys->left = 0;
  if (keycode == ARROW_RIGHT)
    game->keys->right = 0;
  if (keycode == ESCAPE)
    game->keys->escape = 0;
}

int     gere_key(t_game *game)
{
  move(game);
  if (game->keys->escape == 1)
    exit(1);
  view(game);
  draw_mini_map(game);
  mlx_put_image_to_window(game->window->mlx_ptr, game->window->mlx_win,\
  			  game->window->img, 0, 0);
  mlx_put_image_to_window(game->window->mlx_ptr, game->window->mlx_win,\
  			  game->window->mini_map, 30, 30);
}

int             init_keys(t_game *game)
{
  game->keys->up = 0;
  game->keys->down = 0;
  game->keys->left = 0;
  game->keys->right = 0;
  game->keys->escape = 0;
}

int	events(t_game *game)
{
  init_keys(game);
  mlx_hook(game->window->mlx_win, KeyPress, KeyPressMask, &hook_press, game);
  mlx_hook(game->window->mlx_win, KeyRelease, KeyReleaseMask, &hook_release,\
	   game);
  mlx_loop_hook(game->window->mlx_ptr, &gere_key, game);
  mlx_loop(game->window->mlx_ptr);
}
