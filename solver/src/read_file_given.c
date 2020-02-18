/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** __DESCRIPTION__
*/

#include "solver_hd.h"

historic_t *create_historic(int x, int y)
{
    historic_t *history = malloc(sizeof(historic_t) * 25000000);
    historic_t end = {0};

    history[0].x = x - 1;
    history[0].y = y - 1;
    history[0].depth = 1;
    history[1] = end;
    return (history);
}

void check_size_layrint(int *x, int *y, char **labyrinth)
{
    int i = 0;
    int j = 0;

    for (i = 0; labyrinth[i]; i++);
    for (j = 0; labyrinth[0][j]; j++);
    *x = j;
    *y = i;
}

static char *my_read_file(char const *str)
{
    char *fin = NULL;
    struct stat data = {0};
    int op = 0;

    op = open(str, O_RDONLY);
    if (op == -1)
        exit(84);
    stat(str, &data);
    fin = malloc(sizeof(char) * (data.st_size + 1));
    if (read(op, fin, data.st_size) == -1)
        exit(84);
    close(op);
    return (fin);
}

char **read_doub_file(char const *str)
{
    char *tmp = NULL;
    char **button = NULL;

    tmp = my_read_file(str);
    if (tmp == NULL)
        return (NULL);
    button = my_str_to_word_array(tmp);
    free(tmp);
    return (button);
}
