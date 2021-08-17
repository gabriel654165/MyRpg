/*
** EPITECH PROJECT, 2020
** load_from_menu.c
** File description:
** yes
*/

#include "town.h"

int select_load_from_menu(char **path, sfEvent *event)
{
    if (event->type == sfEvtKeyPressed) {
        if (event->key.code == sfKeyReturn && save_tab[LOAD_MENU1] == 1) {
            *path = "town/parser/SAVE1/";
            return 1;
        }
        if (event->key.code == sfKeyReturn && save_tab[LOAD_MENU2] == 1) {
            *path = "town/parser/SAVE2/";
            return 1;
        }
        if (event->key.code == sfKeyReturn && save_tab[LOAD_MENU3] == 1) {
            *path = "town/parser/SAVE3/";
            return 1;
        }
        down_chose(event);
        up_chose(event);
        return 0;
    }
    return 0;
}

char *load_game_from_start_screen(main_town_t *town, sfEvent *event)
{
    char *path;

    save_tab[OPEN_MENU_SAVE] = 1;
    save_tab[LOAD_MENU1] = 1;
    while (1) {
        get_the_scale(sfRenderWindow_getSize(town->window.window), town);
        while (sfRenderWindow_pollEvent(town->window.window, event)) {
            if (select_load_from_menu(&path, event) == 1) {
                sfRenderWindow_clear(town->window.window, sfBlack);
                save_tab[LOAD_MENU1] = 0;
                save_tab[LOAD_MENU2] = 0;
                save_tab[LOAD_MENU3] = 0;
                save_tab[OPEN_MENU_SAVE] = 0;
                return path;
            }
        }
        draw_sprites(town);
        sfRenderWindow_display(town->window.window);
    }
    return ("town/parser/SAVE_DEFAULT/");
}
