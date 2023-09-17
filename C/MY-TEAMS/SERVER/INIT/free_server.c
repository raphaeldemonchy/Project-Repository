/*
** EPITECH PROJECT, 2022
** free_server
** File description:
** free_server.c
*/

#include "../server.h"


void free_data_server(server *_server)
{
    free(_server->client_slot);
    for (int i = 0; _server->client_slot[i] != NULL; i++)
        free(_server->client_slot[i]), _server->client_slot[i] = NULL;
    free(_server->teams);
    for (int i = 0; _server->teams[i] != NULL; i++)
        free(_server->teams[i]);
    free(_server->users);
    for (int i = 0; _server->users[i] != NULL; i++)
        free(_server->users[i]);
    free(_server->channels);
    for (int i = 0; _server->channels[i] != NULL; i++)
        free(_server->channels[i]);
    free(_server->messages);
    for (int i = 0; _server->messages[i] != NULL; i++)
        free(_server->messages[i]);
    close(_server->socket);
}
