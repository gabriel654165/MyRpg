/*
** EPITECH PROJECT, 2020
** inventory_special_case
** File description:
** inventory_special_case
*/

#include "town.h"

void rm_line_of_obj(main_town_t *town, object_t fl)
{
    char **tab = malloc(sizeof(char *) * (my_tab_len(town->parser.object)));
    char *str = my_strcat("/", my_itoa(fl.nbr_tab));
    str = my_strcat(str, ":");
    int i = 0;
    int j = 0;
    for (; my_strcmp(town->parser.object[i], str) != 0; i++, j++)
        tab[j] = my_strcpy_malloc(town->parser.object[i]);
    tab[j] = my_strcpy_malloc(town->parser.object[i]);
    j++;
    i++;
    tab[j] = my_strcpy_malloc(town->parser.object[i]);
    for (i += 2, j++; town->parser.object[i] != NULL; i++, j++)
        tab[j] = my_strcpy_malloc(town->parser.object[i]);
    tab[j] = NULL;
    town->parser.object = free_the_tab(town->parser.object);
    town->parser.object = my_tabcpy_malloc(tab);
    tab = free_the_tab(tab);
    str = free_the_str(str);
}

int obj_manage_special_case(main_town_t *town, object_t *object, object_t fl)
{
    sfVector2f pos;
    sfVector2i coor;
    float x = sfMouse_getPositionRenderWindow(town->window.window).x
        + town->p.value_view.x * town->size.size.x;
    float y = sfMouse_getPositionRenderWindow(town->window.window).y
        + town->p.value_view.y * town->size.size.y;
    for (pos.y = town->p.value_middle.y + 46 * town->size.size.y,
        coor.y = 0; coor.y < 3; coor.y++, pos.y +=
        146 * town->size.size.y)
        for (pos.x = town->p.value_middle.x + 268 * town->size.size.x,
            coor.x = 0; coor.x < 4; coor.x++, pos.x += 96 *
            town->size.size.x)
            if (x > pos.x && x < pos.x + 96 * town->size.size.x
                && y > pos.y && y < pos.y + 146 * town->size.size.y
                && check_if_case_is_empty(town, coor, fl) == 0) {
                rm_line_of_obj(town, fl);
                put_obj_in_inventory(town, object->nbr_texture, 2);
                return 1;
            }
    return 0;
}

void drop_in_scnd_tab(main_town_t *town, object_t *object, object_t fl)
{
    sfVector2f pos;
    sfVector2i coor;
    float x = sfMouse_getPositionRenderWindow(town->window.window).x
        + town->p.value_view.x * town->size.size.x;
    float y = sfMouse_getPositionRenderWindow(town->window.window).y
        + town->p.value_view.y * town->size.size.y;
    for (pos.y = town->p.value_middle.y + fl.begin_y * town->size.size.y,
        coor.y = 0; coor.y < fl.y_min; coor.y++, pos.y +=
        146 * town->size.size.y)
        for (pos.x = town->p.value_middle.x + fl.begin_x * town->size.size.x,
            coor.x = 0; coor.x < fl.x_min; coor.x++, pos.x += 96 *
            town->size.size.x)
            if (x > pos.x && x < pos.x + 96 * town->size.size.x
                && y > pos.y && y < pos.y + 146 * town->size.size.y
                && check_if_case_is_empty(town, coor, fl) == 0) {
                object->y = coor.y;
                object->x = coor.x;
                return;
            }
}

int drop_special_case(main_town_t *town, object_t *object,
    object_t fl, int count)
{
    if (fl.nbr_tab > 2) {
        if (obj_manage_special_case(town, object, fl) == 1)
            return 1;
    }
    else if (fl.nbr_tab == 2) {
        if (scdn_tab_to_special_case(town, object, count) == 1)
            return 1;
        drop_in_scnd_tab(town, object, fl);
    }
    return 0;
}
