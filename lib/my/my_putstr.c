/*
** EPITECH PROJECT, 2020
** a
** File description:
** a
*/

#include "my.h"

int my_putstr(char const *str)
{
    int counter = 0;

    while (str[counter] != '\0') {
        my_putchar(str[counter]);
        counter++;
    }
    return (0);
}
