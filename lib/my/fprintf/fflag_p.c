/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** flag_p
*/
#include "fprintf.h"

void fflag_p(int nbr, FILE *fp)
{
    my_fputstr("0x", fp);
    fbaseoct(nbr, fp);
}