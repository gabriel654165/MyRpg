/*
** EPITECH PROJECT, 2020
** set_enums
** File description:
** yes
*/

#include "town.h"
#include "graphic.h"
#include "olivier.h"

void set_enums3(void)
{
    for (int i = 0; i < GATE_K; i++)
        tab_gate_k[i] = sfTexture_createFromFile(GATE_K_TAB[i].txt, NULL);
    for (int i = 0; i < PNG_QU; i++)
        png_quest_qu[i] = sfTexture_createFromFile(PNG_QUEST_QU[i].txt, NULL);
}

void set_enums2(void)
{
    for (int i = 0; i < CLOCK; i++)
        tab_clock[i] = sfClock_create();
    for (int i = 0; i < MONSTER; i++)
        text_monster[i] = sfTexture_createFromFile(MONSTER_TAB[i].txt, NULL);
    for (int i = 0; i < TILESET; i++)
        tab_tilset[i] = sfTexture_createFromFile(TEXTURE_MAP[i].txt, NULL);
    for (int i = 0; i < TEXTURE; i++)
        tab_txt[i] = sfTexture_createFromFile(TEXTURE_OBJ[i].txt, NULL);
    for (int i = 0; i < TEXTURE_MVT; i++)
        texture_mouv[i] = sfTexture_createFromFile(TEXTURE_MOUV[i].txt, NULL);
    for (int i = 0; i < SAVE_TXT; i++)
        texture_save[i] = sfTexture_createFromFile(TEXTURE_SAVE[i].txt, NULL);
    for (int i = 0; i < STAT_TXT; i++)
        texture_stat[i] = sfTexture_createFromFile(TEXTURE_STAT[i].txt, NULL);
    for (int i = 0; i < SPRITE; i++)
        spr_tab[i] = sfSprite_create();
    for (int i = 0; i < CHEST; i++)
        tab_chest[i] = sfTexture_createFromFile(TEXTURE_CHEST[i].txt, NULL);
}

void set_enums_part_two(void)
{
    for (int i = 0; i < TEXT; i++)
        text_tab[i] = sfText_create();
    for (int i = 0; i < FONT; i++)
        tab_font[i] = sfFont_createFromFile(FONT_TAB[i].txt);
    for (int i = 0; i < COLLISION; i++)
        collision_tab[i] = 0;
    for (int i = 0; i < LOCK; i++)
        int_tab[i] = 0;
    for (int i = 0; i < END; i++)
        save_tab[i] = 0;
}

void set_the_enums(void)
{
    set_stats();
    for (int i = 0; i < GO; i++)
        text_game_over[i] = sfTexture_createFromFile(GAME_OVER_TAB[i].txt,
        NULL);
    for (int i = 0; i < QUEST_ENUM; i++)
        text_quest[i] = sfTexture_createFromFile(QUEST_TAB[i].txt, NULL);
    for (int i = 0; i < RECTANGLE; i++)
        tab_rect[i] = sfRectangleShape_create();
    for (int i = 0; i < INV; i++)
        inventory_tab[i] = sfTexture_createFromFile(INVENTORY_TAB[i].txt, NULL);
    set_enums_part_two();
    set_enums2();
    set_enums3();
}
