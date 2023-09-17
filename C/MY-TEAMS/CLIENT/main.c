/*
** EPITECH PROJECT, 2022
** my_FTP_client
** File description:
** main.c
*/

#include "client.h"

void communication(client *_client, char *buff)
{
    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(STDIN_FILENO, &read_fds);
    FD_SET(_client->socket, &read_fds);
    int max_fd = (_client->socket > STDIN_FILENO) ? _client->socket
        : STDIN_FILENO;
    if (select(max_fd + 1, &read_fds, NULL, NULL, NULL) == -1)
        exit(84);
    if (FD_ISSET(_client->socket, &read_fds)) {
        recv(_client->socket, buff ,1000000, 0);
    }
    if (FD_ISSET(STDIN_FILENO, &read_fds))
        send_request(_client);
    FD_CLR(_client->socket, &read_fds);
}

char *getcmd(char *buff)
{
    char *cmd = malloc(sizeof(char) * 100);
    int i = 0;
    for (; buff[i] != '\0' ; i++) {
        cmd[i] = buff[i];
        if (buff[i] == '|') {
            cmd[i] = '\0';
            return cmd;
        }
    }
    cmd[i - 1] = '\0';
    return cmd;
}

int main(int ac, char **av)
{
    client *_client = malloc(sizeof(client));
    init_client(av[2], _client);
    connect_client(_client);
    while (1) {
        char *serv_answer = malloc(sizeof(char) * 1000000);
        communication(_client, serv_answer);
        if (strlen(serv_answer) != 0) {
            handle_answer(serv_answer,_client);
            memset(_client->buffer, 0, 1024);
        }
    }
    free(_client);
    return 0;
}
