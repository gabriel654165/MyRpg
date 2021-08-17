/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** caracteristique hero
*/

#ifndef HERO_H
#define HERO_H

#include "graphic.h"
#include <stdbool.h>

typedef struct png_s
{
    int dimension;
    sfTexture *texture;
    sfVector2f coor;
    sfSprite *spr;
    sfIntRect rect_mvmt;
    sfIntRect rect_atk;
    sfClock *clock;
    int sens;
    bool move;
    bool attack;
    int run;
} png_t;

enum orientation {
    SUD,
    NORD,
    OUEST,
    EST
};

#endif
