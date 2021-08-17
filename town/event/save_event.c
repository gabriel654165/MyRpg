/*
** EPITECH PROJECT, 2020
** save_event
** File description:
** yes
*/

#include "town.h"
#define TAB town->parser

char **parser_to_write(main_town_t *town, char *file_name)
{
    char **tab_use;

    if (my_strcmp(file_name, "castle.txt") == 0)
        tab_use = TAB.castle;
    if (my_strcmp(file_name, "object.txt") == 0)
        tab_use = TAB.object;
    if (my_strcmp(file_name, "pars.txt") == 0)
        tab_use = TAB.tab_pars;
    if (my_strcmp(file_name, "png_quest.txt") == 0)
        tab_use = TAB.quest_parser;
    if (my_strcmp(file_name, "quest.txt") == 0)
        tab_use = TAB.quest;
    if (my_strcmp(file_name, "olivier.txt") == 0)
        tab_use = TAB.world_parser;
    if (my_strcmp(file_name, "world_quest.txt") == 0)
        tab_use = TAB.quest_world;
    return tab_use;
}

void overwrite_one_file(main_town_t *town, char *save_choosen, char *file_name)
{
    char **tab_use = parser_to_write(town, file_name);
    char *all_txt = "\0";
    char *path_name = my_strcat(save_choosen, file_name);
    FILE *fd;
    size_t byte = 1;
    size_t nb_elem;

    if (open(path_name, O_RDONLY) == -1)
        fd = fopen(path_name, "w+");
    else
        fd = fopen(path_name, "w");
    for (int i1 = 0; tab_use[i1] != NULL; ++i1)
        all_txt = my_strcat_parser(all_txt, tab_use[i1]);
    nb_elem = my_strlen(all_txt);
    fwrite(all_txt, byte, nb_elem, fd);
    fclose(fd);
    free(all_txt);
}

void save_event_continue2(main_town_t *town, sfEvent *event, char *directory)
{
    if (event->key.code == sfKeyReturn && save_tab[SAVE_SLOT_THREE] == 1) {
        directory = "town/parser/SAVE3/";
        overwrite_one_file(town, directory, "castle.txt");
        overwrite_one_file(town, directory, "object.txt");
        overwrite_one_file(town, directory, "world_quest.txt");
        overwrite_one_file(town, directory, "pars.txt");
        overwrite_one_file(town, directory, "png_quest.txt");
        overwrite_one_file(town, directory, "quest.txt");
        overwrite_one_file(town, directory, "olivier.txt");
        reset_delta_time(town);
    }
}

void save_event_continue(main_town_t *town, sfEvent *event, char *directory)
{
    if (event->key.code == sfKeyReturn && save_tab[SAVE_SLOT_TWO] == 1) {
        directory = "town/parser/SAVE2/";
        overwrite_one_file(town, directory, "castle.txt");
        overwrite_one_file(town, directory, "object.txt");
        overwrite_one_file(town, directory, "pars.txt");
        overwrite_one_file(town, directory, "png_quest.txt");
        overwrite_one_file(town, directory, "world_quest.txt");
        overwrite_one_file(town, directory, "quest.txt");
        overwrite_one_file(town, directory, "olivier.txt");
        reset_delta_time(town);
    }
    save_event_continue2(town, event, directory);
}

void save_event(main_town_t *town, sfEvent *event)
{
    char *directory;

    if (event->type == sfEvtKeyPressed) {
        if (event->key.code == sfKeyReturn && save_tab[SAVE_SLOT_ONE] == 1) {
            directory = "town/parser/SAVE1/";
            overwrite_one_file(town, directory, "castle.txt");
            overwrite_one_file(town, directory, "object.txt");
            overwrite_one_file(town, directory, "world_quest.txt");
            overwrite_one_file(town, directory, "pars.txt");
            overwrite_one_file(town, directory, "png_quest.txt");
            overwrite_one_file(town, directory, "quest.txt");
            overwrite_one_file(town, directory, "olivier.txt");
            reset_delta_time(town);
        }
        save_event_continue(town, event, directory);
    }
}
