/*
** EPITECH PROJECT, 2020
** set_olivier
** File description:
** c
*/

#include "../../include/my.h"
#include "../../include/town.h"
#include "../../include/olivier.h"

void set_olivier(void)
{
    for (int i = 0; i < STUFF; i++)
        tab_txt_stuff[i] = sfTexture_createFromFile(TEXTURE_STUFF[i].txt, NULL);
    for (int i = 0; i < NATURE; i++)
        tab_txt_nature[i] =
        sfTexture_createFromFile(TEXTURE_NATURE[i].txt, NULL);
    for (int i = 0; i < ROCKS; i++)
        tab_txt_rocks[i] = sfTexture_createFromFile(TEXTURE_ROCKS[i].txt, NULL);
    for (int i = 0; i < WOODEN; i++)
        tab_text_wooden[i] =
        sfTexture_createFromFile(TEXTURE_WOODEN[i].txt, NULL);
}
