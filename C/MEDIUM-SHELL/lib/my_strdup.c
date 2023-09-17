/*
** EPITECH PROJECT, 2022
** my_strdup
** File description:
** my_strdup
*/

#include "../include/mysh.h"

char *my_strdup2(char *str)
{
    int i = 0;
    for (; str[i]; i += 1);
    char *temp = malloc(sizeof(char) * i + 1);
    for (int i = 0; str[i]; i += 1)
        temp[i] = str[i];
    temp[i] = '\0';
    return temp;
}

char *my_strdup3(char *str, int a)
{
    int i = 0;
    int j = a;
    for (; str[i]; i += 1);
    char *temp = malloc(sizeof(char) * i + 1);
    for (int i = 0; str[j]; i += 1, j += 1)
        temp[i] = str[j];
    temp[i] = '\0';
    return temp;
}

char *my_strdup(char *str)
{
    int a = 0;
    int b = 0;
    while (str[a]) {
        a++;
    }
    char *tmp = (char *)malloc(sizeof(char));
    while (str[b]) {
        tmp[b] = str[b];
        b++;
    }
    tmp[a] = '\0';
    return tmp;
}
