/*
** EPITECH PROJECT, 2020
** free_tab
** File description:
** free_tab
*/

#include "my.h"

char **free_the_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
    tab = NULL;
    return tab;
}
