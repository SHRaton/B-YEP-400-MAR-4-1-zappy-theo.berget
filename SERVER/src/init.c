/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-alexandre.vittenet
** File description:
** init
*/

#include "../include/my.h"

// Fonction qui initialise toutes les variables de la structure server_t et transpose la structure arg_t dans une instance de server_t
// pour tout centraliser dans server_t et n'utiliser plus que cette unique structure dans tout le programme
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
    int i = 0;
    s->server_data->teams = malloc(sizeof(char *) * 1024);
    while (s->arg->_names[i] != NULL) {
        s->server_data->teams[i] = malloc(sizeof(char) * 1024);
        strcpy(s->server_data->teams[i], s->arg->_names[i]);
        strcat(s->server_data->teams[i], ":");
        strcat(s->server_data->teams[i], int_to_str(arg->_nb_clients));
        i++;
    }
}

// Fonction utilitaire qui permet de pouvoir réutiliser un port récemment fermé afin de faciliter les tests et le debug du programme
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

// Fonction qui initialise le socket du serveur a partir du localhost et héberge le serveur sur le port donné en argument.
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
