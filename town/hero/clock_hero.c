/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** clock mvmt hero
*/

#include "town.h"
#include "tab_music.h"

static void attack_hero(png_t *png, sfIntRect *rect, sfTime time,
    allsnd_t *music)
{
    if (sfTime_asMilliseconds(time) >= 200) {
        sfClock_restart(png->clock);
        rect->left += png->rect_atk.width;
        if (rect->left > png->rect_atk.width * 5) {
            sfSound_play(music->snd[MSWORD]);
            png->attack = false;
            *rect = png->rect_mvmt;
        }
    }
}

static void sound_hero_walk(allsnd_t *music, bool run)
{
    static int count = 5;
    static int wind_c = 30;

    if (count == 0) {
        sfSound_play(music->snd[MFOOTSTP]);
        if (run == true)
            count = 3;
        else
            count = 5;
    } else
        --count;
    if (wind_c == 0) {
        sfSound_play(music->snd[MWIND]);
        wind_c = (rand() % 300) + 30;
    } else
        --wind_c;
}

void clock_hero(png_t *png, allsnd_t *music)
{
    sfTime time = sfClock_getElapsedTime(png->clock);
    sfIntRect rect = sfSprite_getTextureRect(png->spr);

    if (png->move == true && sfTime_asMilliseconds(time) >= 200) {
        sound_hero_walk(music, png->run);
        sfClock_restart(png->clock);
        rect.left += rect.width + 2;
        if (png->run == true && rect.left > 381)
            rect.left = 252;
        else if (png->run == 0 && rect.left > 168)
            rect.left = 39;
    } else if (png->move == false && png->attack == false && png->run == 0)
        rect.left = 8;
    if (png->attack == true)
        attack_hero(png, &rect, time, music);
    sfSprite_setTextureRect(png->spr, rect);
}
