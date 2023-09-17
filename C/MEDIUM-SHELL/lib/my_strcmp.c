/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** my_strcmp
*/

#include "../include/mysh.h"

int my_strcmp(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    while ((s1[i] == s2[i]) && s1[i] != '\0' && s2[i] != '\0')
        i += 1;
    for (; s1[j] != '\0'; j += 1);
    if (j == i)
        return 0;
    else
        return 1;
    return 0;
}

int my_strcmp_2(char *str1, char *str2)
{
    if (str1[0] == '\0')
        return (1);
    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i] != str2[i])
            return (1);
    }
    return (0);
}
