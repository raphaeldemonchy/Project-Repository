/*
** EPITECH PROJECT, 2022
** SERVER
** File description:
** GUI_cmd.c
*/

#include"../server.h"

#define CLIENT_SOCKET getClientByUuid(uuid, server->_allClient)->client->_socket
#define q0 getTilesByXY(server->_map, x, y)->food
#define q1 getTilesByXY(server->_map, x, y)->linemate
#define q2 getTilesByXY(server->_map, x, y)->deraumere
#define q3 getTilesByXY(server->_map, x, y)->sibur
#define q4 getTilesByXY(server->_map, x, y)->mendiane
#define q5 getTilesByXY(server->_map, x, y)->phiras
#define q6 getTilesByXY(server->_map, x, y)->thystame
#define _AI AI_getAIByUuid(uuid, server->_ai)

#define q0_cible AI_getAIByUuid(word, server->_ai)->_inventaire->food
#define q1_cible AI_getAIByUuid(word, server->_ai)->_inventaire->linemate
#define q2_cible AI_getAIByUuid(word, server->_ai)->_inventaire->deraumere
#define q3_cible AI_getAIByUuid(word, server->_ai)->_inventaire->sibur
#define q4_cible AI_getAIByUuid(word, server->_ai)->_inventaire->mendiane
#define q5_cible AI_getAIByUuid(word, server->_ai)->_inventaire->phiras
#define q6_cible AI_getAIByUuid(word, server->_ai)->_inventaire->thystame
#define AI_cible AI_getAIByUuid(word, server->_ai)


void map_size(Server *server, char *uuid)
{
    char *response = malloc(sizeof(char)* 1024);
    printf ("%s\n", server->_gui_cmd->cmd);
    sprintf(response, "msz %d %d\n", server->_args->width, server->_args->height);
    write(CLIENT_SOCKET, response, strlen(response));

}
void content_of_tile(Server *server, char *uuid)
{
    char *word = malloc(sizeof(char) * strlen(server->_gui_cmd->cmd));
    char *response = malloc(sizeof(char) * 1024);
    int x = 0;
    int y = 0;
    if (server->_gui_cmd->cmd[3] == '\n')
        return;
    word = strtok(server->_gui_cmd->cmd, " ");
    word = strtok(NULL, " ");
    x = atoi(strdup(word));
    word = strtok(NULL, " ");
    y = atoi(strdup(word));
    sprintf(response, "bct %d %d %d %d %d %d %d %d %d\n", x, y, q0, q1, q2, q3, q4, q5, q6);
    write(CLIENT_SOCKET, response, strlen(response));
    // free(word);
    // free(response)
}
void content_of_the_map(Server *server, char *uuid)
{
    int x = 0;
    int y = 0;
    char *response = malloc(sizeof(char) * 1024);
    for (int i = 0; server->_map->tile[i] != NULL; i++, x++) {
        if (x == server->_args->width)
            x = 0, y++;
        sprintf(response, "bct %d %d %d %d %d %d %d %d %d\n", x, y, q0, q1, q2, q3, q4, q5, q6);
        write(CLIENT_SOCKET, response, strlen(response));
        memset(response, 0, sizeof(response));
    }
    // free(response);
}
void name_of_all_the_teams(Server *server, char *uuid)
{
        for (int i = 0; server->_args->nameOfTeam[i] != NULL; i++) {
            write(CLIENT_SOCKET, "tna ", 4);
            write(CLIENT_SOCKET, server->_args->nameOfTeam[i], strlen(server->_args->nameOfTeam[i]));
            write(CLIENT_SOCKET, "\n", 1);
        }
}
void connection_of_a_new_player(Server *server, char *uuid)
{
    char *response = malloc(sizeof(char) * 1024);
    ClientList *tmp = server->_allClient;
    sprintf(response, "pnw %s %d %d %d %d %s\n", uuid, _AI->_x, _AI->_y, _AI->_orientation, _AI->_level, _AI->_equipe);
    for (;tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->client->type, "GUI") == 0)
            write(tmp->client->_socket, response, strlen(response));
    }
    memset(response, 0, strlen(response));
}
void players_position(Server *server, char *uuid)
{
    char *word = malloc(sizeof(char) * 1024);
    char *response = malloc(sizeof(char) * 1024);
    word = strtok(server->_gui_cmd->cmd, " ");
    word = strtok(NULL, " ");
    word[strlen(word)-1] = '\0';
    if (AI_cible != NULL) {
        sprintf(response, "ppo %s %d %d %d\n", AI_cible->_uuid, AI_cible->_x, AI_cible->_y, AI_cible->_orientation);
        write(CLIENT_SOCKET, response, strlen(response));
    }
    memset(response, 0, strlen(response));
    free(response);
}
void players_level(Server *server, char *uuid)
{
    char *word = malloc(sizeof(char) * 1024);
    char *response = malloc(sizeof(char) * 1024);
    word = strtok(server->_gui_cmd->cmd, " ");
    word = strtok(NULL, " ");
    word[strlen(word)-1] = '\0';
    sprintf(response, "plv %s %d\n", AI_cible->_uuid, AI_cible->_level);
    write(CLIENT_SOCKET, response, strlen(response));
    memset(response, 0, strlen(response));
}
void players_inventory(Server *server, char *uuid)
{
    char *word = malloc(sizeof(char) * 1024);
    char *response = malloc(sizeof(char) * 1024);
    word = strtok(server->_gui_cmd->cmd, " ");
    word = strtok(NULL, " ");
    word[strlen(word)-1] = '\0';
    if (AI_cible != NULL) {
        sprintf(response, "pin %s %d %d %d %d %d %d %d %d %d\n", AI_cible->_uuid, AI_cible->_x, AI_cible->_y,
        q0_cible, q1_cible, q2_cible, q3_cible, q4_cible, q5_cible, q6_cible);
        write(CLIENT_SOCKET, response, strlen(response));
    }
    memset(response, 0, strlen(response));
}
void expulsion(Server *server, char *uuid)
{
    char *response = malloc(sizeof(char) * 1024);
    ClientList *tmp = server->_allClient;
    sprintf(response, "pex %s\n", uuid);
    for (;tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->client->type, "GUI") == 0)
            write(tmp->client->_socket, response, strlen(response));
    }
    memset(response, 0, strlen(response));
}
void broadcast(Server *server, char *uuid)
{
    char *response = malloc(sizeof(char) * 1024);
    ClientList *tmp = server->_allClient;
    sprintf(response, "pbc %s %s\n", uuid, _AI->_message);
    for (;tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->client->type, "GUI") == 0)
            write(tmp->client->_socket, response, strlen(response));
    }
    memset(response, 0, strlen(response));
}
void start_of_an_incantation(Server *server, char *uuid)
{
    char *response = malloc(sizeof(char) * 1024);
    ClientList *tmp = server->_allClient;
    AI *ia = server->_ai;
    sprintf(response, "pic %d %d %d", _AI->_x, _AI->_y, _AI->_level + 1);
    for (;ia != NULL; ia = ia->next) {
        if (ia->_x == _AI->_x && ia->_y == _AI->_y)
            strcat(response, " "), strcat(response, ia->_uuid);
    }
    for (;tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->client->type, "GUI") == 0)
            write(tmp->client->_socket, response, strlen(response));
            write(tmp->client->_socket, "\n", 1);
    }
}
void end_of_an_incantation(Server *server, char *uuid)
{
    char *response = malloc(sizeof(char) * 1024);
    ClientList *tmp = server->_allClient;
    AI *ia = server->_ai;
    sprintf(response, "pie %d %d %d\n", _AI->_x, _AI->_y, 1);
    for (;tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->client->type, "GUI") == 0)
            write(tmp->client->_socket, response, strlen(response));
    }

}
void egg_laying_by_the_player(Server *server, char *uuid)
{
    char *response = malloc(sizeof(char) * 1024);
    ClientList *tmp = server->_allClient;
    sprintf(response, "pfk %s\n", uuid);
    for (;tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->client->type, "GUI") == 0)
            write(tmp->client->_socket, response, strlen(response));
    }
    memset(response, 0, strlen(response));
}
void resource_dropping(Server *server, char *uuid, int nbrOfItems)
{
    char *response = malloc(sizeof(char) * 1024);
    ClientList *tmp = server->_allClient;
    sprintf(response, "pdr %s %d\n", uuid, nbrOfItems);
    for (;tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->client->type, "GUI") == 0)
            write(tmp->client->_socket, response, strlen(response));
    }
    memset(response, 0, strlen(response));
}
void resource_collecting(Server *server, char *uuid, int nbrOfItems)
{
    char *response = malloc(sizeof(char) * 1024);
    ClientList *tmp = server->_allClient;
    sprintf(response, "pgt %s %d\n", uuid, nbrOfItems);
    for (;tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->client->type, "GUI") == 0)
            write(tmp->client->_socket, response, strlen(response));
    }
    memset(response, 0, strlen(response));
}
void death_of_a_player(Server *server, char *uuid)
{
    char *response = malloc(sizeof(char) * 1024);
    ClientList *tmp = server->_allClient;
    sprintf(response, "pdi %s\n", uuid);
    for (;tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->client->type, "GUI") == 0)
            write(tmp->client->_socket, response, strlen(response));
    }
    memset(response, 0, strlen(response));
}
void an_egg_was_laid_by_a_player(Server *server, char *uuid, char *egg_uuid)
{
    char *response = malloc(sizeof(char) * 1024);
    ClientList *tmp = server->_allClient;
    sprintf(response, "enw %s %s %d %d\n", egg_uuid, uuid, _AI->_x, _AI->_y);
    for (;tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->client->type, "GUI") == 0)
            write(tmp->client->_socket, response, strlen(response));
    }
    memset(response, 0, strlen(response));
}
void player_connection_for_an_egg(Server *server, char *egg_uuid)
{
    char *response = malloc(sizeof(char) * 1024);
    ClientList *tmp = server->_allClient;
    sprintf(response, "ebo %s\n", egg_uuid);
    for (;tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->client->type, "GUI") == 0)
            write(tmp->client->_socket, response, strlen(response));
    }
    memset(response, 0, strlen(response));
}
void death_of_an_egg(Server *server, char *egg_uuid)
{
    char *response = malloc(sizeof(char) * 1024);
    ClientList *tmp = server->_allClient;
    sprintf(response, "edi %s\n", egg_uuid);
    for (;tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->client->type, "GUI") == 0)
            write(tmp->client->_socket, response, strlen(response));
    }
    memset(response, 0, strlen(response));
}
void time_unit_request(Server *server, char *uuid)
{
    if (strcmp(server->_gui_cmd->cmd, "\n") == 0) {

    }
}
void time_unit_modification(Server *server, char *uuid)
{
    if (strcmp(server->_gui_cmd->cmd, "\n") == 0) {

    }
}
void end_of_game(Server *server, char *uuid)
{
    if (strcmp(server->_gui_cmd->cmd, "\n") == 0) {

    }
}
void message_from_the_server(Server *server, char *uuid)
{
    if (strcmp(server->_gui_cmd->cmd, "\n") == 0) {

    }
}
void unknown_command(Server *server, char *uuid)
{
    if (strcmp(server->_gui_cmd->cmd, "\n") == 0) {

    }
}
void command_parameter(Server *server, char *uuid)
{
    if (strcmp(server->_gui_cmd->cmd, "\n") == 0) {

    }
}