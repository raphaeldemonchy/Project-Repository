/*
** EPITECH PROJECT, 2023
** my_pasv
** File description:
** my_pasv
*/

#include "../serveur/include/serveur.h"

int init_pasv(int pos, server *_server)
{
    _server->client_slot[pos]->data_socket = socket(AF_INET, SOCK_STREAM, 0);
    _server->client_slot[pos]->data_address.sin_family = AF_INET;
    _server->client_slot[pos]->data_address.sin_port = htons(0);
    _server->client_slot[pos]->data_address.sin_addr.s_addr = INADDR_ANY;
    int _bind = bind(_server->client_slot[pos]->data_socket, (struct sockaddr *)
    &_server->client_slot[pos]->data_address,
    sizeof(_server->client_slot[pos]->data_address));
    return _bind;
}

void cmd_pasv(int pos, char *arg, server *_server)
{
    if (_server->client_slot[pos]->is_connecte != true) {
        write(cli_sock, "530 need login before.\r\n", 24);
        return;
    }
    int _bind = init_pasv(pos, _server);
    if (_bind != 0) {
        write(_server->client_slot[pos]->socket, "425 failed\r\n", 12);
        return;
    }
    int _listen = listen(_server->client_slot[pos]->data_socket, 1);
    if (_listen != 0) {
        write(_server->client_slot[pos]->socket, "425 failed\r\n", 12);
        return;
    } else {
        write(cli_sock, "227 passive mode enable\r\n", 25);
        _server->client_slot[pos]->data_transfer = passive_mode;
    }
}
