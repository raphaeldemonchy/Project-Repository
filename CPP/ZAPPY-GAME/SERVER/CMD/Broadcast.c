/*
** EPITECH PROJECT, 2022
** SERVER
** File description:
** Broadcast.c
*/

#include"../server.h"
#include <stdio.h>
#include <math.h>
#include <math.h>
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif
#define ClienSend  getClientByUuid(uuid, server->_allClient)->client
#define ClientRecv  getClientByUuid(AI_receiver->_uuid, server->_allClient)->client
#define AI_Send  AI_getAIByUuid(uuid, server->_ai)
#define AI_Recv  AI_getAIByUuid(AI_receiver->_uuid, server->_ai)
#define AI_CMD cmd_getCmd_By_Player_Uuid(uuid, server->commands)

char* extract_chars_between_positions(const char* str, int start, int end) {
    int length = strlen(str);

    if (start < 0 || end >= length || start > end) {
        printf("Positions invalides.\n");
        return NULL;
    }

    int extracted_length = end - start + 1;
    char* extracted_chars = malloc(sizeof(char) * (extracted_length + 1));
    strncpy(extracted_chars, str + start, extracted_length);
    extracted_chars[extracted_length] = '\0';

    return extracted_chars;
}

void send_message(int socket, int direction, char *message)
{
    char *new_message = malloc(sizeof(char) * 1024);
    sprintf(new_message, "message %d %s", direction, message);
    write(socket, new_message, strlen(new_message));
}

int dir_for_sud(double angle) {
    if (angle >= 0 && angle <= 30 || angle >= 330)
        return 5;
    if (angle >= 30 && angle <= 60)
        return 4;
    if (angle >= 60 && angle <= 120)
        return 3;
    if (angle >= 120 && angle <= 150)
        return 2;
    if (angle >= 150 && angle <= 210)
        return 1;
    if (angle >= 210 && angle <= 240)
        return 8;
    if (angle >= 240 && angle <= 300)
        return 7;
    if (angle >= 300 && angle <= 330)
        return 6;
}
int dir_for_nord(double angle) {
    if (angle >= 0 && angle <= 30 || angle >= 330)
        return 1;
    if (angle >= 30 && angle <= 60)
        return 8;
    if (angle >= 60 && angle <= 120)
        return 7;
    if (angle >= 120 && angle <= 150)
        return 6;
    if (angle >= 150 && angle <= 210)
        return 5;
    if (angle >= 210 && angle <= 240)
        return 4;
    if (angle >= 240 && angle <= 300)
        return 3;
    if (angle >= 300 && angle <= 330)
        return 2;
}
int dir_for_ouest(double angle) {
    if (angle >= 0 && angle <= 30 || angle >= 330)
        return 7;
    if (angle >= 30 && angle <= 60)
        return 6;
    if (angle >= 60 && angle <= 120)
        return 5;
    if (angle >= 120 && angle <= 150)
        return 4;
    if (angle >= 150 && angle <= 210)
        return 3;
    if (angle >= 210 && angle <= 240)
        return 2;
    if (angle >= 240 && angle <= 300)
        return 1;
    if (angle >= 300 && angle <= 330)
        return 8;
}
int dir_for_est(double angle) {
    if (angle >= 0 && angle <= 30 || angle >= 330)
        return 3;
    if (angle >= 30 && angle <= 60)
        return 2;
    if (angle >= 60 && angle <= 120)
        return 1;
    if (angle >= 120 && angle <= 150)
        return 8;
    if (angle >= 150 && angle <= 210)
        return 7;
    if (angle >= 210 && angle <= 240)
        return 6;
    if (angle >= 240 && angle <= 300)
        return 5;
    if (angle >= 300 && angle <= 330)
        return 4;
}

int get_direction_of_message(AI *sender, AI *receiver) {
    if (sender->_x == receiver->_x && sender->_y == receiver->_y)
        return 0;
    double deltaX = sender->_x - receiver->_x;
    double deltaY = sender->_y - receiver->_y;
    double angle = atan2(deltaY, deltaX) * 180.0 / M_PI;
    if (receiver->_orientation == 1)
        return dir_for_nord(angle);
    if (receiver->_orientation == 2)
        return dir_for_est(angle);
    if (receiver->_orientation == 3)
        return dir_for_sud(angle);
    if (receiver->_orientation == 4)
        return dir_for_ouest(angle);
}

void Broadcast(Server *server, char *uuid)
{
    AI *AI_receiver = server->_ai;
    char *message = extract_chars_between_positions(server->exec_list->cmd, 10, strlen(server->exec_list->cmd) - 1);
    // strcat(message, 0);
    for (;AI_receiver != NULL; AI_receiver = AI_receiver->next) {
        if (strcmp(AI_receiver->_uuid, AI_Send->_uuid) != 0)
            send_message(ClientRecv->_socket, get_direction_of_message(AI_Send, AI_receiver) ,message);
    }
    AI_Send->statu = true;
}