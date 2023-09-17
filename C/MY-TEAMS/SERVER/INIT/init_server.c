/*
** EPITECH PROJECT, 2022
** my_FTP
** File description:
** init_server.c
*/

#include "../server.h"

void init_server(server *_server, char *port, char *path)
{
    _server->MaxSlot = 10;
    _server->client_address_length = sizeof(_server->client_address);
    _server->socket = create_tcp_socket(_server->socket);
    _server->teams = malloc(sizeof(team*) * 10000);
    _server->users = malloc(sizeof(user*) * 10000);
    _server->channels = malloc(sizeof(channel*) * 10000);
    _server->messages = malloc(sizeof(message*) * 10000);
    init_my_teams(_server);
    serv_addr = config_socket(_server->socket, serv_addr, PORT, ANY);
    connection_request_list(_server->socket, _server->MaxSlot);
    _server->client_slot = malloc(sizeof(client *) * 1000);
    add_already_saved_users(_server->users,
    get_save_to_file("SERVER/Save/users_save.txt"));
    add_already_saved_msg(_server->messages,
    get_save_to_file("SERVER/Save/messages_save.txt"));
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

void start_server1(server *_server)
{
    _server->maxfd = _server->socket;
    while (1) {
        set_client_slot(_server);
        select_func(_server);
        accept_client_request(_server);
        get_client_request(_server);

        char *exit_cmd = malloc(sizeof(char) * 1024);
        if (strcmp(exit_cmd, "/exit\n") == 0) {
            break;
        }
        free(exit_cmd);
    }
    free_data_server(_server);
}
