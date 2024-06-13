/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-alexandre.vittenet
** File description:
** commands
*/

#include "../include/my.h"

// Affiche dans le serveur les commandes recues
void print_received_from_client_head(server_t *s, char *str)
{
    if (DEBUG == 1) {
        printf("\033[42m[Received]\033[0m from client ");
        printf("\033[37m[%s:%d]\033[0m --> ", inet_ntoa(s->server_network->clients_head->address.sin_addr),
        ntohs(s->server_network->clients_head->address.sin_port));
        printf("(\"%s\")\n", str);
    }
}

// Affiche dans le serveur les commandes recues
void print_received_from_client(server_t *s, char *str)
{
    if (DEBUG == 1) {
        printf("\033[42m[Received]\033[0m from client ");
        printf("\033[37m[%s:%d]\033[0m --> ", inet_ntoa(s->server_network->current->address.sin_addr),
        ntohs(s->server_network->current->address.sin_port));
        printf("(\"%s\")\n", str);
    }
}

// Fonction qui affiche le message send et à qui le serveur le send
void print_send_to_client_head(server_t *s, char *str)
{
    if (DEBUG == 1) {
        dprintf(1, "\033[43m[Sent]\033[0m to client [\033[37m%s:%d\033[0m] --> (\"%s\")\n",
        inet_ntoa(s->server_network->clients_head->address.sin_addr),
        ntohs(s->server_network->clients_head->address.sin_port), str);
    }
}

// Fonction qui affiche le message send et à qui le serveur le send
void print_send_to_client(server_t *s, char *str)
{
    if (DEBUG == 1) {
        dprintf(1, "\033[43m[Sent]\033[0m to client [\033[37m%s:%d\033[0m] --> (\"%s\")\n",
        inet_ntoa(s->server_network->current->address.sin_addr),
        ntohs(s->server_network->current->address.sin_port), str);
    }
}

// Fonction qui gère les commandes recu par le serveur et si la commande n'existe pas renvoie "Wrong command" a l'utilisateur qui a fait la requete
void commands(server_t *s)
{
    // mettre toutes les fonctions de commandes ici
    if (strcmp(s->server_data->command[0], "ls") == 0) {
        printf("zzzzzz");
    }
    print_send_to_client(s, "commande");
    if (s->server_data->isCommand == 0 && s->server_network->current->isLogin == 1) {
        send(s->server_network->current->socket, "Wrong command", 16, 0);
    }
    s->server_data->isCommand = 0;
}
