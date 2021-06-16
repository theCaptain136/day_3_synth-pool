/*
** EPITECH PROJECT, 2021
** day_3_synth-pool
** File description:
** cook
*/

#include "my.h"

void make_pizza(fridge *f)
{
    if (f->tomato < 5 || f->dough < 1 || f->onion < 3 || f->olive < 8 || f->pepper < 8 || f->ham < 4 || f->cheese < 3) {
        printf("you don't have enough ingedients to make pizza. you need to go shopping fist\n");
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
        printf("you don't have enough ingedients to make pizza. you need to go shopping fist\n");
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