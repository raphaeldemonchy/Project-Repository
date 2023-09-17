##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

NAME	=	mysh

SRC =	src/mysh.c        \
		src/builtin_cd.c        \
		src/init_data.c     \
		src/utils.c     \
		src/gest_disp.c       \
		src/gest_exec.c     \
		src/get_path.c      \
		src/main.c      \
		$(wildcard lib/*.c)

OBJ	=	$(SRC:.c=.o)

all	:	$(NAME)	$(SRC)

$(NAME)	:	$(OBJ)
	gcc	-c	-Wall	-g3	-Wextra	$(SRC)
	gcc	$(OBJ)	-o	$(NAME)

clean :
	rm	-f	src/*.o
	rm	-f	src/*~
	rm  -f  *.o
	rm  -f  *.~
	rm -f lib/*.o
	rm -f lib/*~

fclean :clean
	rm	-f	$(NAME)

re :	fclean	all clean
