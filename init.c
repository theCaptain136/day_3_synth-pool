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

    if (sub_res == NULL || fildes <= 0)
        return (NULL);
    x = read(fildes, sub_res, size);
    close (fildes);
    sub_res[size] = '\0';
    return (sub_res);
}

int error_boot()
{
    char *str = load_1d_arr("./.save");
    int res = 0;

    if (str == NULL)
        return (1);
    for (int i = 0; i < my_strlen(str) - 1; i++) {
        if (str[i] == ' ' && str[i + 1] != ' ')
            res++;
        if ((str[i] < '0' || str[i] > '9') && str[i] != ' ')
            res += 8;
    }
    free(str);
    if (res != 7)
        return (1);
    return (0);
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
    if (fridg == NULL || (fd < 0 && error_boot())) {
        if (error_boot())
            printf("error with './save' file. delete it do fix this. your progess will be lost\n");
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
        free(line);
        free_all(tmp);
        return (fridg);
    }
    fclose(fd2);
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