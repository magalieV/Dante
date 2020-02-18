/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** __DESCRIPTION__
*/

#include "solver_hd.h"

void found_above(int **result, posi_t max, int *my_x, int *my_y)
{
    int moove[8] = {1, 0, 0, 1, -1, 0, 0, -1};
    int a = 0;
    int b = 0;
    int res = -1;
    int save_a = 0;
    int save_b = 0;

    for (int i = 0; i < 8; i++) {
        a = *my_x + moove[i];
        b = *my_y + moove[i + 1];
        if (a >= 0 && a < max.x && b >= 0 && b < max.y) {
            if ((res < 0 || (result[b][a] < res && result[b][a] >= 0))) {
                res = result[b][a];
                save_a = a;
                save_b = b;
            }
        }
        i++;
    }
    *my_x = save_a;
    *my_y = save_b;
}

char **concat_result_maze(int **result, char **maze, posi_t max)
{
    int my_x = 0;
    int my_y = 0;

    maze[0][0] = 'o';
    while (my_x != max.x - 1 || my_y != max.y - 1) {
        found_above(result, max, &my_x, &my_y);
        maze[my_y][my_x] = 'o';
    }
    return (maze);
}

void print_maze(char **maze, int x, int y)
{
    int err = 0;

    for (int i = 0; i < y; i++) {
        err = write(1, maze[i], x);
        if (i != y - 1)
            err = write(1, "\n", 1);
        free(maze[i]);
    }
    if (err == 0)
        free(maze);
}

void solver(char **av)
{
    char **labyrinth = read_doub_file(av[1]);
    int **result = NULL;
    posi_t my_pos = {0};

    if (!labyrinth)
        exit(84);
    check_size_layrint(&my_pos.x, &my_pos.y, labyrinth);
    if (my_pos.x > 5000 && my_pos.y > 5000)
        exit(0);
    if (labyrinth[0][0] != '*' || labyrinth[my_pos.y - 1][my_pos.x - 1] != '*')
        exit(84);
    result = assign_depth(my_pos, labyrinth);
    labyrinth = concat_result_maze(result, labyrinth, my_pos);
    print_maze(labyrinth, my_pos.x, my_pos.y);
}

int main(int ac, char **av)
{
    if (ac < 2)
        return (84);
    solver(av);
    return (0);
}
