/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** fprintf
*/

#ifndef FPRINTF_H_
#define FPRINTF_H_

#include <ncurses.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>

typedef struct norm {
    int nbr;
    int i;
    char *fmt;
    char *flag;
}bases;

typedef struct {
    void (*tpf)(char *, FILE *);
    char flag;
}tabpfchar_s;

typedef struct {
    void (*tpf)(char, FILE *);
    char flag;
}tabpfchar;

typedef struct {
    void (*tpf)(int, FILE *);
    char flag;
}tabpfint;

typedef struct {
    void (*tpf)(unsigned int, FILE *);
    char flag;
}tabpfu_int;

typedef struct {
    void (*tpf)(bases *, FILE *);
    char flag;
}tabpfbases;

int my_fprintf(char *right, char *path, char *fmt, ...);
void fwriting(bases *use, va_list ap, int k, FILE *fp);
void fascii(char *str, FILE *fp);
void my_fputstr(char *str, FILE *fp);
void my_fputchar(char c, FILE *fp);
void my_fputnbr_unsigned(unsigned int nbr, FILE *fp);
void fbase01(int nbr, FILE *fp);
void fbasehex(int nbr, FILE *fp);
void fbaseoct(int nbr, FILE *fp);
void fflag_p(int nbr, FILE *fp);
void fpercent_percent(bases *use, FILE *fp);
void my_fputnbr(int nbr, FILE *fp);
void fbasehex_maj(int nbr, FILE *fp);
int my_strlen(char const *str);
int which_flag(char fmt, bases *use);
int is_it_a_flag(char f, bases *use, char *fmt);
int compteur_percent(bases *use);

static const tabpfchar_s tabcs[] = {
    {my_fputstr, 's'},
    {fascii, 'S'},
    {NULL, 'n'},
};

static const tabpfchar tabc[] = {
    {my_fputchar, 'c'},
    {NULL, 'n'},
};

static const tabpfint tabi[] = {
    {my_fputnbr, 'd'},
    {my_fputnbr, 'i'},
    {fbaseoct, 'o'},
    {fbasehex, 'x'},
    {fbasehex_maj, 'X'},
    {fbase01, 'b'},
    {fflag_p, 'p'},
    {NULL, 'n'},
};

static const tabpfu_int tabu[] = {
    {my_fputnbr_unsigned, 'u'},
    {NULL, 'n'},
};

static const tabpfbases tabb[] = {
    {fpercent_percent, '%'},
    {NULL, 'n'},
};

#endif /* !FPRINTF_H_ */