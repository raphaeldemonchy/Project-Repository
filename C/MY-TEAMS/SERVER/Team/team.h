/*
** EPITECH PROJECT, 2022
** myTeams
** File description:
** Team.h
*/

#pragma once
#include <string.h>

typedef struct team_s {
    char *name;
    char *uuid;
    char *description;
    char **users;
}team;

team *get_team_by_name(team *teams, char *name);
team *get_team_by_uuid(team *teams, char *uuid);
