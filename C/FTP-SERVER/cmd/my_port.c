/*
** EPITECH PROJECT, 2023
** my_port
** File description:
** my_port
*/

#include "../serveur/include/serveur.h"

char **stock(char *arg)
{
    int vir = 0, x = 0, y = 0;
    char **tab = malloc(sizeof(char *) * 7);
    tab[0] = malloc(sizeof(char) * 30);
    for (int i = 0; arg[i + 1] != '\0'; i++, x++) {
        if (arg[i] == ',') {
            tab[y][x] = '\0';
            x = 0, y++, i++,vir++;
            tab[y] = malloc(sizeof(char) * 30);
        } else if (arg[i] < '0' || arg[i] > '9')
            return NULL;
            tab[y][x] = arg[i];
    }
    tab[y][x + 1] = '\0';
    if (vir != 5)
        return NULL;
    return tab;
}

void conf_port(char **address, int pos, server *_server)
{
    char *addr = malloc(sizeof(char) * 100);
    int port = atoi(address[4]) + 256 + atoi(address[5]);
    for (int i = 0; i != 4; i++)
        addr = my_strcat(addr, my_strcat(address[i], "."));
    _server->client_slot[pos]->data_transfer = active_mode;
    _server->client_slot[pos]->data_socket = socket(AF_INET, SOCK_STREAM, 0);
    _server->client_slot[pos]->data_address.sin_family = AF_INET;
    _server->client_slot[pos]->data_address.sin_port = port;
    _server->client_slot[pos]->data_address.sin_addr.s_addr = inet_addr(addr);
    write(cli_sock, "200 active mode enable.\r\n", 25);
}

void cmd_port(int pos, char *arg, server *_server)
{
    if (_server->client_slot[pos]->is_connecte != true) {
        write(cli_sock, "530 need login before.\r\n", 24);
        return;
    }
    if (arg == NULL) {
        write(cli_sock, "501 invalid argument.\r\n", 23);
        return;
    }
    char **tab = malloc(sizeof(char *) * 7);
    tab = stock(arg);
    if (tab != NULL)
        conf_port(tab, pos, _server);
    else {
        write(cli_sock, "550 invalid port given.\r\n", 25);
        return;
    }

}
