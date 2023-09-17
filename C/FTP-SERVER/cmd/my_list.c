/*
** EPITECH PROJECT, 2023
** my_list
** File description:
** my_list
*/

#include "../serveur/include/serveur.h"

void activ_mode_l(int pos, server *_server, char *file)
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

void passiv_mode_l(int pos, server *_server, char * file)
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

char *stockfile(int pos, server *_server, char *arg)
{
    char *file = malloc(sizeof(char) * 100000);
    char *res = malloc(sizeof(char) * 100000);
    char *buffer = my_strdup("ls -l ");
    FILE* pipe;
    if (arg == NULL) {
        pipe = popen(buffer, "r");
        for (;read(fileno(pipe), file, sizeof(file)) > 0;)
            res = strcat(res, file);
        pclose(pipe);
        return file;
    }
    if (access(realpath(arg, NULL), F_OK) == 0) {
        buffer = my_strdup(strcat(buffer, realpath(arg, NULL)));
        pipe = popen(buffer, "r");
        for (;read(fileno(pipe), file, sizeof(file)) > 0;)
            res = strcat(res, file);
        pclose(pipe);
        return file;
    }
    return "\0";
}

void cmd_list(int pos, char *arg, server *_server)
{
    if (_server->client_slot[pos]->is_connecte != true) {
        write(cli_sock, "530 need login before.\r\n", 24);
        return;
    }
    if (_server->client_slot[pos]->data_transfer == NULL) {
        write(cli_sock, "501 PORT or PASV no used.\r\n", 27);
        return;
    }
    char *file = strdup(stockfile(pos, _server, arg));
    if (strcmp(file, "\0") == 0) {
        write(cli_sock, "550 \r\n", 6);
        return;
    }
    if (strcmp (_server->client_slot[pos]->data_transfer, "actif") == 0)
        activ_mode_l(pos, _server, file);
    if (strcmp (_server->client_slot[pos]->data_transfer, "passif") == 0)
        passiv_mode_l(pos, _server, file);
}
