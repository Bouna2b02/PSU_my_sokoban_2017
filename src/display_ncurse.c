/*
** EPITECH PROJECT, 2017
** display_ncurse.c
** File description:
** ...
*/

#include "my.h"

void init_screen(int *row, int *col, int lines_nbr, char *str[])
{
	getmaxyx(stdscr, *row, *col);
	screen_too_small(str, lines_nbr, row, col);
}

void play_game(char *str[], int lines_nbr, char *av[], list *o_pos)
{
	int row;
	int col;
	int ch = 2;

	clear();
	init_screen(&row, &col, lines_nbr, str);
	add_o(o_pos, str);
	for (int i = 0; i < lines_nbr; i += 1)
		mvprintw((row / 2 - lines_nbr / 2) + i,
		(col - my_strlen(str[i])) / 2, "%s", str[i]);
	refresh();
	while (ch != KEY_F(1)) {
		check_end_game(str, lines_nbr, o_pos);
		ch = getch();
		manage_input(str, lines_nbr, ch, av, o_pos);
	}
}
