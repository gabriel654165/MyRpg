/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** option display
*/

#include "../include/main_menu.h"
#include "../include/tab_main_menu.h"
#include "../include/town.h"

void display_snd_but(sfText *text, sfSprite *button, sfRenderWindow *window);
void display_exit_but(sfText *text, sfSprite *button, sfRenderWindow *window);
void display_win_but(sfText *text, sfSprite *button, sfRenderWindow *window);

static void display_option_text(sfText *text, sfRenderWindow *window)
{
    sfText_setScale(text, (sfVector2f) {3, 3});
    sfText_setPosition(text, (sfVector2f) {800, 100});
    sfText_setString(text, "OPTION");
    sfText_setColor(text, (sfColor) {255, 190, 67, 255});
    sfRenderWindow_drawText(window, text, NULL);
    sfText_setScale(text, (sfVector2f) {2, 2});
    sfText_setPosition(text, (sfVector2f) {200, 300});
    sfText_setString(text, "WINDOW SIZE");
    sfRenderWindow_drawText(window, text, NULL);
    sfText_setPosition(text, (sfVector2f) {1300, 300});
    sfText_setString(text, "SOUND");
    sfRenderWindow_drawText(window, text, NULL);
}

void display_rect_opt(sfRectangleShape *shape, sfRenderWindow *window,
int pressed, sfVector2f scale)
{
    sfVector2i poswin = sfMouse_getPositionRenderWindow(window);
    sfVector2f pos = tab_sprt[MBUTTON].pos;
    sfVector2f mpos = {poswin.x / scale.x, poswin.y / scale.y};

    pos.x -= 50;
    for (int i = 0; i != 2; ++i) {
        sfRectangleShape_setScale(shape, (sfVector2f) {1.8, 1.8});
        sfRectangleShape_setPosition(shape,
        (sfVector2f){200+(1100*i), pos.y});
        sfRectangleShape_setFillColor(shape, sfTransparent);
        if (pos.y + 50 < mpos.y && mpos.y < pos.y + 150
            && 200 + (1100*i) < mpos.x && mpos.x < (200 + (1100*i) + 340)) {
            sfRectangleShape_setFillColor(shape,
            (sfColor) {100, 100, 100, 100});
            if (pressed == 1)
                sfRectangleShape_setFillColor(shape,
                (sfColor) {50, 50, 50, 100});
        }
        sfRenderWindow_drawRectangleShape(window, shape, NULL);
    }
}

void display_option(sfmain_menu_t *menu, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, menu->bg[1], NULL);
    display_option_text(menu->text, window);
    display_win_but(menu->text, menu->bg[2], window);
    display_snd_but(menu->text, menu->bg[2], window);
    display_exit_but(menu->text, menu->bg[2], window);
}
