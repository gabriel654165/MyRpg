/*
** EPITECH PROJECT, 2020
** my_tab_len
** File description:
** my_tab_len
*/

#include "my.h"

int my_tab_len(char **tab)
{
    int i;
    for (i = 0; tab[i] != NULL; i++);
    return i;
}
