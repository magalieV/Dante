/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** __Main function__
*/

#include "generator_hd.h"

char **concat_two_labyrinth(char **one, char **two)
{
    char **new_labyrinth = malloc(sizeof(char *) * (my_tab_len_tab(one) + 1));
    int size = 0;
    int i = 0;
    int j = 0;

    for (i = 0; one[i]; i++) {
        for (size = 0; one[i][size]; size++);
        new_labyrinth[i] = malloc(sizeof(char) * (size + 1));
        if (!new_labyrinth[i])
            exit(84);
        for (j = 0; one[i][j]; j++) {
            if (one[i][j] == '*' || two[i][j] == '*')
                new_labyrinth[i][j] = '*';
            else
                new_labyrinth[i][j] = 'X';
        }
        1 ? free(one[i]), free(two[i]) : 0;
        new_labyrinth[i][j] = '\0';
    }
    1 ? free(one), free(two), new_labyrinth[i] = 0 : 0;
    return (new_labyrinth);
}

void print_maze(char **maze, info_lab_t info)
{
    int err = 0;

    for (int i = 0; i < info.y; i++) {
        err = write(1, maze[i], info.x);
        if (i != info.y - 1)
            err = write(1, "\n", 1);
        free(maze[i]);
    }
    if (err == 0)
        free(maze);
}

void gererate_labyrinth(char **av)
{
    info_lab_t info = {0};
    char **labyrinth = NULL;
    char **imperfect = NULL;
    bool test = true;

    1 ? info.x = my_getnbr(av[1]), info.y = my_getnbr(av[2]) : 0;
    if (info.x > 5000 && info.y > 5000)
        exit(0);
    labyrinth = create_labyrinth(info);
    labyrinth[0][0] = '*';
    loop_labyrinth(labyrinth, info, &test);
    if (!av[3] || !my_strncmp(av[3], "imperfect")) {
        imperfect = create_labyrinth(info);
        imperfect[0][0] = '*';
        test = true;
        loop_labyrinth(imperfect, info, &test);
        labyrinth = concat_two_labyrinth(labyrinth, imperfect);
    }
    print_maze(labyrinth, info);
}

void usage(void)
{
    printf("Usage :\n");
    printf("\t./generator x y [perfect]\n");
    printf("\t\tx is the size of the horizontal axis\n");
    printf("\t\ty is the size of the vertical axis\n");
    exit(84);
}

int main(int ac, char **av)
{
    if (ac < 3)
        usage();
    srand(time(0));
    gererate_labyrinth(av);
}
