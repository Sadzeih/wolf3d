/*
** my_str_to_wordtab.c for fdf in /home/guervi_a/rendu/Igraph/MUL_2014_fdf
** 
** Made by Alexis Guerville
** Login   <guervi_a@epitech.net>
** 
** Started on  Sun Nov 16 14:01:31 2014 Alexis Guerville
** Last update Tue Dec 16 13:57:59 2014 Alexis Guerville
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include "my.h"
#include "get_next_line.h"

int	count_words(char *str)
{
  int	i;
  int	words;

  i = 0;
  words = 0;
  while (str[i] != '\0')
    {
      while (str[i] != '\0' && (str[i++] == ' ' || str[i] == '\t'));
      while (str[i] != '\0' && (str[i] != ' ' && str[i] != '\t'))
	{
	  i++;
	}
      if (str[i - 1] != ' ' && str[i - 1] != '\t')
	words++;
    }
  return (words);
}

int	wordlen(char *str, int nb_word)
{
  int	i;
  int	j;
  int	wordlen;

  i = 0;
  j = 1;
  wordlen = 1;
  while (str[i] != '\0' && j <= nb_word)
    {
      while (str[i] != '\0' && (str[i++] == ' ' || str[i] == '\t'));
      while (str[i] != '\0' && (str[i] != ' ' && str[i] != '\t'))
	{
	  if (j == nb_word)
	    wordlen++;
	  i++;
	}
      j++;
    }
  return (wordlen);
}

int	get_word(char *str, int nb)
{
  int	i;
  int	j;
  int	k;
  char	*word;

  i = 0;
  k = 1;
  if ((word = malloc(wordlen(str, nb) + 1 * sizeof(char))) == NULL)
    return (0);
  while (str[i] != '\0' && k <= nb)
    {
      j = 0;
      while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
	i++;
      while (str[i] != '\0' && (str[i] != ' ' && str[i] != '\t'))
	{
	  if (k == nb)
	    word[j] = str[i];
	  i++;
	  j++;
	}
      k++;
    }
  word[j] = '\0';
  return (my_getnbr(word));
}

int	*my_str_to_wordtab(char *str)
{
  int	*tab;
  int	nbr_words;
  int	i;
  int	j;

  i = 0;
  j = 1;
  nbr_words = count_words(str);
  if ((tab = malloc(nbr_words * sizeof(int))) == NULL)
    return (0);
  while (j <= count_words(str))
    {
      tab[i] = get_word(str, j);
      i++;
      j++;
    }
  return (tab);
}
