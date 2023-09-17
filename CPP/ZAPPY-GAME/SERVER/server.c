/*
** EPITECH PROJECT, 2022
** SERVER
** File description:
** server.c
*/

#include "server.h"


void init_server(Server *server)
{
    srand(time(NULL));
    server->_time = 0.0, server->_lastRefill = 0.0;
    server->_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server->_socket == 0)
        printf("socket error\n");
    server->_server_address.sin_family = AF_INET;
    server->_server_address.sin_addr.s_addr = INADDR_ANY;
    server->_server_address.sin_port = htons(server->_args->port);
    server->timeout = NULL;
    server->timeout = (struct timeval*)malloc(sizeof(struct timeval));
    server->exec_list = NULL;
    if (bind(server->_socket, (struct sockaddr *)&server->_server_address, sizeof(server->_server_address)) == -1)
        printf("Failed to bind\n");
    if (listen(server->_socket, 10000) == -1)
        printf("Failed to bind\n");
    FD_ZERO(&server->read_fds);
    FD_ZERO(&server->tmp_fds);
}

void new_client(Server *server)
{
    uuid_t uuid;
    char uuid_str[37];
    uuid_generate(uuid);
    uuid_unparse(uuid, uuid_str);
    server->_allClient = pushBack(server->_client_socket, uuid_str, "undefined",server->_allClient);
}

void select_handel(Server *server)
{
    refreshTimeout(server);
    int selec = select(server->max_fd + 1, &server->tmp_fds, NULL, NULL, server->timeout);
    refillMap(server, 0);
    refreshPlayerLifeOrDeath(server);
    execAllCmd(server);
    execGuiCMD(server);
}

void set_client_fd(Server *server)
{
    server->tmp_fds = server->read_fds;
    FD_SET(server->_socket, &server->tmp_fds);
    for(ClientList *tmp = server->_allClient; tmp != NULL; tmp = tmp->next) {
        if (tmp->client->_socket > 0) {
            FD_SET(tmp->client->_socket, &server->tmp_fds);
            if (tmp->client->_socket > server->max_fd)
                server->max_fd = tmp->client->_socket;
        }
    }
    select_handel(server);
    if (FD_ISSET(server->_socket, &server->tmp_fds)) {
        server->_client_socket = accept(server->_socket, (struct sockaddr *)&server->_client_address, &server->_client_address_length);
        new_client(server);
        server->_client_address_length = sizeof(server->_client_address);
    }
}

void checkWinGame(Server *server)
{
    AI *ai = server->_ai;
    int winner = 0;
    char *reponse = malloc(sizeof(char) * 1000);
    for (int i = 0; server->_equipes[i] != NULL ; i++) {
        for ( AI *ai = server->_ai; ai != NULL; ai = ai->next) {
            if (strcmp(ai->_equipe, server->_equipes[i]->name) == 0 && ai->_level == 8) {
                winner ++;
            }
            if (winner == 6) {
                for (;server->_allClient != NULL; server->_allClient = server->_allClient->next) {
                    if (strcmp(server->_allClient->client->type, "GUI") == 0) {
                        sprintf(reponse, "seg %s\n", server->_equipes[i]->name);
                        write(server->_allClient->client->_socket, reponse, strlen(reponse));
                    }
                }
                exit(0);
            }
        }
        winner = 0;
    }
}

void start_server(Server *server)
{
    while (1) {
        refreshPlayerPos(server);
        refreshEquipeSlot(server);
        set_client_fd(server);
        get_request(server);
        checkWinGame(server);
    }
}


