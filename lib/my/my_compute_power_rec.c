/*
** EPITECH PROJECT, 2019
** my_compute_power_rec
** File description:
** task04 j5
*/

#include "my.h"

int my_compute_power_rec(int nb, int p)
{
    int nb2 = nb;

    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    nb = nb2 * my_compute_power_rec(nb, p - 1);
    return (nb);
}
