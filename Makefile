##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CFLAGS	=	-Wall -Wextra

SRC_DIR	=	src/

MAIN	=	$(SRC_DIR)main.c

SRC	=	$(SRC_DIR)lib.c \
		$(SRC_DIR)play_game.c \
		$(SRC_DIR)linked_lib.c \
		$(SRC_DIR)end_game.c \
		$(SRC_DIR)display_ncurse.c \
		$(SRC_DIR)get_map.c

NAME	=	my_sokoban

INCLUDES	=	includes/

.PHONY: all $(NAME) clean fclean re

all:	$(NAME)
	gcc -o $(NAME) $(MAIN) $(SRC) -I $(INCLUDES) $(CFLAGS) -l ncurses -g3 

test:	$(NAME)
	gcc  $(SRC) $(MAIN) -I $(INCLUDES)

clean:
	rm -f *.o
	rm -rf vgcore*

fclean: clean
	rm -f libmy.a
	rm -rf $(NAME)

re:	$(fclean) all
