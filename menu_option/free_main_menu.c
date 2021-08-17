/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** free main_menu
*/

#include "../include/main_menu.h"
#include "../include/tab_main_menu.h"
#include "../include/town.h"

void free_main_menu(sfmain_menu_t menu)
{
    for (int i = 0; tab_sprt[i].pathfile != NULL; ++i) {
        sfTexture_destroy((sfTexture *) sfSprite_getTexture(menu.bg[i]));
        sfSprite_destroy(menu.bg[i]);
    }
    sfFont_destroy((sfFont *) sfText_getFont(menu.text));
    sfText_destroy(menu.text);
    sfRectangleShape_destroy(menu.rectangle);
}
