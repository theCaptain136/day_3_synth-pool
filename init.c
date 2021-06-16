/*
** EPITECH PROJECT, 2021
** day_3_synth-pool
** File description:
** init
*/

#include "my.h"

int st_size(char const *filepath)
{
    struct stat buf;
    int stat_r = (stat(filepath, &buf));
    int res = buf.st_size;

    return (res);
}

char *load_1d_arr(char *filepath)
{
    int fildes = open(filepath, O_RDONLY);
    int size = st_size(filepath);
    char *sub_res = malloc((sizeof(char)) * (size) + 1);
    int x = 0;

    if (sub_res == NULL)
        return (NULL);
    x = read(fildes, sub_res, size);
    close (fildes);
    sub_res[size] = '\0';
    return (sub_res);
}