/*
** EPITECH PROJECT, 2020
** png_range_fot_quest
** File description:
** png_range_for_quest
*/

#include "town.h"

sfVector2f get_the_range(sfVector2f coor, main_town_t *town, sfSprite *spr)
{
    sfVector2f range;
    range.x = coor.x * town->size.size.x +
        (sfSprite_getLocalBounds(spr).width * town->size.size.x / 2);
    range.y = coor.y * town->size.size.y +
        (sfSprite_getLocalBounds(spr).height * town->size.size.y / 2);
    return range;
}

void display_poss_of_talk(main_town_t *town, quest_t quest)
{
    sfVector2f pos;
    pos.x = quest.coor.x * town->size.size.x;
    pos.y = quest.coor.y * town->size.size.y - 20 * town->size.size.y;
    sfText_setFillColor(text_tab[TALK_POSS], sfBlack);
    sfText_setPosition(text_tab[TALK_POSS], pos);
    sfText_setScale(text_tab[TALK_POSS], town->size.size);
    sfText_setString(text_tab[TALK_POSS], "Parler [E]");
    sfText_setCharacterSize(text_tab[TALK_POSS], 35);
    sfText_setFont(text_tab[TALK_POSS], tab_font[FONT_1]);
    sfRenderWindow_drawText(town->window.window, text_tab[TALK_POSS], NULL);
}

int did_png_is_in_range_for_quest(main_town_t *town, quest_t quest)
{
    sfVector2f pos2 = get_the_range(quest.coor, town, spr_tab[PNG_QUEST]);
    float range_x = 100 * town->size.size.x;
    float range_y = 100 * town->size.size.y;
    if (town->p.value_middle.x >= quest.coor.x * town->size.size.x - range_x
        && town->p.value_middle.x <= pos2.x + range_x)
        if (town->p.value_middle.y >= quest.coor.y * town->size.size.y - range_y
            && town->p.value_middle.y <= pos2.y + range_y) {
            display_poss_of_talk(town, quest);
            int_tab[CAN_TALK] = 1;
            return 1;
        }
    return 0;
}

int dialogue_begin(int i, int dialogue)
{
    static int dia = 0;
    if (dia != dialogue) {
        dia = dialogue;
        return 1;
    }
    dia = dialogue;
    return i;
}

void block_the_player(int lock)
{
    if (lock == 1)
        for (int i = 0; i < COLLISION; i++)
            collision_tab[i] = 1;
    else if (lock == 0)
        for (int i = 0; i < COLLISION; i++)
            collision_tab[i] = 0;
}
