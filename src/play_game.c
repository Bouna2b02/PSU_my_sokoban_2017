/*
** EPITECH PROJECT, 2017
** play_game.c
** File description:
** ...
*/

#include "my.h"
#include <ncurses.h>
#include <stdlib.h>

void get_player_pos(char *str[], int *i, int *j, int lines_nbr)
{
	*i = 0;
	*j = 0;
	for (; *j < lines_nbr; *i += 1) {
		if (str[*j][*i] == 'P')
			return;
		else if (str[*j][*i] == '\n') {
			*j += 1;
			*i = -1;
		}
	}
	endwin();
	exit(84);
}

void move_player(char *s[], int mv_x, int m_y, int lines_nbr, char *av[],
list *o_pos)
{
	int x;
	int y;

	get_player_pos(s, &x, &y, lines_nbr);
	if ( y + m_y < 0 || ((y + m_y * 2 <= 0 || y + m_y * 2 + 1 == lines_nbr)
		&& s[y + m_y][x] == 'X'))
		return;
	clear();
	if (y + m_y == lines_nbr - 1 || s[y + m_y][x + mv_x] == '#' ||
		s[y + m_y][x + mv_x] == '\0') {
		play_game(s, lines_nbr, av, o_pos);
		return;
	} else if (s[y + m_y][x + mv_x] == 'X' && (s[y + m_y * 2][x + mv_x * 2]
		== ' ' || s[y + m_y * 2][x + mv_x * 2] == 'O')) {
		s[y + m_y][x + mv_x] = ' ';
		s[y + m_y * 2][x + mv_x * 2] = 'X';
	}
	if (s[y + m_y][x + mv_x] == ' ' || s[y + m_y][x + mv_x] == 'O') {
		s[y + m_y][x + mv_x] = 'P';
		s[y][x] = ' ';
	}
	play_game(s, lines_nbr, av, o_pos);
}

void manage_input(char *str[], int lines_nbr, int ch, char *av[], list *o_pos)
{
	switch (ch) {
	case 65:
		move_player(str, 0, -1, lines_nbr, av, o_pos);
		break;
	case 66:
		move_player(str, 0, 1, lines_nbr, av, o_pos);
		break;
	case 67:
		move_player(str, 1, 0, lines_nbr, av, o_pos);
		break;
	case 68:
		move_player(str, -1, 0, lines_nbr, av, o_pos);
		break;
	case 32:
		clear();
		main(2, av);
	default:
		break;
	}
}

void screen_too_small(char *str[], int lines_nbr, int *row, int *col)
{
	char *msg[4] = {"Your", "Screen", "Is too", "Small"};

	if (my_strlen(str[0]) > *col || lines_nbr > *row) {
		for (int i = 0; i < 4; i += 1) {
			mvprintw((*row / 2 - 4 / 2) + i,
			(*col - my_strlen(msg[i])) / 2, "%s", msg[i]);
		}
	}
}

void add_o(list *o_pos, char *str[])
{
	element *elem = o_pos->first;

	for (; elem != NULL; elem = elem->next) {
		if (str[elem->y][elem->x] == ' ')
			str[elem->y][elem->x] = 'O';
	}
}
