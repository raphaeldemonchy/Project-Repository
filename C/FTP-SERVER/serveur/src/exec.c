/*
** EPITECH PROJECT, 2023
** exec
** File description:
** exec
*/

#include "../include/serveur.h"

void connexion_que(int socket, int size_list)
{
    if (listen(socket, size_list) != 0)
        exit(ERROR);
}

int init_socket(int new_socket)
{
    new_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (new_socket < 0) {

    }
    return (new_socket);
}

sock_in config(int s, sock_in tar, in_port_t port, in_addr_t addr)
{
    tar.sin_family = AF_INET;
    tar.sin_port = port;
    tar.sin_addr.s_addr = addr;
    if (bind(s, (struct sockaddr *)&tar, sizeof(tar)) != 0) {

    }
    return (tar);
}
