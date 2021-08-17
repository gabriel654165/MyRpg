/*
** EPITECH PROJECT, 2020
** display_with_chrono
** File description:
** display_with_chrono
*/

#include "town.h"

char *get_the_str(int i, int lock, char **tab, int dialogue)
{
    int j;
    char *str = NULL;
    str = malloc(sizeof(char) * (i + 1));
    for (j = 0; j < i; j++) {
        if (lock == 0 && tab[dialogue][j] != 0)
            str[j] = tab[dialogue][j];
        else if (lock == 1 && tab[dialogue + 1][j] != 0)
            str[j] = tab[dialogue + 1][j];
    }
    str[j] = 0;
    return str;
}

int clock_write_dialogue(int i)
{
    sfTime time = sfClock_getElapsedTime(tab_clock[WRITE_DIALOGUE]);
    float seconds = sfTime_asSeconds(time);
    if (seconds > 0.05) {
        i++;
        sfClock_restart(tab_clock[WRITE_DIALOGUE]);
    }
    return i;
}

sfText *draw_lock_0(char *str, main_town_t *town, int pos)
{
    sfText *text = text_tab[DIALOGUE];
    sfText_setCharacterSize(text, 30);
    sfVector2f coor;
    coor.x = town->p.value_middle.x - town->size.size_screen.x / 4
        + 50 * town->size.size.x;
    coor.y = town->p.value_middle.y + town->size.size_screen.y / 2
        - 145 * town->size.size.y;
    if (pos == 1)
        sfText_setPosition(text, coor);
    if (pos == 2)
        sfText_setPosition(text,
        (sfVector2f){coor.x, coor.y + 60 * town->size.size.y});
    sfText_setString(text, str);
    sfText_setFillColor(text, (sfColor){1, 1, 1, 255});
    sfText_setScale(text, town->size.size);
    sfText_setFont(text, tab_font[FONT_1]);
    return text;
}

sfText *draw_lock_1(char **tab, main_town_t *town, int dialogue)
{
    sfText *text = text_tab[DIALOGUE];
    sfVector2f coor;
    coor.x = town->p.value_middle.x - town->size.size_screen.x / 4
        + 50 * town->size.size.x;
    coor.y = town->p.value_middle.y + town->size.size_screen.y / 2
        - 145 * town->size.size.y;
    sfText_setCharacterSize(text, 30);
    sfText_setPosition(text, coor);
    sfText_setFillColor(text, (sfColor){1, 1, 1, 255});
    sfText_setScale(text, town->size.size);
    sfText_setFont(text, tab_font[FONT_1]);
    sfText_setString(text, tab[dialogue]);
    return text;
}

void beautiful_display(char **tab, quest_t quest, int dialogue,
    main_town_t *town)
{
    static int i = 1;
    static int lock = 0;
    block_the_player(1);
    dialogue += quest.first_line;
    i = dialogue_begin(i, dialogue);
    char *str = get_the_str(i, lock, tab, dialogue);
    if (lock == 0) {
        norme_for_dialogue2(town, str);
        if (tab[dialogue][i] != 0)
            i = clock_write_dialogue(i);
    }
    else {
        norme_for_dialogue(town, tab, dialogue, str);
        if (tab[dialogue + 1][i] != 0)
            i = clock_write_dialogue(i);
    }
    if (i == my_strlen(tab[dialogue]) && lock == 0) {
        i = 1;
        lock = 1;
    }
}
