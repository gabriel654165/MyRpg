/*
** EPITECH PROJECT, 2020
** my_str_to_tab
** File description:
** my_str_to_tab
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int get_nbr_word(char *str)
{
    int nb_word = 0;
    while (str && *str) {
        while ((*str && *str == ' ') || *str == '\t')
            str++;
        while ((*str && *str != ' ') && *str != '\t') {
            str++;
            if (*str == ' ' || *str == '\0' || *str == '\t')
                nb_word++;
        }
        while ((*str && *str == ' ') || *str == '\t')
            str++;
    }
    return nb_word;
}

char *get_word(char *str)
{
    char *tmp = str;
    char *fin = NULL;
    int i = 0;
    int j = 0;
    while (*tmp && *tmp != ' ' && *tmp != '\t')
        tmp++;
    i = tmp - str;
    fin = malloc(sizeof(char) * (i + 1));
    if (fin == NULL) {
        write(2, "erreur_de_malloc : my_str_towordtab\n", 36);
        exit(84);
    }
    while (j < i) {
        fin[j] = *str;
        str++;
        j++;
    }
    fin[j] = '\0';
    return fin;
}

char **put_word_in_tab(char **tab, char *str)
{
    int j = 0;
    while (str && *str) {
        while ((*str && *str == ' ') || *str == '\t')
            str++;
        if ((tab[j++] = get_word(str)) == NULL)
            return NULL;
        while ((*str && *str != ' ') && *str != '\t')
            str++;
        while ((*str && *str == ' ') || *str == '\t')
            str++;
    }
    return tab;
}

char **my_str_to_wordtab(char *str)
{
    char **tab = NULL;
    int nbr_word;
    nbr_word = get_nbr_word(str);
    if ((tab = malloc(sizeof(char*) * (nbr_word + 1)))
        == NULL || (tab = put_word_in_tab(tab, str)) ==
        NULL) {
        write(2, "erreur_de_malloc : my_str_towordtab\n", 36);
        exit(84);
    }
    tab[nbr_word] = NULL;
    return tab;
}
