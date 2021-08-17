/*
** EPITECH PROJECT, 2019
** my_strdupo
** File description:
** allocate memory and copies the string given in argument
*/
#include "my.h"

char *my_strdup(char const *src)
{
    int i = 0;
    char *str = malloc(sizeof(char) * my_strlen(src) + 3);

    while (i <= my_strlen(src)) {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}
