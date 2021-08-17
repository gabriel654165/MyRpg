/*
** EPITECH PROJECT, 2020
** parser_to_tab_save
** File description:
** yes
*/

#include "town.h"

void all_parser_to_tab(main_town_t *town, char *path)
{
    if (path == NULL)
        path = "town/parser/SAVE_DEFAULT/";
    town->parser.castle =
        str_to_tab(get_the_buff(my_strcat(path, "castle.txt")));
    town->parser.object =
        str_to_tab(get_the_buff(my_strcat(path, "object.txt")));
    town->parser.tab_pars =
        str_to_tab(get_the_buff(my_strcat(path, "pars.txt")));
    town->parser.world_parser =
        str_to_tab(get_the_buff(my_strcat(path, "olivier.txt")));
    town->parser.quest_world =
        str_to_tab(get_the_buff(my_strcat(path, "world_quest.txt")));
    town->parser.quest_parser =
        str_to_tab(get_the_buff(my_strcat(path, "png_quest.txt")));
    town->parser.quest =
        str_to_tab(get_the_buff(my_strcat(path, "quest.txt")));
}
