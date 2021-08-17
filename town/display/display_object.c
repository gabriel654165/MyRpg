/*
** EPITECH PROJECT, 2020
** display_obj
** File description:
** display_obj
*/

#include "my.h"
#include "town.h"
#include "olivier.h"

void display_object(map_t map, main_town_t *town)
{
    sfVector2f pos;
    sfVector2f size_texture;
    pos.x = map.coor_x.x * town->size.size.x;
    pos.y = map.coor_x.y * town->size.size.y;
    sfSprite_setScale(spr_tab[SPRITE_OBJ], town->size.size);
    sfSprite_setPosition(spr_tab[SPRITE_OBJ], pos);
    sfSprite_setTexture(spr_tab[SPRITE_OBJ], map.texture, sfTrue);
    size_texture =
        (sfVector2f){sfSprite_getGlobalBounds(spr_tab[SPRITE_OBJ]).width,
        sfSprite_getGlobalBounds(spr_tab[SPRITE_OBJ]).height};
    draw_sprite(town, pos, size_texture, spr_tab[SPRITE_OBJ]);
    if (map.collision == 1)
        collision_png(town, pos, spr_tab[SPRITE_OBJ]);
}
