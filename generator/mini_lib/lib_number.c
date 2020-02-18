/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** __Mini_lib__
*/

#include "generator_hd.h"

int my_getnbr(char const *str)
{
    int i = 0;
    int number = 0;
    int a = 1;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            a *= -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        if (number == 214748364 && str[i] == 8 + 48 && a == -1 &&
            !(str[i + 1] < 58 && str[i + 1] > 47))
            return (-2147483648);
        else if ((number == 214748364 && str[i] > 7 + 48) ||
        number > 214748364)
            return (0);
        number *= 10;
        number += str[i] - 48;
        i++;
    }
    return (number * a);
}

int my_tab_len_tab(char **tab)
{
    int size = 0;

    if (!tab)
        return (0);
    for (size = 0; tab[size]; size++);
    return (size);
}

int my_strncmp(char const *sa, char const *sb)
{
    return (!*sa || (*sa != *sb) ? (*sa - *sb) : my_strncmp(sa + 1, sb + 1));
}
