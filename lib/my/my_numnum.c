/*
** EPITECH PROJECT, 2020
** a
** File description:
** a
*/

int my_numnum(char *str)
{
    int counter = 0;
    int n = 0;

    while (str[counter] != '\0') {
        if (str[counter] >= '0' && str[counter] <= '9') {
            n++;
        }
        counter++;
    }
    return (n);
}
