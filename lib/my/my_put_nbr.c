/*
** EPITECH PROJECT, 2020
** a
** File description:
** a
*/

#include "my.h"

int my_put_nbr(int nb)
{
    int i = 1;
    int n = nb;

    if (n < 0) {
        my_putchar('-');
        my_put_nbr(nb * -1);
        return (0);
    }
    while (n > 9) {
        n = n / 10;
        i = i * 10;
    }
    while (i >= 1) {
        my_putchar(((nb / i) % 10) + '0');
        i = i / 10;
    }
    return (0);
}