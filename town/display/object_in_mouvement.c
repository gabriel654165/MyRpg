/*
** EPITECH PROJECT, 2020
** object_in_mouvement
** File description:
** object_in_mouvement
*/

#include "my.h"
#include "town.h"
#include "olivier.h"

int gate_detection(main_town_t *town, sfVector2f pos)
{
    sfVector2f size_texture;
    size_texture =
        (sfVector2f){sfSprite_getGlobalBounds(spr_tab[SPRITE_OBJ]).width
        * town->size.size.x,
        sfSprite_getGlobalBounds(spr_tab[SPRITE_OBJ]).height
        * town->size.size.y};
    if (town->png.coor.x >= pos.x
        && town->png.coor.x <= pos.x + size_texture.x
        && (town->png.coor.y >= pos.y
            + size_texture.y - (300 * town->size.size.x)
            && town->png.coor.y <= pos.y
            + size_texture.y + (300 * town->size.size.y)))
        return 1;
    return 0;
}

int get_sign(int i, int option, int nbr, int ret)
{
    if (option == 1)
        if (i < ret)
            nbr++;
    if (option == 2)
        if (i == ret)
            nbr = 1;
    if (option == 3)
        if (i > ret)
            nbr--;
    if (option == 4)
        if (i == ret)
            nbr = 0;
    return nbr;
}

int gate_open_clock(main_town_t *town, sfVector2f pos, int i)
{
    sfTime time = sfClock_getElapsedTime(tab_clock[CLOCK_GATE_OPEN]);
    float seconds = sfTime_asSeconds(time);
    static int lock = 0;
    if (gate_detection(town, pos) == 1) {
        if (seconds > 0.5) {
            i = get_sign(i, 1, i, 7);
            lock = get_sign(i, 2, lock, 7);
            sfClock_restart(tab_clock[CLOCK_GATE_OPEN]);
        }
    }
    else
        if (seconds > 0.5 && lock == 1) {
            i = get_sign(i, 3, i, 4);
            lock = get_sign(i, 4, lock, 4);
            sfClock_restart(tab_clock[CLOCK_GATE_OPEN]);
        }
    return i;
}

void gate_open(map_t map, main_town_t *town)
{
    sfVector2f pos;
    sfVector2f size_texture;
    static int i = 4;
    pos.x = map.coor_x.x * town->size.size.x;
    pos.y = map.coor_x.y * town->size.size.y;
    sfSprite_setScale(spr_tab[SPRITE_OBJ], town->size.size);
    sfSprite_setPosition(spr_tab[SPRITE_OBJ], pos);
    sfSprite_setTexture(spr_tab[SPRITE_OBJ], texture_mouv[i], sfTrue);
    i = gate_open_clock(town, pos, i);
    size_texture =
    (sfVector2f){sfSprite_getGlobalBounds(spr_tab[SPRITE_OBJ]).width
    * town->size.size.x,
    sfSprite_getGlobalBounds(spr_tab[SPRITE_OBJ]).height
    * town->size.size.y};
    draw_sprite(town, pos, size_texture, spr_tab[SPRITE_OBJ]);
}
