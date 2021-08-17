/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** display all buttons
*/

#include "../include/main_menu.h"
#include "../include/tab_main_menu.h"
#include "../include/town.h"

void display_exit_but(sfText *text, sfSprite *button, sfRenderWindow *window)
{
    sfVector2f pos = tab_sprt[MBUTTON].pos;
    char *strings[2] = {"Resume", "Exit"};

    sfSprite_setScale(button, (sfVector2f) {1.8, 1.8});
    sfText_setScale(text, (sfVector2f) {1.8, 1.8});
    sfText_setColor(text, (sfColor) {0, 0, 0, 255});
    for (int i = 0; i != 2; ++i) {
        sfText_setString(text, strings[i]);
        sfSprite_setPosition(button, (sfVector2f){200 + (1100 * i), pos.y});
        sfText_setPosition(text, (sfVector2f){220 + (1100 * i), pos.y + 10});
        sfRenderWindow_drawSprite(window, button, NULL);
        sfRenderWindow_drawText(window, text, NULL);
    }
}

void display_win_but(sfText *text, sfSprite *button, sfRenderWindow *window)
{
    char *strings[3] = {"1920x1080", "1280x1024", "800x600"};

    sfSprite_setScale(button, (sfVector2f) {2, 1.5});
    sfText_setScale(text, (sfVector2f) {1.8, 1.8});
    sfText_setColor(text, (sfColor) {0, 0, 0, 255});
    for (int i = 0; i != 3; ++i) {
        sfText_setString(text, strings[i]);
        sfSprite_setPosition(button, (sfVector2f){200, 400 + (100 * i)});
        sfText_setPosition(text, (sfVector2f){225, 400 + (100 * i)});
        sfRenderWindow_drawSprite(window, button, NULL);
        sfRenderWindow_drawText(window, text, NULL);
    }
}

void display_snd_but(sfText *text, sfSprite *button, sfRenderWindow *window)
{
    char *strings[4] = {"Mute", "Low", "Medium", "High"};

    sfSprite_setScale(button, (sfVector2f) {2, 1.5});
    sfText_setScale(text, (sfVector2f) {1.8, 1.8});
    sfText_setColor(text, (sfColor) {0, 0, 0, 255});
    for (int i = 0; i != 4; ++i) {
        sfText_setString(text, strings[i]);
        sfSprite_setPosition(button, (sfVector2f){1250, 400 + (100 * i)});
        sfText_setPosition(text, (sfVector2f){1270, 400 + (100 * i)});
        sfRenderWindow_drawSprite(window, button, NULL);
        sfRenderWindow_drawText(window, text, NULL);
    }
}
