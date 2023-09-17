/*
** EPITECH PROJECT, 2022
** SERVER
** File description:
** AI.c
*/

#include "AI.h"

AI *AI_createCell(char *uuid, float f, int x, int y)
{
    uuid_t new_uuid;
    char uuid_str[37];
    uuid_generate(new_uuid);
    uuid_unparse(new_uuid, uuid_str);
    AI *cell = malloc(sizeof(AI));
    cell->_lastRefillLife = 0;
    cell->_inventaire = malloc(sizeof(Inventory));
    cell->_inventaire->deraumere = 0;
    cell->_inventaire->food = 10;
    cell->_inventaire->linemate = 0;
    cell->_inventaire->mendiane = 0;
    cell->_inventaire->phiras = 0;
    cell->_inventaire->sibur = 0;
    cell->_inventaire->thystame = 0;
    cell->_uuid = strdup(uuid);
    cell->_life = 10;
    cell->_level = 8;
    cell->statu = true;
    cell->_equipe = strdup("undefined");
    cell->_x = (rand() % x);
    cell->_y = (rand() % y);
    cell->_orientation = 3;
    cell->_timeleft = 126 / f;
    return cell;
}

AI *AI_add_at(int pos, char *uuid, float f, int x, int y, AI *list)
{
    AI *newNode = AI_createCell(uuid, f, x, y);
    if (pos == 0) {
        newNode->next = list;
        return newNode;
    }
    AI *current = list;
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

int AI_lenList(AI *list) {
    int i = 0;
    for (; list != NULL; list = list->next, i++);
    return i;
}

AI *AI_erase_at(int pos, AI *list) {
    AI *current = list;
    AI *prev = list;
    AI *tmp = list;
    int count = 0;
    if (pos > AI_lenList(tmp) - 1)
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


void AI_printList(AI *list)
{
    while (list != NULL) {
        printf("uuid = %s\nequipe = %s\nlevel = %d\nlife = %d\nposX = %d\nposY = %d\n", list->_uuid, list->_equipe, list->_level, list->_life, list->_x, list->_y);
        list = list->next;
    }
}

AI *AI_pushBack(char *uuid, float f, int x, int y, AI *list)
{
    AI_add_at(AI_lenList(list), uuid, f,x, y, list);
}

AI *AI_getAIByUuid(char *uuid, AI *list)
{
    AI *client = list;
    for (;client != NULL; client = client->next) {
        if (strcmp(client->_uuid, uuid) == 0)
            return client;
    }
    return NULL;
}