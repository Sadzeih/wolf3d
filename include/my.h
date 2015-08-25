/*
** my.h for wolf3d in /home/sadzeih/rendu/Igraph/MUL_2014_wolf3d
** 
** Made by Alexis Guerville
** Login   <guervi_a@epitech.net>
** 
** Started on  Tue Dec  9 14:10:57 2014 Alexis Guerville
** Last update Wed Aug 26 00:27:11 2015 Alexis Guerville
*/

#ifndef			MY_H_
# define		MY_H_

# define		ABS(value) ((value) < 0) ? ((value) * (-1)) : (value)

# define		ARROW_UP 65362
# define		ARROW_DOWN 65364
# define		ARROW_LEFT 65361
# define		ARROW_RIGHT 65363
# define		ESCAPE 65307
# define		SEGMENT 1
# define		DIST (0.5)
# define		ANGLE 60
# define		WIN_X 1280
# define		WIN_Y 720

typedef struct		s_window
{
  void			*mlx_ptr;
  void			*mlx_win;
  void			*img;
  void			*mini_map;
  char			*data;
}			t_window;

typedef struct		s_vec
{
  float			x;
  float			y;
}			t_vec;

typedef struct		s_line
{
  int			x;
  int			y;
}			t_line;

typedef struct		s_keys
{
  int			up;
  int			down;
  int			left;
  int			right;
  int			escape;
}			t_keys;

typedef struct		s_player
{
  float			angle;
  t_vec			*pos;
}			t_player;

typedef struct		s_draw_minimap
{
  int			x;
  int			y;
  int			size;
}			t_draw_minimap;

typedef struct		s_game
{
  t_keys		*keys;
  t_window		*window;
  t_player		*player;
  t_vec			*vec;
  t_draw_minimap	*draw_minimap;
  float			k;
  float			h;
  int			**map;
  int			map_x;
  int			map_y;
  char			or_color;
}			t_game;

int			hook_press(int keycode, t_game *game);
int			hook_release(int keycode, t_game *game);
int			gere_key(t_game *game);
int			**tab_tab_int(char **tab_lines, char *file_name);
char			**get_tab_lines(int fd, char *file_name);
char			*my_strdup(char *src);
int			*my_str_to_wordtab(char *str);
int			events(t_game *game);
int			count_lines(char *file_name);
int			count_words(char *tab_char);
char			*my_strcpy(char *dest, char *src);
void			my_pixel_put_to_minimap(t_game *game, int x, int y,\
					   unsigned int color);
void			my_pixel_put_to_image(t_game *game, int x, int y,\
					      unsigned int color);
int			draw_roof(t_game *game, int x);
int			draw_walls(t_game *game, int x);
int			draw_floor(t_game *game, int x);
int			my_getnbr(char *str);
int			move(t_game *game);
int			view(t_game *game);
int			draw_mini_map(t_game *game);

#endif			/* !MY_H_ */
