/*
** EPITECH PROJECT, 2022
** myTeams
** File description:
** handleAnswer2.c
*/

#include "../client.h"

void handle_login(char **answer, client *_client)
{
    _client->_user->username = strdup(answer[1]);
    _client->_user->uuid = strdup(answer[2]);
    _client->_user->online = true;
    client_event_logged_in(_client->_user->uuid, _client->_user->username);
}

void handle_logout(char **answer, client *_client)
{
    client_event_logged_out(_client->_user->uuid, _client->_user->username);
    _client->_user->online = false;
    free(_client->_user->username), _client->_user->username = NULL;
    free(_client->_user->uuid), _client->_user->uuid = NULL;
    _client->_user->uuid = strdup("0");
}

void handle_all_users(char **tab, client *_client)
{
    char *tmp;
    int a = 0;
    for (int i = 0; tab[i + 1] != NULL; i++) {
        char *uuid = malloc(sizeof(char) * 200);
        char *username = malloc(sizeof(char) * 200);
        char *statu = malloc(sizeof(char) * 200);
        tmp = strtok(tab[i], "|");
        while (tmp != NULL && a < 3) {
            switch (a) {
                case 0: strcpy(username, tmp); break;
                case 1: strcpy(uuid, tmp); break;
                case 2: strcpy(statu, tmp); break;
            }
            tmp = strtok(NULL, "|");
            a++;
        }
        a = 0;
        client_print_users(uuid, username, atoi(statu));
    }
}

void handle_user(char **tab, client *_client)
{
    char *tmp;
    int a = 0;
    char *uuid = malloc(sizeof(char) * 200);
    char *username = malloc(sizeof(char) * 200);
    char *statu = malloc(sizeof(char) * 200);
    tmp = strtok(tab[0], "|");
    while (tmp != NULL && a < 3) {
        switch (a) {
            case 0: strcpy(username, tmp); break;
            case 1: strcpy(uuid, tmp); break;
            case 2: strcpy(statu, tmp); break;
        }
        tmp = strtok(NULL, "|");
        a++;
    }
    a = 0;
    client_print_user(uuid, username, atoi(statu));
}

void handle_messages(char **arg, client *_client)
{
    time_t date;
    int a = 0;
    char *sender, *receiver, *content, *time;
    for (int y = 0; arg[y] != NULL; y++) {
        char *tmp = strtok(arg[y], "&");
        while (tmp != NULL && a < 4) {
            switch (a) {
                case 0: sender = strdup(tmp); break;
                case 1: receiver = strdup(tmp); break;
                case 2: time = strdup(tmp); break;
                case 3: content = strdup(tmp); break;
            }
            tmp = strtok(NULL, "&");
            a++;
        }
        a = 0, client_private_message_print_messages(sender, date, content);
        memset(sender, 0, strlen(sender));
        memset(receiver, 0, strlen(receiver));
        memset(time, 0, strlen(time)), memset(content, 0, strlen(content));
    }
}
