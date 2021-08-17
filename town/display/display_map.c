/*
** EPITECH PROJECT, 2020
** display_map
** File description:
** display_map
*/

#include "../include/my.h"
#include "../include/town.h"
#include "../include/olivier.h"

int cine_draw(int cine)
{
    if (int_tab[CINE_Y] != 0)
        cine = 3670;
    else
        cine = 0;
    return cine;
}

sfVector2f calcul_x_y_min(main_town_t *town, sfVector2f size_map)
{
    sfVector2f min_value;
    int cine = 0;

    cine = cine_draw(cine);
    min_value.x = town->p.value_middle.x -
        (town->size.size_screen.x / 2 + (size_map.x * 2));
    min_value.y = town->p.value_middle.y - cine -
        (town->size.size_screen.y / 2 + (size_map.y * 2));
    return min_value;
}

sfVector2f calcul_x_y_max(main_town_t *town, sfVector2f size_map)
{
    sfVector2f max_value;
    int cine = 0;

    cine = cine_draw(cine);
    max_value.x = town->p.value_middle.x +
        (town->size.size_screen.x / 2 + (size_map.x * 2));
    max_value.y = town->p.value_middle.y + cine +
        (town->size.size_screen.y / 2 + (size_map.y * 2));
    return max_value;
}

void draw_the_map_tile(main_town_t *town, map_t map, int count_x, int count_y)
{
    sfVector2f size_map = (sfVector2f){100 * town->size.size.x,
    100 * town->size.size.y};
    sfVector2f pos = (sfVector2f){0, 0};
    int cine = 0;

    cine = cine_draw(cine);
    pos.x = (count_x * size_map.x) -
        ((town->size.size_screen.x / 2 + size_map.x));
    pos.y = (count_y * size_map.y) - cine -
        ((town->size.size_screen.y / 2 + size_map.y));
    sfSprite_setPosition(spr_tab[SPRITE_MAP], pos);
    sfSprite_setScale(spr_tab[SPRITE_MAP], town->size.size);
    sfSprite_setTexture(spr_tab[SPRITE_MAP], map.texture, sfTrue);
    sfSprite_setTextureRect(spr_tab[SPRITE_MAP], (sfIntRect){0, 0, 100, 100});
    if (count_x >= map.coor_x.x && count_x <= map.coor_x.y + map.coor_x.x
        && count_y >= map.coor_y.x && count_y <= map.coor_y.x + map.coor_y.y)
        sfRenderWindow_drawSprite(town->window.window, spr_tab[SPRITE_MAP],
        NULL);
}

void display_map(map_t map, main_town_t *town)
{
    sfVector2f size_map = (sfVector2f){100 * town->size.size.x,
    100 * town->size.size.y};
    sfVector2f min_value = calcul_x_y_min(town, size_map);
    sfVector2f max_value = calcul_x_y_max(town, size_map);
    int count1 = ((town->size.size_screen.x / 2 + town->p.value_view.x
    * town->size.size.x)) / size_map.x;
    int count2 = ((town->size.size_screen.y / 2 + town->p.value_view.y
    * town->size.size.y)) / size_map.y;

    for (float i = min_value.y, count_y = count2; i < max_value.y;
        i += size_map.y, count_y++) {
        for (float j = min_value.x, count_x = count1; j < max_value.x;
            j += size_map.x, count_x++) {
            draw_the_map_tile(town, map, count_x, count_y);
        }
    }
    if (int_tab[CINE_X] == 0 && int_tab[CINE_Y] == 0)
        sfRenderWindow_drawSprite(town->window.window, town->png.spr, NULL);
}
