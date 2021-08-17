/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** set hero
*/

#include "town.h"
#include "graphic.h"

void set_the_png(png_t *png)
{
    png->spr = sfSprite_create();
    png->coor = (sfVector2f){0, 0};
    png->rect_mvmt = (sfIntRect) {9, 4, 30, 64};
    png->rect_atk = (sfIntRect) {9, 520, 60, 60};
    sfSprite_setScale(png->spr, (sfVector2f) {2, 2});
    png->texture = sfTexture_createFromFile("texture_pack/hero.png", NULL);
    sfSprite_setTexture(png->spr, png->texture, sfTrue);
    sfSprite_setTextureRect(png->spr, png->rect_mvmt);
    png->clock = sfClock_create();
    png->sens = SUD;
    png->run = 0;
    png->move = false;
    png->attack = false;
}
