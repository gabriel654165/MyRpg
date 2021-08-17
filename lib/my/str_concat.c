/*
** EPITECH PROJECT, 2020
** str_concat
** File description:
** str_concat
*/

#include "my.h"

char *str_concat(char *temp, char *str, char c)
{
    if (str == NULL && temp == NULL)
        return NULL;
    int j = 0;
    int i = my_strlen(temp) + my_strlen(str);
    char *res = malloc(sizeof(char) * (i + 2));
    if (res == NULL)
        return NULL;
    if (temp != NULL)
        for (j = 0; temp[j] != '\0'; j++)
            res[j] = temp[j];
    res[j] = c;
    if (str != NULL)
        for (i = 0, j++; str[i] != '\0'; i++, j++)
            res[j] = str[i];
    res[j] = '\0';
    return res;
}
