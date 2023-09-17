#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/time.h>

typedef struct CLIENT {
    int _socket;
    char *type;
    struct sockaddr_in _addr;
    char * _uuid;
}Client;


typedef struct client_s{
    Client *client;
    struct client_s *next;
}ClientList;

typedef struct CommandeList_l {
    char *player_uuid;
    char *cmd;
    double timeleft;
    double startTime;
    struct CommandeList_l *next;
}CommandeList;

ClientList *createCell(int socket, char *uuid, char *type);
ClientList *add_at(int pos, int socket, char *uuid, ClientList *list, char *type);
ClientList *pushBack(int socket, char *uuid, char *type, ClientList *list);
ClientList *erase_at(int pos, ClientList *list);
ClientList *getClientByUuid(char *uuid, ClientList *list);
int lenList(ClientList *list);
void printList(ClientList *list);

CommandeList *cmd_createCell(char* cmd, char *uuid, double time);
CommandeList *cmd_add_at(int pos,char *cmd ,char *uuid, double time, CommandeList *list);
CommandeList *cmd_add_at2(int pos, char *cmd, char *uuid, double start_time, double time, CommandeList *list);
int cmd_lenList(CommandeList *list);
CommandeList *cmd_erase_at(int pos, CommandeList *list);
void cmd_printList(CommandeList *list);
CommandeList *cmd_pushBack(char *cmd, char *uuid, double time, CommandeList *list);
CommandeList *cmd_getCmd_By_Player_Uuid(char *uuid, CommandeList *list);