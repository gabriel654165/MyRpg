/*
** EPITECH PROJECT, 2020
** select_the_save_menu2
** File description:
** yes
*/

#include "town.h"

int display_menu_save_slot7(main_town_t *town)
{
    if (save_tab[LOAD] == 1 && save_tab[BACK_LOAD] == 1) {
        draw_menu_text(town, "~LOAD~", (sfVector2f){35, 120}, 50);
        draw_menu_text(town, "slot1", (sfVector2f){0, 0}, 40);
        draw_menu_text(town, "slot2", (sfVector2f){0, -120}, 40);
        draw_menu_text(town, "slot3", (sfVector2f){0, -240}, 40);
        draw_menu_text(town, "~Back~", (sfVector2f){5, -400}, 40);
        return 1;
    }
    return 0;
}

int display_menu_save_slot6(main_town_t *town)
{
    if ((save_tab[SAVE] == 1 || save_tab[START] == 1)
    && save_tab[BACK_SAVE] == 1) {
        draw_menu_text(town, "~SAVE~", (sfVector2f){35, 120}, 50);
        draw_menu_text(town, "slot1", (sfVector2f){0, 0}, 40);
        draw_menu_text(town, "slot2", (sfVector2f){0, -120}, 40);
        draw_menu_text(town, "slot3", (sfVector2f){0, -240}, 40);
        draw_menu_text(town, "~Back~", (sfVector2f){5, -400}, 40);
        return 1;
    }
    if (display_menu_save_slot7(town) == 1)
        return 1;
    return 0;
}

int display_menu_save_slot5(main_town_t *town)
{
    if (save_tab[LOAD] == 1 && save_tab[LOAD_SLOT_THREE] == 1
    && save_tab[OPEN_MENU_SAVE] == 1) {
        draw_menu_text(town, "~LOAD~", (sfVector2f){35, 120}, 50);
        draw_menu_text(town, "slot1", (sfVector2f){0, 0}, 40);
        draw_menu_text(town, "slot2", (sfVector2f){0, -120}, 40);
        draw_menu_text(town, "~slot3~", (sfVector2f){0, -240}, 40);
        draw_menu_text(town, "Back", (sfVector2f){5, -400}, 40);
        return 1;
    }
    if (display_menu_save_slot6(town) == 1)
        return 1;
    return 0;
}

int display_menu_save_slot4(main_town_t *town)
{
    if (save_tab[LOAD] == 1 && save_tab[LOAD_SLOT_TWO] == 1
    && save_tab[OPEN_MENU_SAVE] == 1) {
        draw_menu_text(town, "~LOAD~", (sfVector2f){35, 120}, 50);
        draw_menu_text(town, "slot1", (sfVector2f){0, 0}, 40);
        draw_menu_text(town, "~slot2~", (sfVector2f){0, -120}, 40);
        draw_menu_text(town, "slot3", (sfVector2f){0, -240}, 40);
        draw_menu_text(town, "Back", (sfVector2f){5, -400}, 40);
        return 1;
    }
    if (display_menu_save_slot5(town) == 1)
        return 1;
    return 0;
}

int display_menu_save_slot3(main_town_t *town)
{
    if (save_tab[LOAD] == 1 && save_tab[LOAD_SLOT_ONE] == 1
    && save_tab[OPEN_MENU_SAVE] == 1) {
        draw_menu_text(town, "~LOAD~", (sfVector2f){35, 120}, 50);
        draw_menu_text(town, "~slot1~", (sfVector2f){0, 0}, 40);
        draw_menu_text(town, "slot2", (sfVector2f){0, -120}, 40);
        draw_menu_text(town, "slot3", (sfVector2f){0, -240}, 40);
        draw_menu_text(town, "Back", (sfVector2f){5, -400}, 40);
        return 1;
    }
    if (display_menu_save_slot4(town) == 1)
        return 1;
    return 0;
}
