/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** compare the lenght of two strings
*/
#include "my.h"

int my_strcmp(char const *empty, char const *wanted)
{
    int i = 0;

    if (my_strlen(empty) != my_strlen(wanted))
        return 1;
    for (i = 0; empty[i] != '\0'; ++i)
        if (wanted[i] != empty[i])
            return 1;
    return 0;
}
