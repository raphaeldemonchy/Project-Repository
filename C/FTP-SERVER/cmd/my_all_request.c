/*
** EPITECH PROJECT, 2023
** my_all_request
** File description:
** my_all_request
*/

#include "../serveur/include/serveur.h"

void exec_req2(int pos, char *cmd, char *arg, server *_server)
{
    if (strcmp(cmd, "DELE") == 0 || strcmp(cmd, "dele") == 0)
        cmd_dele(pos, arg, _server);
    if (strcmp(cmd, "LIST") == 0 || strcmp(cmd, "list") == 0)
        cmd_list(pos, arg ,_server);
    if (strcmp(cmd, "PWD") == 0 || strcmp(cmd, "pwd") == 0)
        cmd_pwd(pos, arg, _server);
    if (strcmp(cmd, "HELP") == 0 || strcmp(cmd, "help") == 0)
        cmd_help(pos, arg, _server);
    if (strcmp(cmd, "NOOP") == 0 || strcmp(cmd, "noop") == 0)
        cmd_noop(pos, arg, _server);
    if (strcmp(cmd, "STOR") == 0 || strcmp(cmd, "stor") == 0)
        cmd_stor(pos, arg, _server);
    if (strcmp(cmd, "RETR") == 0 || strcmp(cmd, "retr") == 0)
        cmd_retr(pos, arg, _server);
}

void exec_req(int pos, char *cmd, char *arg, server *_server)
{
    if (strcmp(cmd, "USER") == 0 || strcmp(cmd, "user") == 0)
        cmd_user(pos, arg, _server);
    if (strcmp(cmd, "PASS") == 0 || strcmp(cmd, "pass") == 0)
        cmd_pass(pos, arg, _server);
    if (strcmp(cmd, "CWD") == 0 || strcmp(cmd, "cwd") == 0)
        cmd_cwd(pos, arg, _server);
    if (strcmp(cmd, "CDUP") == 0 || strcmp(cmd, "cdup") == 0)
        cmd_cdup(pos, arg, _server);
    if (strcmp(cmd, "QUIT") == 0 || strcmp(cmd, "quit") == 0)
        cmd_quit(pos, _server);
    if (strcmp(cmd, "PORT") == 0 || strcmp(cmd, "port") == 0)
        cmd_port(pos, arg, _server);
    if (strcmp(cmd, "PASV") == 0 || strcmp(cmd, "pasv") == 0)
        cmd_pasv(pos, arg, _server);
    exec_req2(pos, cmd, arg, _server);
}
