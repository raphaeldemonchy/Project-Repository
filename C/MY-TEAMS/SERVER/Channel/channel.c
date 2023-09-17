/*
** EPITECH PROJECT, 2022
** mychannels
** File description:
** channel.c
*/

#include "channel.h"

channel *get_channel_by_name(channel *channels, char *name)
{
    int i = 0;
    for (; strcmp (channels[i].name, name) != 0 ; i++);
    return &channels[i];
}

channel *get_channel_by_uuid(channel *channels, char *uuid)
{
    int i = 0;
    for (; channels[i].uuid != uuid; i++);
    return &channels[i];
}
