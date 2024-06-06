/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** my
*/

#pragma once

#define DEBUG 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <uuid/uuid.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <signal.h>

typedef struct sockaddr_in sockaddr_in_t;

// Structure qui stock les infos des clients connectés
typedef struct client_s {
    // Client socket
    int socket;
    struct sockaddr_in address;
    // Infos Client
    int isLogin;
    uuid_t uuid;
    char uuid_s[1024];
    char name[1024];
    // Linked list
    struct client_s *next;
} client_t;

typedef struct server_network_s {
    int server_socket;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    socklen_t client_addr_len;
    client_t *clients_head;
    client_t *current;
    fd_set readfds;
    int max_socket;
    int result;
    int new_socket;
    ssize_t bytes_received;
} server_network_t;

typedef struct server_data_s {
    int isCommand;
    char buffer[1024];
    char **command;
    char **users_name;
    char **users_uuid;
} server_data_t;

typedef struct arg_s {
    int _port;
    int _width;
    int _height;
    char **_names;
    int _nb_clients;
    int _frequence;
} arg_t;

typedef struct server_s {
    server_data_t *server_data;
    server_network_t *server_network;
    arg_t *arg;

} server_t;



///////////////////////////////
/* Déclarations de fonctions */
///////////////////////////////

// -------- main.c -------- //
void print_usage(void);
void print_args(arg_t *arg);
// ------------------------ //

// -------- parsing.c -------- //
void get_pos(char **av, int *flag_pos, int z);
int *recup_flag_pos(int ac, char **av);
int error_handling(int ac, char **av, arg_t *arg, int *flag_pos);
int flags_valid(int ac, char **av, arg_t *arg);
int parsing_argument(int ac, char **av, arg_t *arg);
// -------------------------- //

// -------- server.c -------- //
void start_server(arg_t *arg);
// -------------------------- //

// -------- chained_list_print.c -------- //
void print_clients(client_t *head);
void print_remove(client_t *current);
// -------------------------------------- //

// -------- chained_list.c -------- //
client_t *add_client(client_t *head, int new_s, sockaddr_in_t client_addr);
client_t *remove_client2(client_t *current, client_t *previous, client_t *head);
client_t *remove_client(client_t *head, int socket_to_remove);
void free_clients(client_t *head);
// -------------------------------- //

// -------- init.c -------- //
void apply(server_t *s, arg_t *arg);
void print_loaded_serv(char *user);
void re_use_port(server_t *s);
void init_socket(server_t *s);
// ------------------------ //
