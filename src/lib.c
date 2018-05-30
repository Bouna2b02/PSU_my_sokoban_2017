/*
** EPITECH PROJECT, 2017
** lib.c
** File description:
** ...
*/

#include "my.h"

int get_size_line(char *str, int line_nbr)
{
	int i = 0;

	for (; str[i] != '\n'; i += 1);
	i  = (i) * line_nbr;
	str = str + i;
	for (i = 0; str[i] && str[i] != '\n'; i += 1);
	return (i + 1);
}

void my_putstr(char *str)
{
	write(1, str, my_strlen(str));
}

int my_strlen(char *str)
{
	int i = 0;

	for (; str[i]; i++);
	return (i);
}

void my_putchar(char c)
{
	write(1, &c, 1);
}