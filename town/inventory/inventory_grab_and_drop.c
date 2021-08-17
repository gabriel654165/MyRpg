/*
** EPITECH PROJECT, 2020
** grab_and_drop
** File description:
** grab_and_drop
*/

#include "town.h"

int drop_in_case(main_town_t *town, object_t *object, object_t fl, int count)
{
    if (fl.nbr_tab != 1) {
        if (drop_special_case(town, object, fl, count) == 1)
            return 1;
        else
            return 0;
    }
    else {
        drop_normal(town, object, fl);
        return 0;
    }
    return 0;
}

sfVector2f get_mouse_position(main_town_t *town)
{
    sfVector2f coor;
    coor.x = sfMouse_getPositionRenderWindow(town->window.window).x
        + town->p.value_view.x * town->size.size.x;
    coor.y = sfMouse_getPositionRenderWindow(town->window.window).y
        + town->p.value_view.y * town->size.size.y;
    return coor;
}

sfVector2f get_coor_in_inventory(main_town_t *town, object_t fl,
    object_t object)
{
    sfVector2f coor;
    coor.x = town->p.value_middle.x + fl.begin_x * town->size.size.x;
    coor.y = town->p.value_middle.y + fl.begin_y * town->size.size.y;
    coor.x += (96 * town->size.size.x) * object.x;
    coor.y += (146 * town->size.size.y) * object.y;
    return coor;
}

int take_obj_or_drop(main_town_t *town, object_t fl, int count,
    object_t object)
{
    static int i = 0;
    sfVector2f coor = get_coor_in_inventory(town, fl, object);
    sfVector2f pos = get_mouse_position(town);
    if (int_tab[DROP] == 1 && i == 0)
        if (pos.x > coor.x && pos.x < coor.x + 96 * town->size.size.x
            && pos.y > coor.y && pos.y < coor.y + 146 * town->size.size.y) {
            object.state = 1;
            actualise_object(object, town, count);
            i = 1;
        }
    if (int_tab[DROP] == 0 && object.state == 1) {
        if (drop_in_case(town, &object, fl, count) == 1) {
            i = 0;
            return 1;
        }
        object.state = 0;
        actualise_object(object, town, count);
        i = 0;
    }
    return 0;
}

sfVector2f grab_object(main_town_t *town)
{
    float x = sfMouse_getPositionRenderWindow(town->window.window).x
        + town->p.value_view.x * town->size.size.x;
    float y = sfMouse_getPositionRenderWindow(town->window.window).y
        + town->p.value_view.y * town->size.size.y;
    sfVector2f pos;
    pos.x = x - (sfSprite_getLocalBounds(spr_tab[INVENTORY_SPR]).width
        * town->size.size.x) / 2;
    pos.y = y - (sfSprite_getLocalBounds(spr_tab[INVENTORY_SPR]).height
        * town->size.size.y) / 2;
    return pos;
}
