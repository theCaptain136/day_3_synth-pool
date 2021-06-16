/*
** EPITECH PROJECT, 2021
** a
** File description:
** a
*/

#include "my.h"

int my_strstrlen(char **str)
{
    int i = 0;

    while (str[i] != NULL)
        i++;
    return (i);
}