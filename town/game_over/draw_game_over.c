/*
** EPITECH PROJECT, 2020
** draw_game_over.c
** File description:
** yes
*/

#include "town.h"

void draw_game_over(main_town_t *town, enum game_over TEST)
{
    sfVector2f pos;
    sfVector2f coor;

    sfSprite_setTexture(spr_tab[STAT_SPRITE], text_game_over[TEST], sfTrue);
    sfSprite_setScale(spr_tab[STAT_SPRITE], town->size.size);
    coor.x = sfSprite_getLocalBounds(spr_tab[STAT_SPRITE]).width / 2
        * town->size.size.x;
    coor.y = sfSprite_getLocalBounds(spr_tab[STAT_SPRITE]).height / 2
        * town->size.size.y;
    pos.x = town->p.value_middle.x - coor.x;
    pos.y = town->p.value_middle.y - coor.y;
    sfSprite_setPosition(spr_tab[STAT_SPRITE], pos);
    sfRenderWindow_drawSprite(town->window.window, spr_tab[STAT_SPRITE], NULL);
}

void display_game_over_panel2(main_town_t *town)
{
    if (stat_tab[LOAD_GO] == 1)
        draw_game_over(town, GO_LOAD1);
    if (stat_tab[LOAD_GO] == 2)
        draw_game_over(town, GO_LOAD2);
    if (stat_tab[LOAD_GO] == 3)
        draw_game_over(town, GO_LOAD3);
}

void display_game_over_panel1(main_town_t *town)
{
    if (stat_tab[GAME_OVER_RESTART] == 1)
        draw_game_over(town, GO_LOAD);
    if (stat_tab[GAME_OVER_QUIT] == 1)
        draw_game_over(town, GO_QUIT);
}

void draw_all_game_over(main_town_t *town)
{
    if (stat_tab[GAME_OVER] == 1) {
        sfRenderWindow_clear(town->window.window, sfBlack);
        if (stat_tab[PANEL_TWO] == 0)
            display_game_over_panel1(town);
        if (stat_tab[PANEL_TWO] == 1)
            display_game_over_panel2(town);
        sfRenderWindow_display(town->window.window);
    }
}
