/*
** EPITECH PROJECT, 2020
** quest_menu
** File description:
** quest_menu
*/

#include "town.h"

void draw_the_quest_title2(main_town_t *town, sfVector2f pos, int i)
{
    if (pos.y <= town->p.value_middle.y + 10 * town->size.size.y
        && pos.y >= town->p.value_middle.y - 10 * town->size.size.y) {
        sfSprite_setScale(spr_tab[MENU_QUEST],
        (sfVector2f){1.1 * town->size.size.x, 1.1 * town->size.size.y});
        pos.x -= 25 * town->size.size.x;
    }
    else
        sfSprite_setScale(spr_tab[MENU_QUEST], town->size.size);
    sfSprite_setTexture(spr_tab[MENU_QUEST], text_quest[BANNIERE], sfTrue);
    sfSprite_setPosition(spr_tab[MENU_QUEST], pos);
    sfRenderWindow_drawSprite(town->window.window, spr_tab[MENU_QUEST], NULL);
    sfText_setScale(text_tab[QUEST], town->size.size);
    sfText_setCharacterSize(text_tab[QUEST], 20);
    sfText_setPosition(text_tab[QUEST], (sfVector2f)
    {pos.x + 100 * town->size.size.x, pos.y + 40 * town->size.size.y});
    sfText_setFillColor(text_tab[QUEST], (sfColor){1, 1, 1, 255});
    sfText_setString(text_tab[QUEST], town->parser.quest[i]);
    sfText_setFont(text_tab[QUEST], tab_font[FONT_1]);
    sfRenderWindow_drawText(town->window.window, text_tab[QUEST], NULL);
}

int draw_the_quest_description(main_town_t *town, int i)
{
    sfVector2f pos;
    pos.x = town->p.value_middle.x + 100 * town->size.size.x;
    pos.y = town->p.value_middle.y - 250 * town->size.size.y;
    for (;my_strcmp(town->parser.quest[i], "/end") != 0; i++, pos.y += 50) {
        sfText_setScale(text_tab[QUEST], town->size.size);
        sfText_setCharacterSize(text_tab[QUEST], 20);
        sfText_setPosition(text_tab[QUEST], pos);
        sfText_setFillColor(text_tab[QUEST], (sfColor){1, 1, 1, 255});
        sfText_setString(text_tab[QUEST], town->parser.quest[i]);
        sfText_setFont(text_tab[QUEST], tab_font[FONT_1]);
        sfRenderWindow_drawText(town->window.window, text_tab[QUEST], NULL);
    }
    return i;
}

int draw_the_quest_title(main_town_t *town, int i, int incr)
{
    sfVector2f pos;
    pos.x = town->p.value_middle.x - 600 * town->size.size.x;
    pos.y = town->p.value_middle.y + incr -
        (int_tab[INCR_QUEST] * (120 * town->size.size.y));
    if (pos.y <= town->p.value_middle.y + 2 * (140 * town->size.size.y)
        && pos.y >= town->p.value_middle.y - 2 * (140 * town->size.size.y))
        draw_the_quest_title2(town, pos, i);
    i++;
    if (pos.y <= town->p.value_middle.y + 10 * town->size.size.y
        && pos.y >= town->p.value_middle.y - 10 * town->size.size.y)
        i = draw_the_quest_description(town, i);
    return i;
}

int display_quest(main_town_t *town, int i, int incr)
{
    if (my_strcmp(town->parser.quest[i], "state:1") == 0) {
        i++;
        i = draw_the_quest_title(town, i, incr);
    }
    return i;
}

void display_menu_quest(main_town_t *town)
{
    sfSprite_setTexture(spr_tab[MENU_QUEST], text_quest[QUEST_INV], sfTrue);
    sfSprite_setScale(spr_tab[MENU_QUEST], town->size.size);
    sfVector2f pos;
    pos.x = town->p.value_middle.x -
        town->size.size_screen.x / 2;
    pos.y = town->p.value_middle.y -
        town->size.size_screen.y / 2;
    if (int_tab[OPEN_MENU_QUEST] == 1) {
        sfSprite_setPosition(spr_tab[MENU_QUEST], pos);
        sfRenderWindow_drawSprite(town->window.window,
        spr_tab[MENU_QUEST], NULL);
        for (int i = 0, incr = 0, save = 0;
            town->parser.quest[i] != NULL; i++) {
            save = i;
            if ((i = display_quest(town, i, incr)) != save)
                incr += 120 * town->size.size.y;
        }
    }
}
