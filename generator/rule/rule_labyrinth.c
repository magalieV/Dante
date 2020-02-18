/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** __Rule of algorithm__
*/

#include "generator_hd.h"

static bool rule_no_occupied(char **labyrinth, int x, int y, info_lab_t info)
{
    if (rule_position_exist(x, y, info) && labyrinth[y][x] == '*')
        return (false);
    return (true);
}

static last_pos_t assign_my_rand(int my_rand, int i, int j)
{
    last_pos_t pos = {0};

    switch (my_rand) {
        case UP:
            pos.x = j;
            pos.y = i - 1;
        break;
        case DOWN:
            pos.x = j;
            pos.y = i + 1;
        break;
        case LEFT:
            pos.x = j - 1;
            pos.y = i;
        break;
        default:
            pos.x = j + 1;
            pos.y = i;
        break;
    }
    return (pos);
}

static last_pos_t found_end_labyrinth(int x, int y, info_lab_t info)
{
    last_pos_t pos = {0};

    if (x == info.x - 1 && y == info.y - 3) {
        1 ? pos.x = x, pos.y = y + 1 : 0;
        return (pos);
    }
    if (x == info.x - 2 && y == info.y - 3) {
        1 ? pos.x = x, pos.y = y + 1 : 0;
        return (pos);
    }
    if (x == info.x - 3 && y == info.y - 2) {
        1 ? pos.x = x + 1, pos.y = y : 0;
        return (pos);
    }
    if (check_end_maze(x, y, info, &pos) == true)
        return (pos);
    pos.x = -1;
    return (pos);
}

static void add_to_history(int *history, int id)
{
    int len = my_tab_len(history);

    for (int j = 0; j < len; j++) {
        if (history[j] == id)
            return;
    }
    history[len] = id;
    history[len + 1] = -1;
}

last_pos_t random_choose_moove(char **labyrinth, last_pos_t posi,
    info_lab_t info, bool bol)
{
    int my_rand = rand() % 4 + 1;
    last_pos_t pos = {0};
    static bool should = true;
    static int *history = NULL;

    history = reini_history(history, &should);
    if (bol) {
        pos = found_end_labyrinth(posi.x, posi.y, info);
        if (pos.x != -1)
            return (pos);
        }
    pos = assign_my_rand(my_rand, posi.y, posi.x);
    while ((!rule_position_exist(pos.x, pos.y, info)
        || !rule_around_cell(labyrinth, pos, my_rand, info)
        || !rule_no_occupied(labyrinth, pos.x, pos.y, info))) {
        1 ? add_to_history(history, my_rand), my_rand = rand() % 4 + 1 : 0;
        pos = assign_my_rand(my_rand, posi.y, posi.x);
        if (my_tab_len(history) == 4 && (pos.x = -1))
            return (pos);
    }
    return (pos);
}
