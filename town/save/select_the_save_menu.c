/*
** EPITECH PROJECT, 2020
** select_the_save_menu
** File description:
** yes
*/

#include "town.h"

int display_menu_save_slot2(main_town_t *town)
{
    if ((save_tab[SAVE] == 1 || save_tab[START] == 1)
        && save_tab[SAVE_SLOT_THREE] == 1 && save_tab[OPEN_MENU_SAVE] == 1) {
        draw_menu_text(town, "~SAVE~", (sfVector2f){35, 120}, 50);
        draw_menu_text(town, "slot1", (sfVector2f){0, 0}, 40);
        draw_menu_text(town, "slot2", (sfVector2f){0, -120}, 40);
        draw_menu_text(town, "~slot3~", (sfVector2f){0, -240}, 40);
        draw_menu_text(town, "Back", (sfVector2f){5, -400}, 40);
        return 1;
    }
    if (display_menu_save_slot3(town) == 1)
        return 1;
    return 0;
}

int display_menu_save_slot1(main_town_t *town)
{
    if ((save_tab[SAVE] == 1 || save_tab[START] == 1)
        && save_tab[SAVE_SLOT_TWO] == 1 && save_tab[OPEN_MENU_SAVE] == 1) {
        draw_menu_text(town, "~SAVE~", (sfVector2f){35, 120}, 50);
        draw_menu_text(town, "slot1", (sfVector2f){0, 0}, 40);
        draw_menu_text(town, "~slot2~", (sfVector2f){0, -120}, 40);
        draw_menu_text(town, "slot3", (sfVector2f){0, -240}, 40);
        draw_menu_text(town, "Back", (sfVector2f){5, -400}, 40);
        return 1;
    }
    if (display_menu_save_slot2(town) == 1)
        return 1;
    return 0;
}

int display_menu_save_slot(main_town_t *town)
{
    if ((save_tab[SAVE] == 1 || save_tab[START] == 1)
        && save_tab[SAVE_SLOT_ONE] == 1 && save_tab[OPEN_MENU_SAVE] == 1) {
        draw_menu_text(town, "~SAVE~", (sfVector2f){35, 120}, 50);
        draw_menu_text(town, "~slot1~", (sfVector2f){0, 0}, 40);
        draw_menu_text(town, "slot2", (sfVector2f){0, -120}, 40);
        draw_menu_text(town, "slot3", (sfVector2f){0, -240}, 40);
        draw_menu_text(town, "Back", (sfVector2f){5, -400}, 40);
        return 1;
    }
    if (display_menu_save_slot1(town) == 1)
        return 1;
    return 0;
}

void exit_select(main_town_t *town)
{
    if (save_tab[OPEN_MENU_SAVE] == 1 && save_tab[EXIT] == 1) {
        draw_menu_text(town, " SAVE", (sfVector2f){35, 120}, 50);
        draw_menu_text(town, " LOAD", (sfVector2f){35, 0}, 50);
        draw_menu_text(town, "~EXIT~", (sfVector2f){35, -400}, 50);
        draw_menu_text(town, " game", (sfVector2f){0, -500}, 30);
    }
}

void display_menu_save(main_town_t *town)
{
    if (save_tab[OPEN_MENU_SAVE] == 1)
        draw_menu_bg(town, BG_OPACITY);
    if (display_menu_save_slot(town) == 1)
        return;
    if (save_tab[OPEN_MENU_SAVE] == 1
        && (save_tab[START] == 1 || save_tab[SAVE] == 1)) {
        draw_menu_text(town, "~SAVE~", (sfVector2f){35, 120}, 50);
        draw_menu_text(town, " LOAD", (sfVector2f){35, 0}, 50);
        draw_menu_text(town, " EXIT", (sfVector2f){35, -300}, 50);
    }
    if (save_tab[OPEN_MENU_SAVE] == 1 && save_tab[LOAD] == 1) {
        draw_menu_text(town, " SAVE", (sfVector2f){35, 120}, 50);
        draw_menu_text(town, "~LOAD~", (sfVector2f){35, 0}, 50);
        draw_menu_text(town, " EXIT ", (sfVector2f){35, -300}, 50);
    }
    exit_select(town);
}
