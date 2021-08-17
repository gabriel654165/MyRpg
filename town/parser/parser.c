/*
** EPITECH PROJECT, 2020
** parser
** File description:
** parser
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../../include/my.h"

char *get_the_buff(char *str)
{
    FILE *yes = fopen(str, "r");
    char const *fp = str;
    int fs = open(fp, O_RDONLY);
    size_t len = 0;
    char *line = 0;
    ssize_t rd = 0;
    ssize_t le = 0;

    while ((rd = getline(&line, &len, yes)) != -1)
        le += rd;
    char *buff = malloc(sizeof(char) * (le + 1));
    int fp_fs = read(fs, buff, le);
    buff[fp_fs] = '\0';
    return buff;
}
