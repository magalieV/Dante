/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** __Generate_maze__
*/

#include "generator_hd.h"

bool check_end_maze(int x, int y, info_lab_t info, last_pos_t *pos)
{
    if (x == info.x - 3 && y == info.y - 1) {
        1 ? pos->x = x + 1, pos->y = y : 0;
        return (true);
    }
    if (x == info.x - 2 && y == info.y - 2) {
        1 ? pos->x = x + 1, pos->y = y : 0;
        return (true);
    }
    if (x == info.x - 1 && y == info.y - 2) {
        1 ? pos->x = x, pos->y = y + 1 : 0;
        return (true);
    }
    if (x == info.x - 2 && y == info.y - 1) {
        1 ? pos->x = x + 1, pos->y = y : 0;
        return (true);
    }
    return (false);
}

last_pos_t *add_to_history(last_pos_t *history, last_pos_t pos, int *size)
{
    last_pos_t end = {0};

    history[*size + 1].x = pos.x;
    history[*size + 1].y = pos.y;
    history[*size + 2] = end;
    *size += 1;
    return (history);
}

void recup_last_history(last_pos_t *history, last_pos_t *pos, int *size)
{
    last_pos_t end = {0};

    if (*size < 2 || (history[*size - 1].x == 0 && history[*size - 1].y == 0)) {
        pos->y = 0;
        pos->x = 0;
        *size = 0;
    } else {
        pos->y = history[*size - 1].y;
        pos->x = history[*size - 1].x;
        history[*size] = end;
        *size -= 1;
    }
}

last_pos_t *create_historic(void)
{
    last_pos_t *history = malloc(sizeof(last_pos_t) * 25000000);
    last_pos_t end = {0};

    history[0].x = 0;
    history[0].y = 0;
    history[1] = end;
    return (history);
}

bool loop_labyrinth(char **labyrinth, info_lab_t info, bool *test)
{
    last_pos_t pos = {0};
    last_pos_t *history = create_historic();
    int size_history = 0;
    int save_x = 0;
    int save_y = 0;
    bool begin = true;

    while (pos.x != 0 || pos.y != 0 || begin) {
        1 ? save_x = pos.x, save_y = pos.y, begin = false : 0;
        pos = random_choose_moove(labyrinth, pos, info, (*test));
        if (save_x == 0 && save_y == 0 && pos.x == -1)
            break;
        if (pos.x == -1) {
            recup_last_history(history, &pos, &size_history);
        } else {
            history = add_to_history(history, pos, &size_history);
            labyrinth[pos.y][pos.x] = '*';
        }
        (pos.y == info.y - 1 && pos.x == info.x - 1) ? *test = false : 0;
    }
    free(history);
}
