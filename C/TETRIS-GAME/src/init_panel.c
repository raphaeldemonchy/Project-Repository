/*
** EPITECH PROJECT, 2022
** init_panel
** File description:
** init_panel
*/

#include "../include/tetris.h"

link_t *init_game(link_t *link, g_info *g_info)
{
    link = charge_link_tetriminos(link);
    bool error = error;
    link_t *tmp = link;
    while (tmp) {
        if (my_strcmp(tmp->file, "error") != 0)
            error = true;
        tmp = tmp->next;
    }
    free(tmp);
    if (error == false)
        return NULL;
    return link;
}