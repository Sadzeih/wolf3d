/*
** my.h for wolf3d in /home/sadzeih/rendu/Igraph/MUL_2014_wolf3d
** 
** Made by Alexis Guerville
** Login   <guervi_a@epitech.net>
** 
** Started on  Tue Dec  9 14:10:57 2014 Alexis Guerville
** Last update Tue Dec  9 16:49:31 2014 Alexis Guerville
*/

#ifndef		MY_H_
# define	MY_H_

# define	ABS(value) ((value) < 0) ? ((value) * (-1)) : (value)

# define	ARROW_UP 65362
# define	ARROW_DOWN 65364
# define	ARROW_LEFT 65361
# define	ARROW_RIGHT 65363
# define	ESCAPE 65307

typedef struct	s_window
{
  void		*mlx_ptr;
  void		*mlx_win;
  void		*img;
}		t_window;

typedef struct	s_line
{
  int		x;
  int		y;
}		t_line;

typedef struct	s_keys
{
  int		up;
  int		down;
  int		left;
  int		right;
  int		escape;
}		t_keys;

typedef struct	s_game
{
  t_keys	*keys;
  t_window	*window;
}

#endif		/* !MY_H_ */
