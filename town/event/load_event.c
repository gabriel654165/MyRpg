/*
** EPITECH PROJECT, 2020
** load_event
** File description:
** yes
*/

#include "town.h"
#define TAB town->parser

char *load_event_continue2(main_town_t *town, char *directory)
{
    directory = "town/parser/SAVE2/";
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
    return directory;
}

char *load_event_continue(main_town_t *town, sfEvent *event, char *directory)
{
    if (event->key.code == sfKeyReturn && save_tab[LOAD_SLOT_TWO] == 1) {
        directory = load_event_continue2(town, directory);
    }
    if (event->key.code == sfKeyReturn && save_tab[LOAD_SLOT_THREE] == 1) {
        directory = "town/parser/SAVE3/";
        TAB.castle = str_to_tab(get_the_buff("town/parser/SAVE3/castle.txt"));
        TAB.object = str_to_tab(get_the_buff("town/parser/SAVE3/object.txt"));
        TAB.quest_world =
        str_to_tab(get_the_buff("town/parser/SAVE3/world_quest.txt"));
        TAB.tab_pars = str_to_tab(get_the_buff("town/parser/SAVE3/pars.txt"));
        TAB.world_parser =
        str_to_tab(get_the_buff("town/parser/SAVE3/olivier.txt"));
        TAB.quest_parser =
        str_to_tab(get_the_buff("town/parser/SAVE3/png_quest.txt"));
        TAB.quest = str_to_tab(get_the_buff("town/parser/SAVE3/quest.txt"));
    }
    return directory;
}

char *load_event2(main_town_t *town, char *directory)
{
    directory = "town/parser/SAVE1/";
    TAB.castle =
        str_to_tab(get_the_buff("town/parser/SAVE1/castle.txt"));
    TAB.object =
        str_to_tab(get_the_buff("town/parser/SAVE1/object.txt"));
    TAB.tab_pars =
        str_to_tab(get_the_buff("town/parser/SAVE1/pars.txt"));
    TAB.quest_world =
        str_to_tab(get_the_buff("town/parser/SAVE1/world_quest.txt"));
    TAB.world_parser =
        str_to_tab(get_the_buff("town/parser/SAVE1/olivier.txt"));
    TAB.quest_parser =
        str_to_tab(get_the_buff("town/parser/SAVE1/png_quest.txt"));
    TAB.quest = str_to_tab(get_the_buff("town/parser/SAVE1/quest.txt"));
    return directory;
}

char *load_event(main_town_t *town, sfEvent *event)
{
    char *directory = NULL;
    if (event->type == sfEvtKeyPressed) {
        if (event->key.code == sfKeyReturn && save_tab[LOAD_SLOT_ONE] == 1)
            directory = load_event2(town, directory);
        directory = load_event_continue(town, event, directory);
    }
    return (directory);
}
