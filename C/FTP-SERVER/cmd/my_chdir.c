/*
** EPITECH PROJECT, 2023
** my_chdir
** File description:
** my_chdir
*/

#include "../serveur/include/serveur.h"

char *stock_cwd(int pos, char *arg, server *_server)
{
    char *tmp = my_strdup(_server->client_slot[pos]->working_dir);
    char *real = malloc(sizeof(char) * (strlen(tmp) + strlen(arg)
    + strlen(_server->client_slot[pos]->working_dir)));
    for (int i = 0; i != strlen(tmp); i++)
        real[i] = tmp[i];
    if (arg[0] != '/')
        real = my_strcat(real, "/"),
        real = realpath(my_strcat(real, arg), NULL);
    else
        real = realpath(my_strcat(real, arg), NULL);
    if (strcmp(real, _server->client_slot[pos]->working_dir) == 0) {
        write(cli_sock,"550 no such file or directory.\r\n", 32);
        return NULL;
    }
    if (chdir(real) >= 0) {
        write(cli_sock,"250 \r\n", 6);
        _server->client_slot[pos]->working_dir = realpath(real, NULL);
    } else {
        write(cli_sock,"550 no such file or directory.\r\n", 32);
    }
}

void cmd_cwd(int pos, char *arg, server *_server)
{
    if (_server->client_slot[pos]->is_connecte != true) {
        write(cli_sock,"530 need login before.\r\n", 24);
        return;
    }
    if (arg != NULL) {
        stock_cwd(pos, arg, _server);
        return;
    } else {
        write(cli_sock, "550 no such file or directory.\r\n", 32);
    }
}

void cmd_cdup(int pos, char *arg, server *_server)
{
    if (_server->client_slot[pos]->is_connecte != true) {
        write(cli_sock,
        "530 need login before.\r\n", 24);
        return;
    }
    if (strcmp(_server->client_slot[pos]->working_dir, "/") == 0)
        write(cli_sock, "550 \r\n", 6);
    else {
        my_strcat(_server->client_slot[pos]->working_dir, "/..");
        _server->client_slot[pos]->working_dir =
        realpath(_server->client_slot[pos]->working_dir, NULL);
        chdir(_server->client_slot[pos]->working_dir);
        write(cli_sock, "200 \r\n", 6);
    }

}

void cmd_pwd(int pos, char *arg, server *_server)
{
    if (_server->client_slot[pos]->is_connecte != true) {
        write(cli_sock, "530 need login before.\r\n", 24);
        return;
    }
    write(cli_sock, "257 ", 4);
    write(cli_sock, _server->client_slot[pos]->working_dir,
    strlen(_server->client_slot[pos]->working_dir));
    write(cli_sock, "\r\n", 2);
}
