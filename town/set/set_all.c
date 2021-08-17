/*
** EPITECH PROJECT, 2020
** set_all
** File description:
** yes
*/

#include "town.h"
#include "graphic.h"
#include "olivier.h"

void set_the_window(main_town_t *town)
{
    town->window.video_mode = (sfVideoMode){1920, 1080, 32};
    town->window.color = (sfColor){255, 255, 255, 1};
    town->window.window = sfRenderWindow_create(town->window.video_mode,
        "rpg", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(town->window.window, 60);
}

void set_the_parser(main_town_t *town)
{
    town->parser.tab_pars = NULL;
    town->parser.quest_parser = NULL;
    town->parser.quest = NULL;
    town->parser.world_parser = NULL;
    town->parser.quest_world = NULL;
    town->parser.down = NULL;
}

void set_view(main_town_t *town)
{
    town->parser.tab_pars = NULL;
    srand(time(NULL));
    town->p.view = sfView_create();
    town->p.pos_screen.x = 1920;
    town->p.pos_screen.y = 1080;
    sfView_setSize(town->p.view, town->p.pos_screen);
    town->p.pos_screen.x = 1920 / 2;
    town->p.pos_screen.y = 1080 / 2;
    sfView_setCenter(town->p.view, town->p.pos_screen);
    sfRenderWindow_setView(town->window.window, town->p.view);
    town->p.pos_screen.x = 0;
    town->p.pos_screen.y = 0;
    town->p.value_middle = (sfVector2f){0, 0};
    town->p.value_view = (sfVector2f){0, 0};
    town->size.size_screen = (sfVector2f){0, 0};
}

void set_all(main_town_t *town, char **av, int ac)
{
    (void)ac;
    (void)av;
    set_stats();
    set_the_window(town);
    set_the_enums();
    set_olivier();
    set_view(town);
    set_the_png(&town->png);
    set_the_parser(town);
    set_the_music(&town->music);
}
