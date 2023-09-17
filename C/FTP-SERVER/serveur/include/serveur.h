/*
** EPITECH PROJECT, 2023
** serveur
** File description:
** serveur
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <ctype.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <limits.h>

#define client_adr_len client_address_length
#define serv_addr_len _server->client_address_length
#define serv_client_addr (struct sockaddr *)&_server->client_address
#define serv_addr _server->server_address
#define ANY INADDR_ANY
#define PORT htons(atoi(port))
#define config_socket configure_socket
#define sock_in struct sockaddr_in
#define config configure_socket
#define sa_fam sa_family_t
#define cli_sock  _server->client_slot[pos]->socket
#define data_sock  _server->client_slot[pos]->data_socket
#define active_mode my_strdup("actif");
#define passive_mode my_strdup("passif");
#define ERROR 84
#define VALID

typedef struct client_s {
    int socket;
    char *username;
    char *password;
    char *working_dir;
    int data_socket;
    struct sockaddr_in data_address;
    char *data_transfer;
    bool is_pass;
    bool is_user;
    bool is_connecte;
}client;

typedef struct server_s {
    int socket;
    int new_client;
    int MaxSlot;
    int maxfd;
    char *data;
    char *path;

    struct sockaddr_in client_address;
    struct sockaddr_in server_address;
    socklen_t client_address_length;
    client **client_slot;
    fd_set read_fds;
    fd_set tmp_fds;
}server;

int init_socket(int new_socket);
sock_in config(int s, sock_in tar, in_port_t port, in_addr_t addr);
void connexion_que(int socket, int size_list);
void selec_handle(fd_set readfds, int size_list, int server_socket);
void server_start(int server_socket, struct sockaddr_in address);
void get_data_cli(fd_set readfds, int size_list, int *client_socket);
void init_server(server *_server, char *port, char *path);
void go_server(server *_server);

void new_cli(server *_server);
void cli_is_added(server *_server);
void add_cli_req(server *_server);
void get_cli_req(server *_server);
void exec_req(int pos, char *cmd, char *arg, server *_server);

void cmd_user(int pos, char *arg, server *_server);
void cmd_pass(int pos, char *arg, server *_server);
void cmd_cwd(int pos, char *arg, server *_server);
void cmd_cdup(int pos, char *arg, server *_server);
void cmd_quit(int pos, server *_server);
void cmd_port(int pos, char *arg, server *_server);
void cmd_pasv(int pos, char *arg, server *_server);
void cmd_stor(int pos, char *arg, server *_server);
void cmd_retr(int pos, char *arg, server *_server);
void cmd_list(int pos, char* arg, server *_server);
void cmd_dele(int pos, char *arg, server *_server);
void cmd_pwd(int pos, char *arg, server *_server);
void cmd_help(int pos, char *arg, server *_server);
void cmd_noop(int pos, char *arg, server *_server);

char *stock_cwd(int pos, char *arg, server *_server);
char *stock_port(char *arg, int client_socket);
void my_swap(char *a, char *b);
char *my_revstr(char *str);
void my_swap(char *a, char *b);
char *my_revstr(char *str);
char *my_strdup(char *src);
int my_putstr(char const *str);
char *my_strcat(char *dest, char const *src);
