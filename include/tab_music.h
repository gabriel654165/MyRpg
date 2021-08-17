/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** music tab
*/

#include "graphic.h"

typedef struct music
{
    char *pathfile;
    sfBool loop;
} music_t;

static const music_t tab_zik[] =
{
    {"music/menu.ogg", sfTrue},
    {"music/forest_amb.ogg", sfTrue},
    {"music/death_music.ogg", sfTrue},
    {NULL, sfFalse}
};

typedef enum zik
{
    MMENU,
    FOREST,
    MDEATH
} zik_t;

static const music_t tab_snd[] =
{
    {"music/footstep.ogg", sfFalse},
    {"music/sword.ogg", sfFalse},
    {"music/wind_effect.ogg", sfFalse},
    {"music/dragon_death.ogg", sfFalse},
    {"music/open_inventory.ogg", sfFalse},
    {NULL, sfFalse}
};

typedef enum snd
{
    MFOOTSTP,
    MSWORD,
    MWIND,
    MDRAGON,
    MOPEN
} snd_t;
