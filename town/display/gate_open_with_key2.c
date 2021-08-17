/*
** EPITECH PROJECT, 2020
** gate_open_key
** File description:
** gate_open_key
*/

#include "town.h"

void draw_door_open_close(map_t map, main_town_t *town, sfTexture *text,
    float delta)
{
    sfVector2f pos;
    sfVector2f size_texture;
    sfSprite_setTexture(spr_tab[SPR_GATE_K], text, sfTrue);
    pos.x = (map.coor_x.x * town->size.size.x +
        sfSprite_getLocalBounds(spr_tab[SPR_GATE_KEY]).width *
        town->size.size.x / 2)
        - sfSprite_getLocalBounds(spr_tab[SPR_GATE_K]).width *
        town->size.size.x / 2
        - delta * town->size.size.x;
    pos.y = map.coor_x.y * town->size.size.y + 35 * town->size.size.y;
    sfSprite_setScale(spr_tab[SPR_GATE_K], town->size.size);
    sfSprite_setPosition(spr_tab[SPR_GATE_K], pos);
    size_texture =
    (sfVector2f){sfSprite_getGlobalBounds(spr_tab[SPR_GATE_K]).width *
    town->size.size.x,
    sfSprite_getGlobalBounds(spr_tab[SPR_GATE_K]).height * town->size.size.y};
    draw_sprite(town, pos, size_texture, spr_tab[SPR_GATE_K]);
}

int check_inventory_key(main_town_t *town)
{
    int i = 0;
    for (; my_strcmp(town->parser.object[i], "/1:") != 0; i++);
    for (i += 2; my_strcmp(town->parser.object[i], "/end") != 0; i++) {
        if (get_the_part_want(town->parser.object[i], 2) == 10)
            return 1;
    }
    return 0;
}

void draw_text_choose(main_town_t *town, map_t map, char *str)
{
    sfVector2f pos;
    pos.x = map.coor_x.x * town->size.size.x;
    pos.y = map.coor_x.y * town->size.size.y - 20 * town->size.size.y;
    sfText_setFillColor(text_tab[TALK_POSS], sfBlack);
    sfText_setPosition(text_tab[TALK_POSS], pos);
    sfText_setScale(text_tab[TALK_POSS], town->size.size);
    sfText_setString(text_tab[TALK_POSS], str);
    sfText_setCharacterSize(text_tab[TALK_POSS], 35);
    sfText_setFont(text_tab[TALK_POSS], tab_font[FONT_1]);
    sfRenderWindow_drawText(town->window.window, text_tab[TALK_POSS], NULL);
}

char **actualise_gate_open(char **tab, map_t map, int i)
{
    char *str = NULL;
    str = str_concat(my_itoa(map.coor_x.x), my_itoa(map.coor_x.y), ':');
    str = str_concat(str, my_itoa(1), ':');
    str = str_concat(str, my_itoa(1), ':');
    tab[i] = free_the_str(tab[i]);
    tab[i] = my_strcpy_malloc(str);
    str = free_the_str(str);
    return tab;
}
