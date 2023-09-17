/*
** EPITECH PROJECT, 2022
** my_FTP_server
** File description:
** main.c
*/

#include "all.h"


void argInfo(char **argv, Server *server)
{
    server->_args = malloc(sizeof(Args));
    for (int i = 0; argv[i] != NULL; i++) {
        if (strcmp(argv[i], "-n") == 0) {
            i++;
            server->_args->nameOfTeam = malloc(sizeof(char *) * 10);
            for (int verif = 0, y = 0; argv[i] != NULL && verif != 1 ; i++, y++) {
                if (argv[i][0] != '-')
                    server->_args->nameOfTeam[y] = strdup(argv[i]);
                else
                    verif = 1, i--;
            }
        }
        if (strcmp(argv[i], "-p") == 0)
            server->_args->port = atoi(argv[i + 1]);
        if (strcmp(argv[i], "-x") == 0)
            server->_args->width = atoi(argv[i + 1]);
        if (strcmp(argv[i], "-y") == 0)
            server->_args->height = atoi(argv[i + 1]);
        if (strcmp(argv[i], "-c") == 0)
            server->_args->cliMaxNbr = atoi(argv[i + 1]);
        if (strcmp(argv[i], "-f") == 0)
            server->_args->freq = atof(argv[i + 1]);
    }
}

void refreshPlayerLifeOrDeath(Server *server)
{
    AI *tmp = server->_ai;
    for (int i = 0;tmp != NULL; tmp = tmp->next, i++) {
        if (server->_time - tmp->_lastRefillLife >= 1) {
            tmp->_timeleft -= 1;
            tmp->_lastRefillLife = server->_time;
            if (tmp->_inventaire->food > 0 && tmp->_timeleft <= 0) {
                tmp->_timeleft += (126 / server->_args->freq);
                tmp->_inventaire->food -= 1;
            }
            Death_Player(server,tmp->_uuid);
        }
    }
}

int main(int argc, char **argv)
{
    Server *server = malloc(sizeof(Server));
    argInfo(argv, server);
    init_server(server);
    initMap(server);
    initEquipe(server);
    server->max_fd = server->_socket;
    server->clock_start = time(&server->clock_start);
    start_server(server);
}
