/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** mysh
*/

#include "../include/mysh.h"

char *parse_buffer(char *buffer)
{
    char *tmp;
    buffer[my_strlen(buffer) - 1] = '\0';
    tmp = parse_space(buffer);
    return tmp;
}

char *parse_space(char *buffer)
{
    char *tmp = malloc(sizeof(char) * (my_strlen(buffer) + 1));
    int a = 0;
    int b = 0;
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\t')
            buffer[i] = ' ';
    }
    for (; buffer[a] == ' '; a++);
    for (; buffer[a] != '\0'; a++) {
        if (buffer[a] == ' ' && buffer[a - 1] == ' ')
            continue;
        tmp[b] = buffer[a];
        b++;
    }
    if (tmp[b - 1] == ' ')
        tmp[b - 1] = '\0';
    else
        tmp[b] = '\0';
    return tmp;
}
