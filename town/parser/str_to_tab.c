/*
** EPITECH PROJECT, 2020
** str_to_tab
** File description:
** parse_by_\n
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int get_nbr_return(char *str)
{
    int nbr_return = 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\n' && str[i - 1] != '\n')
            nbr_return++;
    return nbr_return;
}

char *get_line(char *str)
{
    char *tmp = str;
    char *fin = NULL;
    int i = 0;
    int j = 0;
    while (*tmp && *tmp != '\n')
        tmp++;
    i = tmp - str;
    fin = malloc(sizeof(char) * (i + 1));
    if (fin == NULL)
        return NULL;
    for (j = 0; j < i; j++) {
        fin[j] = *str;
        str++;
    }
    fin[j] = '\0';
    return fin;
}

char **put_line_in_tab(char **tab, char *str)
{
    int j = 0;
    for (; str && *str; j++) {
        while ((*str && *str == ' ') || *str == '\t'
        || *str == '\n')
            str++;
        tab[j] = get_line(str);
        if (tab[j] == NULL)
            return NULL;
        while (str && *str && *str != '\n')
            str++;
        while ((*str && *str == ' ') || *str == '\t'
        || *str == '\n')
            str++;
    }
    tab[j] = NULL;
    return tab;
}

char **str_to_tab(char *str)
{
    char **tab = NULL;
    int nbr_return = get_nbr_return(str);
    if ((tab = malloc(sizeof(char *) * (nbr_return + 2)))
        == NULL || (tab = put_line_in_tab(tab, str)) == NULL)
        return NULL;
    return tab;
}
