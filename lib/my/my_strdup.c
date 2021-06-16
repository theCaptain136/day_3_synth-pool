/*
** EPITECH PROJECT, 2020
** a
** File description:
** a
*/

#include <stddef.h>
#include <stdlib.h>

char *my_strdup(char const *src)
{
    int counter = 0;
    int counter2 = 0;
    char *str = NULL;

    while (src[counter] != '\0') {
        counter++;
    }
    str = malloc((sizeof(char)) * counter + 1);
    while (counter2 < counter) {
        str[counter2] = src[counter2];
        counter2 = counter2 + 1;
    }
    str[counter] = '\0';
    return (str);
}
