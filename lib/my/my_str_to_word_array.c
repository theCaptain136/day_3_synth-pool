/*
** EPITECH PROJECT, 2020
** a
** File description:
** a
*/

#include<stdlib.h>
#include<unistd.h>
#include<stddef.h>
#include<stdio.h>

int is_alpha(char c)
{
    if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90)
        || (c >= 97 && c <= 122)) {
        return (1);
    }
    else
        return (0);
}

int wordnum(char const *str)
{
    int word = 0;
    int counter = 0;

    while (str[counter] != '\0') {
        if (is_alpha(str[counter]) == 1 && is_alpha(str[counter + 1]) == 0)
            word++;
        counter++;
    }
    return (word);
}

char **result(char const *str, char **res, int len, int save_var)
{
    int big_it = 0;
    int cell = 0;
    int line = 0;

    for (; str[big_it] != '\0'; cell++) {
        for (big_it; is_alpha(str[big_it]) == 0;big_it++);
        save_var = big_it;
        for (big_it; is_alpha(str[big_it]) == 1; big_it++)
            len++;
        res[cell] = malloc((sizeof(char) * (len + 1)));
        len = 0;
        while (is_alpha(str[save_var]) == 1) {
            res[cell][line] = str[save_var];
            save_var++;
            line++;
        }
        res[cell][line] = '\0';
        line = 0;
    }
    return (res);
}

char **my_str_to_word_array(char const *str)
{
    int big_it = 0;
    int len = 0;
    int words = wordnum(str);
    char **res = NULL;
    int cell = 0;
    int save_var = 0;
    int line = 0;

    res = malloc((sizeof(char *) * (words + 1)));
    if (res == NULL)
        return (NULL);
    res[words] = NULL;
    return (result(str, res, len, save_var));
}
