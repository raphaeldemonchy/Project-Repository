/*
** EPITECH PROJECT, 2022
** my_FTP
** File description:
** client.h
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/select.h>
#include <time.h>
#include <stddef.h>
#include <stdbool.h>
#include <limits.h>
#include <ctype.h>
#include "../SERVER/User/user.h"
#include <netinet/in.h>
#include "../libs/myteams/logging_client.h"
#define SERVER_IP "127.0.0.1"
#define c_malloc40 malloc(sizeof(char) * 40)
#define c_malloc22 malloc(sizeof(char) * 22)
#define c_malloc500 malloc(sizeof(char) * 500)

typedef struct client_s {
    int socket;
    struct sockaddr_in serv_address;
    fd_set client_rds;
    int port;
    char *buffer;
    user *_user;
}client;

int create_tcp_socket(int new_socket);
void connect_client(client *_client);
void init_client(char *port, client *_client);
void send_request(client *_client);
void getRequestResult(user *_user);
void handle_answer(char *answer, client *_client);
void handle_login(char **answer, client *_client);
void handle_logout(char **answer, client *_client);
void handle_all_users(char **tab, client *_client);
void handle_user(char **tab, client *_client);
void handle_messages(char **arg, client *_client);
void handle_new_user_connected(char **answer);
void handle_new_user_disconnected(char **answerTab);
char *getcmd(char *buff);
char **answer_array(char **answer,char *buffer);

int error_handler(char *buffer, int socket);
char *remove_quote(char *string);
int check_quote(char *arg);
int is_alphanumeric(char *str);
