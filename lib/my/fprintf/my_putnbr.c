/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** put nbr
*/
#include "fprintf.h"

void my_fputnbr(int nbr, FILE *fp)
{
    int nbr2;
    if (nbr < 0) {
        my_fputchar('-', fp);
        nbr = nbr * (-1);
    }
    if (nbr >= 10) {
        nbr2 = nbr % 10;
        nbr = nbr / 10;
        my_fputnbr(nbr, fp);
        my_fputchar(nbr2 + 48, fp);
    } else {
        my_fputchar(nbr + 48, fp);
    }
    return;
}
