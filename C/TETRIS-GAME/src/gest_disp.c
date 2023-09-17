/*
** EPITECH PROJECT, 2022
** gest_disp
** File description:
** gest_disp
*/

#include "../include/tetris.h"

int disp_i_logo(struct g_info *g_info, WINDOW *i_logo)
{
    i_logo = subwin(stdscr, 4, 40, 0, 0);
    start_color();
    wbkgd(i_logo, COLOR_PAIR(4));
    disp_text(10, 1, i_logo, "|  T     T     I    |");
    disp_text(10, 2, i_logo, "|     E     R     S |");
    wborder(i_logo, ACS_CKBOARD, ACS_CKBOARD, ACS_CKBOARD, ACS_CKBOARD, ACS_CKBOARD, ACS_CKBOARD, ACS_CKBOARD, ACS_CKBOARD);
    wrefresh(i_logo);
    return 0;
}

int disp_i_ginfo(struct g_info *g_info, WINDOW *i_ginfo)
{
    i_ginfo = subwin(stdscr, 10, 40, 6, 0);
    start_color();
    wbkgd(i_ginfo, COLOR_PAIR(2));
    disp_text(10, 1, i_ginfo, "SCORE |-> ");
    disp_int(20, 1, i_ginfo, g_info->score);
    disp_text(10, 2, i_ginfo, "Lvl   |->");
    disp_int(20, 2, i_ginfo, g_info->lvl);
    disp_text(10, 3, i_ginfo, "TIMER |->");
    disp_int(20, 3, i_ginfo, g_info->timer);
    disp_text(10, 4, i_ginfo, "LINE  |->");
    disp_int(20, 4, i_ginfo, g_info->line);
    disp_text(5, 6, i_ginfo, "Best SCORE |->");
    disp_int(20, 6, i_ginfo, g_info->H_score);
    wrefresh(i_ginfo);
    return 0;
}

int disp_i_map(struct g_info *g_info, WINDOW *i_map)
{
    int size_ap = 15;
    i_map = subwin(stdscr, 16, 35, 0, 40);
    start_color();
    init_pair(4, COLOR_BLACK, COLOR_BLUE);
    wbkgd(i_map, COLOR_PAIR(4));
    wborder(i_map, ACS_CKBOARD, ACS_CKBOARD, ACS_CKBOARD, ACS_CKBOARD, ACS_CKBOARD, ACS_CKBOARD, ACS_CKBOARD, ACS_CKBOARD);
    wrefresh(i_map);
    return 0;
}

int disp_i_trmino(struct g_info *g_info, WINDOW *i_trmino)
{
    i_trmino = subwin(stdscr, 7, 20, 0, 75);
    start_color();
    init_pair(2, COLOR_BLACK, COLOR_WHITE);
    wbkgd(i_trmino, COLOR_PAIR(2));
    disp_text(1, 1, i_trmino, "      {D3V}");
    disp_text(1, 2, i_trmino, "        |");
    disp_text(1, 3, i_trmino, "RAPH <--|--> MOHA");
    disp_text(1, 4, i_trmino, "        |");
    disp_text(1, 5, i_trmino, "        v");
    disp_text(1, 6, i_trmino, "      PIRATE");
    wrefresh(i_trmino);
    return 0;
}