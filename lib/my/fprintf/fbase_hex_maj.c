/*
** EPITECH PROJECT, 2019
** my_putnbr_base
** File description:
** put base
*/
#include "fprintf.h"

int my_fputnbr_basehex_maj(int nbr, char const *base, FILE *fp)
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
        my_fputnbr_basehex_maj(i, base, fp);
    my_fputchar(base[j], fp);
    return (0);
}

void fbasehex_maj(int nbr, FILE *fp)
{
    char *base = "0123456789ABCDEF";
    my_fputnbr_basehex_maj(nbr, base, fp);
}
