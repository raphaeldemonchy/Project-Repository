/*
** EPITECH PROJECT, 2023
** client.c
** File description:
** client
*/

#include "client.h"

int create_socket(client *_client)
{
    if ((_client->socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        exit(84);
    }
}

void init_client(char *port, client *_client)
{
    _client->buffer = malloc(sizeof(char) * 10000);
    _client->buffer = strcpy(_client->buffer, "");
    _client->socket = 0;
    _client->socket = create_socket(_client);
    _client->serv_address.sin_port = htons(atoi(port));
    _client->serv_address.sin_family = AF_INET;
    _client->_user = malloc(sizeof(user ));
    _client->_user->uuid = strdup("0");
    if (inet_pton(AF_INET, SERVER_IP, &_client->serv_address.sin_addr) <= 0)
        exit(84);
}

void connect_client(client *_client)
{
    if (connect(_client->socket, (struct sockaddr *)&_client->serv_address,
        sizeof(_client->serv_address)) < 0) {
            exit(84);
    }
}

char  *new_format_buffer(char *buffer)
{
    int verif = 0;
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\"' && verif < 2)
            verif++;
        if (verif == 2)
            verif = 0;
        if (buffer[i] == ' ' && verif == 0)
            buffer[i] = '|';
    }
    return buffer;
}

void send_request(client *_client)
{
    int flags = fcntl(_client->socket, F_GETFL, 0);
    int error_status;
    fcntl(_client->socket, F_SETFL, flags | O_NONBLOCK);
    fgets(_client->buffer, 1024, stdin);
    _client->buffer = new_format_buffer(_client->buffer);
    _client->buffer = remove_quote(_client->buffer);
    if (_client->buffer[0] != '\0') {
        char *finalRequest = malloc(sizeof(char) * 500);
        strncpy(finalRequest, _client->buffer, strlen(_client->buffer) - 1);
        strcat(finalRequest, "|");
        strcat(finalRequest, _client->_user->uuid);
        send(_client->socket, finalRequest, strlen(finalRequest), 0);
        memset(finalRequest, 0, 500);
    }

}
