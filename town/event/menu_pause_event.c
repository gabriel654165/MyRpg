/*
** EPITECH PROJECT, 2020
** menu_pause
** File description:
** menu_pause
*/

#include "town.h"
#include "main_menu.h"
#include "tab_music.h"

void key_quest_event(sfEvent *event)
{
    if (event->key.code == sfKeyUp)
        int_tab[INCR_QUEST] += 1;
    if (event->key.code == sfKeyDown)
        int_tab[INCR_QUEST] -= 1;
}

void menu_pause_game_event3(sfEvent *event)
{
    if (int_tab[INVENTORY] == 1 && event->key.code == sfKeyRight) {
        int_tab[INVENTORY] = 0;
        save_tab[OPEN_MENU_SAVE] = 1;
        save_tab[START] = 1;
    }
    if (save_tab[OPEN_MENU_SAVE] == 1 && event->key.code == sfKeyLeft) {
        restart_all();
        save_tab[PANEL2] = 0;
        int_tab[INVENTORY] = 1;
    }
}

int menu_pause_game_event2(sfEvent *event)
{
    if (int_tab[INVENTORY] == 1 && event->key.code == sfKeyLeft) {
        int_tab[INVENTORY] = 0;
        int_tab[OPEN_MENU_QUEST] = 1;
        int_tab[INCR_QUEST] = 0;
    }
    if (int_tab[OPEN_MENU_QUEST] == 1 && event->key.code == sfKeyRight) {
        event->type = sfEvtJoystickMoved;
        int_tab[OPEN_MENU_QUEST] = 0;
        int_tab[INVENTORY] = 1;
        return 1;
    }
    if (int_tab[OPEN_MENU_QUEST] == 1)
        key_quest_event(event);
    return 0;
}

int escape_pause_game_menu(void)
{
    if (int_tab[INVENTORY] == 1 || int_tab[OPEN_MENU_QUEST] == 1
        || save_tab[OPEN_MENU_SAVE] == 1) {
        int_tab[INVENTORY] = 0;
        int_tab[OPEN_MENU_QUEST] = 0;
        save_tab[OPEN_MENU_SAVE] = 0;
        int_tab[INCR_QUEST] = 0;
        restart_all();
        save_tab[PANEL2] = 0;
        block_the_player(0);
        return 1;
    }
    return 0;
}

void menu_pause_game_event(sfEvent *event, sfRenderWindow *window,
    allsnd_t *music)
{
    if (event->type == sfEvtKeyPressed) {
        if (event->key.code == sfKeyI) {
            sfSound_play(music->snd[MOPEN]);
            if (escape_pause_game_menu() == 1)
                return;
            if (int_tab[INVENTORY] == 0) {
                int_tab[INVENTORY] = 1;
                block_the_player(1);
            }
        } else if (event->key.code == sfKeyEscape) {
            option_main_menu(window, music);
            return;
        }
        if (menu_pause_game_event2(event) == 1)
            return;
        menu_pause_game_event3(event);
    }
    inventory_event(event);
}
