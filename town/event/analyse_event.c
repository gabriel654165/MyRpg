/*
** EPITECH PROJECT, 2020
** analyse_event
** File description:
** analyse_event
*/

#include "town.h"
#include "tab_music.h"

void key_button_quest(sfEvent *event)
{
    if (event->type == sfEvtKeyPressed) {
        if (event->key.code == sfKeyE)
            int_tab[OPEN_QUEST_DIALOGUE] = 1;
        if (event->key.code == sfKeyReturn
            && int_tab[OPEN_QUEST_DIALOGUE] == 1)
            int_tab[NEXT_DIALOGUE] = 1;
        if (int_tab[OPEN_QUEST_DIALOGUE] == 1
            && int_tab[OPEN_RESPONSES] == 1) {
            if (event->key.code == sfKeyUp)
                int_tab[VALID_RESPONSE] = 0;
            if (event->key.code == sfKeyDown)
                int_tab[VALID_RESPONSE] = 1;
            if (event->key.code == sfKeyReturn)
                int_tab[SAY_YES_NO] = 1;
        }
    }
}

void inventory_event(sfEvent *event)
{
    if (int_tab[INVENTORY] == 1) {
        if (event->type == sfEvtMouseButtonPressed)
            int_tab[DROP] = 1;
        if (event->type == sfEvtMouseButtonReleased)
            int_tab[DROP] = 0;
    }
}

void chest_event_key(sfEvent *event)
{
    if (int_tab[NEXTO_CHEST] == 1)
        if (event->type == sfEvtKeyPressed)
            if (event->key.code == sfKeyReturn)
                int_tab[OPEN_CHEST] = 1;
}

void gate_open_event(sfEvent *event)
{
    if (int_tab[GATE_CAN_BE_OPEN] == 1) {
        if (event->type == sfEvtKeyPressed)
            if (event->key.code == sfKeyReturn)
                int_tab[OPEN_DOOR] = 1;
    }
}

void analyse_event(sfEvent *event, main_town_t *town)
{
    if (event->type == sfEvtClosed) {
        sfRenderWindow_close(town->window.window);
        sfMusic_stop(town->music.zik[MMENU]);
    }
    if (event->type == sfEvtKeyPressed)
        move_hero(&town->png, event);
    if (event->type == sfEvtKeyReleased)
        stop_hero(&town->png, event);
    if (int_tab[CAN_TALK] == 1)
        key_button_quest(event);
    chest_event_key(event);
    view_event(town, event);
    save_interface(town, event);
    game_over_event(town, event);
    gate_open_event(event);
    menu_pause_game_event(event, town->window.window, &town->music);
}
