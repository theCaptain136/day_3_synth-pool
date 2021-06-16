/*
** EPITECH PROJECT, 2020
** a
** File description:
** a
*/

#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>


void my_putchar(char c);
char *my_strstr(char *, char const);
int my_isneg(int);
int my_strcmp(char const *, char const *);
int my_put_nbr(int);
int my_strncmp(char const *, char const *, int);
void my_swap(int *, int *);
char *my_strupcase(char *);
int my_putstr(char const *);
char *my_strlowcase(char *);
int my_strlen(char *);
char *my_strcapitalize(char *);
int my_getnbr(char const *);
int my_str_isalpha(char const *);
void my_sort_int_array(int *, int);
int my_str_isnum(char const *);
int my_compute_power_rec(int, int);
int my_str_islower(char const *);
int my_compute_square_root(int);
int my_str_isupper(char const *);
int my_is_prime(int);
int my_str_isprintable(char const *);
int my_find_prime_sup(int);
int my_showstr(char const *);
char *my_strcpy(char *, char const *);
int my_showmem(char const *, int);
char *my_strncpy(char *, char const *, int);
char *my_strcat(char *, char const *);
char *my_revstr(char *);
char *my_strncat(char *, char const *, int);
char **my_str_to_word_array(char *);
char *my_strdup(char const *);
char **result(char const *, char **, int, int);
int wordnum(char const *);
int is_alpha(char);
int my_numnum(char *);
int calculate_plus(char *, char *);
int calculate_minus(char **, char *, char *);
int my_strstrlen(char **str);
char **my_arr_cpy(char **str, char ***dest);
char **arr_cpy(char **arr);
void free_all(char **str);
int sign(char const *str);