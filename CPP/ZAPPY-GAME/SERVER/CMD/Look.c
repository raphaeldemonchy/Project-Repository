/*
** EPITECH PROJECT, 2022
** SERVER
** File description:
** Look.c
*/

#include"../server.h"
#define ClientAI  getClientByUuid(uuid, server->_allClient)->client
#define _AI  AI_getAIByUuid(uuid, server->_ai)
#define AI_CMD cmd_getCmd_By_Player_Uuid(uuid, server->commands)

void add_to_str(char *name, int nbr, char *dest)
{
    for (int i = 0; i != nbr; i++) {
        if (i != nbr)
            strcat(dest, " ");
        strcat(dest, name);
    }
}

char *generateResponse(Tile *tile, char *respons) {
    if (tile->nbPLAYERS > 0)
        add_to_str("player", tile->nbPLAYERS, respons);
    if (tile->deraumere > 0)
        add_to_str("deraumere", tile->deraumere, respons);
    if (tile->food > 0)
        add_to_str("food", tile->food, respons);
    if (tile->linemate > 0)
        add_to_str("linemate", tile->linemate, respons);
    if (tile->mendiane > 0)
        add_to_str("mendiane", tile->mendiane, respons);
    if (tile->phiras > 0)
        add_to_str("phiras", tile->phiras, respons);
    if (tile->sibur > 0)
        add_to_str("sibur", tile->sibur, respons);
    if (tile->thystame > 0)
        add_to_str("thystame", tile->thystame, respons);

}

#define MAX_VISION_SIZE 38

void getTilesOnLine(int orientation, int limit, int x, int y, Tile **vision, Map *map, Server *server)
{
    int newX = x, newY = y;
    int pos = 0;
    for(; vision[pos] != NULL; pos++);
    if (orientation == 1) {
        newX -= limit;
        for (int j = limit * (-1); j != limit + 1; j++, pos++){
            if (newX > server->_args->width - 1)
                newX -= server->_args->width - 1;
            if (newX < 0)
                newX += server->_args->width;
            if (newY < 0)
                newY += server->_args->height - 1;
            if (newY > server->_args->height - 1)
                newY -= server->_args->height - 1;
            vision[pos] = getTilesByXY(map, newX, newY);
            newX ++;
        }
    }
    if (orientation == 2) {
        newY -= limit;
        for (int j = limit * (-1); j != limit + 1; j++, pos++){
            if (newX > server->_args->width - 1)
                newX -= server->_args->width - 1;
            if (newX < 0)
                newX += server->_args->width;
            if (newY < 0)
                newY += server->_args->height - 1;
            if (newY > server->_args->height - 1)
                newY -= server->_args->height - 1;
            vision[pos] = getTilesByXY(map, newX, newY);
            newY ++;
        }
    }
    if (orientation == 3) {
        newX += limit;
        for (int j = limit * (-1); j != limit + 1; j++, pos++){
            if (newX > server->_args->width - 1)
                newX -= server->_args->width - 1;
            if (newX < 0)
                newX += server->_args->width;
            if (newY < 0)
                newY += server->_args->height - 1;
            if (newY > server->_args->height - 1)
                newY -= server->_args->height - 1;
            vision[pos] = getTilesByXY(map, newX, newY);
            newX --;
        }
    }
    if (orientation == 4) {
        newY += limit;
        for (int j = limit * (-1); j != limit + 1; j++, pos++){
            if (newX > server->_args->width - 1)
                newX -= server->_args->width - 1;
            if (newX < 0)
                newX += server->_args->width;
            if (newY < 0)
                newY += server->_args->height - 1;
            if (newY > server->_args->height - 1)
                newY -= server->_args->height - 1;
            vision[pos] = getTilesByXY(map, newX, newY);
            newY --;
        }
    }
}

Tile **generateVisionOfPlayer(Server *server, Map *map, AI *Player)
{
    Tile **vision = malloc(sizeof(Tile *) * (MAX_VISION_SIZE + 100));
    vision[0] = getTilesByXY(map, Player->_x, Player->_y);
    for (int i = 1; i != Player->_level + 1; i++) {
        if (Player->_orientation == 1) {
            getTilesOnLine(Player->_orientation, i,Player->_x, Player->_y - i, vision, map, server);
        }
        if (Player->_orientation == 2) {
            getTilesOnLine(Player->_orientation, i,Player->_x + i, Player->_y, vision, map, server);
        }
        if (Player->_orientation == 3) {
            getTilesOnLine(Player->_orientation, i,Player->_x, Player->_y + i, vision, map, server);
        }
        if (Player->_orientation == 4) {
            getTilesOnLine(Player->_orientation, i,Player->_x - i, Player->_y, vision, map, server);
        }
    }
    vision[MAX_VISION_SIZE + 1] = NULL;
    return vision;
}

char *getAllTiles(Server *server, Map *map, AI *Player, char *respons)
{
    Tile **vision = generateVisionOfPlayer(server, map, Player);
    strcat(respons, "[");
    for (int i = 0; vision[i] != NULL; i++) {
        generateResponse(vision[i], respons);
        strcat(respons, ",");
    }
    strcat(respons, "]\n");
}

void Look(Server *server, char *uuid)
{
    char *respons = malloc(sizeof(char) * 10000);
    getAllTiles(server, server->_map, _AI, respons);
    write(ClientAI->_socket, respons, strlen(respons));
    _AI->statu = true;
}