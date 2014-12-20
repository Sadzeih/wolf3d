/*
** main.c for wolf3d in /home/sadzeih/rendu/Igraph/MUL_2014_wolf3d
** 
** Made by Alexis Guerville
** Login   <guervi_a@epitech.net>
** 
** Started on  Tue Dec  9 14:00:10 2014 Alexis Guerville
** Last update Fri Dec 19 19:00:58 2014 Alexis Guerville
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <X11/X.h>
#include "mlx.h"
#include "my.h"

t_game		*init_game(t_game *game)
{
  if ((game = malloc(sizeof(t_game))) == NULL)
    return (0);
  if ((game->window = malloc(sizeof(t_window))) == NULL)
    return (0);
  if ((game->keys = malloc(sizeof(t_keys))) == NULL)
    return (0);
  if ((game->vec = malloc(sizeof(t_vec))) == NULL)
    return (0);
  if ((game->player = malloc(sizeof(t_player))) == NULL)
    return (0);
  if ((game->player->pos = malloc(sizeof(t_vec))) == NULL)
    return (0);
  if ((game->draw_minimap = malloc(sizeof(t_draw_minimap))) == NULL)
    return (0);
  if ((game->window->mlx_ptr = mlx_init()) == 0)
    return (0);
  game->window->mlx_win = mlx_new_window(game->window->mlx_ptr, 1280, 720, \
					 "wolf ta maman");
  game->player->pos->x = 8.5;
  game->player->pos->y = 1.5;
  game->player->angle = 90;
  game->window->img = mlx_new_image(game->window->mlx_ptr, 1280, 720);
  game->window->mini_map = mlx_new_image(game->window->mlx_ptr, 150, 150);
  return (game);
}

int		get_map(t_game *game)
{
  char		**tab_char;
  int		fd;

  fd = open("map", O_RDONLY);
  if (fd == 0 || fd == -1)
    exit(1);
  tab_char = get_tab_lines(fd, "map");
  game->map = tab_tab_int(tab_char, "map");
  game->map_x = count_words(tab_char[0]);
  game->map_y = count_lines("map");
}

int		main()
{
  t_game	*game;

  game = init_game(game);
  if (game == 0)
    return (0);
  get_map(game);
  events(game);
}
