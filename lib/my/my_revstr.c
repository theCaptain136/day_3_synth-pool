/*
** EPITECH PROJECT, 2020
** a
** File description:
** a
*/

char *my_revstr(char *str)
{
    int countera = 0;
    int counterb = 0;
    int stor = 0;

    while (str[counterb] != '\0') {
        counterb++;
    }
    counterb--;
    while (countera < counterb) {
        stor = str[countera];
        str[countera] = str[counterb];
        str[counterb] = stor;
        countera++;
        counterb--;
    }
    return (str);
}
