/*
** EPITECH PROJECT, 2020
** monster_aggro_move
** File description:
** monster_aggro_move
*/

#include "town.h"
#define MONSTER_SPEED 3

void get_the_aggro4(main_town_t *town, map_t *monster,
    sfVector2f player, sfVector2f rect)
{
    if (player.x < monster->coor.x
        && player.y < monster->coor.y && get_zone_for_monster(monster,
        town) == 1) {
        monster->coor.x -= MONSTER_SPEED;
        monster->coor.y -= MONSTER_SPEED;
        sfSprite_setOrigin(spr_tab[SPRITE_MONSTER], (sfVector2f){0, 0});
        sfSprite_setScale(spr_tab[SPRITE_MONSTER],
        (sfVector2f){town->size.size.x, town->size.size.y});
    }
    if (player.x < monster->coor.x
        && player.y > monster->coor.y + rect.y
        && get_zone_for_monster(monster, town) == 1) {
        monster->coor.x -= MONSTER_SPEED;
        monster->coor.y += MONSTER_SPEED;
        sfSprite_setOrigin(spr_tab[SPRITE_MONSTER], (sfVector2f){0, 0});
        sfSprite_setScale(spr_tab[SPRITE_MONSTER],
        (sfVector2f){town->size.size.x, town->size.size.y});
    }
}

void get_the_aggro3(main_town_t *town, map_t *monster,
    sfVector2f player, sfVector2f rect)
{
    if (player.x > monster->coor.x + rect.x
        && player.y < monster->coor.y
        && get_zone_for_monster(monster, town) == 1) {
        monster->coor.x += MONSTER_SPEED;
        monster->coor.y -= MONSTER_SPEED;
        sfSprite_setOrigin(spr_tab[SPRITE_MONSTER], (sfVector2f){500, 0});
        sfSprite_setScale(spr_tab[SPRITE_MONSTER],
        (sfVector2f){-town->size.size.x, town->size.size.y});
    }
    if (player.y > monster->coor.y + rect.y
        && player.x > monster->coor.x + rect.x
        && get_zone_for_monster(monster, town) == 1) {
        monster->coor.x += MONSTER_SPEED;
        monster->coor.y += MONSTER_SPEED;
        sfSprite_setOrigin(spr_tab[SPRITE_MONSTER], (sfVector2f){500, 0});
        sfSprite_setScale(spr_tab[SPRITE_MONSTER],
        (sfVector2f){-town->size.size.x, town->size.size.y});
    }
}

void get_the_aggro2(main_town_t *town, map_t *monster,
    sfVector2f player, sfVector2f rect)
{
    if (player.x <= monster->coor.x && player.y >= monster->coor.y
        && player.y <= monster->coor.y + rect.y
        && get_zone_for_monster(monster, town) == 1) {
        monster->coor.x -= MONSTER_SPEED;
        sfSprite_setOrigin(spr_tab[SPRITE_MONSTER], (sfVector2f){0, 0});
        sfSprite_setScale(spr_tab[SPRITE_MONSTER],
        (sfVector2f){town->size.size.x, town->size.size.y});
    }
    if (player.y >= monster->coor.y + rect.y
        && player.x >= monster->coor.x
        && player.x <= monster->coor.x + rect.x
        && get_zone_for_monster(monster, town) == 1)
        monster->coor.y += MONSTER_SPEED;
    if (player.y <= monster->coor.y
        && player.x >= monster->coor.x
        && player.x <= monster->coor.x + rect.x
        && get_zone_for_monster(monster, town) == 1)
        monster->coor.y -= MONSTER_SPEED;
}

void aggro_handling(main_town_t *town, map_t *monster,
    sfVector2f player, sfVector2f rect)
{
    get_the_aggro2(town, monster, player, rect);
    get_the_aggro3(town, monster, player, rect);
    get_the_aggro4(town, monster, player, rect);
}

void get_the_aggro(main_town_t *town, map_t *monster)
{
    sfVector2f player;
    sfVector2f rect;
    player.x = town->p.value_middle.x;
    player.y = town->p.value_middle.y;
    rect.x = monster->rect.width * town->size.size.x;
    rect.y = monster->rect.height * town->size.size.y;
    if (player.x >= monster->coor.x + rect.x && player.y >= monster->coor.y
        && player.y <= monster->coor.y + rect.y
        && get_zone_for_monster(monster, town) == 1) {
        monster->coor.x += MONSTER_SPEED;
        sfSprite_setOrigin(spr_tab[SPRITE_MONSTER], (sfVector2f){500, 0});
        sfSprite_setScale(spr_tab[SPRITE_MONSTER],
        (sfVector2f){-town->size.size.x, town->size.size.y});
    }
    aggro_handling(town, monster, player, rect);
    monster_attack_position(monster, player, town);
    sfSprite_setPosition(spr_tab[SPRITE_MONSTER],
    (sfVector2f){monster->coor.x * town->size.size.x,
    monster->coor.y * town->size.size.y});
}
