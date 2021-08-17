/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** event game
*/

#include "../../include/my.h"
#include "../../include/town.h"

void reset_collision(void)
{
    if (collision_tab[UP] == 1)
        collision_tab[UP] = 0;
    if (collision_tab[DOWN] == 1)
        collision_tab[DOWN] = 0;
    if (collision_tab[RIGHT] == 1)
        collision_tab[RIGHT] = 0;
    if (collision_tab[LEFT] == 1)
        collision_tab[LEFT] = 0;
}

void view_event2(main_town_t *town, sfEvent *event, int speed)
{
    if (event->key.code == sfKeyUp && collision_tab[UP] == 0) {
        reset_collision();
        town->p.pos_screen.y = 0;
        town->p.pos_screen.x = 0;
        town->p.pos_screen.y -= speed;
        town->p.value_view.y -= speed;
        sfView_move(town->p.view, (sfVector2f){town->p.pos_screen.x
        * town->size.size.x, town->p.pos_screen.y * town->size.size.y});
        stat_tab[LAST_ACTION] = 4;
    }
    if (event->key.code == sfKeyDown && collision_tab[DOWN] == 0) {
        reset_collision();
        town->p.pos_screen.y = 0;
        town->p.pos_screen.x = 0;
        town->p.pos_screen.y += speed;
        town->p.value_view.y += speed;
        sfView_move(town->p.view, (sfVector2f){town->p.pos_screen.x
        * town->size.size.x, town->p.pos_screen.y * town->size.size.y});
        stat_tab[LAST_ACTION] = 3;
    }
}

void view_event1(main_town_t *town, sfEvent *event, int speed)
{
    if (event->key.code == sfKeyRight && collision_tab[RIGHT] == 0) {
        reset_collision();
        town->p.pos_screen.x = 0;
        town->p.pos_screen.y = 0;
        town->p.pos_screen.x += speed;
        town->p.value_view.x += speed;
        sfView_move(town->p.view, (sfVector2f){town->p.pos_screen.x
        * town->size.size.x, town->p.pos_screen.y * town->size.size.y});
        stat_tab[LAST_ACTION] = 1;
    }
    if (event->key.code == sfKeyLeft && collision_tab[LEFT] == 0) {
        reset_collision();
        town->p.pos_screen.x = 0;
        town->p.pos_screen.y = 0;
        town->p.pos_screen.x -= speed;
        town->p.value_view.x -= speed;
        sfView_move(town->p.view, (sfVector2f){town->p.pos_screen.x
        * town->size.size.x, town->p.pos_screen.y * town->size.size.y});
        stat_tab[LAST_ACTION] = 2;
    }
}
