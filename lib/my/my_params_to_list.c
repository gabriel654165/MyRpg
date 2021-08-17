/*
** EPITECH PROJECT, 2019
** my_params_to_list
** File description:
** create a new list from the command line argument
*/
#include "my.h"

linked *add_list(long long int data, linked *list)
{
    linked *first_case;

    first_case = malloc(sizeof(linked));
    first_case -> data = data;
    first_case -> next = list;
    return (first_case);
}

linked *my_create_list(void)
{
    linked *list;

    list = NULL;
    return (list);
}

linked *my_params_to_list(int ac, char **av)
{
    int cmp = 0;
    linked *list;

    list = NULL;
    cmp = ac-1;
    while (cmp != 0) {
        list = add_list(my_getnbr(av[cmp]), list);
        cmp--;
    }
    return (list);
}
