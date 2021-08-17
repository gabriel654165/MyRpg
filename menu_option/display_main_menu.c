/*
** EPITECH PROJECT, 2020
** my_RPG
** File description:
** display buttons, text, rectangle...
*/

#include "../include/main_menu.h"
#include "../include/tab_main_menu.h"
#include "../include/town.h"

static void display_button(sfText *text,
sfSprite *button, sfRenderWindow *window)
{
    sfVector2f pos = tab_sprt[MBUTTON].pos;
    char *strings[4] = {"Start game", "Load game", "Option", "Exit"};

    sfText_setScale(text, (sfVector2f) {0.8, 0.8});
    sfText_setColor(text, (sfColor) {0, 0, 0, 255});
    for (int i = 0; i != 4; ++i) {
        sfText_setString(text, strings[i]);
        sfSprite_setPosition(button, (sfVector2f){pos.x + (500 * i), pos.y});
        sfText_setPosition(text, (sfVector2f){pos.x + (525 * i), pos.y + 10});
        sfRenderWindow_drawSprite(window, button, NULL);
        sfRenderWindow_drawText(window, text, NULL);
    }
}

static void display_namegame(sfText *text, sfRenderWindow *window)
{
    sfText_setScale(text, (sfVector2f) {2, 2});
    sfText_setPosition(text, (sfVector2f) {500, 100});
    sfText_setString(text, "Fallen Kigndom's Ledgends");
    sfText_setColor(text, (sfColor) {255, 190, 67, 255});
    sfRenderWindow_drawText(window, text, NULL);
}

void display_rectangle(sfRectangleShape *shape, sfRenderWindow *window,
int pressed, sfVector2f scale)
{
    sfVector2i poswin = sfMouse_getPositionRenderWindow(window);
    sfVector2f pos = tab_sprt[MBUTTON].pos;
    sfVector2f mpos = {poswin.x / scale.x, poswin.y / scale.y};

    for (int i = 0; i != 4; ++i) {
        sfRectangleShape_setPosition(shape,
        (sfVector2f){pos.x + (500 * i), pos.y});
        sfRectangleShape_setOutlineThickness(shape, 1.0);
        sfRectangleShape_setOutlineColor(shape, sfTransparent);
        sfRectangleShape_setFillColor(shape, sfTransparent);
        if (pos.y < mpos.y && mpos.y < pos.y + 90 &&
            pos.x + (500 * i) < mpos.x && mpos.x < (pos.x + (500 * i) + 190)) {
            sfRectangleShape_setFillColor(shape,
            (sfColor) {100, 100, 100, 100});
            if (pressed == 1)
                sfRectangleShape_setFillColor(shape,
            (sfColor) {50, 50, 50, 100});
        }
        sfRenderWindow_drawRectangleShape(window, shape, NULL);
    }
}

void display_sprite(sfmain_menu_t *menu, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, menu->bg[0], NULL);
    display_namegame(menu->text, window);
    display_button(menu->text, menu->bg[MBUTTON], window);
}
