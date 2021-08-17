/*
** EPITECH PROJECT, 2020
** my_RPG
** File description:
** tab for create main_menu
*/

#ifndef tab_main_menu_h
#define tab_main_menu_h

typedef struct struct_sprt
{
    char *pathfile;
    sfVector2f pos;
    sfVector2f scale;
    sfIntRect rect;
} struct_sprt_t;

static const struct_sprt_t tab_sprt[] =
{
    {"texture_pack/assets/main_menu.png",
    (sfVector2f){0, 0}, (sfVector2f){1, 1}, (sfIntRect){0, 0, 1920, 1080}},
    {"texture_pack/medium_obj/none.png",
    (sfVector2f){0, 0}, (sfVector2f){1, 1}, (sfIntRect){0, 0, 1920, 1080}},
    {"texture_pack/assets/grey_button.png",
    (sfVector2f){80, 880}, (sfVector2f){1, 1}, (sfIntRect){0, 0, 190, 50}},
    {NULL, (sfVector2f){0, 0}, (sfVector2f){0, 0}, (sfIntRect){0, 0, 0, 0}},
};

typedef enum name_menu
{
    MMAIN,
    MOPTION,
    MBUTTON,
} name_menu_t;
#endif
