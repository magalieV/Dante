/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** __DESCRIPTION__
*/

#include "solver_hd.h"

int **alloc_labyrinth(char **labyrinth, int x, int y)
{
    int **my_tab = malloc(sizeof(int *) * (y + 1));

    if (!my_tab)
        exit(84);
    for (int i = 0; labyrinth[i]; i++) {
        my_tab[i] = malloc(sizeof(int) * (x + 1));
        if (!my_tab[i])
            exit(84);
        for (int j = 0; labyrinth[i][j]; j++) {
            my_tab[i][j] = -1;
        }
    }
    return (my_tab);
}

historic_t *add_to_history(historic_t *history, posi_t pos, int depth,
    int *size)
{
    historic_t end = {0};

    history[*size + 1].x = pos.x;
    history[*size + 1].y = pos.y;
    history[*size + 1].depth = depth;
    history[*size + 2] = end;
    *size += 1;
    return (history);
}

int recup_last_history(historic_t *history, posi_t *pos, posi_t max, int *size)
{
    historic_t end = {0};
    int depth = 0;

    if (*size < 2 || (history[*size - 1].x == 0 && history[*size - 1].y == 0)) {
        pos->y = max.y - 1;
        pos->x = max.x - 1;
        depth = 1;
        *size = 0;
    } else {
        pos->y = history[*size - 1].y;
        pos->x = history[*size - 1].x;
        depth = history[*size - 1].depth;
        history[*size] = end;
        *size -= 1;
    }
    return (depth);
}

bool found_way(int **my_maze, char **labyrinth, posi_t *pos, posi_t max)
{
    int moove[8] = {1, 0, 0, 1, -1, 0, 0, -1};
    int a = 0;
    int b = 0;
    bool bol = false;

    for (int i = 0; i < 8; i++) {
        a = pos->x + moove[i];
        b = pos->y + moove[i + 1];
        if (b >= 0 && b < max.y && a >= 0 && a < max.x) {
            if (labyrinth[b][a] == '*' && my_maze[b][a] == -1) {
                bol = true;
                pos->x = a;
                pos->y = b;
                break;
            }
        }
        i++;
    }
    return (bol);
}

int **assign_depth(posi_t max, char **labyrinth)
{
    int **my_maze = alloc_labyrinth(labyrinth, max.x, max.y);
    bool bol = false;
    historic_t *history = create_historic(max.x, max.y);
    posi_t pos = {0};
    int depth = 1;
    int sz_histo = 0;

    1 ? pos.x = max.x - 1, pos.y = max.y - 1 : 0;
    my_maze[pos.y][pos.x] = depth;
    while ((pos.y != 0 || pos.x != 0)) {
        bol = found_way(my_maze, labyrinth, &pos, max);
        if (!bol) {
            (pos.y == max.y - 1 && pos.x == max.x - 1) ? exit(84) : 0;
            depth = recup_last_history(history, &pos, max, &sz_histo);
        } else {
            1 ? depth += 1, my_maze[pos.y][pos.x] = depth : 0;
            history = add_to_history(history, pos, depth, &sz_histo);
        }
    }
    free(history);
    return (my_maze);
}
