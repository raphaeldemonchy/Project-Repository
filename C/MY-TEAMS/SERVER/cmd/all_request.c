/*
** EPITECH PROJECT, 2022
** my_FTP
** File description:
** all_request.c
*/

#include "../server.h"

char *get_request_uuid(char **arg)
{
    int i = 0;
    for (; arg[i] != NULL; i++);
    char *tmp = malloc(sizeof(char) * strlen(arg[i - 1]) - 1);
    strcpy(tmp, arg[i - 1]);
    return tmp;
}

void execute_request2(int pos, char *cmd, char **arg, server *_server)
{
}

void execute_request(int pos, char *cmd, char **arg, server *_server)
{
    if (strcmp(cmd, "/help") == 0){}
    if (strcmp(cmd, "/login") == 0)
        login(_server->users, arg, cli_sock);
    if (strcmp(cmd, "/logout") == 0)
        logout(_server->users, get_request_uuid(arg), cli_sock);
    if (strcmp(cmd, "/users") == 0)
        users(_server->users, cli_sock);
    if (strcmp(cmd, "/user") == 0)
        user_func(_server->users, arg[1], cli_sock);
    if (strcmp(cmd, "/send") == 0) {
        message_sended(_server, get_request_uuid(arg),
        arg[1], arg[2]);
    }
    if (strcmp(cmd, "/messages") == 0)
        message_list(_server, arg[1], get_request_uuid(arg), cli_sock);
    execute_request2(pos, cmd, arg, _server);
}
