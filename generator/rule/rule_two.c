/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** __DESCRIPTION__
*/

#include "generator_hd.h"

int *reini_history(int *history, bool *should)
{
    if (should)
        history = malloc(sizeof(int) * 5);
    if (!history)
        exit(84);
    *should = false;
    for (int i = 0; i < 4; i++)
        history[i] = -1;
    return (history);
}

bool rule_position_exist(int x, int y, info_lab_t info)
{
    if (x < 0 || y < 0 || x > info.x - 1 || y > info.y - 1)
        return (false);
    return (true);
}

int my_tab_len(int *tab)
{
    int i = 0;

    while (tab && tab[i] != -1)
        i += 1;
    return (i);
}

static last_pos_t found_last_pos(int j, int i, int my_rand)
{
    last_pos_t pos = {0};

    switch (my_rand) {
        case UP:
            pos.x = j;
            pos.y = i + 1;
        break;
        case DOWN:
            pos.x = j;
            pos.y = i - 1;
        break;
        case LEFT:
            pos.x = j + 1;
            pos.y = i;
        break;
        default:
            pos.x = j - 1;
            pos.y = i;
        break;
    }
    return (pos);
}

bool rule_around_cell(char **labyrinth, last_pos_t pos, int my_rand,
    info_lab_t info)
{
    int moove[8] = {1, 0, 0, 1, -1, 0, 0, -1};
    int x_tmp = 0;
    int y_tmp = 0;
    last_pos_t last = found_last_pos(pos.x, pos.y, my_rand);

    for (int i = 0; i < 8; i++) {
        x_tmp = pos.x + moove[i];
        y_tmp = pos.y + moove[i + 1];
        if ((x_tmp != last.x || y_tmp != last.y)
        && rule_position_exist(x_tmp, y_tmp, info)
        && labyrinth[y_tmp][x_tmp] == '*')
            return (false);
        i += 1;
    }
    return (true);
}
