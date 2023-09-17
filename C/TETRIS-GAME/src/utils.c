/*
** EPITECH PROJECT, 2022
** utils
** File description:
** utils
*/

#include "../include/tetris.h"

char *my_itoa(int nb)
{
    if (nb == 0)
        return "0\0";
    int size = 0;
    char *nb_in_str = NULL;
    int tmp = nb;
    while (tmp > 0) {
        tmp /= 10;
        size++;
    }
    nb_in_str = malloc(sizeof(char) * (size + 1));
    nb_in_str[size] = '\0';
    while (size--) {
        nb_in_str[size] = nb % 10  + '0';
        nb /= 10;
    }
    return nb_in_str;
}

void disp_int(int x, int y, WINDOW *ginfo, int info)
{
    char *i = my_itoa(info);
    for (int a = 0; i[a]; a++)
        mvwaddch(ginfo, y, x + a, i[a]);
}

void disp_text(int x, int y, WINDOW *ginfo, char *info)
{
    int a = 0;
    while (info[a]) {
        mvwaddch(ginfo, y, x + a, info[a]);
        a++;
    }
    a = 0;
}

void disp_map(WINDOW *w, char **tab)
{
    int i = 0;
    while (tab[i] != NULL) {
        mvwprintw(w, LINES / 2 - my_arrlen(tab) / 2 + i,
        COLS / 2 - my_strlen(tab[i]) / 2, tab[i]);
        curs_set(0);
        i += 1;
    }
}

int my_arrlen(char **arr)
{
    int i = 0;
    while (arr[i] != NULL)
        i += 1;
    return (i);
}

    // if (g_info->game_x <= g_info->win_x || g_info->game_y <= g_info->win_y) {
    //     endwin();
    //     my_putstr("𝐑𝐞𝐬𝐢𝐳𝐞 𝐲𝐨𝐮𝐫 𝐓𝐞𝐫𝐦𝐢𝐧𝐚𝐥 🡹\n");
    //     g_info->pause = 1;
    //     return (0);
    // }