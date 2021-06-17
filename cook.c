/*
** EPITECH PROJECT, 2021
** day_3_synth-pool
** File description:
** cook
*/

#include "my.h"

void error_ingedience_pizza(fridge *f)
{
    if (f->tomato < 5)
        printf("'make pizza': not enough tomato\n");
    if (f->dough < 1)
        printf("'make pizza': not enough dough\n");
    if (f->onion < 3)
        printf("'make pizza': not enough onion\n");
    if (f->olive < 8)
        printf("'make pizza': not enough olive\n");
    if (f->pepper < 8)
        printf("'make pizza': not enough pepper\n");
    if (f->ham < 4)
        printf("'make pizza': not enough ham\n");
    if (f->cheese < 3)
        printf("'make pizza': not enough cheese\n");
}

void error_ingedience_pasta(fridge *f)
{
    if (f->tomato < 5)
        printf("'make pizza': not enough tomato\n");
    if (f->pasta < 2)
        printf("'make pizza': not enough dough\n");
    if (f->olive < 6)
        printf("'make pizza': not enough olive\n");
    if (f->pepper < 8)
        printf("'make pizza': not enough pepper\n");
    if (f->ham < 4)
        printf("'make pizza': not enough ham\n");
    if (f->cheese < 3)
        printf("'make pizza': not enough cheese\n");
}

void make_pizza(fridge *f)
{
    if (f->tomato < 5 || f->dough < 1 || f->onion < 3 || f->olive < 8 || f->pepper < 8 || f->ham < 4 || f->cheese < 3) {
        error_ingedience_pizza(f);
        return;
    }
    f->tomato -= 5;
    f->dough -= 1;
    f->onion -= 3;
    f->olive -= 8;
    f->pepper -= 8;
    f->ham -= 4;
    f->cheese -= 3;
    return;
}

void make_pasta(fridge *f)
{
    if (f->tomato < 5 || f->pasta < 2 || f->olive < 6 || f->pepper < 8 || f->ham < 4 || f->cheese < 3) {
        error_ingedience_pasta(f);
        return;
    }
    f->tomato -= 5;
    f->dough -= 1;
    f->onion -= 3;
    f->olive -= 8;
    f->pepper -= 8;
    f->ham -= 4;
    f->cheese -= 3;
    return;
}