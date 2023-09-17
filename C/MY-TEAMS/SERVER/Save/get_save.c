/*
** EPITECH PROJECT, 2022
** myTeams
** File description:
** get_save.c
*/

#include "../server.h"

void add_save_to_file(char *path, char *value)
{
    FILE *file = fopen(path, "a");
    fprintf(file, "%s\n", value);
    fclose(file);
    get_save_to_file(path);
}

char **get_save_to_file(char *path)
{
    FILE *file = fopen(path, "r");
    char **tab_file = malloc(sizeof(char *) * 10000);
    tab_file[0] = malloc(sizeof(char) * 10000);
    char *line = NULL;
    size_t len = 150;
    int y = 0;
    for (; getline(&line, &len, file) != -1; y++) {
        line[strlen(line) - 1] = '\0';
        tab_file[y] = strdup(line);
    }
    tab_file[y] = NULL;
    return (tab_file);
}
