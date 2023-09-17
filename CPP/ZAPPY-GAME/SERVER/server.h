#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <unistd.h>
#include <uuid/uuid.h>
#include <time.h>
#include "CLIENTLIST/client.h"
#include "AI/AI.h"
#include "MAP/map.h"
#include "EGG/egg.h"
#include <stdbool.h>

// #define BUFFER_SIZE 1024
// #define SERVER_SOCKET _server->_socket

typedef struct Args_s {
    int width, height;
    int port;
    char **nameOfTeam;
    int cliMaxNbr;
    float freq;
}Args;

typedef struct Equipe_t
{
    char *name;
    char **_player_uuid;
    int slot;
}Equipe;


typedef struct Server_s {
    // ----server work----
    char *_buffer;
    int _socket;
    struct sockaddr_in _server_address;
    // ----client gest----
    struct sockaddr_in _client_address;
    int _client_socket;
    socklen_t _client_address_length;
    fd_set read_fds;
    fd_set tmp_fds;
    int max_fd;
    struct timeval *timeout;
    CommandeList *_commands;
    CommandeList *exec_list;
    CommandeList *_gui_cmd;
    // ----indicateur de temp du server----
    time_t clock_start, clock_end;
    double _time, _lastRefill;
    pthread_t t_time;
    pthread_t t_server;

    // ----ressource----
    ClientList *_allClient;
    Args *_args;
    Map *_map;
    AI *_ai;
    Egg *_egg;
    Equipe **_equipes;
}Server;

void start_server(Server *server);
void init_server(Server *server);
void initMap(Server *server);
void refillMap(Server *server, int verif);
void get_request(Server *server);
void add_AI_commandes(Server *server, char *player_uuid);
void execute_AI_commandes(Server *server);
void execAllCmd(Server *server);
void refreshTimeout(Server *server);
void stockExecList(Server *server);
void refreshPlayerLifeOrDeath(Server *server);
void refreshPlayerPos(Server *server);
// #############   EQUIPES   ###################

void initEquipe(Server *server);
void addPlayerToEquipe(Server *server, char *name, char *player_uuid);
void erasePlayerToEquipe(Server *server, char *name, char *player_uuid);
bool checkIfHaveEnougthSlot(Server *server, char *name);
int checkNbrEmptySlot(Server *server, char *name);
void printEquipes(Server *server);
void refreshEquipeSlot(Server *server);
Equipe *getEquipeByName(Server *server, char *name);


// #############   COMMANDE AI    ##############
void Forward(Server *server, char *uuid);
void Right(Server *server, char *uuid);
void Left(Server *server, char *uuid);
void Look(Server *server, char *uuid);
void GetInventory(Server *server, char *uuid);
void Broadcast(Server *server, char *uuid);
void Connect_nbr(Server *server, char *uuid);
void Fork_ai(Server *server, char *uuid);
void take_obj(Server *server, char *uuid);
void drop_obj(Server *server, char *uuid, int nrbOfItem);
void Eject(Server *server, char *uuid);
void Incantation(Server *server, char *uuid);
void Death_Player(Server *server, char *uuid);

// #############   COMMANDE GUI   ##############
void execGuiCMD(Server *server);
void map_size(Server *server, char *uuid);
void content_of_tile(Server *server, char *uuid);
void content_of_the_map(Server *server, char *uuid);
void name_of_all_the_teams(Server *server, char *uuid);
void connection_of_a_new_player(Server *server, char *uuid);
void players_position(Server *server, char *uuid);
void players_level(Server *server, char *uuid);
void players_inventory(Server *server, char *uuid);
void expulsion(Server *server, char *uuid);
void broadcast(Server *server, char *uuid);
void start_of_an_incantation(Server *server, char *uuid);
void end_of_an_incantation(Server *server, char *uuid);
void egg_laying_by_the_player(Server *server, char *uuid);
void resource_dropping(Server *server, char *uuid, int nbrOfItems);
void resource_collecting(Server *server, char *uuid, int nbrOfItems);
void death_of_a_player(Server *server, char *uuid);
void an_egg_was_laid_by_a_player(Server *server, char *player_uuid, char *egg_uuid);
void player_connection_for_an_egg(Server *server, char *uuid);
void death_of_an_egg(Server *server, char *uuid);
void time_unit_request(Server *server, char *uuid);
void time_unit_modification(Server *server, char *uuid);
void end_of_game(Server *server, char *uuid);
void message_from_the_server(Server *server, char *uuid);
void unknown_command(Server *server, char *uuid);
void command_parameter(Server *server, char *uuid);