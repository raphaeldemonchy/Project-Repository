/*
** EPITECH PROJECT, 2022
** myTeams
** File description:
** User.c
*/

#include "user.h"

user *get_user_by_name(user **users, char *name)
{
    int i = 0;
    for (; strcmp (users[i]->username, name) != 0 ; i++);
        return users[i];
}

user *get_user_by_uuid(user **users, char *uuid)
{
    int i = 0;
    for (; strcmp (users[i]->uuid, uuid) != 0; i++);
    return users[i];
}

user *add_user(user **users, char *username, int socket)
{
    int i = 0;
    uuid_t new_uuid;
    uuid_generate(new_uuid);
    for (;users[i] != NULL; i++);
    users[i] = malloc(sizeof(user));
    users[i]->username = malloc(sizeof(char) * strlen(username) + 1);
    strcpy(users[i]->username, username);
    users[i]->uuid = malloc(sizeof(char) * 36);
    uuid_unparse(new_uuid, users[i]->uuid);
    users[i]->socket = socket;
    char *save = malloc(sizeof(char) *
        (strlen(username) + 1 + strlen(users[i]->uuid)));
    strcat(save, username), strcat(save, "/"), strcat(save, users[i]->uuid);
    add_save_to_file("SERVER/Save/users_save.txt", save);
    free(save);
    memset(save, 0, strlen(save));
}

void add_already_saved_users(user **users, char **users_tab)
{
    for (int i = 0, a = 0; users_tab[i] != NULL; i++) {
        char *line = strtok(users_tab[i], "/");
        users[i] = malloc(sizeof(user));
        while (line != NULL && a < 2) {
            switch (a) {
                case 0: users[i]->username = strdup(line); break;
                case 1: users[i]->uuid = strdup(line); break;
            }
            line = strtok(NULL, "/");
            a++;
        }
        server_event_user_loaded(users[i]->uuid, users[i]->username);
        a = 0;
    }
}
