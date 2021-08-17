/*
** EPITECH PROJECT, 2020
** monster_stats
** File description:
** yes
*/

#include "town.h"
#define VIEW_ROLEBACK 150
#include "tab_music.h"

void hurt_reloback1(main_town_t *town)
{
    if (stat_tab[LAST_ACTION] == 1 && collision_tab[LEFT] == 0) {
        town->p.pos_screen.x = 0;
        town->p.pos_screen.y = 0;
        town->p.pos_screen.x -= VIEW_ROLEBACK;
        town->p.value_view.x -= VIEW_ROLEBACK;
    }
    if (stat_tab[LAST_ACTION] == 2 && collision_tab[RIGHT] == 0) {
        town->p.pos_screen.x = 0;
        town->p.pos_screen.y = 0;
        town->p.pos_screen.x += VIEW_ROLEBACK;
        town->p.value_view.x += VIEW_ROLEBACK;
    }
}

void hurt_reloback2(main_town_t *town)
{
    if (stat_tab[LAST_ACTION] == 3 && collision_tab[UP] == 0) {
        town->p.pos_screen.x = 0;
        town->p.pos_screen.y = 0;
        town->p.pos_screen.y -= VIEW_ROLEBACK;
        town->p.value_view.y -= VIEW_ROLEBACK;
    }
    if (stat_tab[LAST_ACTION] == 4 && collision_tab[DOWN] == 0) {
        town->p.pos_screen.x = 0;
        town->p.pos_screen.y = 0;
        town->p.pos_screen.y += VIEW_ROLEBACK;
        town->p.value_view.y += VIEW_ROLEBACK;
    }
}

char **monster_state(map_t *monster, main_town_t *town, int i, char **tab_pars)
{
    static int state = 0;
    int drop = 0;

    if (monster->life <= 0 && state == 0) {
        sfSound_play(town->music.snd[MDRAGON]);
        monster->live = 0;
        monster->life = monster->life_save;
        stat_tab[XP_BAR] += monster->xp_gain;
        tab_pars = actualise_monster(*monster, i, tab_pars);
        while (++drop < 5)
            put_obj_in_inventory(town, 6, 1);
        state = 1;
    }
    if (monster->live == 0 && state == 1)
        state = get_random_coor(monster);
    return tab_pars;
}

void monster_hurt_actions(map_t *monster, main_town_t *town)
{
    if (int_tab[INVENTORY] != 1
    && int_tab[OPEN_MENU_QUEST] != 1
    && save_tab[OPEN_MENU_SAVE] != 1) {
        stat_tab[LIFE] -= monster->attack + stat_tab[SHIELD];
        hurt_reloback1(town);
        hurt_reloback2(town);
        sfView_move(town->p.view, (sfVector2f){town->p.pos_screen.x *
        town->size.size.x, town->p.pos_screen.y *
        town->size.size.y});
    }
}

void monster_get_hurt_actions(map_t *monster)
{
    static int action = 0;

    if (stat_tab[ATTACK] == 1 && action == 0) {
        monster->life -= stat_tab[DMG];
        action = 1;
    } else if (stat_tab[ATTACK] == 0)
        action = 0;
}
