/*
** EPITECH PROJECT, 2020
** fulfill_the_monster
** File description:
** fulfill_the_monster
*/

#include "town.h"

void fulfill_the_monster4(map_t *map, int value, int i)
{
    if (i == 19)
        map->life = value;
    if (i == 20)
        map->life_save = value;
    if (i == 21)
        map->attack = value;
    if (i == 22)
        map->xp_gain = value;
    if (i == 23)
        map->hit_box_x.x = value;
    if (i == 24)
        map->hit_box_x.y = value;
    if (i == 25)
        map->hit_box_y.x = value;
    if (i == 26)
        map->hit_box_y.y = value;
}

void fulfill_the_monster3(map_t *map, int value, int i, char *str)
{
    if (i == 10)
        map->min_offset_left = value;
    if (i == 11) {
        map->texture = text_monster[value];
        map->txt = value;
    }
    if (i == 12)
        map->coor.x = value;
    if (i == 13)
        map->coor.y = value;
    if (i == 14)
        map->live = value;
    if (i == 15)
        map->time = my_getnbr_float(str);
    if (i == 16)
        map->direction_time = my_getnbr_float(str);
    if (i == 17)
        map->alea = value;
    if (i == 18)
        map->aggro = value;
}

void fulfill_the_monster2(map_t *map, int value, int i)
{
    if (i == 0)
        map->coor_x.x = value;
    if (i == 1)
        map->coor_x.y = value;
    if (i == 2)
        map->coor_y.x = value;
    if (i == 3)
        map->coor_y.y = value;
    if (i == 4)
        map->rect.left = value;
    if (i == 5)
        map->rect.top = value;
    if (i == 6)
        map->rect.width = value;
    if (i == 7)
        map->rect.height = value;
    if (i == 8)
        map->offset_left = value;
    if (i == 9)
        map->max_offset_left = value;
}

void fulfill_the_monster(map_t *map, char *str)
{
    int value = my_getnbr(str);
    static int i = 0;
    fulfill_the_monster2(map, value, i);
    fulfill_the_monster3(map, value, i, str);
    fulfill_the_monster4(map, value, i);
    i++;
    if (i == 27)
        i = 0;
}
