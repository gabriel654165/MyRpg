/*
** EPITECH PROJECT, 2020
** main
** File description:
** yes
*/

#include "game.h"
#include "town.h"
#include "tab_music.h"

int start_load_game(main_town_t *town, char **path, sfEvent *event)
{
    int load = 0;

    sfMusic_play(town->music.zik[MMENU]);
    load = main_menu(town->window.window, &town->music);
    sfMusic_stop(town->music.zik[MMENU]);
    if (load == -1 || load == 2) {
        free_sound(&town->music);
        return (-1);
    } else if (load == 3)
        *path = load_game_from_start_screen(town, event);
    return (0);
}
