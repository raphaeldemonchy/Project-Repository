/*
** EPITECH PROJECT, 2022
** manage ERROR
** File description:
** manage_error.c
*/

#include "../client.h"

int arg_by_cmd_2(char *cmd)
{
    if (strcmp(cmd, "/subscribe") == 0)
        return 0;
    if (strcmp(cmd, "/subscribed") == 0)
        return 0;
    if (strcmp(cmd, "/unsubscribe") == 0)
        return 0;
    return 0;
}

char *take_arg(char *answer)
{
    char *resultat;
    char *espace = strchr(answer, ' ');
    if (espace != NULL) {
        resultat = strdup(espace + 1);
    } else {
        resultat = strdup("");
    }
    return resultat;
}

int arg_by_cmd(char *cmd)
{
    if (strcmp(cmd, "/help") == 0)
        return 0;
    if (strcmp(cmd, "/login") == 0)
        return 1;
    if (strcmp(cmd, "/logout") == 0)
        return 0;
    if (strcmp(cmd, "/users") == 0)
        return 0;
    if (strcmp(cmd, "/user") == 0)
        return 1;
    if (strcmp(cmd, "/send") == 0)
        return 2;
    if (strcmp(cmd, "/message") == 0)
        return 1;
}

int error_handler(char *buffer, int socket)
{
    if (is_alphanumeric(buffer) == 0) {
        printf("Invalid argument : use alphanumeric char");
        return (84);
    }
    return (0);
}
