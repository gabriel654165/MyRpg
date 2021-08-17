/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** set music
*/

#include "town.h"
#include "tab_music.h"

void change_volume_zik(allsnd_t *music)
{
    for (int i = 0; tab_zik[i].pathfile != NULL; ++i)
        sfMusic_setVolume(music->zik[i], music->volume);
    for (int i = 0; tab_snd[i].pathfile != NULL; ++i)
    sfSound_setVolume(music->snd[i], music->volume);
}

void free_sound(allsnd_t *music)
{
    for (int i = 0; tab_zik[i].pathfile != NULL; ++i)
        sfMusic_destroy(music->zik[i]);
    for (int i = 0; tab_snd[i].pathfile != NULL; ++i) {
        sfSoundBuffer_destroy((sfSoundBuffer*)sfSound_getBuffer(music->snd[i]));
        sfSound_destroy(music->snd[i]);
    }
}

static sfMusic **set_zik(void)
{
    sfMusic **zik;
    int len = 0;

    for (; tab_zik[len].pathfile != NULL; ++len);
    zik = malloc(sizeof(sfMusic *) * len);
    for (int i = 0; tab_zik[i].pathfile != NULL; ++i) {
        zik[i] = sfMusic_createFromFile(tab_zik[i].pathfile);
        sfMusic_setLoop(zik[i], tab_zik[i].loop);
        sfMusic_setVolume(zik[i], 100);
    }
    return (zik);
}

static sfSound **set_snd(void)
{
    sfSound **snd;
    sfSoundBuffer *buffer;
    int len = 0;

    for (; tab_snd[len].pathfile != NULL; ++len);
    snd = malloc(sizeof(sfSound *) * len);
    for (int i = 0; tab_snd[i].pathfile != NULL; ++i) {
        snd[i] = sfSound_create();
        buffer = sfSoundBuffer_createFromFile(tab_snd[i].pathfile);
        sfSound_setBuffer(snd[i], buffer);
        sfSound_setLoop(snd[i], tab_snd[i].loop);
        sfSound_setVolume(snd[i], 100);
    }
    return (snd);
}

void set_the_music(allsnd_t *music)
{
    music->zik = set_zik();
    music->snd = set_snd();
    music->volume = 100;
}
