/*
** EPITECH PROJECT, 2020
** quest_monitor
** File description:
** quest_monitor
*/

#include "town.h"

void put_out_line_obj(main_town_t *town, int i)
{
    char **tab = malloc(sizeof(char *)
    * (my_tab_len(town->parser.object)));
    int j = 0;
    for (int k = 0; town->parser.object[k] != NULL; k++) {
        if (k != i) {
            tab[j] = my_strcpy_malloc(town->parser.object[k]);
            j++;
        }
    }
    tab[j] = NULL;
    town->parser.object = free_the_tab(town->parser.object);
    town->parser.object = my_tabcpy_malloc(tab);
    tab = free_the_tab(tab);
}

void actualise_obj_when_quest_is_done(main_town_t *town, int i, quest_t quest)
{
    if (get_the_part_want(town->parser.object[i], 3) >= quest.nbr_obj_to_find) {
        put_out_line_obj(town, i);
        return;
    }
    char *str = NULL;
    str = str_concat(my_itoa(get_the_part_want(town->parser.object[i], 0)),
    my_itoa(get_the_part_want(town->parser.object[i], 1)), ':');
    str = str_concat(str,
    my_itoa(get_the_part_want(town->parser.object[i], 2)), ':');
    str = str_concat(str,
    my_itoa(get_the_part_want(town->parser.object[i], 3)
    - quest.nbr_obj_to_find), ':');
    str = str_concat(str,
    my_itoa(get_the_part_want(town->parser.object[i], 4)), ':');
    town->parser.object[i] = free_the_str(town->parser.object[i]);
    town->parser.object[i] = my_strcpy_malloc(str);
    str = free_the_str(str);
}

int find_if_quest_is_done(quest_t quest, main_town_t *town)
{
    int i = 0;
    for (; my_strcmp(town->parser.object[i], "/1:") != 0; i++);
    for (i += 2; my_strcmp(town->parser.object[i], "/end") != 0; i++) {
        if (get_the_part_want(town->parser.object[i], 2) == quest.obj_to_find
            && get_the_part_want(town->parser.object[i], 3)
            >= quest.nbr_obj_to_find) {
            actualise_obj_when_quest_is_done(town, i, quest);
            return 1;
        }
    }
    return 0;
}

void quest_monitor(quest_t quest, main_town_t *town)
{
    int i = 0;
    char *str = NULL;
    int c;
    i = norme_on_quest_monitor(town, quest);
    c = town->parser.quest[i + 1][6] - '0';
    if (c + 1 == 2 && find_if_quest_is_done(quest, town) == 1) {
        put_obj_in_inventory(town, quest.txt_obj, quest.tab_to_fill);
        actualise_quest(quest, town);
        free(town->parser.quest[i + 1]);
        town->parser.quest[i + 1] = NULL;
        str = str_concat("state", my_itoa(c + 1), ':');
        town->parser.quest[i + 1] = my_strcpy_malloc(str);
    }
    if (c + 1 == 1) {
        actualise_quest(quest, town);
        free(town->parser.quest[i + 1]);
        town->parser.quest[i + 1] = NULL;
        str = str_concat("state", my_itoa(c + 1), ':');
        town->parser.quest[i + 1] = my_strcpy_malloc(str);
    }
}
