/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** my_fputstr
*/

#include "fprintf.h"

void my_fputstr(char *str, FILE *fp)
{
    for (int i = 0; str[i]; i++)
        my_fputchar(str[i], fp);
}