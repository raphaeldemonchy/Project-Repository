/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "../include/tetris.h"

int my_atoi(char *str)
{
    int i = 0, j = 0;
    int nb = 0;
    int neg = 0;
    while (str[i] < '0' || str[i] > '9')
        i += 1;
    while (str[i] >= '0' && str[i] <= '9') {
        nb = (nb * 10) + ((str[i]) - 48);
        i += 1;
    }
    for (; str[j] != '\0'; j += 1) {
        if (str[j] == '-')
            neg += 1;
    }
    if (neg % 2 == 1)
        return (nb * (-1));
    else
        return (nb);
}

int my_putnbr(int nb)
{
    int a = 0;
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= 10) {
        a = nb % 10;
        nb = nb / 10;
        my_putnbr(nb);
        my_putchar(a + 48);
    } else {
        my_putchar(nb + 48);
    }
    return (0);
}

g_info *init_standard_ginfo(g_info *stock)
{
    stock->score = 0;
    stock->lvl = 1;
    stock->key_left = 260;
    stock->key_right = 261;
    stock->key_turn = 32;
    stock->key_drop = 120;
    stock->key_quit = 113;
    stock->key_pause = 112;
    stock->key_next = true;
    stock->debug = false;
    stock->size_x = 20;
    stock->size_y = 10;
    return stock;
}

char *parser_y(g_info *stock, char const *src)
{
    char *y_size;
    int i = 0;
    int len = 1;
    while (src[i] != ',')
        i += 1;
    int tmp = i;
    for (; src[i] != '\0'; i += 1)
        if (src[i] >= '0' && src[i] <= '9')
            len += 1;
    y_size = malloc(sizeof(char) * len);
    for (int count = 0; src[tmp] != '\0'; tmp += 1)
        if (src[tmp] >= '0' && src[tmp] <= '9')
            y_size[count] = src[tmp], count += 1;
    y_size[tmp] = '\0';
    return y_size;
}

char *parser_x(g_info *stock, char const *src)
{
    char *x_size;
    int len = 1;
    for (int i = 0; src[i] != ','; i += 1)
        if (src[i] >= '0' && src[i] <= '9')
            len += 1;
    x_size = malloc(sizeof(char) * len);
    for (int i = 0; src[i] != ','; i += 1)
        if (src[i] >= '0' && src[i] <= '9')
            x_size[i] = src[i];
    x_size[len] = '\0';
    return x_size;
}

int tetris(g_info *info)
{
    WINDOW *i_logo, *i_ginfo, *i_map, *i_trmino;
    initscr();
    disp_i_ginfo(info, i_ginfo);
    disp_i_map(info, i_map);
    disp_i_trmino(info, i_trmino);
    disp_i_logo(info, i_logo);
    getch();
    endwin();
    return 0;
}

void my_print_size(char *src_1, int src_2, int src_3)
{
    my_putstr(src_1);
    my_putnbr(src_2);
    my_putchar('*');
    my_putnbr(src_3);
    my_putchar('\n');
}

void my_print_2(char *src_1, char src_2, char *src_3, int src_4, char *src_5)
{
    my_putstr(src_1);
    my_putchar(src_2);
    my_putstr(src_3);
    my_putnbr(src_4);
    my_putstr(src_5);
}

void my_print(char *src_1, int src_2, char *src_3)
{
    my_putstr(src_1);
    my_putnbr(src_2);
    my_putstr(src_3);
}

int my_linklen(link_t *link)
{
    int i = 0;
    for (i = 0; link != NULL; i += 1)
        link = link->next;
    return i;
}

void my_debugger_2(g_info *info, link_t *link)
{
    my_print("Number of tetriminos: ", my_linklen(link), "\n");
    while (link != NULL) {
        my_putstr("Tetriminos \'");
        my_putstr(link->name);
        my_putstr("\': ");
        if (my_strcmp(link->file, "error") == 0)
            my_putstr("error\n");
        else {
            my_putstr("size ");
            my_putnbr(link->x);
            my_putstr("*");
            my_putnbr(link->y);
            my_putstr(", color ");
            my_putnbr(link->color);
            my_putstr("\n");
            my_putstr(link->file);
            my_putstr("\n");
        }
        link = link->next;
    }
}

void my_debugger(g_info *info, link_t *link)
{
    my_print("Key left: KEY_LEFT (\0", info->key_left, ")\n\0");
    my_print("Key right: KEY_RIGHT (\0", info->key_right, ")\n\0");
    my_print_2("Key turn: ", info->key_turn, " (", info->key_turn, ")\n");
    my_print_2("Key drop: ", info->key_drop, " (", info->key_drop, ")\n\0");
    my_print_2("Key quit: ", info->key_quit, " (", info->key_quit, ")\n\0");
    my_print_2("Key pause: ", info->key_pause, " (", info->key_pause, ")\n\0");
    my_putstr("Next: ");
    if (info->key_next == true)
        my_putstr("Yes\n");
    else
        my_putstr("No\n");
    my_print("Level: ", info->lvl, "\n");
    my_print_size("Size: ", info->size_x, info->size_y);
    my_putchar('\n');
    my_debugger_2(info, link);
}

int main(int ac, char **av)
{
    int c = 0;
    link_t *link = NULL;
    g_info *info = malloc(sizeof(g_info));
    info = init_standard_ginfo(info);
    bool h = false;
    for (int i = 1; av[i] != NULL; i += 1) {
        c = getopt_long(ac, av, "l:L:r:t:d:q:p:wDh", long_options, 0);
        switch (c) {
            case 'L':
                info->lvl = my_atoi(optarg);
                break;
            case 'l':
                info->key_left = my_atoi(optarg);
                break;
            case 'r':
                info->key_right = my_atoi(optarg);
                break;
            case 't':
                info->key_turn = my_atoi(optarg);
                break;
            case 'd':
                info->key_drop = my_atoi(optarg);
                break;
            case 'q':
                info->key_drop = optarg[0];
                break;
            case 'p':
                info->key_pause = optarg[0];
                break;
            case 'm':
                info->size_x = my_atoi(parser_x(info, optarg));
                info->size_y = my_atoi(parser_y(info, optarg));
                break;
            case 'w':
                info->key_next = false;
                break;
            case 'D':
                info->debug = true;
                break;
            case 'h':
                flag_h(av[0]);
                h = true;
                break;
        }
    }
    link = init_game(link, info);
    if (link == NULL) {
        free(info);
        free(link);
        return 84;
        }
    if (info->debug && !h) {
        my_debugger(info, link);
        free(info);
        free(link);
        return 0;
    }
    if (!h)
        if (tetris(info) == 84) {
            free(info);
            free(link);
            return 84;
        }
    free(info);
    free(link);
    return 0;
}