/*
** EPITECH PROJECT, 2020
** case_2_to_spr
** File description:
** case_2_to_spe
*/

#include "town.h"

int actualise_special_case2(main_town_t *town, object_t *object, int count)
{
    if (check_empty_special_case(town, "/4:") == 1)
        return 0;
    actualise_good_line(town, object, "/4:");
    actualise_scd_tab(town, object, count);
    return 1;
}

int actualise_special_case3(main_town_t *town, object_t *object, int count)
{
    if (check_empty_special_case(town, "/5:") == 1)
        return 0;
    actualise_good_line(town, object, "/5:");
    actualise_scd_tab(town, object, count);
    return 1;
}

int actualise_special_case4(main_town_t *town, object_t *object, int count)
{
    if (check_empty_special_case(town, "/6:") == 1)
        return 0;
    actualise_good_line(town, object, "/6:");
    actualise_scd_tab(town, object, count);
    return 1;
}

int scdn_tab_to_special_case2(main_town_t *town,
    object_t *object, int count)
{
    int fulfill = decide_what_case_fulfill(town);
    if (fulfill == 3) {
        if (actualise_special_case3(town, object, count) == 0)
            return 0;
        return 1;
    }
    if (fulfill == 4) {
        if (actualise_special_case4(town, object, count) == 0)
            return 0;
        return 1;
    }
    return 0;
}

int scdn_tab_to_special_case(main_town_t *town,
    object_t *object, int count)
{
    int fulfill = decide_what_case_fulfill(town);
    if (fulfill == 1) {
        if (actualise_special_case1(town, object, count) == 0)
            return 0;
        return 1;
    }
    if (fulfill == 2) {
        if (actualise_special_case2(town, object, count) == 0)
            return 0;
        return 1;
    }
    return scdn_tab_to_special_case2(town, object, count);
}
