/*
** EPITECH PROJECT, 2020
** fulfill_the_chest
** File description:
** same
*/

#include "../../../include/olivier.h"

void fulfill_the_chest2(map_t *map, int value, int i)
{
    if (i == 3)
        map->collision = value;
    if (i == 4)
        map->txt = value;
    if (i == 5)
        map->attack = value;
    if (i == 6)
        map->live = value;
    if (i == 7)
        map->aggro = value;
}

void fulfill_the_chest(map_t *map, char *str)
{
    int value = my_getnbr(str);
    static int i = 0;
    if (i == 0)
        map->coor_x.x = value;
    if (i == 1)
        map->coor_x.y = value;
    if (i == 2) {
        map->texture = tab_chest[value];
        map->life = value;
    }
    fulfill_the_chest2(map, value, i);
    i++;
    if (i == 8)
        i = 0;
}
