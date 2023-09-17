##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

NAME	=	tetris

CC	=	gcc

LIB	=	-lncurses

SRC	=	src/main.c	\
		src/flag_h.c	\
		src/utils.c	\
		src/gest_disp.c	\
		src/init_panel.c	\
		src/charge_tetriminos.c	\
		lib/my_strcmp.c	\
		lib/my_strlen.c	\
		lib/my_putchar.c	\
		lib/my_putstr.c	\

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	@	$(CC) -g3 $(OBJ) -o $(NAME) $(FLAGS) $(LIB)

clean:
	@	$(RM) $(OBJ)

fclean:
	@	$(RM) $(NAME)

re:	fclean all clean