/*
** parsing.c for FDF in /home/guervi_a/rendu/Igraph/MUL_2014_fdf
** 
** Made by Alexis Guerville
** Login   <guervi_a@epitech.net>
** 
** Started on  Thu Nov  6 09:45:33 2014 Alexis Guerville
** Last update Tue Dec 16 14:03:51 2014 Alexis Guerville
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "get_next_line.h"

int	count_lines(char *file_name)
{
  int	fd;
  int	lines;

  lines = 0;
  fd = open(file_name, O_RDONLY);
  if (fd == 0 || fd == -1)
    return (0);
  while (get_next_line(fd) != NULL)
      lines++;
  close(fd);
  return (lines);
}

char	**get_tab_lines(int fd, char *file_name)
{
  char	*line;
  char	**tab_lines;
  int	i;

  i = 0;
  if ((tab_lines = malloc((count_lines(file_name) + 1) *\
			  sizeof(*tab_lines))) == NULL)
    return (0);
  while ((line = get_next_line(fd)))
    {
      tab_lines[i] = my_strdup(line);
      free(line);
      i++;
    }
  return (tab_lines);
}

int	**tab_tab_int(char **tab_lines, char *file_name)
{
  int	**tab;
  int	i;

  i = 0;
  if ((tab = malloc((count_lines(file_name) + 1) * sizeof(int *))) == NULL)
    return (0);
  while (i < count_lines(file_name))
    {
      tab[i] = my_str_to_wordtab(tab_lines[i]);
      i++;
    }
  return (tab);
}
