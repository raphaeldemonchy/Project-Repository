/*
** EPITECH PROJECT, 2023
** myTeams
** File description:
** handleAnswer1.c
*/

#include "../client.h"

void handle_answer2(char **answerTab, client *_client)
{
    if (strcmp(getcmd(_client->buffer), "/logout") == 0)
        handle_logout(answerTab, _client);
    if (strcmp(getcmd(_client->buffer), "/users") == 0)
        handle_all_users(answerTab, _client);
    if (strcmp(getcmd(_client->buffer), "/user") == 0)
        handle_user(answerTab, _client);
    if (strcmp(getcmd(_client->buffer), "/messages") == 0)
        handle_messages(answerTab, _client);
}

void handle_answer(char *answer, client *_client)
{
    char **answerTab = malloc(sizeof(char *) * 1000);
    answerTab = answer_array(answerTab, answer);
    if (strcmp(answerTab[0], "messagerecv") == 0)
        client_event_private_message_received(
            answerTab[1], answerTab[2]);
    if (strcmp(getcmd(_client->buffer), "/login") == 0)
        handle_login(answerTab, _client);
    if (strcmp(answerTab[0], "new_connexion") == 0 &&
    strcmp(getcmd(_client->buffer), "/login") != 0)
        handle_new_user_connected(answerTab);
    if (strcmp(answerTab[0], "logout") == 0 &&
    strcmp(getcmd(_client->buffer), "/logout") != 0)
        handle_new_user_disconnected(answerTab);
    handle_answer2(answerTab, _client);
    for (int i = 0; answerTab[i] != NULL; i++)
        memset(answerTab[i], 0, strlen(answerTab[i]));
}
