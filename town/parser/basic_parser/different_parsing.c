/*
** EPITECH PROJECT, 2020
** diss_pars
** File description:
** diff_pars
*/

#include "../../../include/olivier.h"
#include "town.h"

void fulfill_the_map(map_t *map, char *str)
{
    int value = my_getnbr(str);
    static int i = 0;
    if (i == 0)
        map->coor_x.x = value;
    if (i == 1)
        map->coor_x.y = value;
    if (i == 2)
        map->coor_y.x = value;
    if (i == 3)
        map->coor_y.y = value;
    if (i == 4)
        map->texture = tab_tilset[value];
    i++;
    if (i == 5)
        i = 0;
}

void fulfill_the_disp_obj(map_t *map, char *str)
{
    int value = my_getnbr(str);
    static int i = 0;
    if (i == 0)
        map->coor_x.x = value;
    if (i == 1)
        map->coor_x.y = value;
    if (i == 2)
        map->coor_y.x = value;
    if (i == 3)
        map->coor_y.y = value;
    if (i == 4)
        map->texture = tab_txt_nature[value];
    if (i == 5)
        map->collision = value;
    i++;
    if (i == 6)
        i = 0;
}

void fulfill_the_house(map_t *map, char *str)
{
    int value = my_getnbr(str);
    static int i = 0;
    if (i == 0)
        map->coor_x.x = value;
    if (i == 1)
        map->coor_x.y = value;
    if (i == 2)
        map->texture = tab_txt[value];
    if (i == 3)
        map->collision = value;
    i++;
    if (i == 4)
        i = 0;
}

void decide_what_fulfill(map_t *map, char *str, int count)
{
    if (count == 1)
        fulfill_the_map(map, str);
    if (count == 2)
        fulfill_the_house(map, str);
    if (count == 3)
        fulfill_stuff(map, str);
    if (count == 4)
        fulfill_nature(map, str);
    if (count == 5)
        fulfill_rock(map, str);
    if (count == 6)
        fulfill_wooden(map, str);
    if (count == 7)
        fulfill_the_disp_obj(map, str);
    if (count == 8)
        fulfill_the_house(map, str);
    if (count == 9)
        fulfill_the_monster(map, str);
    if (count == 10)
        fulfill_the_chest(map, str);
}

map_t parse_and_call_map(char *str, int count)
{
    map_t map;
    int i = 0;
    int j = 0;
    char *temp = str;
    char *fin = NULL;
    while (str && *str) {
        for (;*str == ':'; str++);
        for (; temp[i] != ':' && temp[i] != '\0'; i++);
        fin = malloc(sizeof(char) * (i + 1));
        for (j = 0; str && *str != ':' && *str != '\0'; j++, str++)
            fin[j] = *str;
        fin[j] = 0;
        i++;
        decide_what_fulfill(&map, fin, count);
        decide_what_fulfill2(&map, fin, count);
        free(fin);
        fin = NULL;
    }
    return map;
}
