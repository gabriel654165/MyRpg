/*
** EPITECH PROJECT, 2020
** my_intlen
** File description:
** my_intlen
*/

//#include "my.h"

int my_intlen(int nbr)
{
    int count = 0;
    while (nbr != 0) {
        nbr /= 10;
        count ++;
    }
    return count;
}
