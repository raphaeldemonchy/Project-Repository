/*
** EPITECH PROJECT, 2022
** SERVER
** File description:
** AI.h
*/

#pragma once

#include <stddef.h>
#include <uuid/uuid.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Inventory_s {
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
    int food;
}Inventory;

typedef struct AI_s {
    Inventory *_inventaire;
    bool statu;
    int _level;
    int _life;
    int _x;
    int _y;
    char *_equipe;
    char *_uuid;
    int _orientation;
    char *_message;
    double _timeleft;
    double _lastRefillLife;
    struct AI_s *next;
}AI;

AI *AI_createCell(char *uuid, float f, int x, int y);
AI *AI_add_at(int pos, char *uuid, float f,int x, int y, AI *list);
int AI_lenList(AI *list);
AI *AI_erase_at(int pos, AI *list);
void AI_printList(AI *list);
AI *AI_pushBack(char *uuid, float f, int x, int y, AI *list);
AI *AI_getAIByUuid(char *uuid, AI *list);
