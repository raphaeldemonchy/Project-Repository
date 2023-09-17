/*
** EPITECH PROJECT, 2022
** myTeams
** File description:
** Team.c
*/

#include "team.h"

team *get_team_by_name(team *teams, char *name)
{
    int i = 0;
    for (; strcmp (teams[i].name, name) != 0 ; i++);
    return &teams[i];
}

team *get_team_by_uuid(team *teams, char *uuid)
{
    int i = 0;
    for (; teams[i].uuid != uuid; i++);
    return &teams[i];
}
