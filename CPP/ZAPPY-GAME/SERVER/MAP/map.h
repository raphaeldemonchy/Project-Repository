/*
** EPITECH PROJECT, 2022
** SERVER
** File description:
** map.h
*/

#pragma once

typedef struct Tile_s {
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
    int nbPLAYERS;
    int food;
    int x;
    int y;

}Tile;

typedef struct Map_l {
    Tile **tile;
    float maxItemOnMAp;
    float maxLinemate;
    float maxDeraumere;
    float maxSibur;
    float maxMendiane;
    float maxPhiras;
    float maxThystame;
    float maxFood;
}Map;

Tile *getTilesByXY(Map *map, int x, int y);