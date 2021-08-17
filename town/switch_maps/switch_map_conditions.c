/*
** EPITECH PROJECT, 2020
** switch_map_conditions
** File description:
** yes
*/

#include "town.h"

int tp_in_map1(main_town_t *town)
{
    town->p.pos_screen.y = 0;
    town->p.pos_screen.x = 0;
    town->p.pos_screen.y += 6300;
    town->p.value_view.y += 6300;
    sfView_move(town->p.view, (sfVector2f){town->p.pos_screen.x *
                town->size.size.x, town->p.pos_screen.y * town->size.size.y});
    sfClock_restart(tab_clock[CLOCK_ZONE]);
    return 1;
}

int tp_in_map2(main_town_t *town)
{
    town->p.pos_screen.y = 0;
    town->p.pos_screen.x = 0;
    town->p.pos_screen.y -= 6300;
    town->p.value_view.y -= 6300;
    sfView_move(town->p.view, (sfVector2f){town->p.pos_screen.x *
                town->size.size.x, town->p.pos_screen.y * town->size.size.y});
    sfClock_restart(tab_clock[CLOCK_ZONE]);
    return 0;
}

int tp_in_map3(main_town_t *town)
{
    town->p.pos_screen.y = 0;
    town->p.pos_screen.x = 0;
    town->p.pos_screen.y += 8000;
    town->p.value_view.y += 8000;
    town->p.pos_screen.x += 1070;
    town->p.value_view.x += 1070;
    sfView_move(town->p.view, (sfVector2f){town->p.pos_screen.x *
                town->size.size.x, town->p.pos_screen.y * town->size.size.y});
    sfClock_restart(tab_clock[CLOCK_ZONE]);
    return 2;
}

int change_map(main_town_t *town, int *world, int *display_time)
{
    if (*world == 1 && (town->p.value_middle.y / town->size.size.y) <= -5000) {
        *display_time = 1;
        *world = 0;
        return (tp_in_map1(town));
    } else if (*world == 1)
        return 0;
    if ((town->p.value_middle.y / town->size.size.y) >= 1329 && *world == 0) {
        *world = 1;
        *display_time = 1;
        return (tp_in_map2(town));
    } else if (*world == 0)
        return 1;
    return 0;
}

int choose_map(main_town_t *town)
{
    static int world = 1;
    static int display_time = 0;
    sfTime time = sfClock_getElapsedTime(tab_clock[CLOCK_ZONE]);

    display_time = clock_process(display_time, time);
    if ((town->p.value_middle.y / town->size.size.y) <= -7240
        && (town->p.value_middle.x / town->size.size.x) >= -200
        && (town->p.value_middle.x / town->size.size.x) <= -65
        && world == 0 && int_tab[GO_IN_CASTLE] == 1) {
        display_time = 2;
        world = tp_in_map3(town);
        return 2;
    } else if (world == 2)
        return 2;
    return (change_map(town, &world, &display_time));
}
