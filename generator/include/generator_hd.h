/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** __DESCRIPTION__
*/

#ifndef GENERATOR_HEADER
#define GENERATOR_HEADER

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct info_lab {
    int x;
    int y;
    bool perfect;
} info_lab_t;

typedef struct last_pos {
    int x;
    int y;
} last_pos_t;

enum moovement {UP = 1, DOWN = 2, LEFT = 3, RIGHT = 4};

    /*Back_tracking*/
        /*create_labyrinth*/
char **create_labyrinth(info_lab_t);

        /*read_lab*/
bool loop_labyrinth(char **, info_lab_t, bool *);
bool check_end_maze(int, int, info_lab_t, last_pos_t *);

        /*add_way*/
char **add_way(char **, info_lab_t);

    /*MINI_LIB*/
        /*Lib_number*/
int my_getnbr(char const *);
int my_tab_len_tab(char **);
int my_strncmp(char const *, char const *);

    /*RULE*/
        /*rule_labyrinth*/
last_pos_t random_choose_moove(char **, last_pos_t, info_lab_t, bool);
bool check_no_chance(char **, info_lab_t, int, int);
bool rule_position_exist(int, int, info_lab_t);
bool rule_around_cell(char **, last_pos_t, int, info_lab_t);
int *reini_history(int *, bool *);
int my_tab_len(int *);

#endif
