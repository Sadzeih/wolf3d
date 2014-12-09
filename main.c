/*
** main.c for wolf3d in /home/sadzeih/rendu/Igraph/MUL_2014_wolf3d
** 
** Made by Alexis Guerville
** Login   <guervi_a@epitech.net>
** 
** Started on  Tue Dec  9 14:00:10 2014 Alexis Guerville
** Last update Tue Dec  9 16:47:57 2014 Alexis Guerville
*/

#include <stdlib.h>
#include <stdio.h>
#include <X11/X.h>
#include "mlx.h"
#include "my.h"

int	hook_press(int keycode, t_keys *keys)
{
  if (keycode == ARROW_UP)
    keys->up = 1;
  if (keycode == ARROW_DOWN)
    keys->down = 1;
  if (keycode == ARROW_LEFT)
    keys->left = 1;
  if (keycode == ARROW_RIGHT)
    keys->right = 1;
  if (keycode == ESCAPE)
    keys->escape = 1;
}

int	hook_release(int keycode, t_keys *keys)
{
  if (keycode == ARROW_UP)
    keys->up = 0;
  if (keycode == ARROW_DOWN)
    keys->down = 0;
  if (keycode == ARROW_LEFT)
    keys->left = 0;
  if (keycode == ARROW_RIGHT)
    keys->right = 0;
  if (keycode == ESCAPE)
    keys->escape = 0;
}

int	gere_key(t_keys *keys)
{
  if (keys->up == 1)
    printf("up");
  if (keys->down == 1)
    printf("down");
  if (keys->left == 1)
    printf("left");
  if (keys->right == 1)
    printf("right");
  if (keys->escape == 1)
    exit(1);
}

int		init_keys(t_keys *keys)
{
  keys->up = 0;
  keys->down = 0;
  keys->left = 0;
  keys->right = 0;
  keys->escape = 0;
}

int		main()
{
  t_window	*window;
  t_keys	*keys;

  if ((window = malloc(sizeof(t_window))) == NULL)
    return (0);
  if ((keys = malloc(sizeof(t_keys))) == NULL)
    return (0);
  if ((window->mlx_ptr = mlx_init()) == 0)
    return (0);
  init_keys(keys);
  window->mlx_win = mlx_new_window(window->mlx_ptr, 1280, 720, "wolf ta maman");
  mlx_hook(window->mlx_win, KeyPress, KeyPressMask, &hook_press, keys);
  mlx_hook(window->mlx_win, KeyRelease, KeyReleaseMask, &hook_release, keys);
  mlx_loop_hook(window->mlx_ptr, &gere_key, keys);
  mlx_loop(window->mlx_ptr);
}
