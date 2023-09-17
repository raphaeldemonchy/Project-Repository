/*
** EPITECH PROJECT, 2022
** myTeams
** File description:
** login.c
*/

#include "../server.h"


void all_log_users(user **users, char *answer)
{
    for (int i = 0; users[i] != NULL; i++)
        send(users[i]->socket, answer, strlen(answer), 0);
}

char *construct_answere(char *answer, char *username, char *uuid)
{
    char *tmp = malloc(sizeof(char) * 200);
    tmp = strcpy(tmp, "new_connexion:");
    tmp = strcat(tmp, username), tmp = strcat(tmp, ":");
    answer = strcat(tmp, uuid);
    return (answer);
    memset(tmp, 0, 200), memset(answer, 0, 200);
}

void login(user **users, char **tab, int socket)
{
    int i = 0;
    char *answer = malloc(sizeof(char) * 200);
    for (;users[i] != NULL; i++) {
        if (strcmp(users[i]->username, tab[1]) == 0 &&
        users[i]->online != true) {
            users[i]->online = true;
            users[i]->socket = socket;
            answer = construct_answere(answer, users[i]->username,
                users[i]->uuid);
            server_event_user_logged_in(users[i]->uuid);
            all_log_users(users, answer);
        }
        if (strcmp(users[i]->username, tab[1]) == 0 &&
        users[i]->online == true)
            return;
    }
    add_user(users, tab[1], -1);
    server_event_user_created(users[i]->uuid, users[i]->username);
    login (users, tab, socket);
}

void logout(user **users, char *uuid, int socket)
{
    char *answer = malloc(sizeof(char) * 200);
    if (get_user_by_uuid(users, uuid)->online == true) {
        get_user_by_uuid(users, uuid)->online = false;
        strcpy(answer, "logout:");
        strcat(answer, uuid);
        strcat(answer, ":");
        strcat(answer, get_user_by_uuid(users, uuid)->username);
        server_event_user_logged_out(get_user_by_uuid(users, uuid)->uuid);
        for (int i = 0; users[i] != NULL; i++)
            send(users[i]->socket, answer, strlen(answer), 0);
    }
}
