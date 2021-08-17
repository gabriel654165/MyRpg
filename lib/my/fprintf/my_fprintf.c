/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** my_fprintf
*/
#include "fprintf.h"

int my_fprintf(char *right, char *path, char *fmt, ...)
{
    bases use;
    va_list ap;
    FILE *fp = fopen(path, right);

    va_start(ap, fmt);
    for (use.i = 0; fmt[use.i]; use.i++) {
        if (fmt[use.i] == '%' && is_it_a_flag(fmt[use.i+1], &use, fmt) == 1)
            for (int k = 0; use.flag[k]; k++)
                fwriting(&use, ap, k, fp);
        else {
            if (fmt[use.i-1] == '%'
                && is_it_a_flag(fmt[use.i], &use, fmt) == 0);
            else
                my_fputchar(fmt[use.i], fp);
        }
    }
    va_end(ap);
    fclose(fp);
    return (0);
}