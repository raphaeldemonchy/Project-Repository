/*
** EPITECH PROJECT, 2022
** SERVER
** File description:
** equip.c
*/

#include "../server.h"

void initEquipe(Server *server)
{
    int nbrOfTeam = 0;
    for(;server->_args->nameOfTeam[nbrOfTeam] != NULL; nbrOfTeam++);
    server->_equipes = malloc(sizeof(Equipe *) * nbrOfTeam);
    for (int i = 0; i != nbrOfTeam; i++) {
        server->_equipes[i] = malloc(sizeof(Equipe));
        server->_equipes[i]->_player_uuid = malloc(sizeof(char*) * 10000);
        server->_equipes[i]->name = strdup(server->_args->nameOfTeam[i]);
        server->_equipes[i]->slot = server->_args->cliMaxNbr;
        for (int j = 0; j != 10000; j++)
             server->_equipes[i]->_player_uuid[j] = strdup("undefined");
    }
}

void addPlayerToEquipe(Server *server, char *name, char *player_uuid)
{
    for (int i = 0; server->_equipes[i] != NULL; i++) {
        if (strcmp(server->_equipes[i]->name, name) == 0) {
            for (int y = 0; server->_equipes[i]->_player_uuid[y] != NULL; y++) {
                if (strcmp(server->_equipes[i]->_player_uuid[y], "undefined") == 0) {
                    if (server->_equipes[i]->slot > server->_args->cliMaxNbr) {
                        death_of_an_egg(server, egg_getByEquipe(server->_equipes[i]->name, server->_egg)->uuid);
                        player_connection_for_an_egg(server, egg_getByEquipe(server->_equipes[i]->name, server->_egg)->uuid);
                    }
                    else
                        connection_of_a_new_player(server, player_uuid);
                    server->_equipes[i]->_player_uuid[y] = strdup(player_uuid);
                    break;
                }
            }
        }
    }
}

int lenEquipePlayers(Server *server, char *name)
{
    int nbr = 0;
    for (int i = 0; server->_equipes[i] != NULL; i++) {
        if (strcmp(server->_equipes[i]->name, name) == 0) {
            for (int j = 0; server->_equipes[i]->_player_uuid[j] != NULL; j++) {
                if (strcmp(server->_equipes[i]->_player_uuid[j], "undefined") != 0)
                    nbr ++;
            }
        }
    }
    return nbr;
}

bool checkIfHaveEnougthSlot(Server *server, char *name)
{
    int verif = 0;
    for (int i = 0; server->_equipes[i] != NULL; i++) {
        if (strcmp(server->_equipes[i]->name, name) == 0) {
            for (int y = 0; server->_equipes[i]->_player_uuid[y] != NULL; y++) {
                if (lenEquipePlayers(server, name) < server->_equipes[i]->slot) {
                    return true;
                }
            }
        }
    }
    return false;
}

int checkNbrEmptySlot(Server *server, char *name)
{
    int slotnbr = 0;
    for (int i = 0; server->_equipes[i] != NULL; i++) {
        if (strcmp(server->_equipes[i]->name, name) == 0) {
            slotnbr = server->_equipes[i]->slot - lenEquipePlayers(server, name);
        }
    }
    return slotnbr;
}

Equipe *getEquipeByName(Server *server, char *name)
{
    for (int i = 0; server->_equipes[i] != NULL; i++) {
        if (strcmp(server->_equipes[i]->name, name) == 0)
            return server->_equipes[i];
    }
    printf("no such\n");
    return NULL;
}

void refreshEquipeSlot(Server *server)
{
    Egg *tmp = server->_egg;
    int nbr = 0;
    for (int i = 0; server->_equipes[i] != NULL; i++) {
        nbr = 0;
        for (; tmp != NULL; tmp = tmp->next) {
            if (strcmp(tmp->equipe, server->_equipes[i]->name) == 0)
                nbr++;
        }
        getEquipeByName(server, server->_equipes[i]->name)->slot = server->_args->cliMaxNbr + nbr;
        tmp = server->_egg;
    }
}

void erasePlayerToEquipe(Server *server, char *name, char *player_uuid)
{
}

void printEquipes(Server *server)
{
        printf("            EQUIPES\n");
    for (int i = 0; server->_equipes[i] != NULL; i++) {
        printf("==============================\n");
        printf("name : %s\n", server->_equipes[i]->name);
        printf("==============================\n");
        printf("players uuid :\n");
        for (int j = 0; server->_equipes[i]->_player_uuid[j] != NULL; j++)
            printf("              %s\n", server->_equipes[i]->_player_uuid[j]);
        printf("==============================\n");
    }
}