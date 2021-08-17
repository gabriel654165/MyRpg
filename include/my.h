/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

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

typedef struct list_t
{
    long long int data;
    struct list_t *next;
}linked;

typedef struct norm {
    int nbr;
    int i;
    char *fmt;
    char *flag;
}bases;

typedef struct {
    void (*tpf)(char *);
    char flag;
}tabpfchar_s;

typedef struct {
    void (*tpf)(char);
    char flag;
}tabpfchar;

typedef struct {
    void (*tpf)(int);
    char flag;
}tabpfint;

typedef struct {
    void (*tpf)(unsigned int);
    char flag;
}tabpfu_int;

typedef struct {
    void (*tpf)(bases *);
    char flag;
}tabpfbases;

char *free_the_str(char *str);
char *my_int_to_str(int nbr);
int my_compute_power_rec(int nb, int p);
char **my_tabcpy_malloc(char **tab);
int my_tab_len(char **tab);
int **free_the_int_tab(int **tab, int len);
char **free_the_tab(char **tab);
char *my_strcpy_malloc(char *str);
char **my_str_to_wordtab(char *str);
int my_strlen(char const *str);
void my_putstr(char *str);
void my_putchar(char c);
void my_swap(char *a, char *b);
int my_str_isnum(char const *str);
int my_getnbr(char const *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strdup(char const *src);
void my_putnbr(int nbr);
char *my_strcpy(char *dest, char const *src);
linked *my_params_to_list(int ac, char **av);
linked *my_create_list();
int *my_strcat_int(int *dest, int const *src, int size_dest, int size_src);
void print_link(linked *head);
linked *add_list(long long int data, linked *list);
int count_link(linked *head);
linked *remove_link(int num, linked *head);
void convert_in_bit(char const *str);
char **my_str_to_wordarray(char *str);
int nbr_of_string(char *str);
int len_words(char *str);
int my_putnbr_base(int nbr, char const *base);
void base01(int nbr);
void basehex_maj(int nbr);
void basehex(int nbr);
void baseoct(int nbr);
void flag_p(int nbr);
void my_putnbr_unsigned(unsigned int nbr);
int pointeur(char *str);
void ascii(char *str);
void percent_percent(bases *use);
int my_printf(char *fmt, ...);
int is_it_a_flag(char f, bases *use, char *fmt);
int which_flag(char fmt, bases *use);
void writing(bases *use, va_list ap, int k);
void writing2(va_list ap, int k);
char *my_realloc(char *str, int size);
int my_fprintf(char *path, char *fmt, ...);
char *my_revstr(char *str);
char *my_itoa(int o);
char *my_ftoa(float nbr);
int my_intlen(int o);
char *str_concat(char *temp, char *str, char c);
int my_strlen(char const *str);
float my_getnbr_float(char *str);
char *my_strcat_parser(char *dest, char *src);
char *free_the_str(char *str);

static const tabpfchar_s tabcs[] = {
    {my_putstr, 's'},
    {ascii, 'S'},
    {NULL, 'n'},
};

static const tabpfchar tabc[] = {
    {my_putchar, 'c'},
    {NULL, 'n'},
};

static const tabpfint tabi[] = {
    {my_putnbr, 'd'},
    {my_putnbr, 'i'},
    {baseoct, 'o'},
    {basehex, 'x'},
    {basehex_maj, 'X'},
    {base01, 'b'},
    {flag_p, 'p'},
    {NULL, 'n'},
};

static const tabpfu_int tabu[] = {
    {my_putnbr_unsigned, 'u'},
    {NULL, 'n'},
};

static const tabpfbases tabb[] = {
    {percent_percent, '%'},
    {NULL, 'n'},
};

#endif /* !MY_H_ */
