/*
** EPITECH PROJECT, 2019
** percent
** File description:
** precentù
*/
#include "fprintf.h"

void fpercent_percent(bases *use, FILE *fp)
{
    for (; use->fmt[use->i] != '\0'; use->i += compteur_percent(use)) {
        if (use->fmt[use->i] != '%')
            break;
        if (use->fmt[use->i] == '%' && use->fmt[use->i+1] == '%') {
            my_fputchar('%', fp);
        }
    }
    use->i -= 2;
}
