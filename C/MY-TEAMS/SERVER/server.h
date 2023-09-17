/*
** EPITECH PROJECT, 2022
** my_FTP
** File description:
** server.h
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/select.h>
#include <stdbool.h>
#include <limits.h>
#include "../libs/myteams/logging_client.h"
#include "../libs/myteams/logging_server.h"

#include "User/user.h"
#include "Team/team.h"
#include "Channel/channel.h"
#include "Messages/messages.h"
#include <uuid/uuid.h>

#define client_adr_len client_address_length
#define serv_addr_len _server->client_address_length
#define serv_client_addr (struct sockaddr *)&_server->client_address
#define serv_addr _server->server_address
#define ANY INADDR_ANY
#define PORT htons(atoi(port))
#define config_socket configure_socket
#define sock_in struct sockaddr_in
#define config configure_socket
#define cli_sock  _server->client_slot[pos]->socket

typedef struct client_s {
    int socket;
    int user_uuid;
}client;

typedef struct server_s {
    int socket;
    int new_client;
    int MaxSlot;
    int maxfd;
    struct sockaddr_in client_address;
    struct sockaddr_in server_address;
    socklen_t client_address_length;
    client **client_slot;
    fd_set read_fds;
    fd_set tmp_fds;
    team **teams;
    channel **channels;
    user **users;
    message **messages;
}server;

int create_tcp_socket(int new_socket);
sock_in config(int s, sock_in tar, in_port_t port, in_addr_t addr);
void connection_request_list(int socket, int size_list);
void select_list(fd_set readfds, int size_list, int server_socket);
void start_server(int server_socket, struct sockaddr_in address);
void get_client_data(fd_set readfds, int size_list, int *client_socket);
void init_server(server *_server, char *port, char *path);
void init_my_teams(server *_server);
void start_server1(server *_server);

void free_data_server(server *_server);

void add_client(server *_server);
void client_added(server *_server);
void accept_client_request(server *_server);
void get_client_request(server *_server);
void execute_request(int pos, char *cmd, char **arg, server *_server);
char *get_request_uuid(char **arg);

void login(user **users, char **tab, int socket);
void logout(user **users, char *username, int socket);
void users(user **users, int socket);
void user_func(user **users, char *uuid, int socket);
void help(char **users, int socket);
void message_sended(server *_server, char *sender_uuid,
char *receiver_uuid, char *content);
void message_list(server *_server, char *sender_uuid,
char *receiver_uuid, int socket);
void construct_message(char *answer, char *sender_uuid,
char *receiver_uuid, message *msg);

void my_swap(char *a, char *b);
char *my_revstr(char *str);
void my_swap(char *a, char *b);
char *my_revstr(char *str);
char *my_strdup(char *src);
int my_putstr(char const *str);
char *my_strcat(char *dest, char const *src);
void put_tab(char **tab);
char **arg_array(char **arg, char *buffer);
