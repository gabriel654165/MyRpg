/*
** EPITECH PROJECT, 2019
** my_putnbr_base
** File description:
** put base
*/
#include "fprintf.h"

int my_fputnbr_basehex(int nbr, char const *base, FILE *fp)
{
    unsigned long long i = 0;
    unsigned long long j = 0;
    if (nbr < 0) {
        my_fputchar('-', fp);
        nbr = -nbr;
    }
    i = nbr / my_strlen(base);
    j = nbr % my_strlen(base);
    if (i > 0)
        my_fputnbr_basehex(i, base, fp);
    my_fputchar(base[j], fp);
    return (0);
}

void fbasehex(int nbr, FILE *fp)
{
    char *base1 = "0123456789abcdef";
    my_fputnbr_basehex(nbr, base1, fp);
}