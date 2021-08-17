/*
** EPITECH PROJECT, 2020
** monster_hit_box
** File description:
** yes
*/

#include "town.h"

int hit_box_monster_hurt(map_t *monster,
    sfVector2f player, main_town_t *town)
{
    int checkx = 0, checky = 0;

    if ((monster->coor.x + monster->hit_box_x.x) * town->size.size.x < player.x
        && player.x < ((monster->coor.x +
        sfSprite_getLocalBounds(spr_tab[SPRITE_MONSTER]).width -
        monster->hit_box_x.y) * town->size.size.x))
        checkx += 1;
    if (((monster->coor.y + monster->hit_box_y.x) * town->size.size.y)
        < player.y && player.y < ((monster->coor.y +
        sfSprite_getLocalBounds(spr_tab[SPRITE_MONSTER]).height -
        sfSprite_getLocalBounds(town->png.spr).height - monster->hit_box_y.y) *
        town->size.size.y))
        checky += 1;
    if (checkx == 1 && checky == 1)
        return 1;
    return 0;
}

int hit_box_monster_get_hurt(map_t *monster,
    sfVector2f player, main_town_t *town)
{
    int checkx = 0, checky = 0;

    if ((monster->coor.x) * town->size.size.x < player.x
        && player.x < ((monster->coor.x +
        sfSprite_getLocalBounds(spr_tab[SPRITE_MONSTER]).width) *
        town->size.size.x))
        checkx += 1;
    if (((monster->coor.y) * town->size.size.y) < player.y
        && player.y < ((monster->coor.y +
        sfSprite_getLocalBounds(spr_tab[SPRITE_MONSTER]).height -
        sfSprite_getLocalBounds(town->png.spr).height) * town->size.size.y))
        checky += 1;
    if (checkx == 1 && checky == 1)
        return 1;
    return 0;
}

void monster_attack_damages(map_t *monster,
    sfVector2f player, main_town_t *town)
{
    if (hit_box_monster_hurt(monster, player, town) == 1)
        monster_hurt_actions(monster, town);
    if (hit_box_monster_get_hurt(monster, player, town) == 1)
        monster_get_hurt_actions(monster);
}
