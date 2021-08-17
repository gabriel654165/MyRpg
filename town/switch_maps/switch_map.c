/*
** EPITECH PROJECT, 2020
** switch_map
** File description:
** yes
*/

#include "town.h"

void draw_zone_text(main_town_t *town, enum stat_txt TEST)
{
    sfVector2f pos;
    sfVector2f coor;

    sfSprite_setTexture(spr_tab[ZONE_SPRITE], texture_stat[TEST], sfTrue);
    sfSprite_setScale(spr_tab[ZONE_SPRITE], town->size.size);
    coor.x = (sfSprite_getLocalBounds(spr_tab[ZONE_SPRITE]).width * town->size.size.x) / 2;
    coor.y = (sfSprite_getLocalBounds(spr_tab[ZONE_SPRITE]).height * town->size.size.y) / 2;
    pos.x = town->p.value_middle.x - coor.x;
    pos.y = town->p.value_middle.y - coor.y;
    sfSprite_setPosition(spr_tab[ZONE_SPRITE], pos);
    sfRenderWindow_drawSprite(town->window.window, spr_tab[ZONE_SPRITE], NULL);
}

void move_cine(main_town_t *town)
{
    static int next = 0;

    if (next == 1 && int_tab[CINE_Y] == 0) {
        stat_tab[ZONE_DRAW] = 0;
        return;
    }
    if (int_tab[CINE_Y] > -3760 && next == 0) {
        town->p.pos_screen.y -= 5;
        int_tab[CINE_Y] -= 5;
    }
    if (int_tab[CINE_Y] <= -3760 || next == 1) {
        draw_zone_text(town, ZONE_CASTLE);
        town->p.pos_screen.y += 5;
        int_tab[CINE_Y] += 5;
        next = 1;
    }
}

void cinematic_event(main_town_t *town)
{
    town->p.pos_screen.y = 0;
    town->p.pos_screen.x = 0;
    move_cine(town);
    sfView_move(town->p.view, (sfVector2f){town->p.pos_screen.x *
                town->size.size.x, town->p.pos_screen.y * town->size.size.y});
}

int clock_process(int display_time, sfTime time)
{
    if (display_time == 1 || display_time == 2)
        stat_tab[ZONE_DRAW] = 1;
    if (sfTime_asMilliseconds(time) >= 5000 && display_time == 1) {
        stat_tab[ZONE_DRAW] = 0;
        sfClock_restart(tab_clock[CLOCK_ZONE]);
        return 0;
    }
    if (sfTime_asMilliseconds(time) >= 100000 && display_time == 2) {
        stat_tab[ZONE_DRAW] = 0;
        sfClock_restart(tab_clock[CLOCK_ZONE]);
        return 0;
    }
    return display_time;
}
