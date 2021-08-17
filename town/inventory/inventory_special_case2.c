/*
** EPITECH PROJECT, 2020
** same
** File description:
** same
*/

#include "town.h"

int decide_what_case_fulfill2(main_town_t *town, int x, int y)
{
    if (x >= town->p.value_middle.x + 279 * town->size.size.x &&
        x <= town->p.value_middle.x + 279 * town->size.size.x + 96
        * town->size.size.x)
        if (y >= town->p.value_middle.y + -194 * town->size.size.y &&
            y <= town->p.value_middle.y + -194 * town->size.size.y + 146
            * town->size.size.y)
            return 3;
    if (x >= town->p.value_middle.x + 552 * town->size.size.x &&
        x <= town->p.value_middle.x + 552 * town->size.size.x + 96
        * town->size.size.x)
        if (y >= town->p.value_middle.y + -194 * town->size.size.y &&
            y <= town->p.value_middle.y + -194 * town->size.size.y
            + 146 * town->size.size.y)
            return 4;
    return 0;
}

int decide_what_case_fulfill(main_town_t *town)
{
    float x = sfMouse_getPositionRenderWindow(town->window.window).x
        + town->p.value_view.x * town->size.size.x;
    float y = sfMouse_getPositionRenderWindow(town->window.window).y
        + town->p.value_view.y * town->size.size.y;
    if (x >= town->p.value_middle.x + 279 * town->size.size.x &&
        x <= town->p.value_middle.x + 279 * town->size.size.x + 96
        * town->size.size.x)
        if (y >= town->p.value_middle.y + -392 * town->size.size.y &&
            y <= town->p.value_middle.y + -392 * town->size.size.y
            + 146 * town->size.size.y)
            return 1;
    if (x >= town->p.value_middle.x + 552 * town->size.size.x &&
        x <= town->p.value_middle.x + 552 * town->size.size.x + 96
        * town->size.size.x)
        if (y >= town->p.value_middle.y + -392 * town->size.size.y &&
            y <= town->p.value_middle.y + -392 * town->size.size.y + 146
            * town->size.size.y)
            return 2;
    return decide_what_case_fulfill2(town, x, y);
}

int check_empty_special_case(main_town_t *town, char *str)
{
    int i;
    for (i = 0; my_strcmp(town->parser.object[i], str) != 0; i++);
    if (my_strcmp(town->parser.object[i + 2], "/end") != 0)
        return 1;
    return 0;
}

char *actualise_good_line2(object_t *object)
{
    char *str = NULL;
    str = str_concat(my_itoa(0), my_itoa(0), ':');
    str = str_concat(str, my_itoa(object->nbr_texture), ':');
    str = str_concat(str, my_itoa(1), ':');
    str = str_concat(str, my_itoa(0), ':');
    return str;
}
