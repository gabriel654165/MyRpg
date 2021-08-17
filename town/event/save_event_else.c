/*
** EPITECH PROJECT, 2020
** save_event_else
** File description:
** yes
*/

#include "town.h"

void choose_slot_save_down(sfEvent *event)
{
    if (event->key.code == sfKeyDown &&
        (save_tab[START] == 1 || save_tab[SAVE] == 1)) {
        if (save_tab[OPEN_MENU_SAVE] == 1 && save_tab[SAVE_SLOT_ONE] == 1) {
            save_tab[SAVE_SLOT_TWO] = 1;
            save_tab[SAVE_SLOT_ONE] = 0;
        } else if (save_tab[OPEN_MENU_SAVE] == 1 &&
            save_tab[SAVE_SLOT_TWO] == 1) {
            save_tab[SAVE_SLOT_TWO] = 0;
            save_tab[SAVE_SLOT_THREE] = 1;
        } else if (save_tab[OPEN_MENU_SAVE] == 1 &&
            save_tab[SAVE_SLOT_THREE] == 1) {
            save_tab[SAVE_SLOT_THREE] = 0;
            save_tab[BACK_SAVE] = 1;
        } else if (save_tab[OPEN_MENU_SAVE] == 1 && save_tab[BACK_SAVE] == 1) {
            save_tab[BACK_SAVE] = 0;
            save_tab[SAVE_SLOT_ONE] = 1;
        }
    }
}

void choose_slot_save_up(sfEvent *event)
{
    if (event->key.code == sfKeyUp &&
        (save_tab[START] == 1 || save_tab[SAVE] == 1)) {
        if (save_tab[OPEN_MENU_SAVE] == 1 && save_tab[SAVE_SLOT_ONE] == 1) {
            save_tab[SAVE_SLOT_ONE] = 0;
            save_tab[BACK_SAVE] = 1;
        } else if (save_tab[OPEN_MENU_SAVE] == 1 && save_tab[BACK_SAVE] == 1) {
            save_tab[BACK_SAVE] = 0;
            save_tab[SAVE_SLOT_THREE] = 1;
        } else if (save_tab[OPEN_MENU_SAVE] == 1 &&
            save_tab[SAVE_SLOT_THREE] == 1) {
            save_tab[SAVE_SLOT_THREE] = 0;
            save_tab[SAVE_SLOT_TWO] = 1;
        } else if (save_tab[OPEN_MENU_SAVE] == 1 &&
            save_tab[SAVE_SLOT_TWO] == 1) {
            save_tab[SAVE_SLOT_TWO] = 0;
            save_tab[SAVE_SLOT_ONE] = 1;
        }
    }
}

void choose_slot_load_down(sfEvent *event)
{
    if (event->key.code == sfKeyDown && save_tab[LOAD] == 1) {
        if (save_tab[OPEN_MENU_SAVE] == 1 && save_tab[LOAD_SLOT_ONE] == 1) {
            save_tab[LOAD_SLOT_ONE] = 0;
            save_tab[LOAD_SLOT_TWO] = 1;
        } else if (save_tab[OPEN_MENU_SAVE] == 1 &&
            save_tab[LOAD_SLOT_TWO] == 1) {
            save_tab[LOAD_SLOT_TWO] = 0;
            save_tab[LOAD_SLOT_THREE] = 1;
        } else if (save_tab[OPEN_MENU_SAVE] == 1 &&
            save_tab[LOAD_SLOT_THREE] == 1) {
            save_tab[LOAD_SLOT_THREE] = 0;
            save_tab[BACK_LOAD] = 1;
        } else if (save_tab[OPEN_MENU_SAVE] == 1 && save_tab[BACK_LOAD] == 1) {
            save_tab[BACK_LOAD] = 0;
            save_tab[LOAD_SLOT_ONE] = 1;
        }
    }
}

void choose_slot_load_up(sfEvent *event)
{
    if (event->key.code == sfKeyUp && save_tab[LOAD] == 1) {
        if (save_tab[OPEN_MENU_SAVE] == 1 && save_tab[LOAD_SLOT_ONE] == 1) {
            save_tab[LOAD_SLOT_ONE] = 0;
            save_tab[BACK_LOAD] = 1;
        } else if (save_tab[OPEN_MENU_SAVE] == 1 && save_tab[BACK_LOAD] == 1) {
            save_tab[BACK_LOAD] = 0;
            save_tab[LOAD_SLOT_THREE] = 1;
        } else if (save_tab[OPEN_MENU_SAVE] == 1 &&
            save_tab[LOAD_SLOT_THREE] == 1) {
            save_tab[LOAD_SLOT_THREE] = 0;
            save_tab[LOAD_SLOT_TWO] = 1;
        } else if (save_tab[OPEN_MENU_SAVE] == 1 &&
            save_tab[LOAD_SLOT_TWO] == 1) {
            save_tab[LOAD_SLOT_TWO] = 0;
            save_tab[LOAD_SLOT_ONE] = 1;
        }
    }
}
