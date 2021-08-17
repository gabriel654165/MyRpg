/*
** EPITECH PROJECT, 2020
** collision
** File description:
** collision
*/

#include "town.h"

int oui_la_collision2(main_town_t *town, sfVector2f coor, sfSprite *spr)
{
    if (town->png.coor.x + sfSprite_getLocalBounds(town->png.spr).width
        * town->size.size.x >= coor.x
        && town->png.coor.x <= coor.x + sfSprite_getLocalBounds(spr).width
        * town->size.size.x)
        if (town->png.coor.y + sfSprite_getLocalBounds(town->png.spr).height
            * town->size.size.y >= coor.y + sfSprite_getLocalBounds(spr).height
            * town->size.size.y / 2
            && town->png.coor.y + sfSprite_getLocalBounds(town->png.spr).height
            * town->size.size.y / 2 <= coor.y
            + sfSprite_getLocalBounds(spr).height
            * town->size.size.y)
            return 1;
    return 0;
}

int oui_la_collision(main_town_t *town, sfVector2f coor, sfSprite *spr)
{
    if (oui_la_collision2(town, coor, spr) == 1)
        return 1;
    if (town->png.coor.x + sfSprite_getLocalBounds(town->png.spr).width
        * town->size.size.x <= coor.x
        && town->png.coor.x >= coor.x + sfSprite_getLocalBounds(spr).width
        * town->size.size.x)
        if (town->png.coor.y + sfSprite_getLocalBounds(town->png.spr).height
            * town->size.size.y <= coor.y + sfSprite_getLocalBounds(spr).height
            * town->size.size.y / 2
            && town->png.coor.y + sfSprite_getLocalBounds(town->png.spr).height
            * town->size.size.y / 2 >= coor.y +
            sfSprite_getLocalBounds(spr).height
            * town->size.size.y)
            return 1;
    return 0;
}

sfVector2f get_hitbox_collision(sfSprite *spr, main_town_t *town)
{
    sfVector2f hitbox;
    hitbox.x = sfSprite_getLocalBounds(spr).width * town->size.size.x;
    hitbox.y = sfSprite_getLocalBounds(spr).height * town->size.size.y / 2;
    return hitbox;
}

int collision(main_town_t *town, sfVector2f coor, sfSprite *spr)
{
    sfVector2f hitbox = get_hitbox_collision(spr, town);
    sfVector2f hitbox2 = get_hitbox_collision(town->png.spr, town);
    if (oui_la_collision(town, coor, spr) == 1) {
        if (town->png.coor.x + hitbox2.x >=
            coor.x && town->png.coor.x <= coor.x)
            return 1;
        if (town->png.coor.x <= coor.x + hitbox.x && town->png.coor.x
            + hitbox2.x >= coor.x + hitbox.x)
            return 2;
        if (town->png.coor.y + hitbox2.y * 2 >=
            coor.y + hitbox.y && town->png.coor.y
            + hitbox2.y <= coor.y + hitbox.y)
            return 3;
        if (town->png.coor.y + hitbox2.y <= coor.y + 2 * hitbox.y
            && town->png.coor.y + 2 * hitbox2.y >= coor.y + 2 * hitbox.y)
            return 4;
    }
    return 0;
}

int collision_png(main_town_t *town, sfVector2f coor, sfSprite *spr)
{
    int collide = 0;
    if ((collide = collision(town, coor, spr)) > 0) {
        if (collide == 1) {
            collision_tab[RIGHT] = 1;
            return 1;
        }
        if (collide == 2) {
            collision_tab[LEFT] = 1;
            return 1;
        }
        if (collide == 3){
            collision_tab[DOWN] = 1;
            return 1;
        }
        if (collide == 4) {
            collision_tab[UP] = 1;
            return 1;
        }
    }
    return 0;
}
