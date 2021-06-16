/*
** EPITECH PROJECT, 2021
** B-PSU-200-BER-2-1-bsmysokoban-pablo-elias.herrmann
** File description:
** my_arr_cpy
*/

#include "my.h"

char **my_arr_cpy(char **str, char ***dest)
{
    char **res = arr_cpy(str);

    free_all(*dest);
    return (res);
}

char **arr_cpy(char **arr)
{
    if (arr == NULL) {
        arr = malloc((sizeof(char *)) * 1);
        arr[0] = NULL;
        return (arr);
    }
    char **res = malloc((sizeof(char *)) * my_strstrlen(arr) + 1);
    int i = 0;
    int end = 0;
    int s = 0;
    if (arr == NULL) {
        res[0] = NULL;
        return (res);
    }
    for (i = 0; arr[i] != NULL; i++)
        res[i] = malloc((sizeof(char)) * my_strlen(arr[i]) + 1);
    for (s = 0; arr[s] != NULL; s++)
        res[s] = my_strdup(arr[s]);
    res[s] = NULL;
    return (res);
}

void free_all(char **str)
{
    for (int i = 0; str[i] != NULL; i++)
        free(str[i]);
    free(str);
}
