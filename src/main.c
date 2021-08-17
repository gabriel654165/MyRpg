/*
** EPITECH PROJECT, 2020
** main
** File description:
** yes
*/

#include "../include/my.h"
#include "../include/game.h"
#include "../include/town.h"

static int find_display(char **env)
{
    if (my_getenv(env, "DISPLAY") == NULL)
        return (0);
    return (1);
}

int game_loop(game_m *p, sfRenderWindow *window, allsnd_t *music)
{
    int load = 0;

    set_window(p, window);
    load = main_menu(window, music);
    return load;
}

int main_menu_test(char **env, sfRenderWindow *window, allsnd_t *music)
{
    game_m p;

    if (env == NULL || find_display(env) == 0)
        return (84);
    return (game_loop(&p, window, music));
}
