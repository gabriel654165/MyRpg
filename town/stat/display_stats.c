/*
** EPITECH PROJECT, 2020
** display_stats
** File description:
** yes
*/

#include "town.h"

void draw_stats(main_town_t *town, enum save_txt TEST)
{
    sfVector2f pos;
    sfVector2f coor;

    sfSprite_setTexture(spr_tab[STAT_SPRITE], texture_stat[TEST], sfTrue);
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

void draw_life_text(main_town_t *town)
{
    sfVector2f position;
    sfVector2f coor;
    char *str = my_int_to_str(stat_tab[LIFE]);

    coor.x = (sfSprite_getLocalBounds(spr_tab[STAT_SPRITE]).width - 3250)
        / 2 * town->size.size.x;
    coor.y = (sfSprite_getLocalBounds(spr_tab[STAT_SPRITE]).height - 80)
        / 2 * town->size.size.y;
    position.x = town->p.value_middle.x - coor.x;
    position.y = town->p.value_middle.y - coor.y;
    sfText_setPosition (text_tab[STATS], position);
    sfText_setString (text_tab[STATS], str);
    sfText_setScale(text_tab[STATS], town->size.size);
    sfText_setCharacterSize(text_tab[STATS], 30);
    sfText_setFont(text_tab[STATS], tab_font[FONT_1]);
    sfText_setColor(text_tab[STATS], sfWhite);
    sfRenderWindow_drawText(town->window.window, text_tab[STATS], NULL);
}

void draw_xp_text(main_town_t *town)
{
    sfVector2f position;
    sfVector2f coor;
    char *str = my_int_to_str(stat_tab[XP_LVL]);

    coor.x = (sfSprite_getLocalBounds(spr_tab[STAT_SPRITE]).width - 3250)
        / 2 * town->size.size.x;
    coor.y = (sfSprite_getLocalBounds(spr_tab[STAT_SPRITE]).height - 230)
        / 2 * town->size.size.y;
    position.x = town->p.value_middle.x - coor.x;
    position.y = town->p.value_middle.y - coor.y;
    sfText_setPosition (text_tab[STATS], position);
    sfText_setString (text_tab[STATS], str);
    sfText_setScale(text_tab[STATS], town->size.size);
    sfText_setCharacterSize(text_tab[STATS], 30);
    sfText_setFont(text_tab[STATS], tab_font[FONT_1]);
    sfText_setColor(text_tab[STATS], sfWhite);
    sfRenderWindow_drawText(town->window.window, text_tab[STATS], NULL);
}

void diplay_stats(main_town_t *town)
{
    static int life_chose_sprite = 4;
    static int xp_chose_sprite = 0;

    life_chose_sprite = calcul_life();
    xp_chose_sprite = calcul_xp();
    xp_chose_sprite = xp_diplayed(xp_chose_sprite, town);
    life_chose_sprite = life_display(life_chose_sprite, town);
    increase_capacities();
    if (int_tab[CINE_X] == 0 && int_tab[CINE_Y] == 0) {
        draw_life_text(town);
        draw_xp_text(town);
    }
}
