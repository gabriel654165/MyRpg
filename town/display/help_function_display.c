/*
** EPITECH PROJECT, 2020
** ye
** File description:
** no
*/

#include "../include/my.h"
#include "../include/town.h"
#include "../include/olivier.h"

void draw_spr_chosen(main_town_t *town, sfSprite *spr)
{
    sfRenderWindow_drawSprite(town->window.window, spr, NULL);
}

void draw_png(main_town_t *town, sfVector2f pos, sfSprite *spr)
{
    if (town->png.coor.x >= pos.x && town->png.coor.x <= pos.x +
        sfSprite_getLocalBounds(spr).width * town->size.size.x) {
        if (town->png.coor.y >= pos.y && town->png.coor.y <= pos.y +
            sfSprite_getLocalBounds(spr).height * town->size.size.y) {
            if (town->png.coor.y + sfSprite_getLocalBounds(town->png.spr).height
                * town->size.size.y <= pos.y +
                sfSprite_getLocalBounds(spr).height * town->size.size.y) {
                draw_spr_chosen(town, town->png.spr);
                draw_spr_chosen(town, spr);
            }
            else {
                draw_spr_chosen(town, spr);
                draw_spr_chosen(town, town->png.spr);
            }
        }
        else
            sfRenderWindow_drawSprite(town->window.window, spr, NULL);
    }
    else
        sfRenderWindow_drawSprite(town->window.window, spr, NULL);
}

void draw_sprite(main_town_t *town, sfVector2f pos,
    sfVector2f size_spr, sfSprite *spr)
{
    if (pos.x >= town->p.value_middle.x - (town->size.size_screen.x / 2)
        - size_spr.x
        && pos.x <= town->p.value_middle.x + (town->size.size_screen.x / 2)
        + size_spr.x
        && pos.y <= town->p.value_middle.y + (town->size.size_screen.y / 2)
        + size_spr.y
        && pos.y >= town->p.value_middle.y - (town->size.size_screen.y / 2)
        - size_spr.y)
        draw_png(town, pos, spr);
}
