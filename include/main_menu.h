/*
** EPITECH PROJECT, 2020
** my_RPG
** File description:
** main menu structure
*/

#ifndef	main_menu_h
#define	main_menu_h

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "town.h"
#include <stdlib.h>

typedef struct sfmain_menu
{
    sfSprite **bg;
    sfText *text;
    sfRectangleShape *rectangle;
} sfmain_menu_t;

sfmain_menu_t create_main_menu(void);
void display_sprite(sfmain_menu_t *menu, sfRenderWindow *window);
void display_rectangle(sfRectangleShape *shape, sfRenderWindow *window,
int pressed, sfVector2f scale);
void option_main_menu(sfRenderWindow *window, allsnd_t *music);
void free_main_menu(sfmain_menu_t menu);

#endif
