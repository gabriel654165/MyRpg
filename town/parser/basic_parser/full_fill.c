/*
** EPITECH PROJECT, 2020
** full_fill
** File description:
** c
*/

#include "town.h"
#include "../../../include/olivier.h"

void fulfill_stuff(map_t *map, char *str)
{
    int value = my_getnbr(str);
    static int i = 0;
    if (i == 0)
        map->coor_x.x = value;
    if (i == 1)
        map->coor_x.y = value;
    if (i == 2)
        map->texture = tab_txt_stuff[value];
    if (i == 3)
        map->collision = value;
    i++;
    if (i == 4)
        i = 0;
}

void fulfill_nature(map_t *map, char *str)
{
    int value = my_getnbr(str);
    static int i = 0;
    if (i == 0)
        map->coor_x.x = value;
    if (i == 1)
        map->coor_x.y = value;
    if (i == 2)
        map->texture = tab_txt_nature[value];
    if (i == 3)
        map->collision = value;
    i++;
    if (i == 4)
        i = 0;
}

void fulfill_rock(map_t *map, char *str)
{
    int value = my_getnbr(str);
    static int i = 0;
    if (i == 0)
        map->coor_x.x = value;
    if (i == 1)
        map->coor_x.y = value;
    if (i == 2)
        map->texture = tab_txt_rocks[value];
    if (i == 3)
        map->collision = value;
    i++;
    if (i == 4)
        i = 0;
}

void fulfill_wooden(map_t *map, char *str)
{
    int value = my_getnbr(str);
    static int i = 0;
    if (i == 0)
        map->coor_x.x = value;
    if (i == 1)
        map->coor_x.y = value;
    if (i == 2)
        map->texture = tab_text_wooden[value];
    if (i == 3)
        map->collision = value;
    i++;
    if (i == 4)
        i = 0;
}
