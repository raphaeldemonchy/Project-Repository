/*
** EPITECH PROJECT, 2022
** MY_TEAMS_NORME1
** File description:
** init_answer.c
*/

#include "../client.h"

char **answer_array(char **answer,char *buffer)
{
    int x = 0, y = 0;
    answer[y] = malloc(sizeof(char) * 100000);
    for (int i = 0; buffer[i] != '\0'; i++, x++) {
        if (buffer[i] == ':'){
            answer[y][x] = '\0', x = 0, y++;
            answer[y] = malloc(sizeof(char)* 100000);
            i++;
        }
        answer[y][x] = buffer[i];
    }
    answer[y + 1] = NULL;
    return answer;
}
