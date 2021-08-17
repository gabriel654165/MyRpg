/*
** EPITECH PROJECT, 2020
** same
** File description:
** same
*/

#include "town.h"

void drop_normal(main_town_t *town, object_t *object, object_t fl)
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

int inventory_management2(main_town_t *town, int count)
{
    object_t fl;
    if (my_strcmp(town->parser.object[count], "/3:") == 0) {
        pars_first_line(town->parser.object[count + 1], &fl);
        for (count += 2; my_strcmp(town->parser.object[count], "/end")
            != 0; count++)
            if (draw_object(town, count, fl) == 1)
                return -100;
        return count;
    }
    if (my_strcmp(town->parser.object[count], "/4:") == 0) {
        pars_first_line(town->parser.object[count + 1], &fl);
        for (count += 2; my_strcmp(town->parser.object[count], "/end")
            != 0; count++)
            if (draw_object(town, count, fl) == 1)
                return -100;
        return count;
    }
    return count;
}

int inventory_management3(main_town_t *town, int count)
{
    object_t fl;
    if (my_strcmp(town->parser.object[count], "/5:") == 0) {
        pars_first_line(town->parser.object[count + 1], &fl);
        for (count += 2; my_strcmp(town->parser.object[count], "/end")
            != 0; count++)
            if (draw_object(town, count, fl) == 1)
                return -100;
        return count;
    }
    if (my_strcmp(town->parser.object[count], "/6:") == 0) {
        pars_first_line(town->parser.object[count + 1], &fl);
        for (count += 2; my_strcmp(town->parser.object[count], "/end")
            != 0; count++)
            if (draw_object(town, count, fl) == 1)
                return -100;
        return count;
    }
    return count;
}

int inventory_management4(main_town_t *town, int count)
{
    object_t fl;
    if (my_strcmp(town->parser.object[count], "/1:") == 0) {
        pars_first_line(town->parser.object[count + 1], &fl);
        for (count += 2; my_strcmp(town->parser.object[count], "/end")
            != 0; count++)
            if (draw_object(town, count, fl) == 1)
                return -100;
        return count;
    }
    if (my_strcmp(town->parser.object[count], "/2:") == 0) {
        pars_first_line(town->parser.object[count + 1], &fl);
        for (count += 2; my_strcmp(town->parser.object[count], "/end")
            != 0; count++)
            if (draw_object(town, count, fl) == 1)
                return -100;
        return count;
    }
    return count;
}

int inventory_management(main_town_t *town, int count)
{
    int save_count = count;
    if ((count = inventory_management4(town, count)) != save_count)
        return count;
    save_count = count;
    if ((count = inventory_management2(town, count)) != save_count)
        return count;
    save_count = count;
    if ((count = inventory_management3(town, count)) != save_count)
        return count;
    return count;
}
