/*
** EPITECH PROJECT, 2020
** save_event_bis
** File description:
** yes
*/

#include "town.h"

void restart_all(void)
{
    save_tab[OPEN_MENU_SAVE] = 0;
    save_tab[START] = 1;
    save_tab[LOAD] = 0;
    save_tab[SAVE] = 0;
    save_tab[EXIT] = 0;
    save_tab[SAVE_SLOT_ONE] = 0;
    save_tab[SAVE_SLOT_TWO] = 0;
    save_tab[SAVE_SLOT_THREE] = 0;
    save_tab[LOAD_SLOT_ONE] = 0;
    save_tab[LOAD_SLOT_TWO] = 0;
    save_tab[LOAD_SLOT_THREE] = 0;
    save_tab[BACK_LOAD] = 0;
    save_tab[BACK_SAVE] = 0;
}

void choose_panel_one_down(sfEvent *event, int panel)
{
    if (event->key.code == sfKeyDown && panel == 0) {
        if (save_tab[OPEN_MENU_SAVE] == 1
        && (save_tab[START] == 1 || save_tab[SAVE] == 1)) {
            save_tab[LOAD] = 1;
            save_tab[START] = 0;
            save_tab[SAVE] = 0;
        } else if (save_tab[OPEN_MENU_SAVE] == 1 && save_tab[LOAD] == 1) {
            save_tab[EXIT] = 1;
            save_tab[LOAD] = 0;
        } else if (save_tab[OPEN_MENU_SAVE] == 1 && save_tab[EXIT] == 1) {
            save_tab[SAVE] = 1;
            save_tab[EXIT] = 0;
        }
    }
}

void choose_panel_one_up(sfEvent *event, int panel)
{
    if (event->key.code == sfKeyUp && panel == 0) {
        if (save_tab[OPEN_MENU_SAVE] == 1
        && (save_tab[START] == 1 || save_tab[SAVE] == 1)) {
            save_tab[EXIT] = 1;
            save_tab[START] = 0;
            save_tab[SAVE] = 0;
        } else if (save_tab[OPEN_MENU_SAVE] == 1 && save_tab[EXIT] == 1) {
            save_tab[EXIT] = 0;
            save_tab[LOAD] = 1;
        } else if (save_tab[OPEN_MENU_SAVE] == 1 && save_tab[LOAD] == 1) {
            save_tab[LOAD] = 0;
            save_tab[SAVE] = 1;
        }
    }
}

int move_back(void)
{
    save_tab[OPEN_MENU_SAVE] = 1;
    save_tab[START] = 0;
    save_tab[LOAD] = 0;
    save_tab[SAVE] = 1;
    save_tab[EXIT] = 0;
    save_tab[SAVE_SLOT_ONE] = 0;
    save_tab[SAVE_SLOT_TWO] = 0;
    save_tab[SAVE_SLOT_THREE] = 0;
    save_tab[LOAD_SLOT_ONE] = 0;
    save_tab[LOAD_SLOT_TWO] = 0;
    save_tab[LOAD_SLOT_THREE] = 0;
    save_tab[BACK_LOAD] = 0;
    save_tab[BACK_SAVE] = 0;
    return 0;
}
