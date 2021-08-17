/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** get status and change it
*/

#include "town.h"

void attack_action_hero(png_t *png, sfIntRect *rect)
{
    static int is_atk = 0;

    if (png->attack == true && is_atk == 0) {
        *rect = png->rect_atk;
        is_atk = 1;
    } else if (png->attack == false) {
        is_atk = 0;
        sfSprite_setOrigin(png->spr, (sfVector2f){0, 0});
    }
    stat_tab[ATTACK] = is_atk;
}

void run_action_hero(png_t *png, sfIntRect *rect)
{
    static int is_run = 0;

    if (png->run == 1 && is_run == 0) {
        rect->left = 221;
        is_run = 1;
    } else if (png->run == 0 && png->attack == false && is_run == 1) {
        is_run = 0;
        rect->left = 8;
    }
    stat_tab[RUN] = is_run;
}
