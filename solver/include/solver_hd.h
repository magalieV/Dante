/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** __DESCRIPTION__
*/

#ifndef SOLVER_HEADER
#define SOLVER_HEADER

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef READ_SIZE
#define READ_SIZE (128)
#endif

typedef struct posi {
    int x;
    int y;
} posi_t;

typedef struct historic {
    int x;
    int y;
    int depth;
} historic_t;

char *get_next_line(int fd);
char **my_str_to_word_array(char const *str);
int **assign_depth(posi_t max, char **labyrinth);
char **read_doub_file(char const *str);
void check_size_layrint(int *x, int *y, char **labyrinth);
historic_t *create_historic(int x, int y);

#endif
