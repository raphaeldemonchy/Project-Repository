/*
** EPITECH PROJECT, 2022
** SERVER
** File description:
** request.c
*/

#include "server.h"
#define ClientGUI  getClientByUuid(uuid, server->_allClient)->client
void define_client_type(Server *server, char *clientuuid)
{
    ClientList *tmp = server->_allClient;
    int i = 0, j = 0;
    for (; tmp != NULL && strcmp(clientuuid, tmp->client->_uuid) != 0; tmp = tmp->next, i++);
    if (strcmp(server->_buffer, "AI\n") == 0) {
        strcpy(tmp->client->type, "AI");
        server->_ai = AI_pushBack(clientuuid, server->_args->freq, server->_args->width, server->_args->height, server->_ai);
        write (getClientByUuid(clientuuid, server->_allClient)->client->_socket, "WELCOME\n", 8);
    } else if (strcmp(server->_buffer, "GUI\n") == 0) {
        strcpy(tmp->client->type, "GUI");
        write (getClientByUuid(clientuuid, server->_allClient)->client->_socket, "WELCOME\n", 8);
    }
}

void define_client_equipe(Server *server, char *clientuuid)
{
    int verif = 0;
    char *message = malloc(sizeof(char) * 5);
    char *map_size = malloc(sizeof(char) * 7);
    for (int y = 0;server->_args->nameOfTeam[y] != NULL; y++) {
        if (strncmp(server->_buffer, server->_args->nameOfTeam[y], strlen(server->_args->nameOfTeam[y]) - 1) == 0 &&
            checkIfHaveEnougthSlot(server, server->_args->nameOfTeam[y]) == true) {
                AI_getAIByUuid(clientuuid, server->_ai)->_equipe = strdup(server->_args->nameOfTeam[y]);
                addPlayerToEquipe(server, server->_args->nameOfTeam[y], clientuuid);
                sprintf(message, "%d\n", checkNbrEmptySlot(server, server->_args->nameOfTeam[y]));
                sprintf(map_size, "%d %d\n", server->_args->width, server->_args->height);
                write(getClientByUuid(clientuuid, server->_allClient)->client->_socket, message, strlen(message));
                write(getClientByUuid(clientuuid, server->_allClient)->client->_socket, map_size, strlen(map_size));
                verif = 1;
        }
    }
    if (verif == 0) {
        write(getClientByUuid(clientuuid, server->_allClient)->client->_socket, "ko\n", 3);
    }
}

void GUI_cmd(Server *server, char *uuid)
{
     if (strcmp (ClientGUI->type, "GUI") == 0) {
        if (strncmp(server->_buffer, "msz\n", 4) == 0)
            server->_gui_cmd = cmd_pushBack(server->_buffer, uuid, 0, server->_gui_cmd);
        if (strncmp(server->_buffer, "bct", 3) == 0)
            server->_gui_cmd = cmd_pushBack(server->_buffer, uuid, 0, server->_gui_cmd);
        if (strncmp(server->_buffer, "mct\n", 4) == 0)
            server->_gui_cmd = cmd_pushBack(server->_buffer, uuid, 0, server->_gui_cmd);
        if (strncmp(server->_buffer, "tna\n", 4) == 0)
            server->_gui_cmd = cmd_pushBack(server->_buffer, uuid, 0, server->_gui_cmd);
        if (strncmp(server->_buffer, "ppo ", 4) == 0)
            server->_gui_cmd = cmd_pushBack(server->_buffer, uuid, 0,server->_gui_cmd);
        if (strncmp(server->_buffer, "plv", 3) == 0)
            server->_gui_cmd = cmd_pushBack(server->_buffer, uuid, 0, server->_gui_cmd);
        if (strncmp(server->_buffer, "pin ", 4) == 0)
            server->_gui_cmd = cmd_pushBack(server->_buffer, uuid, 0, server->_gui_cmd);
    }
}

void handle_request(Server *server, char *clientuuid)
{
    if (strcmp(getClientByUuid(clientuuid, server->_allClient)->client->type, "undefined") == 0) {
        define_client_type(server, clientuuid);
        return;
    }
    if (strcmp(getClientByUuid(clientuuid, server->_allClient)->client->type, "AI") == 0) {
        if (strcmp(AI_getAIByUuid(clientuuid, server->_ai)->_equipe, "undefined") == 0) {
            define_client_equipe(server, clientuuid);
            return;
        }
        if (strcmp(AI_getAIByUuid(clientuuid, server->_ai)->_equipe, "undefined") != 0) {
            add_AI_commandes(server, clientuuid);
            return;
        }
    }
    if (strcmp(getClientByUuid(clientuuid, server->_allClient)->client->type, "GUI") == 0) {
        GUI_cmd(server, clientuuid);
    }
}

void get_request(Server *server)
{
    ClientList *tmp = server->_allClient;
    for (int clientnbr = 0;tmp != NULL; tmp = tmp->next, clientnbr++) {
        server->_buffer = malloc(sizeof(char) * 1024);
        if (FD_ISSET(tmp->client->_socket, &server->tmp_fds)) {
            if (read(tmp->client->_socket, server->_buffer, 1024) == 0) {
                close(tmp->client->_socket);
                FD_CLR(tmp->client->_socket, &server->tmp_fds);
            } else {
                if (server->_buffer != NULL) {
                    handle_request(server, tmp->client->_uuid);
                    free(server->_buffer);
                    memset(server->_buffer, 0, strlen(server->_buffer));
                }
            }
        }
    }
}