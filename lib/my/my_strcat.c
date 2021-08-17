/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** my strkat
*/
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    char *result = malloc(sizeof(char)*(my_strlen(dest) + my_strlen(src)) + 1);
    int i = 0;
    int j = 0;

    for (; dest[i] != '\0'; i++)
        result[i] = dest[i];
    for (; src[j] != '\0'; i++, j++)
        result[i] = src[j];
    result[i] = '\0';
    return result;
}
