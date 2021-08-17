/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "tab_music.h"
#include "town.h"
#include "graphic.h"
#include "olivier.h"

void get_the_scale2(main_town_t *town)
{
    sfView_setSize(town->p.view, town->size.size_screen);
    sfRenderWindow_setView(town->window.window, town->p.view);
    town->png.coor.x = town->p.value_middle.x -
    sfSprite_getLocalBounds(town->png.spr).width * town->size.size.x / 2;
    town->png.coor.y = town->p.value_middle.y -
    sfSprite_getLocalBounds(town->png.spr).height * town->size.size.y / 2;
    sfSprite_setPosition(town->png.spr, town->png.coor);
    sfSprite_setScale(town->png.spr, (sfVector2f){town->size.size.x * 2,
    town->size.size.y * 2});
}

void get_the_scale(sfVector2u scale, main_town_t *town)
{
    static sfVector2f old_view = (sfVector2f){0, 0};
    town->size.size.x = scale.x / 1920.0;
    town->size.size.y = scale.y / 1080.0;
    town->p.value_middle.x = (1920 / 2) * town->size.size.x
        + town->p.value_view.x * town->size.size.x + int_tab[CINE_X];
    town->p.value_middle.y = (1080 / 2) * town->size.size.y
        + town->p.value_view.y * town->size.size.y + int_tab[CINE_Y];
    if (old_view.x != scale.x || old_view.y != scale.y)
        sfView_setCenter(town->p.view, town->p.value_middle);
    old_view = town->size.size_screen;
    town->size.size_screen.x = scale.x;
    town->size.size_screen.y = scale.y;
    get_the_scale2(town);
}

void map_scene(main_town_t *town)
{
    int i = choose_map(town);
    if (i == 0) {
        town->parser.tab_pars
        = get_obj_pos(town, town->parser.tab_pars, 0);
        get_obj_pos(town, town->parser.quest_parser, 1);
        if (stat_tab[ZONE_DRAW] == 1)
            draw_zone_text(town, ZONE_PARS);
    } else if (i == 1) {
        town->parser.world_parser
        = get_obj_pos(town, town->parser.world_parser, 0);
        get_obj_pos(town, town->parser.quest_world, 2);
        if (stat_tab[ZONE_DRAW] == 1)
            draw_zone_text(town, ZONE_WORLD);
    } else {
        town->parser.castle
        = get_obj_pos(town, town->parser.castle, 0);
        if (stat_tab[ZONE_DRAW] == 1)
            cinematic_event(town);
    }
}

void call_in_main(main_town_t *town)
{
    get_the_scale(sfRenderWindow_getSize(town->window.window), town);
    change_dir_hero(&town->png);
    clock_hero(&town->png, &town->music);
    map_scene(town);
    diplay_stats(town);
    inventory_monitor(town);
    display_menu_quest(town);
    display_menu_save(town);
    draw_all_game_over(town);
}

int main(int ac, char **av, char **env)
{
    char *path = NULL;
    sfEvent event;
    main_town_t town;
    if (error_env(env) == 84)
        return (84);
    set_all(&town, av, ac);
    if (start_load_game(&town, &path, &event) == -1)
        return (0);
    sfMusic_play(town.music.zik[FOREST]);
    all_parser_to_tab(&town, path);
    int_tab[TOWN_SCENE] = 1;
    while (sfRenderWindow_isOpen(town.window.window)) {
        sfRenderWindow_clear(town.window.window, town.window.color);
        call_in_main(&town);
        sfRenderWindow_display(town.window.window);
        while (sfRenderWindow_pollEvent(town.window.window, &event))
            analyse_event(&event, &town);
    }
    free_all(&town);
}
