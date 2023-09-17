/*
** EPITECH PROJECT, 2023
** my_stor
** File description:
** my_stor
*/

#include "../serveur/include/serveur.h"

void activ_mode_s(int pos, server *_server, char *file)
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

void passiv_mode_s(int pos, server *_server, char * file)
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

char *stock_file_s(int pos, char *arg, server *_server)
{
    char *tmp;
    if (_server->client_slot[pos]->data_transfer == NULL)
        return NULL;
    if (realpath(arg, NULL) != NULL)
        tmp = strdup(realpath(arg, NULL));
    else
        return "\0";
    char *file = malloc(sizeof(char) * 100000);
    FILE *fp;
    char ch;
    fp = fopen(tmp, "r");
    if (fp == NULL)
        return "\0";
    for (int i = 0; (ch = fgetc(fp)) != EOF; i++)
        file[i] = ch;
    fclose(fp);
    return file;
}

void cmd_stor(int pos, char *arg, server *_server)
{
    char *file = malloc(sizeof(char) * 100000);
    file = stock_file_s(pos, arg, _server);
    if (_server->client_slot[pos]->is_connecte != true) {
        write(cli_sock, "530 need login before.\r\n", 24);
        return;
    }
    if (file == NULL) {
        write(cli_sock, "501 PORT or PASV no used.\r\n", 27);
        return;
    }
    if (strcmp(file, "\0") == 0)
        write(cli_sock, "550 no such file or directory.\r\n", 32);
    if (strcmp (_server->client_slot[pos]->data_transfer, "actif") == 0)
        activ_mode_s(pos, _server, file);
    if (strcmp (_server->client_slot[pos]->data_transfer, "passif") == 0)
        passiv_mode_s(pos, _server, file);

}
