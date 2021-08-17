/*
** EPITECH PROJECT, 2020
** capacities
** File description:
** yes
*/

#include "town.h"

void increase_capacities(void)
{
    if (stat_tab[XP_LVL] >= 2) {
        stat_tab[SHIELD] = 10;
        stat_tab[DMG] = 40;
    }
    if (stat_tab[XP_LVL] >= 7) {
        stat_tab[SHIELD] = 20;
        stat_tab[DMG] = 50;
    }
    if (stat_tab[XP_LVL] >= 7) {
        stat_tab[SHIELD] = 40;
        stat_tab[DMG] = 58;
    }
}
