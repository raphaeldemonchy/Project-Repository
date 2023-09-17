/*
** EPITECH PROJECT, 2023
** start_srv
** File description:
** start_srv
*/

#include "../include/serveur.h"

void init_server(server *_server, char *port, char *path)
{
    _server->MaxSlot = 10;
    _server->data = "Hello World!\n";
    _server->client_address_length = sizeof(_server->client_address);
    _server->socket = init_socket(_server->socket);
    _server->path = realpath(path, NULL);
    if (chdir (_server->path) == -1)
        exit(84);
    serv_addr = config_socket(_server->socket, serv_addr, PORT, ANY);
    connexion_que(_server->socket, _server->MaxSlot);
    _server->client_slot = malloc(sizeof(client *) * 1000);
    FD_ZERO(&_server->read_fds);
    FD_ZERO(&_server->tmp_fds);
}

void set_new_client_socket(int pos, server *_server)
{
    if (cli_sock > 0) {
        FD_SET(cli_sock, &_server->tmp_fds);
        if (cli_sock > _server->maxfd)
            _server->maxfd = cli_sock;
    }
}

void set_client_slot(server *_server)
{
    _server->tmp_fds = _server->read_fds;
    FD_SET(_server->socket, &_server->tmp_fds);
    for (int i = 0; _server->client_slot[i] != NULL; i++) {
        set_new_client_socket(i, _server);
    }
}

void select_func(server *_server)
{
    if (select(_server->maxfd + 1, &_server->tmp_fds,NULL,NULL,NULL) < 0) {
    }
}

void go_server(server *_server)
{
    _server->maxfd = _server->socket;
    while (1) {
        set_client_slot(_server);
        select_func(_server);
        add_cli_req(_server);
        get_cli_req(_server);
    }
    close(_server->socket);
}
