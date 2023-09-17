/*
** EPITECH PROJECT, 2022
** tetris.h
** File description:
** tetris.h
*/

#include <stdlib.h>
#include <unistd.h>
#include <curses.h>
#include <ncurses.h>
#include <getopt.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#ifndef TETRIS_H_
    #define TETRIS_H_

    static struct option long_options[] = {
        {"level", 1, NULL, 'L'},
        {"key-left", 1, NULL, 'l'},
        {"key-right", 1, NULL, 'r'},
        {"key-turn", 1, NULL, 't'},
        {"key-drop", 1, NULL, 'd'},
        {"key-quit", 1, NULL, 'q'},
        {"key-pause", 1, NULL, 'p'},
        {"map-size", 1, NULL, 'm'},
        {"help", 0, NULL, 'h'},
        {"without-next", 0, NULL, 'w'},
        {"debug", 0, NULL, 'D'}
    };

    typedef struct link_s {
        int x;
        int y;
        int color;
        char *file;
        char *name;
        struct link_s *next;
    } link_t;

    typedef struct g_info {
        int size_x;
        int size_y;

        int total_piece_number;
        int score;
        int H_score;
        int line;
        int lvl;
        int timer;

        int remove_line;
        int disp_debug;

        int win_x;
        int win_y;
        int key_right;

        int key_quit;
        int key_pause;
        int key_left;
        int key_front;
        int key_turn;
        int key_drop;

        bool key_next;
        bool debug;

    } g_info;

    //LIB
    int my_strcmp(char const *s1, char const *s2);
    int my_strlen(char *str);
    void my_putstr(char *str);
    void my_putchar(char c);
    int my_put_nbr(int nb);
    char *my_strdup(char *str);
    int my_atoi(char *str);

    //Flag Help
    void flag_h(char *src);

    //GEST WINDOW DISP
    int disp_i_logo(struct g_info *g_info, WINDOW *i_logo);
    int disp_i_ginfo(struct g_info *g_info, WINDOW *i_ginfo);
    int disp_i_map(struct g_info *g_info, WINDOW *i_map);
    int disp_i_trmino(struct g_info *g_info, WINDOW *i_trmino);

    //INIT
    link_t *init_game(link_t *link, g_info *g_info);

    // UTILS
    void disp_text(int x, int y, WINDOW *ginfo, char *info);
    void disp_int(int x, int y, WINDOW *ginfo, int info);
    void disp_map(WINDOW *w, char **tab);
    int my_arrlen(char **arr);
    char *my_itoa(int nb);

    //CHARGE_TETRIMINOS
    char *my_fusion_str(char *src, char *src_2, char *src_3);
    void putlink(link_t *link);
    link_t *new_cell(link_t *link_chain, char *src, char *name);
    char *open_file(char *pathfile);
    link_t *charge_link_tetriminos(link_t *link);

#endif