/*
** EPITECH PROJECT, 2022
** my_putchar
** File description:
** my_putchar
*/

#include "../include/tetris.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}