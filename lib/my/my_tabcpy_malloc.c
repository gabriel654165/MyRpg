/*
** EPITECH PROJECT, 2020
** my_tabcpy
** File description:
** my_tabcpy
*/

#include "my.h"

char **my_tabcpy_malloc(char **tab)
{
    int j = 0;
    int len = my_tab_len(tab);
    char **res = malloc(sizeof(char*) * (len + 1));
    for (j = 0; j < len; j++)
        res[j] = my_strcpy_malloc(tab[j]);
    res[j] = NULL;
    return res;
}
