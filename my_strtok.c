/*
** EPITECH PROJECT, 2021
** B-CPE-201-BER-2-1-corewar-eduard.popp
** File description:
** my_strtok
*/

#include "./my.h"

int count_delim(char *str, char delim)
{
    int i = 0;

    for (int a = 1; str[a] != '\0'; a++)
        if (str[a] == delim && str[a - 1] != delim)
            i++;
    return (i);
}

void loop_tok(str_tok t)
{
    for (int a = 0; a < t.end - t.start; a++)
        t.res[*t.cell][a] = t.str[*t.i + t.start + a];
    t.res[*t.cell][t.end - t.start] = '\0';
    *t.i += t.end;
    *t.cell += 1;
}

char **my_strtok(char *str, char delim)
{
    char **res = malloc(sizeof(char *) * (count_delim(str, delim) + 2));
    int start = 0;
    int end = 0;
    int cell = 0;

    if (res == NULL)
        return (NULL);
    for (int i = 0; str[i] != '\0'; i++) {
        for (start = 0; str[start + i] == delim; start++);
        for (end = start; str[end + i] != '\0' && str[end + i] != delim; \
        end++);
        res[cell] = malloc(sizeof(char) * ((end - start) + 1));
        if (res[cell] == NULL)
            return (NULL);
        loop_tok((str_tok){res, end, start, &i, str, &cell});
    }
    res[count_delim(str, delim) + 1] = NULL;
    return (res);
}