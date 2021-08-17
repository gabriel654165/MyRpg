/*
** EPITECH PROJECT, 2020
** actualise_monster_parser
** File description:
** actualise_monster_parser
*/

#include "town.h"

char *actualise_monster3(map_t map, char *str)
{
    str = str_concat(str, my_itoa(map.live), ':');
    str = str_concat(str, my_ftoa(map.time), ':');
    str = str_concat(str, my_ftoa(map.direction_time), ':');
    str = str_concat(str, my_itoa(map.alea), ':');
    str = str_concat(str, my_itoa(map.aggro), ':');
    str = str_concat(str, my_itoa(map.life), ':');
    str = str_concat(str, my_itoa(map.life_save), ':');
    str = str_concat(str, my_itoa(map.attack), ':');
    str = str_concat(str, my_itoa(map.xp_gain), ':');
    str = str_concat(str, my_itoa(map.hit_box_x.x), ':');
    str = str_concat(str, my_itoa(map.hit_box_x.y), ':');
    str = str_concat(str, my_itoa(map.hit_box_y.x), ':');
    str = str_concat(str, my_itoa(map.hit_box_y.y), ':');
    return str;
}

char *actualise_monster2(map_t map, char *str)
{
    str = str_concat(str, my_itoa(map.coor_y.x), ':');
    str = str_concat(str, my_itoa(map.coor_y.y), ':');
    str = str_concat(str, my_itoa(map.rect.left), ':');
    str = str_concat(str, my_itoa(map.rect.top), ':');
    str = str_concat(str, my_itoa(map.rect.width), ':');
    str = str_concat(str, my_itoa(map.rect.height), ':');
    str = str_concat(str, my_itoa(map.offset_left), ':');
    str = str_concat(str, my_itoa(map.max_offset_left), ':');
    str = str_concat(str, my_itoa(map.min_offset_left), ':');
    str = str_concat(str, my_itoa(map.txt), ':');
    str = str_concat(str, my_itoa(map.coor.x), ':');
    str = str_concat(str, my_itoa(map.coor.y), ':');
    return str;
}

char **actualise_monster(map_t map, int i, char **tab_pars)
{
    free(tab_pars[i]);
    tab_pars[i] = NULL;
    char *str = NULL;
    str = str_concat(my_itoa(map.coor_x.x), my_itoa(map.coor_x.y), ':');
    str = actualise_monster2(map, str);
    str = actualise_monster3(map, str);
    tab_pars[i] = my_strcpy_malloc(str);
    free(str);
    return tab_pars;
}
