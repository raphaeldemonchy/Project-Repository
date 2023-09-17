/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** my_strcat
*/

#include <stdlib.h>
#include "../include/mysh.h"

char *my_strcat(char *dest, char *src, char c)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char *res = malloc((my_strlen(dest) + my_strlen(src) + 1) * sizeof(char));

    for (; dest[i] != '\0'; i++)
        res[i] = dest[i];
    if (dest[my_strlen(dest)] != c && src[0] != c) {
        res[my_strlen(dest)] = c;
        k++;
    }
    while (src[j]) {
        res[i + j + k] = src[j];
        j++;
    }
    res[i + j + k] = '\0';
    return (res);
}

char *my_strcat2(char *dest, char const *src)
{
    int a = 0;
    int i = 0;
    char *stk = malloc(sizeof(char) * my_strlen(dest) + my_strlen(src) + 1);
    stk = my_strdup(dest);
    while (stk[a] != '\0')
        a = a + 1;
    while (src[i] != '\0') {
        dest[a + i] = src[i];
        i = i + 1;
    }
    dest[a + i] = '\0';
    return (dest);
}
