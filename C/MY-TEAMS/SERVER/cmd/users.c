/*
** EPITECH PROJECT, 2022
** myTeams
** File description:
** users.c
*/

#include "../server.h"

void users(user **users, int socket)
{
    char *answer = malloc(sizeof(char) * 1000);
    char *uuid;
    char *username;
    char *statu;
    for (int i = 0; users[i] != NULL; i++) {
        uuid = strdup(users[i]->uuid);
        username = strdup(users[i]->username);
        if (users[i]->online == true)
            statu = strdup("1");
        else
            statu = strdup("0");
        strcat(answer, uuid), strcat(answer, "|");
        strcat(answer, username), strcat(answer, "|");
        strcat(answer, statu), strcat(answer, ":");
    }
    send(socket, answer, strlen(answer), 0);
    free(answer);
    memset(answer, 0, 1000);
}

void user_func(user **users, char *uuid, int socket)
{
    char *answer = malloc(sizeof(char) * 1000);
    char *statu;
    if (get_user_by_uuid(users, uuid)->online == true)
        statu = strdup("1");
    else
        statu = strdup("0");
    strcat(answer, uuid), strcat(answer, "|");
    strcat(answer, get_user_by_uuid(users, uuid)->username);
    strcat(answer, "|");
    strcat(answer, statu);
    send(socket, answer, strlen(answer), 0);
    free(answer);
    memset(answer, 0, 1000);
}
