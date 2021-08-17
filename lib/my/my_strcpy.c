/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** copies a string into another
*/
#include "my.h"

char *my_strcpy_malloc(char *str)
{
    char *temp = malloc(sizeof(char) * (my_strlen(str) + 1));
    int j = 0;
    for (j = 0; str[j] != '\0'; j++)
        temp[j] = str[j];
    temp[j] = '\0';
    return temp;
}

char *my_strcpy(char *dest, char const *src)
{
    int j;
    for (j = 0; src[j] != '\0'; j++) {
        dest[j] = src[j];
    }
    dest[j] = '\0';
    return (dest);
}
