/*
** EPITECH PROJECT, 2017
** end_game.c
** File description:
** ...
*/

#include "my.h"

int not_empity(char what)
{
	if (what == '#' || what == 'X')
		return (1);
	return (0);
}

int is_blocked(char *str[], int x, int y, list *entry)
{
	element *elem = entry->first;

	for (; elem != NULL; elem = elem->next) {
		if (str[elem->y][elem->x] == ' ') {
			str[elem->y][elem->x] = 'O';
		}
	}
	if (not_empity(str[y][x + 1]) || not_empity(str[y][x - 1])) {
		if (not_empity(str[y + 1][x]) || not_empity(str[y - 1][x]))
			return (1);
	}
	if (not_empity(str[y - 1][x]) || not_empity(str[y + 1][x])) {
		if (not_empity(str[y][x + 1] || not_empity(str[y][x - 1])))
			return (1);
	}
	return (0);
}

void check_map_blocked(list *o_pos, char *str[], int lines_nbr)
{
	int i = 0;
	int j = 0;

	for (; j < lines_nbr; i += 1) {
		if (str[j][i] == '\n') {
			j += 1;
			i = -1;
		} else if (str[j][i] == 'X' && !is_blocked(str, i, j, o_pos))
			return;
	}
	endwin();
	exit(1);
}

void check_win_game(char *str[], list *o_pos)
{
	element *elem = o_pos->first;

	while (elem != NULL) {
		if (str[elem->y][elem->x] != 'X')
			return;
		elem = elem->next;
	}
	endwin();
	my_putstr("Wp ! You won !\n");
	exit(0);
}

void check_end_game(char *str[], int lines_nbr, list *o_pos)
{
	check_win_game(str, o_pos);
	check_map_blocked(o_pos, str, lines_nbr);
}
