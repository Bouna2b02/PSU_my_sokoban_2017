/*
** EPITECH PROJECT, 2017
** get_map.c
** File description:
** ...
*/

#include "my.h"

void check_line_length(char *str[], int line_nbr)
{
	int i = 0;
	int keep = my_strlen(str[0]);

	for (; i <= line_nbr; i += 1) {
		if (keep != my_strlen(str[i]))
			exit(84);
	}
}

int invalid_input(char letter)
{
	unsigned int i = 0;
	char allowed_letter[] = {'X', ' ', 'P', '#', 'O', '	'};

	for (; i < sizeof(allowed_letter); i += 1) {
		if (allowed_letter[i] == letter)
			return (0);
	}
	return (1);
}

void check_valid_map(char *str[], int lines_nbr)
{
	for (int x = 0, y = 0; y < lines_nbr && str[y][x]; x += 1) {
		if (str[y][x] == '\n') {
			x = -1;
			y += 1;
		} else if (invalid_input(str[y][x])) {
			exit(84);
		}
	}
}

char *my_strdump(char *str, char *copy)
{
	str = malloc(sizeof(char) * (my_strlen(copy) + 1));
	int i = 0;

	for (; copy[i]; i += 1)
		str[i] = copy[i];
	str[i] = '\0';
	return (str);
}

char **get_map(char *path, int *lines_nbr)
{
	FILE *stream = fopen(path, "r");
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char **str;
	struct stat sb;

	if (stat(path, &sb) == -1 || stream == NULL)
		exit (84);
	str = malloc(sizeof(char) * (sb.st_size + 1));
	for (; (read = getline(&line, &len, stream)) != -1; *lines_nbr += 1)
		str[*lines_nbr] = my_strdump(str[*lines_nbr], line);
	check_valid_map(str, *lines_nbr);
	fclose(stream);
	return (str);
}