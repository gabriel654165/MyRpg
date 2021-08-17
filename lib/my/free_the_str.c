/*
** EPITECH PROJECT, 2020
** free_the_str
** File description:
** free_the_str
*/

#include "my.h"

char *free_the_str(char *str)
{
    if (str != NULL)
        free(str);
    return NULL;
}
