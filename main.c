/*
** EPITECH PROJECT, 2021
** day_3_synth-pool
** File description:
** main
*/

#include "my.h"

int check_for_it(char *str)
{
    if (strcmp(str, "cheese") == 0)
        return (1);
    if (strcmp(str, "dough") == 0)
        return (2);
    if (strcmp(str, "ham") == 0)
        return (3);
    if (strcmp(str, "olive") == 0)
        return (4);
    if (strcmp(str, "onion") == 0)
        return (5);
    if (strcmp(str, "pasta") == 0)
        return (6);
    if (strcmp(str, "pepper") == 0)
        return (7);
    if (strcmp(str, "tomato") == 0)
        return (8);
    return (0);
}

void add_to_fridge(fridge *fridg, char **tmp)
{
    switch (check_for_it(tmp[1])) {
        case 1: fridg->cheese += my_getnbr(tmp[2]); break;
        case 2: fridg->dough += my_getnbr(tmp[2]); break;
        case 3: fridg->ham += my_getnbr(tmp[2]); break;
        case 4: fridg->olive += my_getnbr(tmp[2]); break;
        case 5: fridg->onion += my_getnbr(tmp[2]); break;
        case 6: fridg->pasta += my_getnbr(tmp[2]); break;
        case 7: fridg->pepper += my_getnbr(tmp[2]); break;
        case 8: fridg->tomato += my_getnbr(tmp[2]); break;
    }
}

void loop(fridge *fridg)
{
    char *line = NULL;
    size_t n = 0;
    char **tmp = NULL;

    while (getline(&line, &n, stdin) != EOF) {
        if (line[my_strlen(line) - 1] == '\n')
            line[my_strlen(line) - 1] = '\0';
        tmp = my_strtok(line, ' ');
        if (strcmp(tmp[0], "exit") == 0)
            break;
        else if (my_strstrlen(tmp) == 2 && strcmp(tmp[0], "disp") == 0 && strcmp(tmp[1], "fridge") == 0)
            print(fridg);
        else if (my_strstrlen(tmp) == 3 && strcmp(tmp[0], "addToFridge") == 0 && check_for_it(tmp[1]) > 0 && my_getnbr(tmp[2]) > 0)
            add_to_fridge(fridg, tmp);
        else if (strcmp(tmp[0], "make") == 0) {
            if (my_strstrlen(tmp) >= 2) {
                if (strcmp(tmp[1], "pasta") == 0)
                    make_pasta(fridg);
                else if (strcmp(tmp[1], "pizza") == 0)
                    make_pizza(fridg);
                else
                    printf("'%s': meal unknown\n", tmp[1]);
            } else {
                printf("specify 'pizza' or 'pasta' as a meal for 'make'\n");
            }
        }
        else
            printf("\'%s\': Invalid operation\n", line);
        free_all(tmp);
    }
    free_all(tmp);
    free(line);
    return;
}

void print(fridge *fridg)
{
    printf("tomato = %d\n", fridg->tomato);
    printf("dough = %d\n", fridg->dough);
    printf("onions = %d\n", fridg->onion);
    printf("pasta = %d\n", fridg->pasta);
    printf("olives = %d\n", fridg->olive);
    printf("pepper = %d\n", fridg->pepper);
    printf("ham = %d\n", fridg->ham);
    printf("cheese = %d\n", fridg->cheese);
}

int main(int ac, char **av)
{
    fridge *fridg = boot_fridge();

    if (fridg == NULL)
        return (84);
    if (ac == 1 && my_strstrlen(av) == 1)
        loop(fridg);
    save_at_exit(fridg);
    free(fridg);
    return (0);
}