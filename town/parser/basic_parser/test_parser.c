/*
** EPITECH PROJECT, 2020
** test_parser
** File description:
** test_parser.c
*/

#include "town.h"
#include "../../../include/olivier.h"

void fulfill_the_gate_with_key(map_t *map, char *str)
{
    int value = my_getnbr(str);
    static int i = 0;
    if (i == 0)
        map->coor_x.x = value;
    if (i == 1)
        map->coor_x.y = value;
    if (i == 2)
        map->collision = value;
    if (i == 3)
        map->life = value;
    i++;
    if (i == 4)
        i = 0;
}

void decide_what_fulfill2(map_t *map, char *str, int count)
{
    if (count == 11)
        fulfill_the_gate_with_key(map, str);
}

char **set_pos5(int i, main_town_t *town, char **tab_pars)
{
    if (my_strcmp(tab_pars[i], "/gate_key:") == 0) {
        i += 2;
        for (int j = i + my_getnbr(tab_pars[i - 1]);
        i < j; i++) {
            tab_pars =
            gate_open_with_key(parse_and_call_map(tab_pars[i], 11), town,
            i, tab_pars);
        }
        return tab_pars;
    }
    return tab_pars;
}

char **set_pos(int i, main_town_t *town, char **tab_pars)
{
    if (set_pos2(i, town, tab_pars) == 1)
        return tab_pars;
    if (set_pos3(i, town, tab_pars) == 1)
        return tab_pars;
    tab_pars = chest_option(tab_pars, i, town);
    tab_pars = set_pos4(i, town, tab_pars);
    other_stuff(tab_pars, i, town);
    tab_pars = set_pos5(i, town, tab_pars);
    return tab_pars;
}

char **get_obj_pos(main_town_t *town, char **tab_pars, int dim)
{
    int i1;
    town->png.dimension = (dim == 1 ? 1 : 2);
    for (i1 = 0; tab_pars[i1] != NULL; ++i1)
        if (tab_pars[i1][0] == '/') {
            tab_pars = set_pos(i1, town, tab_pars);
            i1 = i1 + my_getnbr(tab_pars[i1 + 1]);
        }
    return tab_pars;
}
