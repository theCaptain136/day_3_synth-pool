/*
** EPITECH PROJECT, 2020
** a
** File description:
** a
*/

int my_strlen(char const *str)
{
    int counter = 0;

    while (str[counter] != '\0') {
        counter++;
    }
    return (counter);
}
