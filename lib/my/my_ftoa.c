/*
** EPITECH PROJECT, 2020
** my_ftoa
** File description:
** my_ftoa
*/

#include "my.h"

float my_getnbr_float(char *str)
{
    int len = my_strlen(str), n = 0, i = 0;
    float f = 1.0, val = 0.0;
    
    while(i < len && str[i] != '.')
        n = 10 * n + (str[i++] - '0');
    if(i == len)
        return n;
    i++;
    while(i<len)
    {
        f *= 0.1;
        val += f * (str[i++] - '0');
    }
    return(val+n);
}

char *my_ftoa(float nbr)
{
    float res = nbr - (int)nbr;
    res *= 100000;
    char *integer = str_concat(my_itoa((int)nbr), my_itoa(res), '.');
    return integer;
}
