##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	matchstick.c	\
		init.c	\
		win.c	\
		organise.c	\
		error.c	\
		ia.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-g

NAME	=	matchstick

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/my/
	gcc -o $(NAME) $(OBJ) -lncurses -L./lib/my -lmy

clean:
	make clean -C ./lib/my/
	rm -f $(OBJ)

fclean:	clean
	make fclean -C ./lib/my/
	rm -f $(NAME)

re:	fclean all
