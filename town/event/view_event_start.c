/*
** EPITECH PROJECT, 2020
** view_event_start
** File description:
** yes
*/

#include "../../include/my.h"
#include "../../include/town.h"

#define VIEW_OFFSET_WALK 10
#define VIEW_OFFSET_RUN 25

void view_event(main_town_t *town, sfEvent *event)
{
    int speed = 0;

    if (sfKeyboard_isKeyPressed(sfKeyLShift) == true)
        speed = VIEW_OFFSET_RUN;
    else
        speed = VIEW_OFFSET_WALK;
    view_event1(town, event, speed);
    view_event2(town, event, speed);
}
