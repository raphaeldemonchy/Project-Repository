/*
** EPITECH PROJECT, 2022
** SERVER
** File description:
** egg.c
*/

#include "egg.h"
Egg *egg_createCell(int x, int y, char *equipe)
{
    uuid_t new_uuid;
    char uuid_str[37];
    uuid_generate(new_uuid);
    uuid_unparse(new_uuid, uuid_str);
    Egg *cell = malloc(sizeof(Egg));
    cell->x = x;
    cell->y = y;
    cell->equipe = strdup(equipe);
    cell->uuid = strdup(uuid_str);
    return cell;
}

Egg *egg_add_at(int pos, int x, int y, char *equipe, Egg *list)
{
    Egg *newNode = egg_createCell(x, y, equipe);
    if (pos == 0) {
        newNode->next = list;
        return newNode;
    }
    Egg *current = list;
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

Egg *egg_erase_at(int pos, Egg *list) {
    Egg *current = list;
    Egg *prev = list;
    Egg *tmp = list;
    int count = 0;
    if (pos > egg_lenList(tmp) - 1)
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

int egg_lenList(Egg *list) {
    int i = 0;
    for (; list != NULL; list = list->next, i++);
    return i;
}

void egg_printList(Egg *list)
{
}

Egg *egg_pushBack(int x, int y, char *equipe, Egg *list)
{
    egg_add_at(egg_lenList(list), x, y, equipe, list);
}

Egg *egg_eraseByEquipe(char *equipe, Egg *list)
{
    Egg *tmp = list;
    for (int i = 0; tmp != NULL; tmp = tmp->next, i++) {
        if (strcmp(tmp->equipe, equipe) == 0) {
            list = egg_erase_at(i, list);
            return list;
        }
    }
    return list;
}

Egg *egg_getByEquipe(char *equipe, Egg *list)
{
    Egg *tmp = list;
    for (; tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->equipe, equipe) == 0) {
            return list;
        }
    }
    return list;
}