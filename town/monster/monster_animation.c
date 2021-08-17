/*
** EPITECH PROJECT, 2020
** monster_animation
** File description:
** monster_animation
*/

#include "town.h"

void monster_territory3(main_town_t *town, map_t *monster)
{
    if (monster->alea == 7 && get_zone_for_monster(monster, town) == 1) {
        sfSprite_setOrigin(spr_tab[SPRITE_MONSTER], (sfVector2f){500, 0});
        sfSprite_setScale(spr_tab[SPRITE_MONSTER],
        (sfVector2f){-town->size.size.x, town->size.size.y});
        monster->coor.x += 1;
        monster->coor.y -= 1;
    }
    if (monster->alea == 8 && get_zone_for_monster(monster, town) == 1) {
        sfSprite_setOrigin(spr_tab[SPRITE_MONSTER], (sfVector2f){0, 0});
        sfSprite_setScale(spr_tab[SPRITE_MONSTER], town->size.size);
        monster->coor.x -= 1;
        monster->coor.y -= 1;
    }
    sfSprite_setPosition(spr_tab[SPRITE_MONSTER],
    (sfVector2f){monster->coor.x * town->size.size.x,
    monster->coor.y * town->size.size.y});
}

void monster_territory2(main_town_t *town, map_t *monster)
{
    if (monster->alea == 4 && get_zone_for_monster(monster, town) == 1) {
        monster->coor.x -= 1;
        sfSprite_setOrigin(spr_tab[SPRITE_MONSTER], (sfVector2f){0, 0});
        sfSprite_setScale(spr_tab[SPRITE_MONSTER], town->size.size);
    }
    if (monster->alea == 5 && get_zone_for_monster(monster, town) == 1) {
        sfSprite_setOrigin(spr_tab[SPRITE_MONSTER], (sfVector2f){500, 0});
        sfSprite_setScale(spr_tab[SPRITE_MONSTER],
        (sfVector2f){-town->size.size.x, town->size.size.y});
        monster->coor.x += 1;
        monster->coor.y += 1;
    }
    if (monster->alea == 6 && get_zone_for_monster(monster, town) == 1) {
        sfSprite_setOrigin(spr_tab[SPRITE_MONSTER], (sfVector2f){0, 0});
        sfSprite_setScale(spr_tab[SPRITE_MONSTER], town->size.size);
        monster->coor.x -= 1;
        monster->coor.y += 1;
    }
}

void monster_territory(main_town_t *town, map_t *monster)
{
    sfTime time = sfClock_getElapsedTime(tab_clock[CLOCK_MOVE_MONSTER]);
    float seconds = sfTime_asSeconds(time);
    if (seconds - monster->direction_time >= 5) {
        monster->alea = rand()% 8 + 1;
        monster->direction_time = seconds;
    }
    if (monster->alea == 1 && get_zone_for_monster(monster, town) == 1)
        monster->coor.y -= 1;
    if (monster->alea == 2 && get_zone_for_monster(monster, town) == 1) {
        monster->coor.x += 1;
        sfSprite_setOrigin(spr_tab[SPRITE_MONSTER], (sfVector2f){500, 0});
        sfSprite_setScale(spr_tab[SPRITE_MONSTER],
        (sfVector2f){-town->size.size.x, town->size.size.y});
    }
    if (monster->alea == 3 && get_zone_for_monster(monster, town) == 1)
        monster->coor.y += 1;
    monster_territory2(town, monster);
    monster_territory3(town, monster);
}

int get_random_coor(map_t *monster)
{
    int chance = 0;
    sfTime time = sfClock_getElapsedTime(tab_clock[CLOCK_SPAWN_MONSTER]);
    float seconds = sfTime_asSeconds(time);
    if (seconds > 5) {
        chance = rand() % 3 + 1;
        sfClock_restart(tab_clock[CLOCK_SPAWN_MONSTER]);
    }
    if (chance == 1) {
        int max_x = monster->coor_x.x + monster->coor_x.y;
        int max_y = monster->coor_y.x + monster->coor_y.y;
        int alea_x = rand() % max_x + monster->coor_x.x;
        int alea_y = rand() % max_y + monster->coor_y.x;
        monster->coor.x = alea_x;
        monster->coor.y = alea_y;
        monster->live = 1;
        return 0;
    }
    return 1;
}

char **monster_animation(map_t monster, main_town_t *town, int i,
    char **tab_pars)
{
    tab_pars = monster_state(&monster, town, i, tab_pars);
    if (monster.live == 1 && stat_tab[GAME_OVER] != 1) {
        float seconds = get_elapsed_time(tab_clock[CLOCK_MONSTER]);
        if (seconds - monster.time > 0.2) {
            monster.rect.left -= monster.offset_left;
            if (monster.rect.left <= monster.min_offset_left)
                monster.rect.left = monster.max_offset_left;
            monster.time = seconds;
        }
        if (aggro_monster(town, &monster) == 1)
            get_the_aggro(town, &monster);
        else
            monster_territory(town, &monster);
        sfSprite_setTexture(spr_tab[SPRITE_MONSTER], monster.texture, sfTrue);
        sfSprite_setTextureRect(spr_tab[SPRITE_MONSTER], monster.rect);
        if (monster.live == 1)
            draw_spr_chosen(town, spr_tab[SPRITE_MONSTER]);
        tab_pars = actualise_monster(monster, i, tab_pars);
    }
    return tab_pars;
}
