/*
** EPITECH PROJECT, 2020
** my_strcat_parser.c
** File description:
** yes
*/

#include "my.h"

char *my_strcat_parser(char *dest, char *src)
{
    char *result = malloc(sizeof(char)*(my_strlen(dest) + my_strlen(src)) + 2);
    int i = 0;
    int j = 0;

    for (; dest[i] != '\0'; i++)
        result[i] = dest[i];
    for (; src[j] != '\0'; i++, j++)
        result[i] = src[j];
    result[i] = '\n';
    result[i + 1] = '\0';
    return result;
}
