/*
** EPITECH PROJECT, 2023
** my_login
** File description:
** my_login
*/

#include "../serveur/include/serveur.h"

void cmd_user(int pos, char *arg, server *_server)
{
    if (arg != NULL) {
        _server->client_slot[pos]->username = my_strdup(arg);
        _server->client_slot[pos]->is_user = true;
        if (strcmp(_server->client_slot[pos]->username, "Anonymous") == 0
        && _server->client_slot[pos]->password == NULL
        && _server->client_slot[pos]->is_pass == true) {
            _server->client_slot[pos]->is_connecte = true;
            write(cli_sock,
            "230 User logged in, proceed.\r\n", 30);
            return;
        }
        write(cli_sock,
        "331 User name okay, need password.\r\n", 36);
    } else
        write(cli_sock, "530 invalid log.\r\n", 18);
}

void cmd_pass(int pos, char *arg, server *_server)
{
    if (arg != NULL) {
        _server->client_slot[pos]->password = my_strdup(arg);
        _server->client_slot[pos]->is_pass = true;
    } else
        _server->client_slot[pos]->password = NULL;
    if (_server->client_slot[pos]->username == NULL) {
        write(cli_sock,
        "332 Need account for login.\r\n", 29);
        return;
    }
    if (_server->client_slot[pos]->username != NULL) {
        if (strcmp(_server->client_slot[pos]->username, "Anonymous") == 0
        && _server->client_slot[pos]->password == NULL) {
            _server->client_slot[pos]->is_connecte = true;
            write(cli_sock,
            "230 User logged in, proceed.\r\n", 30);
            return;
        } else
        write(cli_sock, "530 invalid log.\r\n", 18);
    }
}

void cmd_quit(int pos, server *_server)
{
    write(cli_sock, "221 \r\n", 6);
    close(cli_sock);
    FD_CLR(cli_sock, &_server->tmp_fds);
    cli_sock = 0;
}
