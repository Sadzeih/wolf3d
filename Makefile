##
## Makefile for wolf3d in /home/sadzeih/rendu/Igraph/MUL_2014_wolf3d
## 
## Made by Alexis Guerville
## Login   <guervi_a@epitech.net>
## 
## Started on  Tue Dec  9 16:50:16 2014 Alexis Guerville
## Last update Mon Dec 15 15:38:16 2014 Alexis Guerville
##

CC	= cc

NAME	= wolf3d

RM	= rm -f

SRC	= 	events.c \
	  	parsing.c \
	  	my_str_to_wordtab.c \
	  	get_next_line.c \
	  	functions.c \
	  	vision.c \
	  	main.c \
	  	draw.c \
		draw_mini_map.c \
		move.c \
		my_put_pixel_to_image.c

CFLAGS	= -g -I./include

OBJ	= $(SRC:.c=.o)

LIB	= -lm -lmlx -L/usr/lib64/minilibx -lX11 -lXext

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIB)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
