/*
** get_next_line.c for get_next_line in /home/guervi_a/rendu/C_Prog_Elem/CPE_2014_getnextline
** 
** Made by Alexis Guerville
** Login   <guervi_a@epitech.net>
** 
** Started on  Mon Nov 10 11:17:07 2014 Alexis Guerville
** Last update Sat Dec 13 18:56:02 2014 Alexis Guerville
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

char    *my_strcat(char *dest, char *src)
{
  int   i;
  int   j;

  i = 0;
  j = 0;
  while (dest[i] != '\0')
    {
      i++;
    }
  while (src[j] != '\0')
    {
      dest[i] = src[j];
      i++;
      j++;
    }
  dest[i] = '\0';
  return (dest);
}

char    *my_strcpy(char *dest, char *src)
{
  int   i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

char	*my_realloc(char *str, int size)
{
  char	*tmp;

  if (str != NULL)
    {
      if ((tmp = malloc(size * sizeof(char))) == NULL)
	return (0);
      my_strcpy(tmp, str);
      free(str);
      return (tmp);
    }
  else
    {
      if ((tmp = malloc(size * sizeof(char))) == NULL)
	return (0);
      tmp[0] = '\0';
      return (tmp);
    }
}

char		*get_line(char *reading, int size)
{
  static int	i = 0;
  char		*line;
  int		j;

  j = 0;
  if ((line = malloc(size * sizeof(char))) == NULL)
    return (0);
  while (reading[i] != '\n' && reading[i] != '\0')
    {
      line[j] = reading[i];
      i++;
      j++;
    }
  if (reading[i] == '\n')
    {
      line[j] = '\0';
      i++;
      return (line);
    }
  if (reading[i] == '\0')
    {
      free(line);
      return (NULL);
    }
  return (NULL);
}

char		*get_next_line(const int fd)
{
  char		buffer[BUFFER + 1];
  static char	*reading;
  static int	size = 0;
  int		ret;

  ret = 1;
  while (ret > 0)
    {
      ret = read(fd, buffer, BUFFER);
      if (ret != 0)
	{
	  buffer[ret] = '\0';
	  size += ret + 1;
	  reading = my_realloc(reading, size);
	  my_strcat(reading, buffer);
	}
    }
  return (get_line(reading, size));
}
