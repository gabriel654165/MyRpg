/*
** EPITECH PROJECT, 2020
** game_over
** File description:
** yes
*/

#include "town.h"
#include "tab_music.h"

void quit_and_off_music(main_town_t *town, sfEvent *event)
{
    if (event->key.code == sfKeyReturn && stat_tab[GAME_OVER_QUIT] == 1) {
        sfRenderWindow_close(town->window.window);
        sfMusic_stop(town->music.zik[MMENU]);
    }
}

int select_first(main_town_t *town, sfEvent *event)
{
    if (event->type == sfEvtKeyPressed) {
        if ((event->key.code == sfKeyDown || event->key.code == sfKeyUp)
        && stat_tab[GAME_OVER_RESTART] == 1) {
            stat_tab[GAME_OVER_RESTART] = 0;
            stat_tab[GAME_OVER_QUIT] = 1;
            return 0;
        }
        if ((event->key.code == sfKeyDown || event->key.code == sfKeyUp)
        && stat_tab[GAME_OVER_QUIT] == 1) {
            stat_tab[GAME_OVER_QUIT] = 0;
            stat_tab[GAME_OVER_RESTART] = 1;
            return 0;
        }
        quit_and_off_music(town, event);
        if (event->key.code == sfKeyReturn && stat_tab[GAME_OVER_RESTART] == 1)
            return 1;
    }
    return 0;
}

int select_load2(sfEvent *event, int load)
{
    if (event->key.code == sfKeyUp && load == 1) {
        load = 3;
        return load;
    }
    if (event->key.code == sfKeyUp && load == 3) {
        load = 2;
        return load;
    }
    if (event->key.code == sfKeyUp && load == 2)
        load = 1;
    return load;
}

int select_load(sfEvent *event, int load)
{
    if (event->type == sfEvtKeyPressed) {
        if (event->key.code == sfKeyDown && load == 1) {
            load = 2;
            return load;
        }
        if (event->key.code == sfKeyDown && load == 2) {
            load = 3;
            return load;
        }
        if (event->key.code == sfKeyDown && load == 3) {
            load = 1;
            return load;
        }
        load = select_load2(event, load);
    }
    return load;
}

void game_over_event(main_town_t *town, sfEvent *event)
{
    if (stat_tab[GAME_OVER] == 1) {
        if (sfMusic_getStatus(town->music.zik[MDEATH]) != sfPlaying) {
            sfMusic_play(town->music.zik[MDEATH]);
            sfMusic_stop(town->music.zik[FOREST]);
        }
        if (stat_tab[PANEL_TWO] == 1) {
            stat_tab[LOAD_GO] = select_load(event, stat_tab[LOAD_GO]);
            load_game_over(town, event);
            return;
        }
        if (stat_tab[PANEL_TWO] == 0)
            stat_tab[PANEL_TWO] = select_first(town, event);
    }
}
