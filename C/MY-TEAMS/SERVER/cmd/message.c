/*
** EPITECH PROJECT, 2022
** myTeams
** File description:
** message.c
*/

#include "../server.h"

char *message_save(char* sender, char *receiver, char *content, time_t time)
{
    char *messageSave = malloc(sizeof(char) *
    (strlen(sender) + strlen(receiver) + strlen(content) + 30));
    messageSave = strcpy(messageSave, sender);
    strcat(messageSave, "/");
    strcat(messageSave, receiver);
    strcat(messageSave, "/");
    strcat(messageSave, content);
    strcat(messageSave, "/");
    strcat(messageSave, ctime(&time));
    messageSave[strlen(messageSave) - 1] = '\0';
    return messageSave;
}

void message_sended(server *_server, char *sender_uuid, char *receiver_uuid,
char *content)
{
    int socket = get_user_by_uuid(_server->users, sender_uuid)->socket, i = 0;
    for (; _server->messages[i] != NULL; i++);
    _server->messages[i] = malloc(sizeof(message));
    _server->messages[i]->author_uuid = strdup(sender_uuid);
    _server->messages[i]->dest_uuid = strdup(receiver_uuid);
    _server->messages[i]->content = strdup(content);
    time(&_server->messages[i]->message_times);
    char *answer = malloc(sizeof(char) * (
        strlen(sender_uuid) + 10 + strlen(content) + strlen("messagerecv")));
    server_event_private_message_sended(sender_uuid, receiver_uuid, content);
    strcpy(answer,"messagerecv"), strcat(answer,":");
    strcat(answer, sender_uuid), strcat(answer, ":");
    strcat(answer, content);
    send(get_user_by_uuid(_server->users, receiver_uuid)->socket,
        answer, strlen(answer), 0);
    add_save_to_file("SERVER/Save/messages_save.txt", message_save(sender_uuid,
    receiver_uuid, content, _server->messages[i]->message_times));
}

void message_list(server *_server, char *sender_uuid, char *receiver_uuid,
int socket)
{
    int i = 0;
    char *answer = malloc(sizeof(char) * 1000000);

    for (int i = 0; _server->messages[i] != NULL; i++) {
        if (strcmp(_server->messages[i]->author_uuid, sender_uuid) == 0
            && strcmp(_server->messages[i]->dest_uuid, receiver_uuid) == 0) {
            construct_message(answer, sender_uuid,
            receiver_uuid, _server->messages[i]);
        }
        if (strcmp(_server->messages[i]->author_uuid, receiver_uuid) == 0
            && strcmp(_server->messages[i]->dest_uuid, sender_uuid) == 0) {
            construct_message(answer, receiver_uuid,
            sender_uuid, _server->messages[i]);
        }
    }
    answer[strlen(answer) - 1] = '\0';
    send(socket, answer, strlen(answer), 0);
    memset(answer, 0, strlen(answer));
}

void construct_message(char *answer, char *sender_uuid, char *receiver_uuid,
message *msg)
{
    char str_time[20];
    struct tm *timeinfo = malloc(sizeof(struct tm));
    strftime(str_time, sizeof(str_time), "%Y-%m-%d|%Hh%Mm%Ss", timeinfo);
    strcat(answer, sender_uuid), strcat(answer, "&");
    strcat(answer, receiver_uuid), strcat(answer, "&");
    strcat(answer, str_time), strcat(answer, "&");
    strcat(answer, msg->content);
    strcat(answer, ":");
}
