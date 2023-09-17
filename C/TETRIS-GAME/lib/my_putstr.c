/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** xxxxxx
*/

#include "../include/tetris.h"

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}