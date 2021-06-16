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
        else if (my_strstrlen(tmp) == 3 && strcmp(tmp[0], "add") == 0 && check_for_it(tmp[1]) > 0 && my_getnbr(tmp[2]) > 0)
            add_to_fridge(fridg, tmp);
        else if (my_strstrlen(tmp) == 2 && strcmp(tmp[0], "make") == 0 && strcmp(tmp[1], "pasta") == 0)
            make_pasta(fridg);
        else if (my_strstrlen(tmp) == 2 && strcmp(tmp[0], "make") == 0 && strcmp(tmp[1], "pizza") == 0)
            make_pizza(fridg);
        else
            printf("\'%s\': Invalid operation\n", tmp[0]);
        free_all(tmp);
    }
    free_all(tmp);
    free(line);
    return;
}

void print(fridge *fridg)
{
    printf("cheese = %d\n", fridg->cheese);
    printf("dough = %d\n", fridg->dough);
    printf("ham = %d\n", fridg->ham);
    printf("olives = %d\n", fridg->olive);
    printf("onions = %d\n", fridg->onion);
    printf("pasta = %d\n", fridg->pasta);
    printf("pepper = %d\n", fridg->pepper);
    printf("tomato = %d\n", fridg->tomato);
}

fridge *boot_fridge()
{
    int fd = open ("./.save", O_RDWR | O_CREAT, 0777);
    FILE *fd2 = NULL;
    fridge *fridg = malloc(sizeof(fridge));
    char *line = NULL;
    size_t n = 0;
    char dump = 0;
    char **tmp = NULL;
    
    close(fd);
    fd2 = fopen("./.save", "r");
    if (fridg == NULL || fd < 0) {
        fclose(fd2);
        return (NULL);
    }
    if (read(fd, &dump, 1) < 1) {
        fridg->cheese = 50;
        fridg->dough = 50;
        fridg->ham = 50;
        fridg->olive = 50;
        fridg->onion = 50;
        fridg->pasta = 50;
        fridg->pepper = 50;
        fridg->tomato = 50;
        fclose(fd2);
        return (fridg);
    } else {
        fclose(fd2);
        fd2 = fopen("./.save", "r");
        if (getline(&line, &n, fd2) == EOF) {
            fclose(fd2);
            return (NULL);
        }
        tmp = my_strtok(line, ' ');
        if (tmp == NULL) {
            fclose(fd2);
            return (NULL);
        }
        fridg->cheese = my_getnbr(tmp[0]);
        fridg->dough = my_getnbr(tmp[1]);
        fridg->ham = my_getnbr(tmp[2]);
        fridg->olive = my_getnbr(tmp[3]);
        fridg->onion = my_getnbr(tmp[4]);
        fridg->pasta = my_getnbr(tmp[5]);
        fridg->pepper = my_getnbr(tmp[6]);
        fridg->tomato = my_getnbr(tmp[7]);
        fclose(fd2);
        return (fridg);
    }
}

void save_at_exit(fridge *fridg)
{
    int save_out = dup(STDOUT_FILENO);
    int fd = open("./.save", O_TRUNC | O_WRONLY);
    int nb = dup2(fd, STDOUT_FILENO);

    my_put_nbr(fridg->cheese);
    my_putchar(' ');
    my_put_nbr(fridg->dough);
    my_putchar(' ');
    my_put_nbr(fridg->ham);
    my_putchar(' ');
    my_put_nbr(fridg->olive);
    my_putchar(' ');
    my_put_nbr(fridg->onion);
    my_putchar(' ');
    my_put_nbr(fridg->pasta);
    my_putchar(' ');
    my_put_nbr(fridg->pepper);
    my_putchar(' ');
    my_put_nbr(fridg->tomato);
    my_putchar('\n');
    dup2(save_out, STDOUT_FILENO);
    close(fd);
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