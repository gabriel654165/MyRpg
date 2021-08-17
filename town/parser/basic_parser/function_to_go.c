/*
** EPITECH PROJECT, 2020
** function_to_go
** File description:
** function_to_go
*/

#include "town.h"

char **set_pos4(int i, main_town_t *town, char **tab_pars)
{
    if (my_strcmp(tab_pars[i], "/monster:") == 0) {
        i += 2;
        for (int j = i + my_getnbr(tab_pars[i - 1]);
            i < j; i++) {
            tab_pars =
            monster_animation(parse_and_call_map(tab_pars[i], 9),
            town, i, tab_pars);
        }
        return tab_pars;
    }
    if (my_strcmp(tab_pars[i], "/png_quest:") == 0) {
        png_quest(parse_the_quest(tab_pars[i + 2], tab_pars, i + 2),
        tab_pars, town);
        i += my_getnbr(tab_pars[i + 1]) + 1;
        return tab_pars;
    }
    return tab_pars;
}

int set_pos3(int i, main_town_t *town, char **tab_pars)
{
    if (my_strcmp(tab_pars[i], "/map:") == 0) {
        i += 2;
        for (int j = i + my_getnbr(tab_pars[i - 1]);
        i < j; i++)
            display_map(parse_and_call_map(tab_pars[i], 1), town);
        return 1;
    }
    if (my_strcmp(tab_pars[i], "/gate_open:") == 0) {
        i += 2;
        for (int j = i + my_getnbr(tab_pars[i - 1]);
        i < j; i++)
            gate_open(parse_and_call_map(tab_pars[i], 8), town);
        return 1;
    }
    return 0;
}

int set_pos2(int i, main_town_t *town, char **tab_pars)
{
    if (my_strcmp(tab_pars[i], "/house:") == 0) {
        i += 2;
        for (int j = i + my_getnbr(tab_pars[i - 1]);
        i < j; i++)
            display_object(parse_and_call_map(tab_pars[i], 2), town);
        return 1;
    }
    if (my_strcmp(tab_pars[i], "/disp_obj:") == 0) {
        i += 2;
        for (int j = i + my_getnbr(tab_pars[i - 1]);
        i < j; i++)
            display_obj_as_map(parse_and_call_map(tab_pars[i], 7), town);
        return 1;
    }
    return 0;
}
