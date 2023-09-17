/*
** EPITECH PROJECT, 2022
** SERVER
** File description:
** commande.c
*/

#include "client.h"

CommandeList *cmd_createCell(char *cmd, char *uuid, double time)
{
    CommandeList *cell = malloc(sizeof(CommandeList));
    cell->player_uuid = strdup(uuid);
    cell->timeleft = time;
    cell->cmd = strdup(cmd);
    cell->next = NULL;
    return cell;
}

CommandeList *cmd_add_at(int pos, char *cmd, char *uuid, double time, CommandeList *list)
{
    CommandeList *newNode = cmd_createCell(cmd, uuid, time);
    if (pos == 0) {
        newNode->next = list;
        return newNode;
    }
    CommandeList *current = list;
    int count = 0;
    while (current != NULL && count < pos - 1) {
        current = current->next;
        count++;
    }
    if (current == NULL)
        return list;
    newNode->next = current->next;
    current->next = newNode;
    return list;
}

CommandeList *cmd_add_at2(int pos, char *cmd, char *uuid, double start_time, double time, CommandeList *list)
{
    CommandeList *newNode = cmd_createCell(cmd, uuid, time);
    newNode->startTime = start_time;
    if (pos == 0) {
        newNode->next = list;
        return newNode;
    }
    CommandeList *current = list;
    int count = 0;
    while (current != NULL && count < pos - 1) {
        current = current->next;
        count++;
    }
    if (current == NULL)
        return list;
    newNode->next = current->next;
    current->next = newNode;
    return list;
}

int cmd_lenList(CommandeList *list) {
    int i = 0;
    for (; list != NULL; list = list->next, i++);
    return i;
}

CommandeList *cmd_erase_at(int pos, CommandeList *list) {
    CommandeList *current = list;
    CommandeList *prev = list;
    CommandeList *tmp = list;
    int count = 0;
    if (pos > cmd_lenList(tmp) - 1)
        return tmp;
    if (pos == 0) {
        list = tmp->next;
        return list;
    }
    for (int i = 0; i < pos; i++) {
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
    free(current);
    if (current == NULL)
        return list;
    return list;
}


void cmd_printList(CommandeList *list)
{
    if (list != NULL) {
        printf("-----------------------\n");
        while (list != NULL) {
            printf("___________________\ncmd = %splayer uuid = %s\ntime left = %f sec\nstart time = %f\n", list->cmd, list->player_uuid, list->timeleft, list->startTime);
            list = list->next;
        }
        printf("-----------------------\n");
    }
}

CommandeList *cmd_pushBack(char *cmd, char *uuid, double time, CommandeList *list)
{
    cmd_add_at(cmd_lenList(list), cmd ,uuid, time, list);
}

CommandeList* cmd_getCmd_By_Player_Uuid(char* uuid, CommandeList* list)
{
    CommandeList *cmd = list;
    for (;cmd != NULL; cmd = cmd->next) {
        if (strcmp(cmd->player_uuid, uuid) != 0);
            return cmd;
    }
    return NULL;
}


CommandeList* cmd_erase_By_Player_Uuid(char* uuid, CommandeList* list)
{
    CommandeList* head = list;
    CommandeList* prev = NULL;
    while (list != NULL) {
        if (strcmp(list->player_uuid, uuid) == 0) {
            CommandeList* next = list->next;
            if (prev != NULL) {
                prev->next = next;
            } else {
                head = next;
            }
            free(list);
            list = next;
        } else {
            prev = list;
            list = list->next;
        }
    }
    return head;
}
