/*
** EPITECH PROJECT, 2019
** my_int_to_str
** File description:
** fonction annexe
*/

#include "my.h"

int my_compute_power_rec(int nb, int p);

char *str01(char *str, int nbr, int ne)
{
    if (nbr == 0) {
        str[0] = nbr + '0';
        str[1] = '\0';
        return (str);
    } else if (ne == 1) {
        str[0] = '-';
        str[1] = nbr + '0';
        str[2] = '\0';
    } else {
        str[0] = nbr + '0';
        str[1] = '\0';
    }
    return (str);
}

char *int_str(char *str, int nbr, int i, int ne)
{
    int instr = 0, nbrstr = 0, p = 0;

    p = my_compute_power_rec(10, i - 1);
    if (ne == 1) {
        instr++;
        str[0] = '-';
    }
    for (; nbr != 0 || p != 0; p = p / 10, instr++) {
        nbrstr = nbr / p;
        nbr = nbr % p;
        str[instr] = nbrstr + '0';
    }
    str[instr] = '\0';
    return (str);
}

char *my_int_to_str(int nbr)
{
    int i = 1, ne = 0;
    char *str = NULL;

    if (nbr < 0) {
        nbr = nbr * (-1);
        ne++;
    }
    for (int z = 1; z <= nbr; z = z * 10)
        i++;
    str = malloc(sizeof(char) * (i + ne + 1));
    if (nbr == 0 || nbr == 1) {
        str = str01(str, nbr, ne);
        return (str);
    }
    str = int_str(str, nbr, i - 1, ne);
    return (str);
}
