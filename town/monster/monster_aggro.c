/*
** EPITECH PROJECT, 2020
** monster_aggro
** File description:
** monster_aggro
*/

#include "town.h"
#define MONSTER_SPEED 5

void monster_attack_position(map_t *monster,
    sfVector2f player, main_town_t *town)
{
    sfVector2f rect;

    rect.x = monster->rect.width * town->size.size.x;
    rect.y = monster->rect.height * town->size.size.y;
    if (monster->coor.x + rect.x >= player.x
        && monster->coor.x + rect.x <= player.x +
        sfSprite_getLocalBounds(town->png.spr).width * town->size.size.x) {
        sfSprite_setOrigin(spr_tab[SPRITE_MONSTER], (sfVector2f){500, 0});
        sfSprite_setScale(spr_tab[SPRITE_MONSTER],
        (sfVector2f){-town->size.size.x, town->size.size.y});
    }
    if (monster->coor.x <= player.x && monster->coor.x >= player.x -
        sfSprite_getLocalBounds(town->png.spr).width * town->size.size.x
        && monster->coor.y <= player.y && monster->coor.y >= player.y -
        sfSprite_getLocalBounds(town->png.spr).height * town->size.size.y) {
        sfSprite_setOrigin(spr_tab[SPRITE_MONSTER], (sfVector2f){0, 0});
        sfSprite_setScale(spr_tab[SPRITE_MONSTER],
        (sfVector2f){town->size.size.x, town->size.size.y});
    }
    monster_attack_damages(monster, player, town);
}

int get_zone_for_monster(map_t *monster, main_town_t *town)
{
    sfVector2f coor;

    coor.x = monster->coor_x.x + monster->coor_x.y;
    coor.y = monster->coor_y.x + monster->coor_y.y;
    if (monster->coor.x >= monster->coor_x.x && monster->coor.x <= coor.x)
        if (monster->coor.y >= monster->coor_y.x && monster->coor.y <= coor.y)
            return 1;
    if (monster->coor.x >= coor.x)
        monster->coor.x -= 10 * town->size.size.x;
    if (monster->coor.x <= monster->coor_x.x)
        monster->coor.x += 10 * town->size.size.x;
    if (monster->coor.y >= coor.y)
        monster->coor.y -= 10 * town->size.size.y;
    if (monster->coor.y <= monster->coor_y.x)
        monster->coor.y += 10 * town->size.size.y;
    return 0;
}

int aggro_monster(main_town_t *town, map_t *monster)
{
    sfVector2f coor;

    coor.x = monster->coor.x +
    (sfSprite_getLocalBounds(spr_tab[SPRITE_MONSTER]).width *
    town->size.size.x / 2);
    coor.y = monster->coor.y +
    (sfSprite_getLocalBounds(spr_tab[SPRITE_MONSTER]).height *
    town->size.size.y / 2);
    if (town->p.value_middle.x >= coor.x - (monster->aggro * town->size.size.x)
        && town->p.value_middle.x <= coor.x +
        (monster->aggro * town->size.size.x)
        && town->p.value_middle.y <= coor.y +
        (monster->aggro * town->size.size.y)
        && town->p.value_middle.y >= coor.y -
        (monster->aggro * town->size.size.y)) {
        return 1;
    }
    return 0;
}
