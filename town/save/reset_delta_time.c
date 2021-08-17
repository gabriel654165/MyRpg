/*
** EPITECH PROJECT, 2020
** reset_delta_time
** File description:
** reset_delta_time
*/

#include "town.h"

char *reset_time4(char *res, char *str)
{
    str = str_concat(str, my_itoa(get_the_part_want(res, 25)), ':');
    str = str_concat(str, my_itoa(get_the_part_want(res, 26)), ':');
    return str;
}

char *reset_time3(char *res, char *str)
{
    str = str_concat(str, my_itoa(get_the_part_want(res, 17)), ':');
    str = str_concat(str, my_itoa(get_the_part_want(res, 18)), ':');
    str = str_concat(str, my_itoa(get_the_part_want(res, 19)), ':');
    str = str_concat(str, my_itoa(get_the_part_want(res, 20)), ':');
    str = str_concat(str, my_itoa(get_the_part_want(res, 21)), ':');
    str = str_concat(str, my_itoa(get_the_part_want(res, 22)), ':');
    str = str_concat(str, my_itoa(get_the_part_want(res, 23)), ':');
    str = str_concat(str, my_itoa(get_the_part_want(res, 24)), ':');
    return str;
}

char *reset_time2(char *res, char *str)
{
    str = str_concat(str, my_itoa(get_the_part_want(res, 8)), ':');
    str = str_concat(str, my_itoa(get_the_part_want(res, 9)), ':');
    str = str_concat(str, my_itoa(get_the_part_want(res, 10)), ':');
    str = str_concat(str, my_itoa(get_the_part_want(res, 11)), ':');
    str = str_concat(str, my_itoa(get_the_part_want(res, 12)), ':');
    str = str_concat(str, my_itoa(get_the_part_want(res, 13)), ':');
    str = str_concat(str, my_itoa(get_the_part_want(res, 14)), ':');
    str = str_concat(str, my_itoa(0), ':');
    str = str_concat(str, my_itoa(0), ':');
    return str;
}

char *reset_time(char *res)
{
    char *str = NULL;
    str = str_concat(my_itoa(get_the_part_want(res, 0)),
    my_itoa(get_the_part_want(res, 1)), ':');
    str = str_concat(str, my_itoa(get_the_part_want(res, 2)), ':');
    str = str_concat(str, my_itoa(get_the_part_want(res, 3)), ':');
    str = str_concat(str, my_itoa(get_the_part_want(res, 4)), ':');
    str = str_concat(str, my_itoa(get_the_part_want(res, 5)), ':');
    str = str_concat(str, my_itoa(get_the_part_want(res, 6)), ':');
    str = str_concat(str, my_itoa(get_the_part_want(res, 7)), ':');
    str = reset_time2(res, str);
    str = reset_time3(res, str);
    str = reset_time4(res, str);
    res = free_the_str(res);
    return str;
}

void reset_delta_time(main_town_t *town)
{
    for (int i = 0; town->parser.world_parser[i] != NULL; i++)
        if (my_strcmp(town->parser.world_parser[i], "/monster:") == 0) {
            i += 2;
            for (int j = i + my_getnbr(town->parser.world_parser[i - 1]);
                i < j; i++) {
                town->parser.world_parser[i]
                = reset_time(town->parser.world_parser[i]);
            }
        }
    for (int i = 0; town->parser.castle[i] != NULL; i++)
        if (my_strcmp(town->parser.castle[i], "/monster:") == 0) {
            i += 2;
            for (int j = i + my_getnbr(town->parser.castle[i - 1]);
                i < j; i++) {
                town->parser.castle[i]
                = reset_time(town->parser.castle[i]);
            }
        }
}
