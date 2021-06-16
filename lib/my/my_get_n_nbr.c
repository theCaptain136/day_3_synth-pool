/*
** EPITECH PROJECT, 2020
** a
** File description:
** a
*/


#include "my.h"

int n_start(char const *str, int *i)
{
    int a = *i;

    while ((str[a] <= 47 || str [a] >= 58) && (str[a] != '\0') && str[a] \
    != '\n') {
        a++;
        *i = *i + 1;
    }
    return (a);
}

int my_get_n_nbr(char *str, int *i)
{
    int a = n_start(str, i);
    int si = sign(str);
    int stor = 0;
    long res = 0;

    if (res > 2147483647 || res < -2147483648)
        return (0);
    while (str[a] >= 48 && str[a] <= 57) {
        stor = (str[a] - '0');
        res = res * 10;
        res = res + stor;
        a++;
        *i = *i + 1;
    }
    *i = *i + 1;
    return (res);
}
