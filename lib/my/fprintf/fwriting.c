/*
** EPITECH PROJECT, 2019
** printc
** File description:
** print des f
*/
#include "fprintf.h"

void fwriting2(va_list ap, int k, FILE *fp)
{
    if (k == 2 || k == 3 || k == 4 || k == 5
        || k == 6 || k == 7 || k == 9) {
        if (k == 2)
            k = 0;
        if (k == 3)
            k = 1;
        if (k == 4)
            k = 2;
        if (k == 5)
            k = 3;
        if (k == 6)
            k = 4;
        if (k == 7)
            k = 5;
        if (k == 9)
            k = 6;
        tabi[k].tpf(va_arg(ap, int), fp);
        k = 0;
    }
}

void fwriting(bases *use, va_list ap, int k, FILE *fp)
{
    if (use->flag[k] == use->flag[which_flag(use->fmt[use->i+1], use)]) {
        if (k == 0 || k == 10) {
            if (k == 10)
                k = 1;
            tabcs[k].tpf(va_arg(ap, char *), fp);
            k = 0;
        }
        if (k == 1)
            tabc[0].tpf(va_arg(ap, int), fp);
        if (k == 8)
            tabu[0].tpf(va_arg(ap, unsigned int), fp);
        if (k == 11)
            tabb[0].tpf(use, fp);
        fwriting2(ap, k, fp);
        use->i++;
    }
}