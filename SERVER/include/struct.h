/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-alexandre.vittenet
** File description:
** my
*/

#pragma once

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
    int isAI;
    uuid_t uuid;
    char uuid_s[1024];
    char team_name[1024];
    int pos_x;
    int pos_y;
    int orientation;
    int level;
    int player_number;
    // Linked list
    struct client_s *next;
} client_t;

// strcuture qui permet de gérer la partie net du serveur
typedef struct server_net_s {
    int server_socket;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    socklen_t client_addr_len;
    client_t *cli_head;
    client_t *current;
    client_t *gui;
    fd_set readfds;
    int max_socket;
    int result;
    int new_socket;
    ssize_t bytes_received;

} server_net_t;

// structure pour stocker tout ce qui conecerne les donnés / messages reçu
typedef struct server_data_s {
    // Command handling
    int isCommand;
    char buffer[1024];
    char **command;

    // Stockage des teams et de leur capacité
    char **teams;

    // Stockage de la map et des elements de chaque tile
    char **map;

    // Variables
    int player_nb;

} server_data_t;

// structure pour stocker les arguments
typedef struct arg_s {
    int _port;
    int _width;
    int _height;
    char **_names;
    int _nb_clients;
    int _frequence;
} arg_t;


// structure du serveur
typedef struct server_s {
    server_data_t *server_data;
    server_net_t *server_net;
    arg_t *arg;

} server_t;
