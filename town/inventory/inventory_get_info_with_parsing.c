/*
** EPITECH PROJECT, 2020
** get_info
** File description:
** get_info
*/

#include "town.h"

void send_rect(object_t *object, char *str)
{
    int value = my_getnbr(str);
    static int i = 0;
    if (i == 0)
        object->y = value;
    if (i == 1)
        object->x = value;
    if (i == 2)
        object->nbr_texture = value;
    if (i == 3)
        object->nbr_obj = value;
    if (i == 4)
        object->state = value;
    i++;
    if (i == 5)
        i = 0;
}

void pars_object(char *str, object_t *object)
{
    char *tmp = str;
    char *fin = NULL;
    int i = 0;
    int j = 0;
    while (str && *str) {
        while (*tmp && *tmp != ':')
            tmp++;
        i = tmp - str;
        tmp++;
        fin = malloc(sizeof(char) * (i + 1));
        for (j = 0; j < i; j++, str++)
            fin[j] = *str;
        if (*str)
            str++;
        fin[j] = '\0';
        send_rect(object, fin);
        free(fin);
        fin = NULL;
    }
}

sfVector2i get_the_position_in_tab(char *str)
{
    sfVector2i coor;
    char *tmp = str;
    char *fin = NULL;
    for (int i = 0, j = 0, count = 0; count < 2; count++) {
        for (;*tmp && *tmp != ':'; tmp++);
        i = tmp - str;
        tmp++;
        fin = malloc(sizeof(char) * (i + 1));
        for (j = 0; j < i; j++, str++)
            fin[j] = *str;
        if (*str)
            str++;
        fin[j] = '\0';
        if (count == 0)
            coor.y = my_getnbr(fin);
        if (count == 1)
            coor.x = my_getnbr(fin);
        fin = free_the_str(fin);
    }
    return coor;
}
