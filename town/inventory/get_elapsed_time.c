/*
** EPITECH PROJECT, 2020
** clock_time
** File description:
** clock_time
*/

#include "town.h"

float get_elapsed_time(sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = sfTime_asSeconds(time);
    return seconds;
}

void draw_png_for_the_quest(main_town_t *town, quest_t quest)
{
    sfVector2f pos;
    pos.x = quest.coor.x * town->size.size.x;
    pos.y = quest.coor.y * town->size.size.y;
    sfSprite_setPosition(spr_tab[PNG_QUEST], pos);
    sfSprite_setTexture(spr_tab[PNG_QUEST], quest.texture, sfTrue);
    sfSprite_setScale(spr_tab[PNG_QUEST], (sfVector2f){town->size.size.x * 2,
    town->size.size.y * 2});
    sfRenderWindow_drawSprite(town->window.window, spr_tab[PNG_QUEST], NULL);
}

void norme_for_dialogue2(main_town_t *town, char *str)
{
    sfRenderWindow_drawText(town->window.window,
    draw_lock_0(str, town, 1), NULL);
}

void norme_for_dialogue(main_town_t *town, char **tab,
    int dialogue, char *str)
{
    sfRenderWindow_drawText(town->window.window,
    draw_lock_1(tab, town, dialogue), NULL);
    sfRenderWindow_drawText(town->window.window,
    draw_lock_0(str, town, 2), NULL);
}

int norme_on_quest_monitor(main_town_t *town, quest_t quest)
{
    int i = 0;
    for (i = 0; my_strcmp(town->parser.quest[i],
    my_itoa(quest.nbr_quest)) != 0; i++);
    return i;
}
