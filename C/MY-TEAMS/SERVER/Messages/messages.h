/*
** EPITECH PROJECT, 2022
** myTeams
** File description:
** messages.h
*/

#pragma once
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../Save/save.h"
#include <time.h>

typedef struct message_s {
    char *content;
    char *dest_uuid;
    char *author_uuid;
    time_t message_times;
}message;

void add_already_saved_msg(message **message, char **messages_tab);
