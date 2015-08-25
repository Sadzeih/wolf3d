##
## Makefile for wolf3d in /home/sadzeih/rendu/Igraph/MUL_2014_wolf3d
## 
## Made by Alexis Guerville
## Login   <guervi_a@epitech.net>
## 
## Started on  Tue Dec  9 16:50:16 2014 Alexis Guerville
## Last update Wed Aug 26 00:14:52 2015 Alexis Guerville
##

CC	= cc

NAME	= wolf3d

RM	= rm -f

SRC	=	parsing/parsing.c \
	 	parsing/my_str_to_wordtab.c \
	 	parsing/get_next_line.c \
	 	events/events.c \
	 	events/move.c \
		draw/vision.c \
		draw/draw.c \
		draw/draw_mini_map.c \
		draw/my_put_pixel_to_image.c \
		functions.c \
	  	main.c

CFLAGS	= -I./include

OBJ	= $(SRC:.c=.o)

LIB	= -lm -lmlx -L./minilibx -lX11 -lXext

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIB)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
