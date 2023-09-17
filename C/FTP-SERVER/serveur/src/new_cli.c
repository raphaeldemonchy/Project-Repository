/*
** EPITECH PROJECT, 2023
** new_cli
** File description:
** new_cli
*/

#include "../include/serveur.h"

void new_cli(server *_server)
{
    client *client = malloc(10 * sizeof(client));
    client->socket = 0;
    client->username = NULL;
    client->password = NULL;
    client->working_dir = my_strdup(_server->path);
    client->is_pass = false;
    client->is_user = false;
    client->is_connecte = false;
    int i = 0;
    for (; _server->client_slot[i] != NULL; i++);
    _server->client_slot[i] = client;
}

void check_request(int pos, int read, char *buff, server *_server)
{
    char *cmd = malloc(sizeof(char) * 1024);
    char *tmp = malloc(sizeof(char) * 1024);
    char *arg = malloc(sizeof(char) * 1024);
    if (read == 0) {
        close(cli_sock);
        FD_CLR(cli_sock, &_server->tmp_fds);
        cli_sock = 0;
    } else {
        tmp = strtok(buff, "\n\r\t");
        if (tmp != NULL) {
            char *cmd = strtok(tmp, " ");
            char *arg = strtok(NULL, " ");
            exec_req(pos, cmd, arg, _server);
        }
    }
}

void cli_is_added(server *_server)
{
    int a = 0;
    for (; _server->client_slot[a] != NULL; a++) {
        if (_server->client_slot[a]->socket == 0) {
            _server->client_slot[a]->socket = _server->new_client;
            write(_server->client_slot[a]->socket, "220 \r\n", 6);
            break;
        }
    }
}

void add_cli_req(server *_server)
{
    if (FD_ISSET(_server->socket, &_server->tmp_fds)) {
        _server->new_client = accept(_server->socket,
        serv_client_addr, &serv_addr_len);
        if (_server->new_client < 0) {
        }
        new_cli(_server);
        cli_is_added(_server);
    }
}

void get_cli_req(server *_server)
{
    char buff[1024];
    int val;
    for (int a = 0; _server->client_slot[a] != NULL; a++) {
        if (FD_ISSET(_server->client_slot[a]->socket, &_server->tmp_fds)) {
            val = read(_server->client_slot[a]->socket, buff, 1024);
            check_request(a, val, buff, _server);
        }
    }
}
