/*
** EPITECH PROJECT, 2020
** my_RPG
** File description:
** main menu
*/

#include "../include/main_menu.h"
#include "../include/tab_main_menu.h"
#include "tab_music.h"
#include "town.h"
#include <stdio.h>

static int manage_mouse_event(sfRenderWindow *window, sfVector2f scale)
{
    sfVector2i posm = sfMouse_getPositionRenderWindow(window);
    sfVector2f pos = tab_sprt[MBUTTON].pos;
    sfVector2f mpos = {posm.x / scale.x, posm.y / scale.y};

    if (pos.y < mpos.y && mpos.y < pos.y + 90) {
        if (pos.x + (500 * 3) < mpos.x && mpos.x < pos.x + (500 * 3) + 190) {
            sfRenderWindow_close(window);
            return (-1);
        }
        if (pos.x < mpos.x && mpos.x < (pos.x + 190))
            return (1);
        if (pos.x + (500 * 2) < mpos.x && mpos.x < (pos.x + (500 * 3) + 190))
            return (2);
        if (pos.x + (500 * 1) < mpos.x && mpos.x < pos.x + (500 * 1) + 190)
            return (3);
    }
    return (0);
}

static int event_main_menu(sfRenderWindow *window, sfmain_menu_t *menu)
{
    static int pressed = 0;
    sfEvent event;
    sfVector2u win = sfRenderWindow_getSize(window);
    sfVector2f scale = {(float) win.x / 1920, (float) win.y / 1080};

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            return (-1);
        }
        if (event.type == sfEvtMouseButtonReleased) {
            pressed = 0;
            return (manage_mouse_event(window, scale));
        } else if (event.type == sfEvtMouseButtonPressed)
            pressed = 1;
    }
    display_rectangle(menu->rectangle, window, pressed, scale);
    return (0);
}

int main_menu(sfRenderWindow *window, allsnd_t *music)
{
    int event = 0;
    sfmain_menu_t menu = create_main_menu();

    sfRenderWindow_setView(window, sfRenderWindow_getDefaultView(window));
    while (sfRenderWindow_isOpen(window)) {
        display_sprite(&menu, window);
        event = event_main_menu(window, &menu);
        if (event == -1 || event == 1 || event == 3)
            break;
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        if (event == 2)
            option_main_menu(window, music);
    }
    free_main_menu(menu);
    return (event);
}
