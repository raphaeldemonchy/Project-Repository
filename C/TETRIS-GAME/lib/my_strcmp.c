/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** xxxxxxx
*/

#include "../include/tetris.h"

int my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0; s1[i] != '\0' || s2[i] != '\0'; i++) {
        if (s1[i] > s2[i])
            return (1);
        else if (s1[i] < s2[i])
            return (-1);
    }
    return (0);
}