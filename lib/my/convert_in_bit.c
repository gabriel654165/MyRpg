/*
** EPITECH PROJECT, 2019
** convert
** File description:
** in bit
*/
#include "my.h"

void convert_in_bit(char const *str)
{
    int num = my_getnbr(str);
    int i;

    for ( i = (sizeof(int) * 8) - 1; i >= 0; i--){
        char c = (num &(1 << i))? '1' : '0';
        my_putchar(c);
    }
    my_putchar('\n');
}
