/*
** EPITECH PROJECT, 2021
** a
** File description:
** a
*/

#include "my.h"

void put_2d(char **str)
{
    char tmp = '\n';

    for (int i = 0; str[i] != NULL; i++) {
        my_putstr(str[i]);
        write(1, &tmp, 1);
    }
}