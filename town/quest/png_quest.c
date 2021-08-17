/*
** EPITECH PROJECT, 2020
** png_quest
** File description:
** png_quest
*/

#include "town.h"

void display_rect_response(main_town_t *town)
{
    sfVector2f pos;
    pos.x = town->p.value_middle.x - town->size.size_screen.x / 4;
    pos.y = town->p.value_middle.y + town->size.size_screen.y / 2
    - 330 * town->size.size.y;
    sfRectangleShape_setPosition(tab_rect[RECT_DIALOGUE], pos);
    sfRectangleShape_setSize(tab_rect[RECT_DIALOGUE],
    (sfVector2f){350 * town->size.size.x,
    150 * town->size.size.y});
    sfRectangleShape_setOutlineThickness(tab_rect[RECT_DIALOGUE], 15);
    sfRectangleShape_setOutlineColor(tab_rect[RECT_DIALOGUE],
    (sfColor){154, 146, 146, 255});
    sfRectangleShape_setFillColor(tab_rect[RECT_DIALOGUE],
    (sfColor){194, 188, 188, 255});
    sfRenderWindow_drawRectangleShape(town->window.window,
    tab_rect[RECT_DIALOGUE], NULL);
}

int display_dialogue2(quest_t quest, int dialogue, main_town_t *town,
    char **tab)
{
    if (int_tab[OPEN_RESPONSES] == 1) {
        display_rect_response(town);
        write_responses(quest, tab, town, dialogue);
        return (validate_or_not_the_response(quest, town));
    }
    return 0;
}

int display_dialogue(quest_t quest, int dialogue, main_town_t *town, char **tab)
{
    beautiful_display(tab, quest, dialogue, town);
    if (int_tab[NEXT_DIALOGUE] == 1
        && dialogue < quest.last_line - 2) {
        int_tab[NEXT_DIALOGUE] = 0;
        return 1;
    }
    if (int_tab[NEXT_DIALOGUE] == 1
        && dialogue >= quest.last_line - 2
        && int_tab[OPEN_RESPONSES] == 0) {
        possibilities_of_dialogs(quest, tab, dialogue);
        int_tab[NEXT_DIALOGUE] = 0;
        if (int_tab[OPEN_QUEST_DIALOGUE] == 0)
            return 2;
        else
            return 0;
    }
    return display_dialogue2(quest, dialogue, town, tab);
}

void display_rect_dialogue(main_town_t *town)
{
    sfVector2f pos;
    pos.x = town->p.value_middle.x - town->size.size_screen.x / 4;
    pos.y = town->p.value_middle.y + town->size.size_screen.y / 2
    - 165 * town->size.size.y;
    sfRectangleShape_setPosition(tab_rect[RECT_DIALOGUE], pos);
    sfRectangleShape_setSize(tab_rect[RECT_DIALOGUE],
    (sfVector2f){town->size.size_screen.x / 4 * 2,
    150 * town->size.size.y});
    sfRectangleShape_setOutlineThickness(tab_rect[RECT_DIALOGUE], 15);
    sfRectangleShape_setOutlineColor(tab_rect[RECT_DIALOGUE],
    (sfColor){154, 146, 146, 255});
    sfRectangleShape_setFillColor(tab_rect[RECT_DIALOGUE],
    (sfColor){194, 188, 188, 255});
    sfRenderWindow_drawRectangleShape(town->window.window,
    tab_rect[RECT_DIALOGUE], NULL);
}

void png_quest(quest_t quest, char **tab, main_town_t *town)
{
    static int count = 0;
    int one;
    draw_png_for_the_quest(town, quest);
    if (did_png_is_in_range_for_quest(town, quest) == 1) {
        if (int_tab[OPEN_QUEST_DIALOGUE] == 1) {
            display_rect_dialogue(town);
            one = display_dialogue(quest, count, town, tab);
            count += one;
            if (one == 2)
                count = 0;
        }
        if (int_tab[OPEN_QUEST_DIALOGUE] == 0)
            count = 0;
    }
}
