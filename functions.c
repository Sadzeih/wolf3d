/*
** functions.c for wolf3d in /home/sadzeih/rendu/Igraph/MUL_2014_wolf3d
** 
** Made by Alexis Guerville
** Login   <guervi_a@epitech.net>
** 
** Started on  Tue Dec  9 18:37:54 2014 Alexis Guerville
** Last update Sat Dec 13 18:57:27 2014 Alexis Guerville
*/

#include <stdlib.h>

int             sign(char *str)
{
  int           i;
  int           m;

  i = 0;
  m = 0;
  while (str[i] == '-' || str[i] == '+')
    {
      if (str[i] == '-')
	m++;
      i++;
    }
  return (m);
}

int             my_getnbr(char *str)
{
  int           m;
  int           i;
  int           nb;
  int           nb2;

  i = 0;
  nb = 0;
  m = sign(str);
  while (str[i] == '-' || str[i] == '+')
    i++;
  while (str[i] >= 48 && str[i] <= 57)
    {
      nb2 = str[i] - 48;
      nb = nb * 10 + nb2;
      i++;
    }
  if (m % 2 != 0)
    {
      nb = nb * (-1);
    }
  return (nb);
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i++] != '\0');
  return (i);
}

char    *my_strdup(char *src)
{
  int   size;
  char  *dest;

  size = my_strlen(src);
  if ((dest = malloc((size + 2) * sizeof(char))) != NULL)
    {
      my_strcpy(dest, src);
      return (dest);
    }
  else
    {
      free(dest);
      return (0);
    }
}
