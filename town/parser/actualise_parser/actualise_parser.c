/*
** EPITECH PROJECT, 2020
** actualise_parser
** File description:
** actualise_parser
*/

#include "town.h"

char *str_concat(char *temp, char *str, char c)
{
    if (str == NULL && temp == NULL)
        return NULL;
    int j = 0;
    int i = my_strlen(temp) + my_strlen(str);
    char *res = malloc(sizeof(char) * (i + 2));
    if (res == NULL)
        return NULL;
    if (temp != NULL)
        for (j = 0; temp[j] != '\0'; j++)
            res[j] = temp[j];
    res[j] = c;
    if (str != NULL)
        for (i = 0, j = j + 1; str[i] != '\0'; i++, j++)
            res[j] = str[i];
    res[j] = '\0';
    return res;
}

void actualise_quest(quest_t quest, main_town_t *town)
{
    char *str = NULL;
    str = str_concat(my_itoa(quest.coor.x), my_itoa(quest.coor.y), ':');
    str = str_concat(str, my_itoa(quest.nb_texture), ':');
    str = str_concat(str, my_itoa(quest.dialogue_nb + 1), ':');
    str = str_concat(str, my_itoa(quest.nbr_quest), ':');
    str = str_concat(str, my_itoa(quest.txt_obj), ':');
    str = str_concat(str, my_itoa(quest.tab_to_fill), ':');
    str = str_concat(str, my_itoa(quest.obj_to_find), ':');
    str = str_concat(str, my_itoa(quest.nbr_obj_to_find), ':');
    if (town->png.dimension == 1) {
        free(town->parser.quest_parser[quest.line]);
        town->parser.quest_parser[quest.line] = NULL;
        town->parser.quest_parser[quest.line] = my_strcpy_malloc(str);
    }
    else {
        free(town->parser.quest_world[quest.line]);
        town->parser.quest_world[quest.line] = NULL;
        town->parser.quest_world[quest.line] = my_strcpy_malloc(str);
    }
    str = free_the_str(str);
}

void actualise_object(object_t object, main_town_t *town, int count)
{
    free(town->parser.object[count]);
    town->parser.object[count] = NULL;
    char *str = NULL;
    str = str_concat(my_itoa(object.y), my_itoa(object.x), ':');
    str = str_concat(str, my_itoa(object.nbr_texture), ':');
    str = str_concat(str, my_itoa(object.nbr_obj), ':');
    str = str_concat(str, my_itoa(object.state), ':');
    town->parser.object[count] = my_strcpy_malloc(str);
    free(str);
}
