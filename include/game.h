/*
** EPITECH PROJECT, 2020
** game
** File description:
** game.h
*/

#ifndef GAME_H
#define GAME_H

#include "include.h"
#include "struct.h"
#include "town.h"

void set_window(game_m *p, sfRenderWindow *window);
int game_loop(game_m *p, sfRenderWindow *window, allsnd_t *music);
void all(game_m *p);
char *my_getenv(char **nenv, char *elem);
int main_menu(sfRenderWindow *window, allsnd_t *music);

#endif /* GAME_H */
