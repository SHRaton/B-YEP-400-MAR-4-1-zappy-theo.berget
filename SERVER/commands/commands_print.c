/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** command_print
*/

#include "../include/my.h"
#include <stdarg.h>

void print_to_log(server_t *s, char *str, int index)
{
    char *str1 = malloc(sizeof(char) * 1024);
    FILE *file = fopen("./LOG/server.log", "a");

    if (file == NULL) {
        return;
    }
    if (index == 1) {
        sprintf(str1, "[RECEIVED] from client [%s:%d]",
        inet_ntoa(s->server_net->cli_head->address.sin_addr),
        ntohs(s->server_net->cli_head->address.sin_port));
    }
    if (index == 2) {
        sprintf(str1, "[RECEIVED] from client [%s:%d]",
        inet_ntoa(s->server_net->current->address.sin_addr),
        ntohs(s->server_net->current->address.sin_port));
    }
    if (index == 3) {
        sprintf(str1, "[Sent] to client [%s:%d]",
        inet_ntoa(s->server_net->cli_head->address.sin_addr),
        ntohs(s->server_net->cli_head->address.sin_port));
    }
    if (index == 4) {
        sprintf(str1, "[Sent] to client [%s:%d]",
        inet_ntoa(s->server_net->current->address.sin_addr),
        ntohs(s->server_net->current->address.sin_port));
    }
    fprintf(file, "%s ---> (\"%s\")\n", str1, str);
    fclose(file);
}

// Affiche dans le serveur les commandes recues
void print_received_from_client_head(server_t *s, char *str)
{
    if (DEBUG == 1) {
        printf("\033[42m[Received]\033[0m from client ");
        printf("\033[37m[%s:%d]\033[0m        --> ",
        inet_ntoa(s->server_net->cli_head->address.sin_addr),
        ntohs(s->server_net->cli_head->address.sin_port));
        printf("(\"%s\")\n", str);
        print_to_log(s, str, 1);
    }
}

// Affiche dans le serveur les commandes recues
void print_received_from_client(server_t *s, char *str)
{
    char *who = malloc(sizeof(char) * 999);

    if (who == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
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
        print_to_log(s, str, 2);
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
        print_to_log(s, str, 3);
    }
}

// Fonction qui affiche le message send et à qui le serveur le send
void print_send_to_client(server_t *s, char *str)
{
    char *who = malloc(sizeof(char) * 999);
    if (who == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

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
        print_to_log(s, str, 4);
    }
    free(who);
}
