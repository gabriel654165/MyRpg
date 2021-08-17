/*
** EPITECH PROJECT, 2020
** monster_parser
** File description:
** monster_parser
*/

#include "../../../include/olivier.h"
#include "town.h"

void ask_quest(quest_t *quest, char **tab, int line, int count)
{
    if (count == 0) {
        while (my_strcmp(tab[line], "/0:") != 0)
            line++;
        quest->first_line = line + 2;
        quest->last_line = my_getnbr(tab[line + 1]);
    }
    if (count == 1) {
        while (my_strcmp(tab[line], "/1:") != 0)
            line++;
        quest->first_line = line + 2;
        quest->last_line = my_getnbr(tab[line + 1]);
    }
    if (count == 2) {
        while (my_strcmp(tab[line], "/2:") != 0)
            line++;
        quest->first_line = line + 2;
        quest->last_line = my_getnbr(tab[line + 1]);
    }
}

void fulfill_the_png_quest3(quest_t *quest, int value, int i)
{
    if (i == 4)
        quest->nbr_quest = value;
    if (i == 5)
        quest->txt_obj = value;
    if (i == 6)
        quest->tab_to_fill = value;
    if (i == 7)
        quest->obj_to_find = value;
    if (i == 8)
        quest->nbr_obj_to_find = value;
}

void fulfill_the_png_quest2(quest_t *quest, int value, int i)
{
    if (i == 0)
        quest->coor.x = value;
    if (i == 1)
        quest->coor.y = value;
    if (i == 2) {
        quest->nb_texture = value;
        quest->texture = png_quest_qu[value];
    }
}

void fulfill_the_png_quest(quest_t *quest, char *str, char **tab, int line)
{
    int value = my_getnbr(str);
    static int i = 0;
    fulfill_the_png_quest2(quest, value, i);
    if (i == 3) {
        quest->dialogue_nb = value;
        if (value == 0)
            ask_quest(quest, tab, line, 0);
        if (value == 1)
            ask_quest(quest, tab, line, 1);
        if (value == 2)
            ask_quest(quest, tab, line, 2);
    }
    fulfill_the_png_quest3(quest, value, i);
    i++;
    if (i == 9)
        i = 0;
}

quest_t parse_the_quest(char *str, char **tab_pars, int line)
{
    quest_t quest;
    quest.line = line;
    int i = 0;
    int j = 0;
    char *temp = tab_pars[line];
    char *fin = NULL;
    while (str && *str) {
        for (;*str == ':'; str++);
        for (; temp[i] != ':' && temp[i] != '\0'; i++);
        fin = malloc(sizeof(char) * (i + 1));
        for (j = 0; str && *str != ':' && *str != '\0'; j++, str++)
            fin[j] = *str;
        fin[j] = 0;
        i++;
        fulfill_the_png_quest(&quest, fin, tab_pars, line);
        free(fin);
        fin = NULL;
    }
    return quest;
}
