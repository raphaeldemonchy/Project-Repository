/*
** EPITECH PROJECT, 2023
** my_other_cmd
** File description:
** my_other_cmd
*/

#include "../serveur/include/serveur.h"

void cmd_dele(int pos, char *arg, server *_server)
{
    if (_server->client_slot[pos]->is_connecte != true) {
        write(cli_sock, "530 need login before.\r\n", 24);
        return;
    }
    if (access(realpath(arg,NULL), F_OK) == 0) {
        int rem = remove(realpath(arg, NULL));
        if (rem == -1 && errno == EISDIR) {
            rem = rmdir(realpath(arg, NULL));
        }
        write(_server->client_slot[pos]->socket, "250 \r\n", 6);
    } else
        write(_server->client_slot[pos]->socket, "550 \r\n", 6);
}

void cmd_help(int pos, char *arg, server *_server)
{
    if (_server->client_slot[pos]->is_connecte != true) {
        write(cli_sock, "530 need login before.\r\n", 24);
        return;
    }
    write(_server->client_slot[pos]->socket, "214 \r\n", 6);
}

void cmd_noop(int pos, char *arg, server *_server)
{
    if (_server->client_slot[pos]->is_connecte != true) {
        write(cli_sock, "530 need login before.\r\n", 24);
        return;
    }
    write(_server->client_slot[pos]->socket, "200 \r\n", 6);
}
