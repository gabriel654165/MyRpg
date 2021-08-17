/*
** EPITECH PROJECT, 2019
** printc %S
** File description:
** oui
*/
#include "fprintf.h"

void fascii(char *str, FILE *fp)
{
    for (int i = 0; str[i]; i++) {
        if ((0 <= str[i] && str[i] <= 32) || (str[i] == 127)) {
            my_fputchar('\\', fp);
            if (0 <= str[i] && str[i] <= 7)
                my_fputstr("00", fp);
            if (8 <= str[i] && str[i] <= 32)
                my_fputchar('0', fp);
            fbaseoct(str[i], fp);
            i++;
        }
        my_fputchar(str[i], fp);
    }
}
