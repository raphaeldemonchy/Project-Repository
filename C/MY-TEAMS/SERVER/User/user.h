/*
** EPITECH PROJECT, 2022
** myTeams
** File description:
** User.h
*/

#pragma once
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <uuid/uuid.h>
#include "../Save/save.h"

typedef struct user_s {
    char *username;
    char *uuid;
    char **teams;
    bool online;
    int socket;
}user;

user *get_user_by_name(user **users, char *name);
user *get_user_by_uuid(user **users, char  *uuid);
user *add_user(user **users, char *username, int socket);
void add_already_saved_users(user **users, char **users_tab);
