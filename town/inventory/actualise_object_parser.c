/*
** EPITECH PROJECT, 2020
** actualise_object_parser
** File description:
** actualise_object_parser
*/

#include "town.h"

int check_if_obj_exist(char *str, int nbr_texture)
{
    int count = get_the_part_want(str, 2);
    if (count == nbr_texture)
        return 1;
    return 0;
}

int **check_if_object_is_in_tab(main_town_t *town, int nbr_texture, int **tab)
{
    int i = 0;
    for (i = 0; my_strcmp(town->parser.object[i], "/1:") != 0; i++);
    i += 2;
    for (; my_strcmp(town->parser.object[i], "/end") != 0; i++) {
        if (check_if_obj_exist(town->parser.object[i], nbr_texture) == 1) {
            actualise_when_more_than_one_object(town, i);
            return NULL;
        }
        tab = fullfil_the_int_tab(tab, town->parser.object[i]);
    }
    return tab;
}

int **fulfill_when_new_object(main_town_t *town, int nbr_texture,
    int type_of_block, int **tab)
{
    sfVector2i coor;
    for (int k = 0; k < 6; k++) {
        for (int j = 0; j < 4; j++)
            if (tab[k][j] == 0) {
                coor.x = j;
                coor.y = k;
                actualise_obj_when_put_in_inventory(town, coor,
                nbr_texture, type_of_block);
                return tab;
            }
    }
    return tab;
}

void put_obj_in_first_line(main_town_t *town, int nbr_texture,
    int type_of_block)
{
    int **tab = malloc(sizeof(int *) * 6);
    for (int i = 0; i < 6; i++)
        tab[i] = malloc(sizeof(int) * 4);
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 4; j++)
            tab[i][j] = 0;
    tab = check_if_object_is_in_tab(town, nbr_texture, tab);
    if (tab == NULL)
        return;
    tab = fulfill_when_new_object(town, nbr_texture, type_of_block, tab);
}

void put_obj_in_inventory(main_town_t *town, int nbr_texture, int type_of_obj)
{
    if (type_of_obj == 1)
        put_obj_in_first_line(town, nbr_texture, type_of_obj);
    else
        put_obj_in_second_line(town, nbr_texture, type_of_obj);
}
