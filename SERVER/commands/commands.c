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
        printf("\033[37m[%s:%d]\033[0m        --> ",
        inet_ntoa(s->server_net->cli_head->address.sin_addr),
        ntohs(s->server_net->cli_head->address.sin_port));
        printf("(\"%s\")\n", str);
    }
}

// Affiche dans le serveur les commandes recues
void print_received_from_client(server_t *s, char *str)
{
    char *who = malloc(sizeof(char) * 999);

    if (DEBUG == 1) {
        if (s->server_net->current->isAI == 1) {
            strcpy(who, "\033[44m AI  \033[0m");
        } else {
            strcpy(who, "\033[45m GUI \033[0m");
        }
        printf("\033[42m[Received]\033[0m from client ");
        printf("\033[37m[%s:%d |%s]\033[0m --> ",
        inet_ntoa(s->server_net->current->address.sin_addr),
        ntohs(s->server_net->current->address.sin_port), who);
        printf("(\"%s\")\n", str);
    }
    free(who);
}

// Fonction qui affiche le message send et à qui le serveur le send
void print_send_to_client_head(server_t *s, char *str)
{
    if (DEBUG == 1) {
        dprintf(1, "\033[43m  [Sent]  \033[0m to   client ");
        dprintf(1, "[\033[37m%s:%d\033[0m]        --> (\"%s\")\n",
        inet_ntoa(s->server_net->cli_head->address.sin_addr),
        ntohs(s->server_net->cli_head->address.sin_port), str);
    }
}

// Fonction qui affiche le message send et à qui le serveur le send
void print_send_to_client(server_t *s, char *str)
{
    char *who = malloc(sizeof(char) * 999);

    if (DEBUG == 1) {
        if (s->server_net->current->isAI == 1) {
            strcpy(who, "\033[44m AI  \033[0m");
        } else {
            strcpy(who, "\033[45m GUI \033[0m");
        }
        dprintf(1, "\033[43m[  Sent  ]\033[0m to   client ");
        dprintf(1, "[\033[37m%s:%d |%s\033[0m] --> (\"%s\")\n",
        inet_ntoa(s->server_net->current->address.sin_addr),
        ntohs(s->server_net->current->address.sin_port), who, str);
    }
    free(who);
}

// Fonction qui gère les commandes recu par le serveur et si la commande
// n'existe pas renvoie "Wrong command" a l'utilisateur qui a fait la requete
void commands(server_t *s)
{
    forward(s);
    look(s);
    infos(s);
    ppo(s);
    mct(s);
    if (s->server_data->isCommand == 0) {
        send(s->server_net->current->socket, "Wrong command\n", 16, 0);
        print_send_to_client(s, "Wrong command");
    }
    s->server_data->isCommand = 0;
}
