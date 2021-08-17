/*
** EPITECH PROJECT, 2020
** save_interface.c
** File description:
** yes
*/

#include "town.h"
#include "tab_music.h"

int pause_interface(int panel_two)
{
    if (save_tab[PANEL2] == 0)
        panel_two = 0;
    else
        panel_two = 1;

    if (save_tab[SAVE_SLOT_ONE] == 1 || save_tab[SAVE_SLOT_TWO] == 1
    || save_tab[SAVE_SLOT_THREE] == 1 || save_tab[LOAD_SLOT_ONE] == 1
    || save_tab[LOAD_SLOT_TWO] == 1 || save_tab[LOAD_SLOT_THREE] == 1
    || save_tab[BACK_LOAD] == 1 || save_tab[BACK_SAVE] == 1)
        panel_two = 1;
    return panel_two;
}

void select_interface(sfEvent *event, int panel_two)
{
    if (event->type == sfEvtKeyPressed) {
        choose_panel_one_down(event, panel_two);
        choose_panel_one_up(event, panel_two);
        choose_slot_save_down(event);
        choose_slot_save_up(event);
        choose_slot_load_down(event);
        choose_slot_load_up(event);
    }
}

int push_entry(sfEvent *event, int panel_two, main_town_t *town)
{
    if (event->type == sfEvtKeyPressed) {
        if (event->key.code == sfKeyReturn && save_tab[EXIT] == 1) {
            sfRenderWindow_close(town->window.window);
            sfMusic_stop(town->music.zik[MMENU]);
        }
        if (event->key.code == sfKeyReturn
        && (save_tab[SAVE] == 1 || save_tab[START]))
            save_tab[SAVE_SLOT_ONE] = 1;
        if (event->key.code == sfKeyReturn && save_tab[LOAD] == 1)
            save_tab[LOAD_SLOT_ONE] = 1;
    }
    if (event->type == sfEvtKeyPressed)
        if (event->key.code == sfKeyReturn
            && (save_tab[BACK_SAVE] == 1 || save_tab[BACK_LOAD] == 1))
            panel_two = move_back();
    return panel_two;
}

void save_interface(main_town_t *town, sfEvent *event)
{
    static int panel_two = 0;

    save_event(town, event);
    load_event(town, event);
    panel_two = pause_interface(panel_two);
    select_interface(event, panel_two);
    panel_two = push_entry(event, panel_two, town);
}
