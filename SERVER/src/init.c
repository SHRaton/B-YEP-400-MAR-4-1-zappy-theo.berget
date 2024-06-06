/*
** EPITECH PROJECT, 2024
** B-NWP-400-MAR-4-1-myftp-alexandre.vittenet
** File description:
** init
*/

#include "../my.h"

void apply(server_t *s, arg_t *arg)
{
    s->arg = malloc(sizeof(arg_t));
    s->arg = arg;
    s->server_network = malloc(sizeof(server_network_t));
    s->server_data = malloc(sizeof(server_data_t));
    s->server_network->server_socket = 0;
    s->server_network->client_addr_len = sizeof(s->server_network->client_addr);
    s->server_network->clients_head = NULL;
    s->server_network->current = s->server_network->clients_head;
    s->server_network->max_socket = 0;
    s->server_network->result = 0;
    s->server_network->new_socket = 0;
    s->server_data->isCommand = 0;
}

void print_loaded_serv(char *user)
{
    char *tok = malloc(sizeof(char) * 9999);
    char *first = malloc(sizeof(char) * 9999);
    char *second = malloc(sizeof(char) * 9999);
    char *tmp = malloc(sizeof(char) * 1024);

    strcpy(tmp, user);
    tok = strtok(tmp, ":");
    first = strdup(tok);
    tok = strtok(NULL, ":");
    second = strdup(tok);
    free(first);
    free(second);
    free(tmp);
}

void re_use_port(server_t *s)
{
    int reuseaddr;

    reuseaddr = 1;
    if (setsockopt(s->server_network->server_socket, SOL_SOCKET,
    SO_REUSEADDR, &reuseaddr, sizeof(int)) == -1) {
        perror("setsockopt failed");
        close(s->server_network->server_socket);
        exit(EXIT_FAILURE);
    }
}

void init_socket(server_t *s)
{
    s->server_network->server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (s->server_network->server_socket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    s->server_network->server_addr.sin_family = AF_INET;
    s->server_network->server_addr.sin_addr.s_addr = INADDR_ANY;
    s->server_network->server_addr.sin_port = htons(s->arg->_port);
    re_use_port(s);
    if (bind(s->server_network->server_socket, (struct sockaddr*)&s->server_network->server_addr,
    sizeof(s->server_network->server_addr)) == -1) {
        perror("Bind failed");
        close(s->server_network->server_socket);
        exit(EXIT_FAILURE);
    }
    if (listen(s->server_network->server_socket, 5) == -1) {
        perror("Listen failed");
        close(s->server_network->server_socket);
        exit(EXIT_FAILURE);
    }
}
