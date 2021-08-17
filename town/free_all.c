/*
** EPITECH PROJECT, 2020
** free_all
** File description:
** free_all
*/

#include "town.h"
#include "olivier.h"

void free_all3(void)
{
    for (int i = 0; i < GATE_K; i++)
        sfTexture_destroy(tab_gate_k[i]);
    for (int i = 0; i < PNG_QU; i++)
        sfTexture_destroy(png_quest_qu[i]);
}

void free_all2(void)
{
    for (int i = 0; i < CLOCK; i++)
        sfClock_destroy(tab_clock[i]);
    for (int i = 0; i < MONSTER; i++)
        sfTexture_destroy(text_monster[i]);
    for (int i = 0; i < TILESET; i++)
        sfTexture_destroy(tab_tilset[i]);
    for (int i = 0; i < TEXTURE; i++)
        sfTexture_destroy(tab_txt[i]);
    for (int i = 0; i < TEXTURE_MVT; i++)
        sfTexture_destroy(texture_mouv[i]);
    for (int i = 0; i < SAVE_TXT; i++)
        sfTexture_destroy(texture_save[i]);
    for (int i = 0; i < STAT_TXT; i++)
        sfTexture_destroy(texture_stat[i]);
    for (int i = 0; i < SPRITE; i++)
        sfSprite_destroy(spr_tab[i]);
    for (int i = 0; i < CHEST; i++)
        sfTexture_destroy(tab_chest[i]);
}

void free_all(main_town_t *town)
{
    for (int i = 0; i < GO; i++)
        sfTexture_destroy(text_game_over[i]);
    for (int i = 0; i < QUEST_ENUM; i++)
        sfTexture_destroy(text_quest[i]);
    for (int i = 0; i < RECTANGLE; i++)
        sfRectangleShape_destroy(tab_rect[i]);
    for (int i = 0; i < INV; i++)
        sfTexture_destroy(inventory_tab[i]);
    for (int i = 0; i < TEXT; i++)
        sfText_destroy(text_tab[i]);
    for (int i = 0; i < FONT; i++)
        sfFont_destroy(tab_font[i]);
    free_all2();
    free_all3();
    free_sound(&town->music);
}
