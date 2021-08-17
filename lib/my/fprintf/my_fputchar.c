/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** my_fputchar
*/

#include "fprintf.h"

void my_fputchar(char c, FILE *fp)
{
    fwrite(&c, 1, 1, fp);
}