/*
** EPITECH PROJECT, 2022
** my_FTP
** File description:
** start_cmd.c
*/

#include "../server.h"

int create_tcp_socket(int new_socket)
{
    new_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (new_socket < 0)
        perror("Socket creation failed."), exit(84);
    return new_socket;
}

sock_in config(int s, sock_in tar, in_port_t port, in_addr_t addr)
{
    tar.sin_family = AF_INET;
    tar.sin_port = port;
    tar.sin_addr.s_addr = addr;
    if (bind(s, (struct sockaddr *)&tar, sizeof(tar)) != 0)
        perror("Bind failed.\n"), exit(84);
    return tar;
}

void connection_request_list(int socket, int size_list)
{
    if (listen(socket, size_list) != 0)
        perror("Listen failed.\n"), exit(84);
}
