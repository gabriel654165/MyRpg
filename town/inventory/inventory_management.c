/*
** EPITECH PROJECT, 2020
** inventory_management
** File description:
** inventory_management
*/

#include "town.h"

void draw_stack(main_town_t *town, object_t obj, sfVector2f coor)
{
    coor.x += 60 * town->size.size.x;
    coor.y += 110 * town->size.size.y;
    sfText_setPosition(text_tab[STACKS], coor);
    sfText_setFont(text_tab[STACKS], tab_font[FONT_1]);
    sfText_setCharacterSize(text_tab[STACKS], 20);
    sfText_setString(text_tab[STACKS], my_itoa(obj.nbr_obj));
    sfText_setScale(text_tab[STACKS], town->size.size);
    sfText_setFillColor(text_tab[STACKS], sfWhite);
    sfRenderWindow_drawText(town->window.window, text_tab[STACKS], NULL);
}

void fullfil_value_fl(object_t *object, char *str)
{
    int value = my_getnbr(str);
    static int i = 0;
    if (i == 0)
        object->begin_x = value;
    if (i == 1)
        object->begin_y = value;
    if (i == 2)
        object->x_min = value;
    if (i == 3)
        object->y_min = value;
    if (i == 4)
        object->nbr_tab = value;
    i++;
    if (i == 5)
        i = 0;
}

void pars_first_line(char *str, object_t *object)
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
        fullfil_value_fl(object, fin);
        free(fin);
        fin = NULL;
    }
}
