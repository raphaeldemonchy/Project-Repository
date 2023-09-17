/*
** EPITECH PROJECT, 2022
** myTeams
** File description:
** save.h
*/

#pragma once
#include <stdio.h>
#include "../../libs/myteams/logging_client.h"
#include "../../libs/myteams/logging_server.h"
void add_save_to_file(char *path, char *value);
char **get_save_to_file(char *path);
