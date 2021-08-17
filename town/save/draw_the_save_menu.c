/*
** EPITECH PROJECT, 2020
** draw_save_menu.cc
** File description:
** yes
*/

#include "town.h"

void draw_menu_bg(main_town_t *town, enum save_txt TEST)
{
    sfVector2f pos;
    sfVector2f coor;

    sfSprite_setTexture(spr_tab[SAVE_SPRITE], texture_save[TEST], sfTrue);
    sfSprite_setScale(spr_tab[SAVE_SPRITE], town->size.size);
    coor.x = sfSprite_getLocalBounds(spr_tab[SAVE_SPRITE]).width
    / 2 * town->size.size.x;
    coor.y = sfSprite_getLocalBounds(spr_tab[SAVE_SPRITE]).height
    / 2 * town->size.size.y;
    pos.x = town->p.value_middle.x - coor.x;
    pos.y = town->p.value_middle.y - coor.y;
    sfSprite_setPosition(spr_tab[SAVE_SPRITE], pos);
    sfRenderWindow_drawSprite(town->window.window, spr_tab[SAVE_SPRITE], NULL);
}

void draw_menu_all(main_town_t *town, enum save_txt TEST)
{
    sfVector2f pos;
    sfVector2f coor;

    sfSprite_setTexture(spr_tab[SAVE_SPRITE], texture_save[TEST], sfTrue);
    sfSprite_setScale(spr_tab[SAVE_SPRITE], town->size.size);
    coor.x = sfSprite_getLocalBounds(spr_tab[SAVE_SPRITE]).width / 2
        * town->size.size.x;
    coor.y = sfSprite_getLocalBounds(spr_tab[SAVE_SPRITE]).height / 2
        * town->size.size.y;
    pos.x = town->p.value_middle.x - coor.x;
    pos.y = town->p.value_middle.y - coor.y;
    sfSprite_setPosition(spr_tab[SAVE_SPRITE], pos);
    sfRenderWindow_drawSprite(town->window.window, spr_tab[SAVE_SPRITE], NULL);
}

void draw_menu_text(main_town_t *town, char *str, sfVector2f p, int size)
{
    sfVector2f position;
    sfVector2f coor;
    coor.x = (sfSprite_getLocalBounds(spr_tab[STAT_SPRITE]).width - 1780 + p.x)
        / 2 * town->size.size.x;
    coor.y = (sfSprite_getLocalBounds(spr_tab[STAT_SPRITE]).height - 900 + p.y)
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
