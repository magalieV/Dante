/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** __Create_maze__
*/

#include "generator_hd.h"

static char *alloc_line_labyrinth(char *new_labyrinth, info_lab_t info)
{
    new_labyrinth = malloc(sizeof(char) * (info.x + 1));
    if (!new_labyrinth)
        exit(84);
    return (new_labyrinth);
}

static char **alloc_my_labyrinth(info_lab_t info)
{
    char **new_labyrinth = NULL;

    new_labyrinth = malloc(sizeof(char *) * (info.y + 1));
    if (!new_labyrinth)
        exit(84);
    return (new_labyrinth);
}

char **create_labyrinth(info_lab_t info)
{
    char **new_labyrinth = alloc_my_labyrinth(info);
    int j = 0;

    for (int i = 0; i < info.y; i++) {
        new_labyrinth[i] = alloc_line_labyrinth(new_labyrinth[i], info);
        for (j = 0; j < info.x; j++) {
            new_labyrinth[i][j] = 'X';
        }
        new_labyrinth[i][j] = '\0';
    }
    new_labyrinth[info.y] = 0;
    return (new_labyrinth);
}
