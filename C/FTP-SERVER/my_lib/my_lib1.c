/*
** EPITECH PROJECT, 2023
** my_lib2
** File description:
** my_lib1
*/

#include "../serveur/include/serveur.h"

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
