/*
** EPITECH PROJECT, 2022
** my_putchar
** File description:
** my_putchar
*/

#include "../include/mysh.h"
#include "unistd.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putchar_error(char c)
{
    write(2, &c, 1);
}
