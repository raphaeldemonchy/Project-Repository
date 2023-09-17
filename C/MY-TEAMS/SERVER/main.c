/*
** EPITECH PROJECT, 2022
** my_FTP_server
** File description:
** main.c
*/

#include "server.h"

int main(int argc, char **argv)
{
    server *_server = malloc(sizeof(server));
    if (argc < 2 || atoi(argv[1]) > 65535 || atoi(argv[1]) < 0)
        exit(84);
    init_server(_server, argv[1], argv[2]);
    start_server1(_server);
    free(_server);
}
