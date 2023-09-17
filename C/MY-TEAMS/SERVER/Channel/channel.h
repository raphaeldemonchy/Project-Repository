/*
** EPITECH PROJECT, 2022
** mychannels
** File description:
** Channel.h
*/

#pragma once
#include <string.h>

typedef struct channel_s {
    char *name;
    char *uuid;
    char *description;
} channel;

channel *get_channel_by_name(channel *channels, char *name);
channel *get_channel_by_uuid(channel *channels, char *uuid);
