/*
** EPITECH PROJECT, 2021
** my_str_to_wrdo_array
** File description:
** str to tab
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "../include/mysh.h"

int count_words(char *str, char end)
{
    int nb = 0;
    int a = 0;

    while (str[a]) {
        if (str[a] == end && str[a + 1])
            nb++;
        a++;
    }
    nb++;
    return (nb);
}

int word_len(char *str, char end)
{
    int a = 0;

    for (; str[a] && str[a] != end; a++);
    return (a);
}

char **my_str_to_word_custom(char *str, char end)
{
    char **tab;
    l_list li = {0, 0, 0};

    tab = malloc(sizeof(char *) * (count_words(str, end)) + 1);
    while (str[li.x]) {
        if (str[li.x] == end) {
            while (str[li.x] == end)
                li.x++;
            li.y++;
            li.col = 0;
        }
        tab[li.y] = malloc(sizeof(char) * word_len(str + li.x, end) + 1);
        while (str[li.x] != end && str[li.x])
            tab[li.y][li.col++] = str[li.x++];
        tab[li.y][li.col] = 0;
    }
    tab[li.y + 1] = 0;
    return (tab);
}

char **my_str_to_word_v2(char *str, char end)
{
    char **tab;
    l_list li = {5, 0, 0};

    tab = malloc(sizeof(char *) * (count_words(str, end)) + 1);
    while (str[li.x]) {
        if (str[li.x] == end) {
            while (str[li.x] == end)
                li.x++;
            li.y++;
            li.col = 0;
        }
        tab[li.y] = malloc(sizeof(char) * word_len(str + li.x, end) + 1);
        while (str[li.x] != end && str[li.x])
            tab[li.y][li.col++] = str[li.x++];
        tab[li.y][li.col] = 0;
    }
    tab[li.y + 1] = 0;
    return (tab);
}
