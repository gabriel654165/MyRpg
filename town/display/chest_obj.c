/*
** EPITECH PROJECT, 2020
** chest
** File description:
** chest
*/

#include "town.h"

void display_text_chest(main_town_t *town, map_t quest)
{
    sfVector2f pos;
    pos.x = quest.coor_x.x * town->size.size.x;
    pos.y = quest.coor_x.y * town->size.size.y - 50 * town->size.size.y;
    sfText_setFillColor(text_tab[TALK_POSS], sfBlack);
    sfText_setPosition(text_tab[TALK_POSS], pos);
    sfText_setScale(text_tab[TALK_POSS], town->size.size);
    sfText_setString(text_tab[TALK_POSS], "CHERCHER [ENTRER]");
    sfText_setCharacterSize(text_tab[TALK_POSS], 35);
    sfText_setFont(text_tab[TALK_POSS], tab_font[FONT_1]);
    sfRenderWindow_drawText(town->window.window, text_tab[TALK_POSS], NULL);
}

char **actualise_chest_parser(map_t map, char **tab, int i)
{
    tab[i] = free_the_str(tab[i]);
    char *str = NULL;
    str = str_concat(my_itoa(map.coor_x.x), my_itoa(map.coor_x.y), ':');
    str = str_concat(str, my_itoa(map.life), ':');
    str = str_concat(str, my_itoa(map.collision), ':');
    str = str_concat(str, my_itoa(map.txt), ':');
    str = str_concat(str, my_itoa(map.attack), ':');
    str = str_concat(str, my_itoa(map.live), ':');
    str = str_concat(str, my_itoa(map.aggro + 1), ':');
    tab[i] = my_strcpy_malloc(str);
    str = free_the_str(str);
    return tab;
}

char **chest_function(map_t map, main_town_t *town, char **tab, int i)
{
    display_text_chest(town, map);
    if (int_tab[OPEN_CHEST] == 1 && map.aggro == 0) {
        for (int count = 0; count < map.txt; count++)
            put_obj_in_inventory(town, map.attack, map.live);
        int_tab[OPEN_CHEST] = 0;
        tab = actualise_chest_parser(map, tab, i);
    }
    return tab;
}

char **chest_obj(map_t map, main_town_t *town, int i, char **tab)
{
    sfVector2f pos;
    sfVector2f size_texture;
    pos.x = map.coor_x.x * town->size.size.x;
    pos.y = map.coor_x.y * town->size.size.y;
    sfSprite_setScale(spr_tab[SPRITE_OBJ], town->size.size);
    sfSprite_setPosition(spr_tab[SPRITE_OBJ], pos);
    sfSprite_setTexture(spr_tab[SPRITE_OBJ], map.texture, sfTrue);
    size_texture =
        (sfVector2f){sfSprite_getGlobalBounds(spr_tab[SPRITE_OBJ]).width *
        town->size.size.x,
        sfSprite_getGlobalBounds(spr_tab[SPRITE_OBJ]).height *
        town->size.size.y};
    draw_sprite(town, pos, size_texture, spr_tab[SPRITE_OBJ]);
    if (map.collision == 1) {
        int_tab[NEXTO_CHEST] = 1;
        if (collision_png(town, pos, spr_tab[SPRITE_OBJ]) == 1)
            tab = chest_function(map, town, tab, i);
    } else
        int_tab[NEXTO_CHEST] = 1;
    return tab;
}
