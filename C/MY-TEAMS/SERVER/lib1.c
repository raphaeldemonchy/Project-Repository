/*
** EPITECH PROJECT, 2022
** Sans titre(Espace de travail)
** File description:
** lib1.c
*/

#include "server.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
}

int my_strlen(char *str)
{
    int i = 0;
    for (; str[i] != '\0'; i++);
    return i;
}

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    for (; dest[i] != '\0'; i++);
    for (int j = 0; src[j] != '\0'; j++, i++)
        dest[i] = src[j];
    return dest;
}

char **arg_array(char **arg, char *buffer)
{
    int x = 0, y = 0, lenline = 0, lenTab = 0;
    arg[y] = malloc(sizeof(char) * 1000);
    for (int i = 0; buffer[i] != '\0'; i++, x++) {
        if (buffer[i] == '|') {
            arg[y][x] = '\0', x = 0,lenline = 0, y++;
            arg[y] = malloc(sizeof(char)* 1000);
            i++;
        }
        arg[y][x] = buffer[i];
    }
    arg[y][x] = '\0';
    return arg;
}
