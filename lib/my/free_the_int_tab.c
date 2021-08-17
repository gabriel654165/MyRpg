/*
** EPITECH PROJECT, 2020
** free_the_int_tab
** File description:
** free_the_int_tab
*/

#include "my.h"

int **free_the_int_tab(int **tab, int len)
{
    for (int i = 0; i < len; i++) {
        free(tab[i]);
    }
    free(tab);
    tab = NULL;
    return tab;
}
