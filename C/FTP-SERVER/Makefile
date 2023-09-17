##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

NAME	= myftp

SRC	=   *.c \
		serveur/src/*.c\
		my_lib/*.c\
		cmd/*.c

all:	$(NAME)

$(NAME):
			gcc -o  $(NAME) $(SRC) -g3

clean:
	rm		-rf		$(OBJ)

fclean:
	rm	 -rf 	$(NAME)

re:		fclean all clean
