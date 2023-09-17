/*
** EPITECH PROJECT, 2022
** SERVER
** File description:
** Eject.c
*/

#include "../server.h"
#define ClientAI  getClientByUuid(uuid, server->_allClient)->client
#define _AI  AI_getAIByUuid(uuid, server->_ai)
#define _AI_cible AI_getAIByUuid(aiuuid, server->_ai)
#define AI_CMD cmd_getCmd_By_Player_Uuid(uuid, server->commands)

void EjectMove(char *aiuuid, Server *server)
{
    if (_AI_cible->_orientation == 1) {
        _AI_cible->_y += 1;
        if (_AI_cible->_y > server->_args->height)
            _AI_cible->_y = 0;
    }
    if (_AI_cible->_orientation == 2) {
        _AI_cible->_x -= 1;
        if (_AI_cible->_x < 0)
            _AI_cible->_x = server->_args->width - 1;
    }
    if (_AI_cible->_orientation == 3) {
        _AI_cible->_y -= 1;
        if (_AI_cible->_y < 0)
            _AI_cible->_y = server->_args->height - 1;
    }
    if (_AI_cible->_orientation == 4) {
        _AI_cible->_x += 1;
        if (_AI_cible->_y > server->_args->width)
            _AI_cible->_x = 0;
    }
}

void EjectCancelCmd(char *aiuuid, Server *server)
{
    CommandeList *exec = server->exec_list;
    if (exec == NULL)
        return;
    for (int i = 0 ;exec != NULL; exec = exec->next, i++) {
        if (strcmp(_AI_cible->_uuid, exec->player_uuid) == 0) {
            write(getClientByUuid(exec->player_uuid, server->_allClient)->client->_socket, "ko\n", 3);
            server->exec_list = cmd_erase_at(i, server->exec_list);
            break;
        }
    }
}

void Eject(Server *server, char *uuid)
{
    AI *ai = server->_ai;
    for (int i = 0; ai != NULL; ai = ai->next) {
        if (ai->_y == _AI->_y && ai->_x == _AI->_x && strcmp(uuid, ai->_uuid) != 0) {
            EjectMove(ai->_uuid, server);
            EjectCancelCmd(ai->_uuid, server);
        }
    }
    write(ClientAI->_socket, "ok\n", 3);
    // _AI->statu = true;
}