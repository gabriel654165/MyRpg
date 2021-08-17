/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** my_itoa
*/

#include "my.h"

char *itoa_neg(int i, int temp, char *result)
{
    char *res = NULL;

    temp *= -1;
    res = malloc(sizeof(char) * (my_intlen(temp) + 2));
    for (; temp != 0; i++) {
        res[i] = temp % 10 + '0';
        temp /= 10;
    }
    res[i] = '-';
    res[i+1] = '\0';
    free(result);
    return (my_revstr(res));
}

char *my_itoa(int o)
{
    int i = 0;
    int temp = o;
    char *result = malloc(sizeof(char) * (my_intlen(o) + 1));
    
    if (temp == 0)
        return "0";
    if (o < 0)
        return (itoa_neg(i, temp, result));
    for (i = 0; temp != 0; i++) {
        result[i] = temp % 10 + '0';
        temp /= 10;
    }
    result[i] = '\0';
    return (my_revstr(result));
}
