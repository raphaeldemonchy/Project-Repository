##
## EPITECH PROJECT, 2022
## B-OOP-400-MAR-4-1-raytracer-raphael.de-monchy
## File description:
## Makefile
##

SRC	=	rayTracer.cpp	\
		include/vector3D/vector3D.cpp	\
		include/point3D/point3D.cpp	\
		include/sphere3D/sphere3D.cpp	\
		include/ray/ray.cpp	\

OBJ	=	$(SRC:.cpp=.o)

NAME	=	raytracer

all:	$(NAME)

$(NAME):
		g++	-std=c++20	-c	$(SRC)
		g++	-std=c++20	$(SRC)	-o	$(NAME)
		./$(NAME) > raytracer.ppm

clean:
		rm	-rf	$(OBJ)
		rm	-rf	*.o
		rm	-rf	*~

fclean:	clean
		rm	-rf	$(NAME)

re:	fclean	all