/*
** EPITECH PROJECT, 2020
** inventory_monitor
** File description:
** inventory_monitor
*/

#include "town.h"

int check_if_first_tab_is_empty(main_town_t *town, sfVector2i coor)
{
    sfVector2i pos_tab;
    int i = 0;
    for (i = 0; my_strcmp(town->parser.object[i], "/1:") != 0; i++);
    i += 2;
    for (; my_strcmp(town->parser.object[i], "/end") != 0; i++) {
        pos_tab = get_the_position_in_tab(town->parser.object[i]);
        if (pos_tab.x == coor.x && pos_tab.y == coor.y)
            return 1;
    }
    return 0;
}

int check_if_second_tab_is_empty(main_town_t *town, sfVector2i coor)
{
    sfVector2i pos_tab;
    int i = 0;
    for (i = 0; my_strcmp(town->parser.object[i], "/2:") != 0; i++);
    i += 2;
    for (; my_strcmp(town->parser.object[i], "/end") != 0; i++) {
        pos_tab = get_the_position_in_tab(town->parser.object[i]);
        if (pos_tab.x == coor.x && pos_tab.y == coor.y)
            return 1;
    }
    return 0;
}

int check_if_case_is_empty(main_town_t *town, sfVector2i coor, object_t fl)
{
    if (fl.nbr_tab == 1)
        return (check_if_first_tab_is_empty(town, coor));
    if (fl.nbr_tab > 1)
        return (check_if_second_tab_is_empty(town, coor));
    return 0;
}

int draw_object(main_town_t *town, int count, object_t fl)
{
    sfVector2f coor;
    object_t object;
    int ret = 0;
    pars_object(town->parser.object[count], &object);
    coor.x = town->p.value_middle.x + fl.begin_x * town->size.size.x;
    coor.y = town->p.value_middle.y + fl.begin_y * town->size.size.y;
    coor.x += (96 * town->size.size.x) * object.x;
    coor.y += (146 * town->size.size.y) * object.y;
    sfSprite_setTexture(spr_tab[INVENTORY_SPR],
    inventory_tab[object.nbr_texture], sfTrue);
    sfSprite_setScale(spr_tab[INVENTORY_SPR], town->size.size);
    ret = take_obj_or_drop(town, fl, count, object);
    if (object.state == 1)
        coor = grab_object(town);
    sfSprite_setPosition(spr_tab[INVENTORY_SPR], coor);
    sfRenderWindow_drawSprite(town->window.window,
    spr_tab[INVENTORY_SPR], NULL);
    if (object.state == 0)
        draw_stack(town, object, coor);
    return (ret == 1 ? 1 : 0);
}

void inventory_monitor(main_town_t *town)
{
    sfVector2f pos;
    if (int_tab[INVENTORY] == 1) {
        sfSprite_setTexture(spr_tab[INVENTORY_SPR],
        inventory_tab[TXT_INV], sfTrue);
        sfSprite_setScale(spr_tab[INVENTORY_SPR], town->size.size);
        pos.x = town->p.value_middle.x -
            town->size.size_screen.x / 2;
        pos.y = town->p.value_middle.y -
            town->size.size_screen.y / 2;
        sfSprite_setPosition(spr_tab[INVENTORY_SPR], pos);
        sfRenderWindow_drawSprite(town->window.window,
        spr_tab[INVENTORY_SPR], NULL);
        for (int count = 0; town->parser.object[count] != NULL; count++) {
            count = inventory_management(town, count);
            if (count == -100)
                count = -1;
        }
    }
}
