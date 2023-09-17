/*
** EPITECH PROJECT, 2022
** utils
** File description:
** utils
*/

#include "../include/mysh.h"

int count_bin(char **env)
{
    int a = 0;
    int count = 0;

    while (env[4][a] != '\0') {
        if (env[4][a] == ':')
            count++;
        a++;
    }
    return count + 1;
}
