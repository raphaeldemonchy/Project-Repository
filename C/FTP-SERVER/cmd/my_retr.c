/*
** EPITECH PROJECT, 2023
** my_retr
** File description:
** my_retr
*/

#include "../serveur/include/serveur.h"

void activ_mode(int pos, server *_server, char *file)
{
    connect(_server->client_slot[pos]->data_socket,
    (struct sockaddr*) &_server->client_slot[pos]->data_address,
    sizeof(_server->client_slot[pos]->data_address));
    write(cli_sock, "150 \r\n", 6);
    write(cli_sock, "226 \r\n", 6);
    write(data_sock, file, strlen(file));
    close(data_sock);
    _server->client_slot[pos]->data_transfer = NULL;
}

void passiv_mode(int pos, server *_server, char * file)
{
    socklen_t new_length = sizeof(_server->client_slot[pos]->data_address);
    int new_socket = accept(_server->client_slot[pos]->data_socket,
    (struct sockaddr*) &_server->client_slot[pos]->data_address, &new_length);
    write(cli_sock, "150 \r\n", 6);
    write(cli_sock, "226 \r\n", 6);
    write(new_socket, file, 6);
    close(data_sock);
    close(new_socket);
    _server->client_slot[pos]->data_transfer = NULL;
}

char *stock_file(int pos, char *arg, server *_server)
{
    char *tmp;
    if (_server->client_slot[pos]->data_transfer == NULL)
        return NULL;
    if (realpath(arg, NULL) != NULL)
        tmp = strdup(realpath(arg, NULL));
    else
        return "\0";
    char *file = malloc(sizeof(char) * 100000);
    int o;
    char ch;
    o = open(tmp, O_RDONLY);
    if (o == 0)
        return "\0";
    read(o, file, 100000);
    close(o);
    return file;
}

void cmd_retr(int pos, char *arg, server *_server)
{
    char *file = malloc(sizeof(char) * 100000);
    file = stock_file(pos, arg, _server);
    if (_server->client_slot[pos]->is_connecte != true) {
        write(cli_sock, "530 need login before.\r\n", 24);
        return;
    }
    if (file == NULL) {
        write(cli_sock, "501 PORT or PASV no used.\r\n", 27);
        return;
    }
    if (strcmp(file, "\0") == 0) {
        write(cli_sock, "550 no such file or directory.\r\n", 32);
        return;
    }
    if (strcmp (_server->client_slot[pos]->data_transfer, "actif") == 0)
        activ_mode(pos, _server, file);
    if (strcmp (_server->client_slot[pos]->data_transfer, "passif") == 0)
        passiv_mode(pos, _server, file);
}
