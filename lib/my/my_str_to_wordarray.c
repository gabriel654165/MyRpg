/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** my_str_to_wordarray
*/
#include "my.h"

int len_words(char *str)
{
    int cmp = 0;
    static int i = 0;

    for (; str[i]; i++) {
        if (str[i] == ' ') {
            i++;
            return (cmp);
        }
        if ((65 <= str[i] && str[i] <= 90)
        || (97 <= str[i] && str[i] <= 122))
            cmp++;
    }

    return (cmp);
}

int nbr_of_string(char *str)
{
    static int nbr = 0;
    int space = 0;
    int word = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ') {
            space++;
            nbr = 0;
        }
        else {
            if (nbr == 0) {
                word++;
                nbr++;
            }
        }
    }
    nbr = 0;
    return (word);
}

char **my_str_to_wordarray(char *str)
{
    int a = 0;
    int b = 0;
    int c = 0;
    int nbr_str = nbr_of_string(str);
    char **tab = malloc(sizeof(char *) * nbr_str);

    for (int i = 0; i != nbr_str; i++)
        tab[i] = malloc(sizeof(char) * (len_words(str) + 1));
    for (; str[b]; b++, c++) {
        tab[a][c] = str[b];
        if (str[b] == ' ') {
            tab[a][c] = '\0';
            a++;
            c = -1;
        }
    }
    return (tab);
}
