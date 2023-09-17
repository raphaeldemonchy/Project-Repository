/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** xxxxxxx
*/

#include "../include/tetris.h"

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i += 1;
    return (i);
}
