/*
** EPITECH PROJECT, 2020
** other_stuff
** File description:
** c
*/

#include "town.h"
#include "../../../include/olivier.h"

char **chest_option(char **tab_pars, int i, main_town_t *town)
{
    if (my_strcmp(tab_pars[i], "/chest:") == 0) {
        i += 2;
        for (int j = i + my_getnbr(tab_pars[i - 1]);
        i < j; i++)
            tab_pars =
            chest_obj(parse_and_call_map(tab_pars[i], 10), town, i, tab_pars);
        return tab_pars;
    }
    return tab_pars;
}

void part_two(char **tab_pars, int i, main_town_t *town)
{
    if (my_strcmp(tab_pars[i], "/rock:") == 0) {
        i += 2;
        for (int j = i + my_getnbr(tab_pars[i - 1]);
        i < j; i++)
            display_object(parse_and_call_map(tab_pars[i], 5), town);
        return;
    }
    if (my_strcmp(tab_pars[i], "/wooden:") == 0) {
        i += 2;
        for (int j = i + my_getnbr(tab_pars[i - 1]);
        i < j; i++)
            display_object(parse_and_call_map(tab_pars[i], 6), town);
        return;
    }
}

void other_stuff(char **tab_pars, int i, main_town_t *town)
{
    if (my_strcmp(tab_pars[i], "/stuff:") == 0) {
        i += 2;
        for (int j = i + my_getnbr(tab_pars[i - 1]);
        i < j; i++)
            display_object(parse_and_call_map(tab_pars[i], 3), town);
        return;
    }
    if (my_strcmp(tab_pars[i], "/nature:") == 0) {
        i += 2;
        for (int j = i + my_getnbr(tab_pars[i - 1]);
        i < j; i++)
            display_object(parse_and_call_map(tab_pars[i], 4), town);
        return;
    }
    part_two(tab_pars, i, town);
}
