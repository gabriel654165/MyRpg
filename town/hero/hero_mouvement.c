/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** mouvement
*/

#include "town.h"
#include "graphic.h"

void move_hero(png_t *png, sfEvent *event)
{
    if (event->key.code == sfKeyLeft || event->key.code == sfKeyRight ||
        event->key.code == sfKeyDown || event->key.code == sfKeyUp)
        png->move = true;
    if (event->key.code == sfKeyLeft)
        png->sens = OUEST;
    if (event->key.code == sfKeyRight)
        png->sens = EST;
    if (event->key.code == sfKeyUp)
        png->sens = NORD;
    if (event->key.code == sfKeyDown)
        png->sens = SUD;
    if (event->key.code == sfKeyLShift)
        png->run = 1;
    if (event->key.code == sfKeyW)
        png->attack = true;
}

void stop_hero(png_t *png, sfEvent *event)
{
    if (event->key.code == sfKeyLeft || event->key.code == sfKeyRight ||
        event->key.code == sfKeyUp || event->key.code == sfKeyDown)
        png->move = false;
    if (event->key.code == sfKeyLShift)
        png->run = 0;
}

void change_dir_hero(png_t *png)
{
    sfIntRect rect = sfSprite_getTextureRect(png->spr);
    sfVector2f hscale = sfSprite_getScale(png->spr);

    if (png->attack == true) {
        if (png->sens == OUEST) {
            sfSprite_setScale(png->spr, (sfVector2f){-hscale.x, hscale.y});
            sfSprite_setOrigin(png->spr, (sfVector2f){rect.width, 0});
        }
        png->move = false;
        png->run = 0;
    }
    if (png->attack == false)
        rect.top = (png->rect_mvmt.height * png->sens) + 4;
    run_action_hero(png, &rect);
    attack_action_hero(png, &rect);
    sfSprite_setTextureRect(png->spr, rect);
}
