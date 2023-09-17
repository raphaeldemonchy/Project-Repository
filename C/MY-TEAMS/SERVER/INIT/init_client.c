/*
** EPITECH PROJECT, 2022
** my_FTP
** File description:
** init_client.c
*/

#include "../server.h"

void add_client(server *_server)
{
    client *client = malloc(10 * sizeof(client));
    client->socket = 0;
    int i = 0;
    for (; _server->client_slot[i] != NULL; i++);
    _server->client_slot[i] = client;
}

void client_added(server *_server)
{
    int i = 0;
    for (; _server->client_slot[i] != NULL; i++) {
        if (_server->client_slot[i]->socket == 0) {
            _server->client_slot[i]->socket = _server->new_client;
            break;
        }
    }
}

void accept_client_request(server *_server)
{
    if (FD_ISSET(_server->socket, &_server->tmp_fds)) {
        _server->new_client = accept(_server->socket,
        serv_client_addr, &serv_addr_len);
        if (_server->new_client < 0)
            perror("Connection Failed\n"), exit(84);
        add_client(_server);
        client_added(_server);
    }
}

void check_request(int pos, int read, char *buff, server *_server)
{
    char *tmp = malloc(sizeof(char) * 1024);
    char *cmd = malloc(sizeof(char) * 1024);
    char **arg = malloc(sizeof(char*) * 10000);
    if (read == 0) {
        close(cli_sock);
        FD_CLR(cli_sock, &_server->tmp_fds);
        cli_sock = 0;
    } else {
        if (buff != NULL) {
            arg_array(arg ,buff);
            execute_request(pos, arg[0], arg, _server);
        }
    }
}

void get_client_request(server *_server)
{
    char buff[1024];
    int val;
    for (int i = 0; _server->client_slot[i] != NULL; i++) {
        if (FD_ISSET(_server->client_slot[i]->socket, &_server->tmp_fds)) {
            val = read(_server->client_slot[i]->socket, buff, 1024);
            char *result = strdup(buff);
            result[val] = '\0';
            check_request(i, val, result, _server);
        }
    }
}
