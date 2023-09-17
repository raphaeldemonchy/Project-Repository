#pragma once

#include "server.h"

typedef struct ALL_RESSOURCES
{
    Server *_server;
    int _nbrOfPlayers;
    char *uuid;
}All;