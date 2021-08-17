/*
** EPITECH PROJECT, 2020
** load_game_over
** File description:
** yes
*/

#include "tab_music.h"
#include "town.h"
#define TAB town->parser

void load_game_over_continue2(main_town_t *town)
{
    TAB.castle = str_to_tab(get_the_buff("town/parser/SAVE2/castle.txt"));
    TAB.object = str_to_tab(get_the_buff("town/parser/SAVE2/object.txt"));
    TAB.tab_pars = str_to_tab(get_the_buff("town/parser/SAVE2/pars.txt"));
    TAB.quest_world =
        str_to_tab(get_the_buff("town/parser/SAVE2/world_quest.txt"));
    TAB.world_parser =
        str_to_tab(get_the_buff("town/parser/SAVE2/olivier.txt"));
    TAB.quest_parser =
        str_to_tab(get_the_buff("town/parser/SAVE2/png_quest.txt"));
    TAB.quest = str_to_tab(get_the_buff("town/parser/SAVE2/quest.txt"));
    set_stats();
}

void load_game_over_continue(main_town_t *town, sfEvent *event)
{
    if (event->key.code == sfKeyReturn && stat_tab[LOAD_GO] == 2) {
        sfMusic_stop(town->music.zik[MDEATH]);
        load_game_over_continue2(town);
    }
    if (event->key.code == sfKeyReturn && stat_tab[LOAD_GO] == 3) {
        TAB.castle = str_to_tab(get_the_buff("town/parser/SAVE3/castle.txt"));
        TAB.quest_world =
            str_to_tab(get_the_buff("town/parser/SAVE3/world_quest.txt"));
        TAB.object = str_to_tab(get_the_buff("town/parser/SAVE3/object.txt"));
        TAB.tab_pars = str_to_tab(get_the_buff("town/parser/SAVE3/pars.txt"));
        TAB.world_parser =
            str_to_tab(get_the_buff("town/parser/SAVE3/olivier.txt"));
        TAB.quest_parser =
            str_to_tab(get_the_buff("town/parser/SAVE3/png_quest.txt"));
        TAB.quest = str_to_tab(get_the_buff("town/parser/SAVE3/quest.txt"));
        sfMusic_stop(town->music.zik[MDEATH]);
        set_stats();
    }
}

void load_game_over(main_town_t *town, sfEvent *event)
{
    if (event->type == sfEvtKeyPressed) {
        if (event->key.code == sfKeyReturn && stat_tab[LOAD_GO] == 1) {
            TAB.castle =
                str_to_tab(get_the_buff("town/parser/SAVE1/castle.txt"));
            TAB.quest_world =
                str_to_tab(get_the_buff("town/parser/SAVE1/world_quest.txt"));
            TAB.object =
                str_to_tab(get_the_buff("town/parser/SAVE1/object.txt"));
            TAB.tab_pars =
                str_to_tab(get_the_buff("town/parser/SAVE1/pars.txt"));
            TAB.world_parser =
                str_to_tab(get_the_buff("town/parser/SAVE1/olivier.txt"));
            TAB.quest_parser =
                str_to_tab(get_the_buff("town/parser/SAVE1/png_quest.txt"));
            TAB.quest = str_to_tab(get_the_buff("town/parser/SAVE1/quest.txt"));
            sfMusic_stop(town->music.zik[MDEATH]);
            set_stats();
        }
        load_game_over_continue(town, event);
    }
}
