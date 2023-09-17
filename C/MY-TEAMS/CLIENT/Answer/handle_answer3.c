/*
** EPITECH PROJECT, 2022
** myTeams
** File description:
** handle_answer3.c
*/

#include "../client.h"

void handle_new_user_connected(char **answer)
{
    client_event_logged_in(answer[2], answer[1]);
}

void handle_new_user_disconnected(char **answerTab)
{
    client_event_logged_out(answerTab[1], answerTab[2]);
}
