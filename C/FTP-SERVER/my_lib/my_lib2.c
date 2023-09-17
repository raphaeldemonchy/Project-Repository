/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** lib2
*/

#include "../serveur/include/serveur.h"

void my_swap(char *a, char *b)
{
    char c;
    c = *a;
    *a = *b;
    *b = c;
}

char *my_revstr(char *str)
{
    int end = (strlen(str) - 1);
    int first = 0;
    while (first < end) {
        my_swap(&str[first], &str[end]);
        first++;
        end--;
    }
    return str;
}

char *my_strdup(char *src)
{
    char *tmp = malloc(sizeof(char) * strlen(src));
    for (int i = 0; src[i] != '\0'; i++)
        tmp[i] = src[i];
    return tmp;
}
