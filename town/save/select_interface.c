/*
** EPITECH PROJECT, 2020
** select_interface.c
** File description:
** yes
*/

#include "town.h"

void draw_load_text(main_town_t *town, char *str, sfVector2f p, int size)
{
    sfVector2f position;
    sfVector2f coor;

    coor.x = (sfSprite_getLocalBounds(spr_tab[STAT_SPRITE]).width + 165 + p.x)
    / 2 * town->size.size.x;
    coor.y = (sfSprite_getLocalBounds(spr_tab[STAT_SPRITE]).height + p.y)
    / 2 * town->size.size.y;
    position.x = town->p.value_middle.x - coor.x;
    position.y = town->p.value_middle.y - coor.y;
    sfText_setPosition (text_tab[STATS], position);
    sfText_setString (text_tab[STATS], str);
    sfText_setScale(text_tab[STATS], town->size.size);
    sfText_setCharacterSize(text_tab[STATS], size);
    sfText_setFont(text_tab[STATS], tab_font[FONT_1]);
    sfText_setColor(text_tab[STATS], sfBlack);
    sfRenderWindow_drawText(town->window.window, text_tab[STATS], NULL);
}

void draw_sprites(main_town_t *town)
{
    if (save_tab[OPEN_MENU_SAVE] == 1) {
        draw_menu_bg(town, BG_MENU);
        draw_menu_all(town, TXT_MENU1);
    }
    if (save_tab[LOAD_MENU1] == 1) {
        draw_load_text(town, "~SLOT1~", (sfVector2f){20, 120}, 50);
        draw_load_text(town, "~SLOT2~", (sfVector2f){0, 0}, 40);
        draw_load_text(town, "~SLOT3~", (sfVector2f){0, -120}, 40);
    }
    if (save_tab[LOAD_MENU2] == 1) {
        draw_load_text(town, "~SLOT1~", (sfVector2f){0, 120}, 40);
        draw_load_text(town, "~SLOT2~", (sfVector2f){20, 0}, 50);
        draw_load_text(town, "~SLOT3~", (sfVector2f){0, -120}, 40);
    }
    if (save_tab[LOAD_MENU3] == 1) {
        draw_load_text(town, "~SLOT1~", (sfVector2f){0, 120}, 40);
        draw_load_text(town, "~SLOT2~", (sfVector2f){0, 0}, 40);
        draw_load_text(town, "~SLOT3~", (sfVector2f){20, -120}, 50);
    }
}

void down_chose(sfEvent *event)
{
    if (event->key.code == sfKeyDown && save_tab[LOAD_MENU1] == 1) {
        save_tab[LOAD_MENU1] = 0;
        save_tab[LOAD_MENU2] = 1;
    } else if (event->key.code == sfKeyDown && save_tab[LOAD_MENU2] == 1) {
        save_tab[LOAD_MENU2] = 0;
        save_tab[LOAD_MENU3] = 1;
        return;
    }
    if (event->key.code == sfKeyDown && save_tab[LOAD_MENU3] == 1) {
        save_tab[LOAD_MENU3] = 0;
        save_tab[LOAD_MENU1] = 1;
    }
}

void up_chose(sfEvent *event)
{
    if (event->key.code == sfKeyUp && save_tab[LOAD_MENU1] == 1) {
        save_tab[LOAD_MENU1] = 0;
        save_tab[LOAD_MENU3] = 1;
    } else if (event->key.code == sfKeyUp && save_tab[LOAD_MENU3] == 1) {
        save_tab[LOAD_MENU3] = 0;
        save_tab[LOAD_MENU2] = 1;
        return;
    }
    if (event->key.code == sfKeyUp && save_tab[LOAD_MENU2] == 1) {
        save_tab[LOAD_MENU2] = 0;
        save_tab[LOAD_MENU1] = 1;
    }
}
