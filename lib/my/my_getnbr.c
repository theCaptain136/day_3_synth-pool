/*
** EPITECH PROJECT, 2020
** a
** File description:
** a
*/

#include<stdio.h>

int sign(char const *str)
{
    int a = 0;
    int c = 0;

    while (str[a] <= 47 || str[a] >= 58) {
        if (str[a] == 45)
            c++;
        a++;
    }
    if (c % 2 == 1)
        c = -1;
    else
        c = 1;
    return (c);
}

int start(char const *str)
{
    int a = 0;

    while ((str[a] <= 47 || str [a] >= 58) && (str[a] != '\0'))
    {
        a++;
    }
    return (a);
}

int my_getnbr(char const *str)
{
    int a = start(str);
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
    }
    return (res * si);
}
