/*
** EPITECH PROJECTS, 2017
** my.h
** File description:
** ...
*/

#ifndef MY_H

	typedef struct element element;
	typedef struct list list;

	struct element
	{
		int x;
		int y;
		element *next;
	};

	struct list
	{
		element *first;
	};

	#define MY_H
	#include <ncurses.h>
	#include <unistd.h>
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <fcntl.h>
	#include <stdio.h>
	#include <stdlib.h>

	list *get_o_pos(char *str[], int lines_nbr);
	void my_putstr(char *);
	int my_strlen(char *);
	char **get_map(char *path, int *lines_nbr);
	void move_player(char *str[], int, int, int, char *[], list *o);
	int main(int ac, char *av[]);
	void manage_input(char *s[], int, int, char *av[], list *o);
	void play_game(char *str[], int, char *av[], list *o_pos);
	void check_end_game(char *str[], int lines_nbr, list *o_pos);
	void check_map_blocked(list *o_pos, char *str[], int lines_nbr);
	void init_screen(int *row, int *col, int lines_nbr, char *str[]);
	void play_game(char *str[], int lines_nbr, char *av[], list *o_pos);
	void init_screen(int *row, int *col, int lines_nbr, char *str[]);
	void init_screen(int *row, int *col, int lines_nbr, char *str[]);
	void screen_too_small(char *str[], int lines_nbr, int *row, int *col);
	void add_o(list *o_pos, char *str[]);
#endif