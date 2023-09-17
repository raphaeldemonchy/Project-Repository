/*
** EPITECH PROJECT, 2022
** flag_h
** File description:
** flag_h
*/

#include "../include/tetris.h"

void flag_h(char *src)
{
    my_putstr("Usage: ");
    my_putstr(src);
    my_putstr(" [option]\n");
    my_putstr("Option:\n  --help\t\t");
    my_putstr("Display this help\n");
    my_putstr("  -L --level={num}\t");
    my_putstr("Start Tetris at level num (def: 1)\n");
    my_putstr("  -l --key-left={K}\tMove the tetrimino ");
    my_putstr("LEFT using the K key (def: left arrow)\n");
    my_putstr("  -r --key-right={K}\tMove the tetrimino RIGHT");
    my_putstr(" using the K key (def: right arrow)\n");
    my_putstr("  -t --key-turn={K}\tTURN the tetrimino ");
    my_putstr("clockwise 90d using the K key (def: top arrow)\n");
    my_putstr("  -d --key-drop={K}\tDrop the tetrimino using ");
    my_putstr("the K key (def: down arrow)\n  -q --key-quit={K}\t");
    my_putstr("Quit the game using the K key (def: 'q' key)\n");
    my_putstr("  -p --key-pause={K}\tPAUSE/RESTART the game");
    my_putstr(" using the K key (def: space bar)\n  --map-size=");
    my_putstr("{row, col}\tSet the numbers of rows and columns");
    my_putstr(" of the map (def: 20,10)\n  -w --without-next");
    my_putstr("\tHide next tetrimino (def: false)\n  -D --debug");
    my_putstr("\t\tDebug mode (def: false)\n");
}
