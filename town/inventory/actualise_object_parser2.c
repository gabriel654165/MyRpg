/*
** EPITECH PROJECT, 2020
** actualise_object
** File description:
** actualise_object
*/

#include "town.h"

int **fullfil_the_int_tab(int **tab, char *str)
{
    sfVector2i coor;
    coor.y = get_the_part_want(str, 0);
    coor.x = get_the_part_want(str, 1);
    tab[coor.y][coor.x] = 1;
    return tab;
}

int **fulfill_when_new_object_second_tab(main_town_t *town, int nbr_texture,
    int type_of_block, int **tab)
{
    sfVector2i coor;
    for (int k = 0; k < 3; k++) {
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

int **check_if_object_is_in_second_tab(main_town_t *town, int nbr_texture,
    int **tab)
{
    int i = 0;
    for (i = 0; my_strcmp(town->parser.object[i], "/2:") != 0; i++);
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

void put_obj_in_second_line(main_town_t *town, int nbr_texture,
    int type_of_block)
{
    int **tab = malloc(sizeof(int *) * 6);
    for (int i = 0; i < 3; i++)
        tab[i] = malloc(sizeof(int) * 4);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
            tab[i][j] = 0;
    if ((tab = check_if_object_is_in_second_tab(town, nbr_texture, tab))
        == NULL) {
        return;
    }
    tab = fulfill_when_new_object_second_tab(town, nbr_texture,
    type_of_block, tab);
}
