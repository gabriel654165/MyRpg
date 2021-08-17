/*
** EPITECH PROJECT, 2020
** values_stats
** File description:
** yes
*/

#include "town.h"

void set_stats(void)
{
    stat_tab[LIFE] = 100;
    stat_tab[XP_LVL] = 0;
    stat_tab[XP_BAR] = 0;
    stat_tab[GAME_OVER] = 0;
    stat_tab[PANEL_TWO] = 0;
    stat_tab[GAME_OVER_RESTART] = 1;
    stat_tab[GAME_OVER_QUIT] = 0;
    stat_tab[LOAD_GO] = 1;
    stat_tab[LAST_ACTION] = 3;
    stat_tab[ATTACK] = 0;
    stat_tab[RUN] = 0;
    stat_tab[ZONE_DRAW] = 0;
    stat_tab[SHIELD] = 0;
    stat_tab[DMG] = 30;
}

int life_display(int life_chose_sprite, main_town_t *town)
{
    if (life_chose_sprite == 0 || stat_tab[LIFE] == 0) {
        life_chose_sprite = 4;
        stat_tab[LIFE] = 100;
        stat_tab[GAME_OVER] = 1;
    }
    if (int_tab[CINE_X] == 0 && int_tab[CINE_Y] == 0) {
        if (life_chose_sprite == 1)
            draw_stats(town, QUART_L);
        if (life_chose_sprite == 2)
            draw_stats(town, MID_L);
        if (life_chose_sprite == 3)
            draw_stats(town, SC_L);
        if (life_chose_sprite == 4)
            draw_stats(town, FULL_L);
    }
    return life_chose_sprite;
}

int xp_diplayed(int xp_chose_sprite, main_town_t *town)
{
    if (int_tab[CINE_X] == 0 && int_tab[CINE_Y] == 0) {
        if (xp_chose_sprite == 0)
            draw_stats(town, EMPTY_X);
        if (xp_chose_sprite == 1)
            draw_stats(town, QUART_X);
        if (xp_chose_sprite == 2)
            draw_stats(town, MID_X);
        if (xp_chose_sprite == 3)
            draw_stats(town, SC_X);
        if (xp_chose_sprite == 4)
            draw_stats(town, FULL_X);
    }
    return xp_chose_sprite;
}

int calcul_life(void)
{
    int life = 0;

    if (stat_tab[LIFE] <= 0)
        life = 0;
    if (stat_tab[LIFE] > 0 && stat_tab[LIFE] <= 25)
        life = 1;
    if (stat_tab[LIFE] > 25 && stat_tab[LIFE] <= 50)
        life = 2;
    if (stat_tab[LIFE] > 50 && stat_tab[LIFE] <= 75)
        life = 3;
    if (stat_tab[LIFE] > 75 && stat_tab[LIFE] <= 100)
        life = 4;
    return life;
}

int calcul_xp(void)
{
    int xp = 0;

    if (stat_tab[XP_BAR] <= 0)
        xp = 0;
    if (stat_tab[XP_BAR] > 0 && stat_tab[XP_BAR] <= 25)
        xp = 1;
    if (stat_tab[XP_BAR] > 25 && stat_tab[XP_BAR] <= 50)
        xp = 2;
    if (stat_tab[XP_BAR] > 50 && stat_tab[XP_BAR] <= 75)
        xp = 3;
    if (stat_tab[XP_BAR] > 75 && stat_tab[XP_BAR] <= 100)
        xp = 4;
    if (stat_tab[XP_BAR] >= 100) {
        stat_tab[XP_LVL] += 1;
        stat_tab[XP_BAR] = 0;
        xp = 0;
    }
    return xp;
}
