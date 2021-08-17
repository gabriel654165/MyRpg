/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** option game
*/

#include "../include/main_menu.h"
#include "../include/tab_main_menu.h"
#include "../include/town.h"
#include <stdio.h>

void display_option(sfmain_menu_t *menu, sfRenderWindow *window);
void display_rect_opt(sfRectangleShape *shape, sfRenderWindow *window,
int pressed, sfVector2f scale);

static void change_size_win(sfVector2f mpos, sfRenderWindow *window)
{
    if (415 < mpos.y && mpos.y < 490)
        sfRenderWindow_setSize(window, (sfVector2u) {1920, 1080});
    if (500 < mpos.y && mpos.y < 575)
        sfRenderWindow_setSize(window, (sfVector2u) {1280, 1024});
    if (600 < mpos.y && mpos.y < 675)
        sfRenderWindow_setSize(window, (sfVector2u) {800, 600});
}

static void change_music_volume(sfVector2f mpos, allsnd_t *music)
{
    if (428 < mpos.y && mpos.y < 500)
        music->volume = 0;
    if (533 < mpos.y && mpos.y < 608)
        music->volume = 33;
    if (639 < mpos.y && mpos.y < 713)
        music->volume = 66;
    if (746 < mpos.y && mpos.y < 820)
        music->volume = 100;
    change_volume_zik(music);
}

static int mouse_event(sfEvent event, int *pressed,
sfRenderWindow *window, allsnd_t *music)
{
    sfVector2u win = sfRenderWindow_getSize(window);
    sfVector2f scale = {(float) win.x / 1920, (float) win.y / 1080};
    sfVector2i poswin = sfMouse_getPositionRenderWindow(window);
    sfVector2f mpos = {poswin.x / scale.x, poswin.y / scale.y};

    if (event.type == sfEvtMouseButtonReleased) {
        *pressed = 0;
        if (934 < mpos.y && mpos.y < 1030) {
            if (1233 < mpos.x && mpos.x < 1570)
                sfRenderWindow_close(window);
            if (27 < mpos.x && mpos.x < 377)
                return (1);
        }
        if (200 < mpos.x && mpos.x < 580)
            change_size_win(mpos, window);
        if (1253 < mpos.x && mpos.x < 1630)
            change_music_volume(mpos, music);
    }
    return (0);
}

static int event_main_menu(sfRenderWindow *window,
sfmain_menu_t *menu, allsnd_t *music)
{
    int ret_event = 0;
    static int pressed = 0;
    sfEvent event;
    sfVector2u win = sfRenderWindow_getSize(window);
    sfVector2f scale = {(float) win.x / 1920, (float) win.y / 1080};

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonPressed)
            pressed = 1;
        ret_event = mouse_event(event, &pressed, window, music);
        if (ret_event == 1)
            return (ret_event);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            return (1);
    }
    display_rect_opt(menu->rectangle, window, pressed, scale);
    return (0);
}

void option_main_menu(sfRenderWindow *window, allsnd_t *music)
{
    int event = 0;
    sfmain_menu_t menu = create_main_menu();

    sfRenderWindow_setView(window, sfRenderWindow_getDefaultView(window));
    while (sfRenderWindow_isOpen(window)) {
        display_option(&menu, window);
        event = event_main_menu(window, &menu, music);
        if (event == 1)
            break;
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
    }
    free_main_menu(menu);
}
