/*
** EPITECH PROJECT, 2022
** SERVER
** File description:
** AI_Cmd.c
*/

#include"../server.h"
#define ClientAI  getClientByUuid(uuid, server->_allClient)->client
#define _AI  AI_getAIByUuid(uuid, server->_ai)
#define AI_CMD cmd_getCmd_By_Player_Uuid(uuid, server->commands)

void Forward(Server *server, char *uuid)
{
    if (_AI->_orientation == 1)
        _AI->_y -= 1;
    if (_AI->_orientation == 2)
         _AI->_x += 1;
    if (_AI->_orientation == 3)
        _AI->_y += 1;
    if (_AI->_orientation == 4)
         _AI->_x -= 1;
    if (_AI->_x < 0)
        _AI->_x = server->_args->width - 1;
    if (_AI->_y < 0)
        _AI->_y = server->_args->height - 1;
    if (_AI->_x > server->_args->width - 1)
        _AI->_x = 0;
    if (_AI->_y > server->_args->height - 1)
        _AI->_y = 0;
    write(ClientAI->_socket, "ok\n", 3);
    _AI->statu = true;

}

void Right(Server *server, char *uuid)
{
    if (_AI->_orientation == 4) {
        _AI->_orientation = 1;
        write(ClientAI->_socket, "ok\n", 3);
        return;
    }
    if (_AI->_orientation == 3) {
        _AI->_orientation = 4;
        write(ClientAI->_socket, "ok\n", 3);
        return;
    }
    if (_AI->_orientation == 2) {
        _AI->_orientation = 3;
        write(ClientAI->_socket, "ok\n", 3);

        return;
    }
    if (_AI->_orientation == 1) {
        _AI->_orientation = 2;
        write(ClientAI->_socket, "ok\n", 3);
        return;
    }
    _AI->statu = true;
}

void Left(Server *server, char *uuid)
{
    if (_AI->_orientation == 4) {
        _AI->_orientation = 3;
        write(ClientAI->_socket, "ok\n", 3);
        return;
    }
    if (_AI->_orientation == 3) {
        _AI->_orientation = 2;
        write(ClientAI->_socket, "ok\n", 3);
        return;
    }
    if (_AI->_orientation == 2) {
        _AI->_orientation = 1;
        write(ClientAI->_socket, "ok\n", 3);
        return;
    }
    if (_AI->_orientation == 1) {
        _AI->_orientation = 4;
        write(ClientAI->_socket, "ok\n", 3);
        return;
    }
    _AI->statu = true;
}

void GetInventory(Server *server, char *uuid)
{
    char *resp = malloc(sizeof(char) * 150);
    sprintf(resp, "[food %d, deraumere %d, linemate %d, mendiane %d, phiras %d, sibur %d, thystame %d]\n",
    _AI->_inventaire->food, _AI->_inventaire->deraumere,_AI->_inventaire->linemate,_AI->_inventaire->mendiane,
    _AI->_inventaire->phiras, _AI->_inventaire->sibur, _AI->_inventaire->thystame);
    write(ClientAI->_socket, resp, strlen(resp));
    _AI->statu = true;
}

void take_obj(Server *server, char *uuid) {
    char *arg = strtok(server->exec_list->cmd, " ");
    int verif = 0;
    arg = strtok(NULL, " ");
    if (strcmp(arg, "deraumere\n") == 0) {
        if (getTilesByXY(server->_map, _AI->_x, _AI->_y)->deraumere > 0) {
            getTilesByXY(server->_map, _AI->_x, _AI->_y)->deraumere --, verif=1;
            _AI->_inventaire->deraumere ++;
        }
    }
    if (strcmp(arg, "food\n") == 0) {
        if (getTilesByXY(server->_map, _AI->_x, _AI->_y)->food > 0) {
            getTilesByXY(server->_map, _AI->_x, _AI->_y)->food --, verif=1;
            _AI->_inventaire->food ++;
        }
    }
    if (strcmp(arg, "linemate\n") == 0) {
        if (getTilesByXY(server->_map, _AI->_x, _AI->_y)->linemate > 0) {
            getTilesByXY(server->_map, _AI->_x, _AI->_y)->linemate --, verif=1;
            _AI->_inventaire->linemate ++;
        }
    }
    if (strcmp(arg, "mendiane\n") == 0) {
        if (getTilesByXY(server->_map, _AI->_x, _AI->_y)->mendiane > 0) {
            getTilesByXY(server->_map, _AI->_x, _AI->_y)->mendiane --, verif=1;
            _AI->_inventaire->mendiane ++;
        }
    }
    if (strcmp(arg, "phiras\n") == 0) {
        if (getTilesByXY(server->_map, _AI->_x, _AI->_y)->phiras > 0) {
            getTilesByXY(server->_map, _AI->_x, _AI->_y)->phiras --, verif=1;
            _AI->_inventaire->phiras ++;
        }
    }
    if (strcmp(arg, "sibur\n") == 0) {
        if (getTilesByXY(server->_map, _AI->_x, _AI->_y)->sibur > 0) {
            getTilesByXY(server->_map, _AI->_x, _AI->_y)->sibur --, verif=1;
            _AI->_inventaire->sibur ++;
        }
    }
    if (strcmp(arg, "thystame\n") == 0) {
        if (getTilesByXY(server->_map, _AI->_x, _AI->_y)->thystame > 0) {
            getTilesByXY(server->_map, _AI->_x, _AI->_y)->thystame --, verif=1;
            _AI->_inventaire->thystame ++;
        }
    }
    if (verif == 1) {
        write(ClientAI->_socket, "ok\n", 3);
        resource_collecting(server, uuid, 1);
    }
    else
        write(ClientAI->_socket, "ko\n", 3);
    _AI->statu = true;
}

void drop_obj(Server *server, char *uuid, int nrbOfItem) {
    char *arg = strtok(server->exec_list->cmd, " ");
    int verif = 0;
    arg = strtok(NULL, " ");
    if (strcmp(arg, "deraumere\n") == 0) {
        if (_AI->_inventaire->deraumere > 0) {
            getTilesByXY(server->_map, _AI->_x, _AI->_y)->deraumere ++, verif=1;
            _AI->_inventaire->deraumere --;
        }
    }
    if (strcmp(arg, "food\n") == 0) {
        if (_AI->_inventaire->food > 0) {
            getTilesByXY(server->_map, _AI->_x, _AI->_y)->food ++, verif=1;
            _AI->_inventaire->food --;
        }
    }
    if (strcmp(arg, "linemate\n") == 0) {
        if (_AI->_inventaire->linemate > 0) {
            getTilesByXY(server->_map, _AI->_x, _AI->_y)->linemate ++, verif=1;
            _AI->_inventaire->linemate --;
        }
    }
    if (strcmp(arg, "mendiane\n") == 0) {
        if (_AI->_inventaire->mendiane > 0) {
            getTilesByXY(server->_map, _AI->_x, _AI->_y)->mendiane ++, verif=1;
            _AI->_inventaire->mendiane --;
        }
    }
    if (strcmp(arg, "phiras\n") == 0) {
        if (_AI->_inventaire->phiras > 0) {
            getTilesByXY(server->_map, _AI->_x, _AI->_y)->phiras ++, verif=1;
            _AI->_inventaire->phiras --;
        }
    }
    if (strcmp(arg, "sibur\n") == 0) {
        if (_AI->_inventaire->sibur > 0) {
            getTilesByXY(server->_map, _AI->_x, _AI->_y)->sibur ++, verif=1;
            _AI->_inventaire->sibur --;
        }
    }
    if (strcmp(arg, "thystame\n") == 0) {
        if (_AI->_inventaire->thystame > 0) {
            getTilesByXY(server->_map, _AI->_x, _AI->_y)->thystame ++, verif=1;
            _AI->_inventaire->thystame --;
        }
    }
    if (verif == 1) {
        write(ClientAI->_socket, "ok\n", 3);
        resource_dropping(server, uuid, 1);
    }
    else
        write(ClientAI->_socket, "ko\n", 3);
    _AI->statu = true;
}

void Fork_ai(Server *server, char *uuid)
{
    server->_egg = egg_pushBack(_AI->_x, _AI->_y, _AI->_equipe, server->_egg);
    Egg *tmp = server->_egg;
    for (;tmp->next != NULL; tmp = tmp->next);
    an_egg_was_laid_by_a_player(server, uuid, tmp->uuid);
    write(ClientAI->_socket, "ok\n", 3);
    _AI->statu = true;
}

void Incantation(Server *server, char *uuid)
{
    if (_AI->_level == 1) {
        if (getTilesByXY(server->_map, _AI->_x, _AI->_y)->linemate >= 1)
            _AI->_level++;
            getTilesByXY(server->_map, _AI->_x, _AI->_y)->linemate--;
    }
    if (_AI->_level == 2) {
        if (getTilesByXY(server->_map, _AI->_x, _AI->_y)->linemate >= 1 &&
        getTilesByXY(server->_map, _AI->_x, _AI->_y)->deraumere >= 1 &&
        getTilesByXY(server->_map, _AI->_x, _AI->_y)->nbPLAYERS >= 2) {
            _AI->_level++;
            getTilesByXY(server->_map, _AI->_x, _AI->_y)->linemate--;
            getTilesByXY(server->_map, _AI->_x, _AI->_y)->deraumere--;
        }
    }
    if (_AI->_level == 3) {
        if (getTilesByXY(server->_map, _AI->_x, _AI->_y)->linemate >= 2 &&
        getTilesByXY(server->_map, _AI->_x, _AI->_y)->phiras >= 2 &&
        getTilesByXY(server->_map, _AI->_x, _AI->_y)->sibur >= 1 &&
        getTilesByXY(server->_map, _AI->_x, _AI->_y)->nbPLAYERS >= 2) {
            _AI->_level++;
            getTilesByXY(server->_map, _AI->_x, _AI->_y)->linemate-=2;
            getTilesByXY(server->_map, _AI->_x, _AI->_y)->phiras-=2;
            getTilesByXY(server->_map, _AI->_x, _AI->_y)->sibur--;
        }
    }
    if (_AI->_level == 4) {
        if (getTilesByXY(server->_map, _AI->_x, _AI->_y)->linemate >= 1 &&
        getTilesByXY(server->_map, _AI->_x, _AI->_y)->deraumere >= 1 &&
        getTilesByXY(server->_map, _AI->_x, _AI->_y)->sibur >= 1 &&
        getTilesByXY(server->_map, _AI->_x, _AI->_y)->phiras >= 1 &&
        getTilesByXY(server->_map, _AI->_x, _AI->_y)->nbPLAYERS >= 4) {
            _AI->_level++;
            getTilesByXY(server->_map, _AI->_x, _AI->_y)->linemate--;
            getTilesByXY(server->_map, _AI->_x, _AI->_y)->deraumere--;
            getTilesByXY(server->_map, _AI->_x, _AI->_y)->sibur--;
            getTilesByXY(server->_map, _AI->_x, _AI->_y)->phiras--;
        }
    }
    if (_AI->_level == 5) {
        if (getTilesByXY(server->_map, _AI->_x, _AI->_y)->linemate >= 1 &&
        getTilesByXY(server->_map, _AI->_x, _AI->_y)->deraumere >= 2 &&
        getTilesByXY(server->_map, _AI->_x, _AI->_y)->sibur >= 1 &&
        getTilesByXY(server->_map, _AI->_x, _AI->_y)->mendiane >= 3 &&
        getTilesByXY(server->_map, _AI->_x, _AI->_y)->nbPLAYERS >= 4) {
            _AI->_level++;
            getTilesByXY(server->_map, _AI->_x, _AI->_y)->linemate--;
            getTilesByXY(server->_map, _AI->_x, _AI->_y)->deraumere-=2;
            getTilesByXY(server->_map, _AI->_x, _AI->_y)->sibur --;
            getTilesByXY(server->_map, _AI->_x, _AI->_y)->mendiane-=3;
        }

    }
    if (_AI->_level == 6) {
        if (getTilesByXY(server->_map, _AI->_x, _AI->_y)->linemate >= 1 &&
        getTilesByXY(server->_map, _AI->_x, _AI->_y)->deraumere >= 2 &&
        getTilesByXY(server->_map, _AI->_x, _AI->_y)->sibur >= 3 &&
        getTilesByXY(server->_map, _AI->_x, _AI->_y)->phiras >= 1 &&
        getTilesByXY(server->_map, _AI->_x, _AI->_y)->nbPLAYERS >= 6) {
            _AI->_level++;
            getTilesByXY(server->_map, _AI->_x, _AI->_y)->linemate--;
            getTilesByXY(server->_map, _AI->_x, _AI->_y)->deraumere-=2;
            getTilesByXY(server->_map, _AI->_x, _AI->_y)->sibur-=3;
            getTilesByXY(server->_map, _AI->_x, _AI->_y)->phiras--;
        }

    }
    if (_AI->_level == 7) {
        if (getTilesByXY(server->_map, _AI->_x, _AI->_y)->linemate >= 2 &&
        getTilesByXY(server->_map, _AI->_x, _AI->_y)->deraumere >= 2 &&
        getTilesByXY(server->_map, _AI->_x, _AI->_y)->sibur >= 2 &&
        getTilesByXY(server->_map, _AI->_x, _AI->_y)->phiras >= 2 &&
        getTilesByXY(server->_map, _AI->_x, _AI->_y)->thystame >= 1 &&
        getTilesByXY(server->_map, _AI->_x, _AI->_y)->nbPLAYERS >= 6) {
            _AI->_level++;
            getTilesByXY(server->_map, _AI->_x, _AI->_y)->linemate-=2;
            getTilesByXY(server->_map, _AI->_x, _AI->_y)->deraumere-=2;
            getTilesByXY(server->_map, _AI->_x, _AI->_y)->sibur-=2;
            getTilesByXY(server->_map, _AI->_x, _AI->_y)->phiras-=2;
            getTilesByXY(server->_map, _AI->_x, _AI->_y)->thystame --;
        }
    }
    end_of_an_incantation(server, uuid);
    _AI->statu = true;

}

void Connect_nbr(Server *server, char *uuid)
{
    char *resp = malloc(sizeof(char) * 6);
    sprintf(resp, "%d\n", checkNbrEmptySlot(server, _AI->_equipe));
    write(ClientAI->_socket, resp, strlen(resp));
    _AI->statu = true;
}

void Death_Player(Server *server, char *uuid)
{
    CommandeList *commands = server->_commands;
    ClientList *client = server->_allClient;
    AI *AIlist = server->_ai;
    if (strcmp(ClientAI->type, "AI") == 0) {
        if (_AI->_timeleft < 0) {
            write(ClientAI->_socket, "dead\n", 5);
            for (int a = 0; commands != NULL; commands = commands->next, a++) {
                if (strcmp(uuid, commands->player_uuid) == 0) {
                    server->_commands = cmd_erase_at(a, server->_commands);
                }
            }
            int e = 0;
            for (;strcmp(getEquipeByName(server,  _AI->_equipe)->_player_uuid[e], uuid) != 0; e++);
            getEquipeByName(server,  _AI->_equipe)->_player_uuid[e] = strdup("undefined");
            server->_egg = egg_eraseByEquipe(_AI->_equipe, server->_egg);
            for (int c = 0; AIlist != NULL; AIlist = AIlist->next, c++) {
                if (strcmp(uuid, AIlist->_uuid) == 0) {
                    server->_ai = AI_erase_at(c, server->_ai);
                }
            }
            for (int b = 0; client != NULL; client = client->next, b++) {
                if (strcmp(uuid, client->client->_uuid) == 0) {
                    FD_CLR(ClientAI->_socket, &server->tmp_fds);
                    close(ClientAI->_socket);
                    strcpy(ClientAI->type, "undefined");
                    server->_allClient = erase_at(b, server->_allClient);
                }
            }
            death_of_a_player(server, uuid);
        }
    }
}

void add_AI_commandes(Server *server, char *uuid)
{
    float f = server->_args->freq;
    if (strcmp (ClientAI->type, "AI") == 0) {
        if (strcmp(server->_buffer, "Forward\n") == 0)
            server->_commands = cmd_pushBack(server->_buffer, uuid, 7/f, server->_commands);
        if (strcmp(server->_buffer, "Right\n") == 0)
            server->_commands = cmd_pushBack(server->_buffer, uuid, 7/f, server->_commands);
        if (strcmp(server->_buffer, "Left\n") == 0)
            server->_commands = cmd_pushBack(server->_buffer, uuid, 7/f, server->_commands);
        if (strcmp(server->_buffer, "Look\n") == 0)
            server->_commands = cmd_pushBack(server->_buffer, uuid, 7/f, server->_commands);
        if (strcmp(server->_buffer, "Inventory\n") == 0)
            server->_commands = cmd_pushBack(server->_buffer, uuid, 1/f, server->_commands);
        if (strncmp(server->_buffer, "Broadcast ", 10) == 0)
            server->_commands = cmd_pushBack(server->_buffer, uuid, 7/f, server->_commands);
        if (strcmp(server->_buffer, "Connect_nbr\n") == 0)
            server->_commands = cmd_pushBack(server->_buffer, uuid, 0/f, server->_commands);
        if (strcmp(server->_buffer, "Fork\n") == 0)
            server->_commands = cmd_pushBack(server->_buffer, uuid, 42/f, server->_commands);
        if (strcmp(server->_buffer, "Eject\n") == 0)
            server->_commands = cmd_pushBack(server->_buffer, uuid, 7/f, server->_commands);
        if (strncmp(server->_buffer, "Take ", 5) == 0)
            server->_commands = cmd_pushBack(server->_buffer, uuid, 7/f, server->_commands);
        if (strncmp(server->_buffer, "Set ", 4) == 0)
            server->_commands = cmd_pushBack(server->_buffer, uuid, 7/f, server->_commands);
        if (strcmp(server->_buffer, "Incantation\n") == 0)
            server->_commands = cmd_pushBack(server->_buffer, uuid, 300/f, server->_commands);
    }
}