/*
** EPITECH PROJECT, 2022
** SERVER
** File description:
** map.c
*/

#include "../server.h"

void initMap(Server *server)
{
    server->_map = malloc(sizeof(Map));
    server->_map->tile = malloc(sizeof(Tile *) * (server->_args->height * server->_args->width));
    for (int i = 0, x = 0, y = 0; i != (server->_args->height * server->_args->width); i++, x++) {
        if (x == server->_args->width)
            x = 0, y++;
        server->_map->tile[i] = malloc(sizeof(Tile));
        server->_map->tile[i]->deraumere = 0;
        server->_map->tile[i]->linemate = 0;
        server->_map->tile[i]->mendiane = 0;
        server->_map->tile[i]->nbPLAYERS = 0;
        server->_map->tile[i]->phiras = 0;
        server->_map->tile[i]->sibur = 0;
        server->_map->tile[i]->thystame = 0;
        float mapXY = server->_args->height * server->_args->width;
        server->_map->maxLinemate = 0.3 * mapXY;
        server->_map->maxDeraumere = 0.15 * mapXY;
        server->_map->maxSibur = 0.1 * mapXY;
        server->_map->maxMendiane = 0.1 * mapXY;
        server->_map->maxPhiras = 0.08 * mapXY;
        server->_map->maxThystame = 0.05 * mapXY;
        server->_map->maxFood = 0.5 * mapXY;
        server->_map->maxItemOnMAp = (0.3 + 0.15 + 0.1 + 0.1 + 0.08 + 0.05 + 0.5) * mapXY;
        server->_map->tile[i]->x = x;
        server->_map->tile[i]->y = y;
    }
    refillMap(server, 1);
}

int getTotalNumOfItem(char *name, Server *server) {
    int nbr = 0;
    for (int y = 0; server->_map->tile[y] != NULL; y++) {
        if (strcmp("deraumere", name) == 0)
            nbr += server->_map->tile[y]->deraumere;
        if (strcmp("linemate", name) == 0)
            nbr += server->_map->tile[y]->linemate;
        if (strcmp("mendiane", name) == 0)
            nbr += server->_map->tile[y]->mendiane;
        if (strcmp("phiras", name) == 0)
            nbr += server->_map->tile[y]->phiras;
        if (strcmp("sibur", name) == 0)
            nbr += server->_map->tile[y]->sibur;
        if (strcmp("thystame", name) == 0)
            nbr += server->_map->tile[y]->thystame;
        if (strcmp("food", name) == 0)
            nbr += server->_map->tile[y]->food;
    }
    return nbr;
}
int getAllItemNbr(Server *server) {
    int nbr = 0;
    for (int y = 0; server->_map->tile[y] != NULL; y++) {
        nbr += server->_map->tile[y]->deraumere;
        nbr += server->_map->tile[y]->linemate;
        nbr += server->_map->tile[y]->mendiane;
        nbr += server->_map->tile[y]->phiras;
        nbr += server->_map->tile[y]->sibur;
        nbr += server->_map->tile[y]->thystame;
        nbr += server->_map->tile[y]->food;
    }
    return nbr;
}

void placeItem(Server *server, char *name, int pos, int ratio)
{
    int nombreAleatoire = (rand() % ratio) + (pos - ratio);
    if (strcmp("deraumere", name) == 0)
        server->_map->tile[nombreAleatoire]->deraumere++;
    if (strcmp("linemate", name) == 0)
        server->_map->tile[nombreAleatoire]->linemate++;
    if (strcmp("mendiane", name) == 0)
        server->_map->tile[nombreAleatoire]->mendiane++;
    if (strcmp("phiras", name) == 0)
        server->_map->tile[nombreAleatoire]->phiras++;
    if (strcmp("sibur", name) == 0)
        server->_map->tile[nombreAleatoire]->sibur++;
    if (strcmp("thystame", name) == 0)
        server->_map->tile[nombreAleatoire]->thystame++;
    if (strcmp("food", name) == 0)
        server->_map->tile[nombreAleatoire]->food++;
}

void distribItems(Server *server, char *name, float maxOfThisItem)
{
    int ratio = 0;
    ratio = (server->_map->maxItemOnMAp / maxOfThisItem);
    for (int y = 0, j = 0; server->_map->tile[y] != NULL; y++, j++) {
        if (j == ratio) {
            if (getTotalNumOfItem(name, server) < maxOfThisItem &&
                getAllItemNbr(server) < server->_map->maxItemOnMAp) {
                placeItem(server, name, y, ratio);
                j = 0;
            }
        }
    }
}

void refillMap(Server *server, int verif)
{
    if (server->_time - server->_lastRefill >= server->_args->freq * 20 || verif == 1) {
        distribItems(server,"linemate", server->_map->maxLinemate);
        distribItems(server,"deraumere", server->_map->maxDeraumere);
        distribItems(server,"sibur", server->_map->maxSibur);
        distribItems(server,"mendiane", server->_map->maxMendiane);
        distribItems(server,"phiras", server->_map->maxPhiras);
        distribItems(server,"thystame", server->_map->maxThystame);
        distribItems(server,"food", server->_map->maxFood);
        server->_lastRefill = server->_time;
        verif = 0;
    }
}

void refreshPlayerPos(Server *server)
{
    AI *ia = server->_ai;
    for (int i = 0; server->_map->tile[i] != NULL; i++) {
        server->_map->tile[i]->nbPLAYERS = 0;
    }
    for (;ia != NULL; ia = ia->next)
            getTilesByXY(server->_map, ia->_x, ia->_y)->nbPLAYERS ++;
    free(ia);
}

Tile *getTilesByXY(Map *map, int x, int y)
{
    int i = 0;
    for (; map->tile[i] != NULL; i++)
    {
        if (map->tile[i]->x == x && map->tile[i]->y == y)
            return map->tile[i];
    }
}