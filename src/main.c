/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** ...
*/

#include "my.h"

void is_h_asked(int ac, char *av[])
{
	if (ac < 2)
		exit(84);
	if (av[1][0] == '-' && av[1][1] == 'h') {
		my_putstr("USAGE\n	./my_sokoban map\nDESCRIPTION\n"
		"	map file representing the warehouse map, containing "
		"‘#’ for walls,\n		‘P’ for the player, ‘X’ "
		"for boxes and ‘O’ for storage locations.\n");
		exit(0);
	}
}

void check_x_on_border(char *str[], int lines_nbr)
{
	int x = my_strlen(str[0]);

	for (int i = 0; i < x; i++) {
		if (str[0][i] == 'X' || str[lines_nbr - 1][i] == 'X')
			exit(84);
	}
	for (int i = 0; i < lines_nbr; i++) {
		if (str[i][0] == 'X' || str[i][x] == 'X')
			exit(84);
	}
}

int main(int ac, char *av[])
{
	int lines_nbr = 0;
	char **str;
        list *o_pos;

	is_h_asked(ac, av);
	str = get_map(av[1], &lines_nbr);
	check_x_on_border(str, lines_nbr);
	o_pos = get_o_pos(str, lines_nbr);
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	play_game(str, lines_nbr, av, o_pos);
	free(str);
	return (0);
}
