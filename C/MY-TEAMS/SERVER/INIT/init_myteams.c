/*
** EPITECH PROJECT, 2022
** myTeams
** File description:
** init_myteams.c
*/

#include "../server.h"

void init_my_teams(server *_server)
{
    int i = 0;
    for (; i != 10000; i++) {
        _server->messages[i] = malloc(sizeof(message));
        _server->teams[i] = malloc(sizeof(team));
        _server->channels[i] = malloc(sizeof(channel));
        _server->users[i] = malloc(sizeof(user));
        _server->users[i]->username = malloc(sizeof(char));
        _server->messages[i]->author_uuid = malloc(sizeof(char));
        _server->messages[i]->dest_uuid = malloc(sizeof(char));
        _server->messages[i]->content = malloc(sizeof(char) * 570);
        _server->messages[i] = NULL;
        _server->teams[i] = NULL;
        _server->channels[i] = NULL;
        _server->users[i] = NULL;
    }
}
