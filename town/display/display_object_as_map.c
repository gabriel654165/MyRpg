/*
** EPITECH PROJECT, 2020
** display_obj
** File description:
** display
*/

#include "my.h"
#include "town.h"
#include "olivier.h"

void draw_the_obj_as_map(map_t map, main_town_t *town, int count_x, int count_y)
{
    sfVector2f pos = (sfVector2f){0, 0};
    sfVector2f size_map =
    (sfVector2f){sfSprite_getLocalBounds(spr_tab[SPRITE_DISP_OBJ]).width
    * town->size.size.x,
    sfSprite_getLocalBounds(spr_tab[SPRITE_DISP_OBJ]).height *
    town->size.size.y};
    pos.x = (count_x * size_map.x) - (town->size.size_screen.x / 2
    + size_map.x);
    pos.y = (count_y * size_map.y) - (town->size.size_screen.y / 2
    + size_map.y);
    sfSprite_setPosition(spr_tab[SPRITE_DISP_OBJ], pos);
    sfSprite_setScale(spr_tab[SPRITE_DISP_OBJ], town->size.size);
    sfSprite_setTexture(spr_tab[SPRITE_DISP_OBJ], map.texture, sfTrue);
    if (count_x >= map.coor_x.x && count_x <= map.coor_x.y + map.coor_x.x
        && count_y >= map.coor_y.x && count_y <= map.coor_y.x + map.coor_y.y) {
        draw_png(town, pos, spr_tab[SPRITE_DISP_OBJ]);
        if (map.collision == 1)
            collision_png(town, pos, spr_tab[SPRITE_DISP_OBJ]);
    }
}

void display_obj_as_map(map_t map, main_town_t *town)
{
    sfVector2f size_map = (sfVector2f){sfTexture_getSize(map.texture).x
    * town->size.size.x, sfTexture_getSize(map.texture).y * town->size.size.y};
    sfVector2f min_value = calcul_x_y_min(town, size_map);
    sfVector2f max_value = calcul_x_y_max(town, size_map);
    int count1 = (town->size.size_screen.x / 2 + town->p.value_view.x
    * town->size.size.x) / size_map.x;
    int count2 = (town->size.size_screen.y / 2 + town->p.value_view.y
    * town->size.size.y) / size_map.y;
    for (float i = min_value.y, count_y = count2; i < max_value.y;
        i += size_map.y, count_y++) {
        for (float j = min_value.x, count_x = count1; j < max_value.x;
            j += size_map.x, count_x++) {
            draw_the_obj_as_map(map, town, count_x, count_y);
        }
    }
}
