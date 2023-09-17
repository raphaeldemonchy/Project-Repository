/*
** EPITECH PROJECT, 2022
** SERVER
** File description:
** Exec.c
*/

#include "../server.h"

int check_if_ia_have_cmd(char *ia_uuid, CommandeList *CmdInExec) {
    CommandeList *tmp = CmdInExec;
    int verif = 0;
    for (;tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->player_uuid, ia_uuid) == 0) {
            verif = 1;
        }
    }
    return verif;
}

void sendGui_info(Server *server, char *cmd, char  *uuid)
{
    if (strcmp(cmd, "Incantation\n") == 0)
        start_of_an_incantation(server, uuid);
    if (strcmp(cmd, "Fork\n") == 0)
        egg_laying_by_the_player(server, uuid);
}


void stockExecList(Server *server)
{
    AI *ai = server->_ai;
    CommandeList *cmd = server->_commands;
    int i = 0;
    for (;cmd != NULL; cmd = cmd->next, i++) {
        if (check_if_ia_have_cmd(cmd->player_uuid, server->exec_list) == 0
        && AI_getAIByUuid(cmd->player_uuid, ai)->statu == true) {
            sendGui_info(server, cmd->cmd, cmd->player_uuid);
            server->exec_list = cmd_add_at2(cmd_lenList(server->exec_list),cmd->cmd, cmd->player_uuid, server->_time, cmd->timeleft, server->exec_list);
            server->_commands = cmd_erase_at(i, server->_commands);
            // AI_getAIByUuid(cmd->player_uuid, ai)->statu = false;
        }
    }
}
void refreshTimeout(Server *server)
{
    stockExecList(server);
    server->timeout->tv_sec = 1;
    server->timeout->tv_usec = 0;
    server->clock_end = time(NULL);
    server->_time = difftime(server->clock_end, server->clock_start);
}
void execCMD(CommandeList *cmd, Server *server)
{
    if (strcmp(cmd->cmd, "Look\n") == 0)
        Look(server, cmd->player_uuid);
    if (strcmp(cmd->cmd, "Right\n") == 0)
        Right(server, cmd->player_uuid);
    if (strcmp(cmd->cmd, "Left\n") == 0)
        Left(server, cmd->player_uuid);
    if (strcmp(cmd->cmd, "Forward\n") == 0)
        Forward(server, cmd->player_uuid);
    if (strcmp(cmd->cmd, "Inventory\n") == 0)
        GetInventory(server, cmd->player_uuid);
    if (strncmp(cmd->cmd, "Broadcast ", 10) == 0)
        Broadcast(server, cmd->player_uuid);
    if (strcmp(cmd->cmd, "Connect_nbr\n") == 0)
        Connect_nbr(server, cmd->player_uuid);
    if (strcmp(cmd->cmd, "Fork\n") == 0)
        Fork_ai(server, cmd->player_uuid);
    if (strcmp(cmd->cmd, "Eject\n") == 0)
        Eject(server, cmd->player_uuid);
    if (strncmp(cmd->cmd, "Take ", 5) == 0)
        take_obj(server, cmd->player_uuid);
    if (strncmp(cmd->cmd, "Set ", 4) == 0)
        drop_obj(server, cmd->player_uuid, 0);
    if (strcmp(cmd->cmd, "Incantation\n") == 0)
        Incantation(server, cmd->player_uuid);
}

void execGuiCMD(Server *server) {
    for (;server->_gui_cmd != NULL; server->_gui_cmd = server->_gui_cmd->next) {
        if (strncmp(server->_gui_cmd->cmd, "msz\n", 4) == 0)
            map_size(server, server->_gui_cmd->player_uuid);
        if (strncmp(server->_gui_cmd->cmd, "bct", 3) == 0)
            content_of_tile(server , server->_gui_cmd->player_uuid);
        if (strncmp(server->_gui_cmd->cmd, "mct\n", 4) == 0)
            content_of_the_map(server , server->_gui_cmd->player_uuid);
        if (strncmp(server->_gui_cmd->cmd, "tna\n", 4) == 0)
            name_of_all_the_teams(server, server->_gui_cmd->player_uuid);
        if (strncmp(server->_gui_cmd->cmd, "ppo ", 4) == 0)
            players_position(server, server->_gui_cmd->player_uuid);
        if (strncmp(server->_gui_cmd->cmd, "plv", 3) == 0)
            players_level(server, server->_gui_cmd->player_uuid);
        if (strncmp(server->_gui_cmd->cmd, "pin ", 4) == 0)
            players_inventory(server, server->_gui_cmd->player_uuid);
    }
}

void execAllCmd(Server *server) {
    CommandeList *tmp = server->exec_list;
    int i = 0;
     if (tmp != NULL) {
        for (;tmp != NULL; tmp = tmp->next, i++) {
            if (server->_time - tmp->startTime >= tmp->timeleft) {
                execCMD(tmp, server);
                server->exec_list = cmd_erase_at(i, server->exec_list);
            }
        }
     }
}

