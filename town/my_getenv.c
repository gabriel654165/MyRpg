/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** getenv
*/

#include "../include/my.h"
#include "../include/game.h"

static int search_name_env(char *name, char *str_to_find)
{
    for (int i = 0; str_to_find[i] != '\0'; ++i)
        if (name[i] != str_to_find[i])
            return (0);
    return (1);
}

static char *find_elem(char *nenv, char *elem)
{
    if (search_name_env(nenv, elem) == 1) {
        return (nenv);
    } else
        return (NULL);
}

char *my_getenv(char **nenv, char *elem)
{
    char *path = NULL;

    for (int i = 0; nenv[i] != NULL; ++i) {
        path = find_elem(nenv[i], elem);
        if (path != NULL)
            break;
    }
    return (path);
}

int error_env(char **env)
{
    if (env == NULL || my_getenv(env, "DISPLAY") == NULL)
        return (84);
    return (0);
}
