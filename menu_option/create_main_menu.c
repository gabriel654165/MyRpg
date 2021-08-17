/*
** EPITECH PROJECT, 2020
** my_RPG
** File description:
** creating main menu sprite etc...
*/

#include "../include/main_menu.h"
#include "../include/tab_main_menu.h"
#include "../include/town.h"

static sfSprite **create_allsprite(void)
{
    int len_tab = 0;
    sfSprite **all_sprite;
    sfTexture *texture;

    for (; tab_sprt[len_tab].pathfile != NULL; ++len_tab);
    all_sprite = malloc(sizeof(sfSprite *) * (len_tab));
    for (int i = 0; tab_sprt[i].pathfile != NULL; ++i) {
        texture = sfTexture_createFromFile(tab_sprt[i].pathfile, NULL);
        if (texture == NULL) {
            free(all_sprite);
            return (NULL);
        }
        all_sprite[i] = sfSprite_create();
        sfSprite_setPosition(all_sprite[i], tab_sprt[i].pos);
        sfSprite_setScale(all_sprite[i], tab_sprt[i].scale);
        sfSprite_setTexture(all_sprite[i], texture, sfFalse);
        sfSprite_setTextureRect(all_sprite[i], tab_sprt[i].rect);
    }
    return (all_sprite);
}

sfmain_menu_t create_main_menu(void)
{
    sfmain_menu_t menu;

    menu.bg = create_allsprite();
    menu.text = sfText_create();
    sfText_setFont(menu.text,
    sfFont_createFromFile("texture_pack/assets/menu_font.otf"));
    menu.rectangle = sfRectangleShape_create();
    sfRectangleShape_setSize(menu.rectangle, (sfVector2f){190, 50});
    return (menu);
}
