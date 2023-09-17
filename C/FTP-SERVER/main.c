/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "serveur/include/serveur.h"

void flag_usage(void)
{
    printf("USAGE: ./myftp port path\n");
    printf("\t\tport is the port number on which the server socket listens\n");
    printf("\t\tpath is the path to the home directory for the Anonymous\n");
}

int check_arg(int ac, char **av)
{
    for (int a = 0; av[1][a] != '\0'; a++) {
        if (!isdigit(av[1][a]) || atoi(av[1]) > 65535) {
            printf("ERROR Invalid Port required [int]: use [-h] for usage");
            return ERROR;
        }
    }
    if (access(av[2], F_OK) == -1) {
        printf("ERROR Invalid Path : use [-h] for usage\n");
        return ERROR;
    }
    if (ac != 3)
    return 0;
}

int main(int ac, char **av)
{
    server *_server = malloc(sizeof(server));
    if (check_arg(ac, av) == ERROR)
        exit(ERROR);
    init_server(_server, av[1], av[2]);
    go_server(_server);
}
