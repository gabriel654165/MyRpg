/*
** EPITECH PROJECT, 2020
** same
** File description:
** same
*/

#include "town.h"

void actualise_good_line(main_town_t *town, object_t *object, char *beg)
{
    char **tab = malloc(sizeof(char *) * (my_tab_len(town->parser.object) + 2));
    char *str = actualise_good_line2(object);
    int i;
    int j = 0;
    for (i = 0; my_strcmp(town->parser.object[i], beg) != 0; i++, j++)
        tab[j] = my_strcpy_malloc(town->parser.object[i]);
    tab[j] = my_strcpy_malloc(town->parser.object[i]);
    i++;
    j++;
    tab[j] = my_strcpy_malloc(town->parser.object[i]);
    j++;
    tab[j] = my_strcpy_malloc(str);
    for (j++, i++; town->parser.object[i] != NULL; i++, j++)
        tab[j] = my_strcpy_malloc(town->parser.object[i]);
    tab[j] = NULL;
    str = free_the_str(str);
    town->parser.object = free_the_tab(town->parser.object);
    town->parser.object = my_tabcpy_malloc(tab);
    tab = free_the_tab(tab);
}

char **actualise_scd_tab3(main_town_t *town, int count)
{
    int i = 0;
    char **tab = NULL;
    tab = malloc(sizeof(char *) * my_tab_len(town->parser.object));
    for (int j = 0; town->parser.object[j] != NULL; j++)
        if (j != count) {
            tab[i] = my_strcpy_malloc(town->parser.object[j]);
            i++;
        }
    tab[i] = NULL;
    return tab;
}

char *actualise_scd_tab2(object_t *object)
{
    char *str = NULL;
    str = str_concat(my_itoa(object->y), my_itoa(object->x), ':');
    str = str_concat(str, my_itoa(object->nbr_texture), ':');
    str = str_concat(str, my_itoa(object->nbr_obj - 1), ':');
    str = str_concat(str, my_itoa(0), ':');
    return str;
}

void actualise_scd_tab(main_town_t *town, object_t *object, int count)
{
    char *str = NULL;
    char **tab = NULL;
    if (object->nbr_obj > 1) {
        str = actualise_scd_tab2(object);
        town->parser.object[count] = free_the_str(town->parser.object[count]);
        town->parser.object[count] = my_strcpy_malloc(str);
        str = free_the_str(str);
    }
    else {
        tab = actualise_scd_tab3(town, count);
        town->parser.object = free_the_tab(town->parser.object);
        town->parser.object = my_tabcpy_malloc(tab);
        tab = free_the_tab(tab);
    }
}

int actualise_special_case1(main_town_t *town, object_t *object, int count)
{
    if (check_empty_special_case(town, "/3:") == 1)
        return 0;
    actualise_good_line(town, object, "/3:");
    actualise_scd_tab(town, object, count);
    return 1;
}
