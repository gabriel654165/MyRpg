/*
** EPITECH PROJECT, 2020
** dialog_process
** File description:
** dialog_process
*/

#include "town.h"

void write_responses2(quest_t quest, char **tab, main_town_t *town,
    int dialogue)
{
    sfText *text = text_tab[DIALOGUE];
    sfVector2f pos;
    sfText_setString(text, tab[quest.first_line + dialogue + 3]);
    sfRenderWindow_drawText(town->window.window, text, NULL);
    if (int_tab[VALID_RESPONSE] == 1)
        sfText_setCharacterSize(text, 30);
    else
        sfText_setCharacterSize(text, 20);
    pos.x = town->p.value_middle.x -
        town->size.size_screen.x / 4 + 10 * town->size.size.x;
    pos.y = town->p.value_middle.y + town->size.size_screen.y / 2
        - 250 * town->size.size.y;
    sfText_setPosition(text, pos);
    sfText_setString(text, tab[quest.first_line + dialogue + 4]);
    sfRenderWindow_drawText(town->window.window, text, NULL);
}

void write_responses(quest_t quest, char **tab, main_town_t *town, int dialogue)
{
    sfText *text = text_tab[DIALOGUE];
    sfVector2f pos;
    pos.x = town->p.value_middle.x -
        town->size.size_screen.x / 4 + 10 * town->size.size.x;
    pos.y = town->p.value_middle.y + town->size.size_screen.y / 2
        - 300 * town->size.size.y;
    sfText_setPosition(text, pos);
    sfText_setFillColor(text, (sfColor){1, 1, 1, 255});
    sfText_setScale(text, town->size.size);
    sfText_setFont(text, tab_font[FONT_1]);
    if (int_tab[VALID_RESPONSE] == 0)
        sfText_setCharacterSize(text, 30);
    else
        sfText_setCharacterSize(text, 20);
    write_responses2(quest, tab, town, dialogue);
}

void positive_response(quest_t quest, main_town_t *town)
{
    if (quest.dialogue_nb != 0)
        stat_tab[XP_LVL] += 1;
    quest_monitor(quest, town);
    block_the_player(0);
    int_tab[CAN_TALK] = 0;
    int_tab[OPEN_QUEST_DIALOGUE] = 0;
    int_tab[SAY_YES_NO] = 0;
    int_tab[VALID_RESPONSE] = 0;
    int_tab[NEXT_DIALOGUE] = 0;
    int_tab[OPEN_RESPONSES] = 0;
}

int validate_or_not_the_response(quest_t quest, main_town_t *town)
{
    if (int_tab[SAY_YES_NO] == 1) {
        if (int_tab[VALID_RESPONSE] == 0) {
            positive_response(quest, town);
            int_tab[SAY_YES_NO] = 0;
            int_tab[VALID_RESPONSE] = 0;
            int_tab[OPEN_RESPONSES] = 0;
            return 3;
        }
        if (int_tab[VALID_RESPONSE] == 1) {
            int_tab[SAY_YES_NO] = 0;
            int_tab[VALID_RESPONSE] = 0;
            int_tab[OPEN_RESPONSES] = 0;
            return 3;
        }
        int_tab[SAY_YES_NO] = 0;
    }
    return 0;
}

void possibilities_of_dialogs(quest_t quest, char **tab, int dialogue)
{
    if (my_strcmp(tab[quest.first_line + dialogue + 2], "/responses:") == 0) {
        int_tab[OPEN_RESPONSES] = 1;
    }
    if (my_strcmp(tab[quest.first_line + dialogue + 2], "/end") == 0) {
        int_tab[OPEN_QUEST_DIALOGUE] = 0;
        block_the_player(0);
    }
}
