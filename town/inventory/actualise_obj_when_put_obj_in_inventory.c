/*
** EPITECH PROJECT, 2020
** actualise_obj_when_put_obj_in_inventory
** File description:
** actualise_obj_when_put_obj_in_inventory
*/

#include "town.h"

int get_the_part_want(char *str, int count)
{
    char *tmp = str;
    char *fin = NULL;
    int i = 0;
    int j = 0;
    for (int res = 0; str && *str; res++) {
        for (;*tmp && *tmp != ':'; tmp++);
        i = tmp - str;
        tmp++;
        fin = malloc(sizeof(char) * (i + 1));
        for (j = 0; j < i; j++, str++)
            fin[j] = *str;
        if (*str)
            str++;
        fin[j] = '\0';
        if (res == count)
            return (my_getnbr(fin));
        fin = free_the_str(fin);
    }
    return 0;
}

void actualise_when_more_than_one_object(main_town_t *town, int i)
{
    char *str = NULL;
    str = str_concat(my_itoa(get_the_part_want(town->parser.object[i], 0)),
        my_itoa(get_the_part_want(town->parser.object[i], 1)), ':');
    str = str_concat(str,
        my_itoa(get_the_part_want(town->parser.object[i], 2)), ':');
    str = str_concat(str,
        my_itoa(get_the_part_want(town->parser.object[i], 3) + 1), ':');
    str = str_concat(str,
        my_itoa(get_the_part_want(town->parser.object[i], 4)), ':');
    town->parser.object[i] = free_the_str(town->parser.object[i]);
    town->parser.object[i] = my_strcpy_malloc(str);
    str = free_the_str(str);
}

void actualise_first_tab(main_town_t *town, sfVector2i coor,
    int nbr_texture, char **tab)
{
    int i = 0;
    int save = 0;
    char *str = NULL;
    for (i = 0; my_strcmp(town->parser.object[i], "/1:") != 0; i++)
        tab[i] = my_strcpy_malloc(town->parser.object[i]);
    for (; my_strcmp(town->parser.object[i], "/end") != 0; i++)
        tab[i] = my_strcpy_malloc(town->parser.object[i]);
    save = i;
    str = str_concat(my_itoa(coor.y), my_itoa(coor.x), ':');
    str = str_concat(str, my_itoa(nbr_texture), ':');
    str = str_concat(str, my_itoa(1), ':');
    str = str_concat(str, my_itoa(0), ':');
    tab[i] = my_strcpy_malloc(str);
    free(str);
    for (i++; town->parser.object[save] != NULL; i++, save++)
        tab[i] = my_strcpy_malloc(town->parser.object[save]);
    tab[i] = NULL;
    town->parser.object = free_the_tab(town->parser.object);
    town->parser.object = my_tabcpy_malloc(tab);
    tab = free_the_tab(tab);
}

void actualise_second_tab(main_town_t *town, sfVector2i coor,
    int nbr_texture, char **tab)
{
    int i = 0;
    int save = 0;
    char *str = NULL;
    for (i = 0; my_strcmp(town->parser.object[i], "/2:") != 0; i++)
        tab[i] = my_strcpy_malloc(town->parser.object[i]);
    for (; my_strcmp(town->parser.object[i], "/end") != 0; i++)
        tab[i] = my_strcpy_malloc(town->parser.object[i]);
    save = i;
    str = str_concat(my_itoa(coor.y), my_itoa(coor.x), ':');
    str = str_concat(str, my_itoa(nbr_texture), ':');
    str = str_concat(str, my_itoa(1), ':');
    str = str_concat(str, my_itoa(0), ':');
    tab[i] = my_strcpy_malloc(str);
    free(str);
    for (i++; town->parser.object[save] != NULL; i++, save++)
        tab[i] = my_strcpy_malloc(town->parser.object[save]);
    tab[i] = NULL;
    town->parser.object = free_the_tab(town->parser.object);
    town->parser.object = my_tabcpy_malloc(tab);
    tab = free_the_tab(tab);
}

void actualise_obj_when_put_in_inventory(main_town_t *town,
    sfVector2i coor, int nbr_texture, int type_of_block)
{
    int len = my_tab_len(town->parser.object);
    char **tab = malloc(sizeof(char *) * (len + 2));
    if (type_of_block == 1)
        actualise_first_tab(town, coor, nbr_texture, tab);
    else if (type_of_block == 2)
        actualise_second_tab(town, coor, nbr_texture, tab);
}
