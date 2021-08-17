/*
** EPITECH PROJECT, 2020
** struct
** File description:
** yes
*/

#ifndef STRUCT_H
#define STRUCT_H

typedef struct game {
    sfRenderWindow *window;
    sfView *view;
    sfVector2f pos_screen;
    sfTexture *bg_tx;
    sfSprite *bg_sp;
    sfVector2f blockpos;
} game_m;

#endif /* STRUCT_H */
