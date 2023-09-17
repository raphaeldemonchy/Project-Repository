/*
** EPITECH PROJECT, 2022
** SERVER
** File description:
** client.c
*/

#include "client.h"

ClientList *createCell(int socket, char *uuid, char *type)
{
    ClientList *cell = malloc(sizeof(ClientList));
    cell->client = malloc(sizeof(Client));
    cell->client->_socket = socket;
    cell->client->_uuid = strdup(uuid);
    cell->client->type = strdup(type);
    return cell;
}

ClientList *add_at(int pos, int socket, char *uuid, ClientList *list, char *type)
{
    ClientList *newNode = createCell(socket, uuid, type);
    if (pos == 0) {
        newNode->next = list;
        return newNode;
    }
    ClientList *current = list;
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

ClientList *erase_at(int pos, ClientList *list) {
    ClientList *current = list;
    ClientList *prev = list;
    ClientList *tmp = list;
    int count = 0;
    if (pos > lenList(tmp) - 1)
        return tmp;
    if (pos == 0) {
        list = tmp->next;
        return list;
    }
    for (int i = 0; i < pos; i++) {
        prev = current;
        current = current->next;
    }
    if (current == NULL)
        return list;
    prev->next = current->next;
    // free(current);
    return list;
}

int lenList(ClientList *list) {
    int i = 0;
    for (; list != NULL; list = list->next, i++);
    return i;
}

void printList(ClientList *list)
{
    if (list != NULL) {
        while (list != NULL) {
            printf("socket = %d\nuuid = %s\ntype = %s\n", list->client->_socket, list->client->_uuid, list->client->type);
            list = list->next;
        }
    }
}

ClientList *pushBack(int socket, char *uuid, char *type, ClientList *list)
{
    add_at(lenList(list), socket, uuid, list, type);
}

ClientList *getClientByUuid(char *uuid, ClientList *list)
{
    ClientList *client = list;
    for (;strcmp(client->client->_uuid, uuid) != 0;client = client->next);
    return client;
}
