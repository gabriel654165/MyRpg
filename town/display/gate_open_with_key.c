/*
** EPITECH PROJECT, 2020
** gate_open_with_key
** File description:
** gate_open_with_key
*/

#include "town.h"

char **door_open_management(main_town_t *town, map_t map, char **tab, int i)
{
    int_tab[GATE_CAN_BE_OPEN] = 1;
    if (map.life == 0 && int_tab[OPEN_DOOR] == 1)
        if (check_inventory_key(town) == 1) {
            int_tab[OPEN_DOOR] = 0;
            tab = actualise_gate_open(tab, map, i);
            int_tab[GO_IN_CASTLE] = 1;
            return tab;
        }
    if (map.life == 1 && int_tab[OPEN_DOOR] == 1) {
        int_tab[OPEN_DOOR] = 0;
        int_tab[GO_IN_CASTLE] = 1;
    }
    int_tab[OPEN_DOOR] = 0;
    if (check_inventory_key(town) == 1 && map.life == 0)
        draw_text_choose(town, map, "Ouvrir [ENTRER]");
    else if (check_inventory_key(town) == 1 && map.life == 1)
        draw_text_choose(town, map, "CHATEAU DE BOSS [ENTRER]");
    else
        draw_text_choose(town, map, "Vous ne pouvez pas aller a cet endroit");
    return tab;
}

void draw_wall_for_door(main_town_t *town, sfVector2f pos)
{
    sfVector2f size_texture;
    sfSprite_setScale(spr_tab[SPR_GATE_KEY], town->size.size);
    sfSprite_setPosition(spr_tab[SPR_GATE_KEY], pos);
    sfSprite_setTexture(spr_tab[SPR_GATE_KEY], tab_gate_k[WALL_K], sfTrue);
    size_texture =
    (sfVector2f){sfSprite_getGlobalBounds(spr_tab[SPR_GATE_KEY]).width *
    town->size.size.x,
    sfSprite_getGlobalBounds(spr_tab[SPR_GATE_KEY]).height * town->size.size.y};
    draw_sprite(town, pos, size_texture, spr_tab[SPR_GATE_KEY]);
}

char **gate_open_with_key(map_t map, main_town_t *town, int i, char **tab)
{
    sfVector2f pos;
    pos.x = map.coor_x.x * town->size.size.x;
    pos.y = map.coor_x.y * town->size.size.y;
    draw_wall_for_door(town, pos);
    if (map.life == 0)
        draw_door_open_close(map, town, tab_gate_k[GATE_K_CLOSE], 0);
    else
        draw_door_open_close(map, town, tab_gate_k[GATE_K_OPEN], 30);
    if (map.collision == 1)
        if (collision_png(town, pos, spr_tab[SPR_GATE_KEY]))
            door_open_management(town, map, tab, i);
    return tab;
}
