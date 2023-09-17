/*
** EPITECH PROJECT, 2022
** SERVER
** File description:
** egg.h
*/

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <uuid/uuid.h>
#include <sys/time.h>

typedef struct Egg_t
{
    char *equipe;
    int x;
    int y;
    double timeleft;
    char *uuid;
    struct Egg_t *next;
}Egg;

Egg *egg_createCell(int x, int y, char *equipe);
Egg *egg_add_at(int pos, int x, int y, char *equipe, Egg *list);
Egg *egg_erase_at(int pos, Egg *list);
int egg_lenList(Egg *list);
void egg_printList(Egg *list);
Egg *egg_pushBack(int x, int y, char *equipe, Egg *list);
Egg *egg_eraseByEquipe(char *equipe, Egg *list);
Egg *egg_getByEquipe(char *equipe, Egg *list);