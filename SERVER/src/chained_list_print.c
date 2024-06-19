/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-alexandre.vittenet
** File description:
** chained_list_print
*/

#include "../include/my.h"

// Fonction qui affiche dans le serveur la liste de tout les
// clients connectés si DEBUG == 1
void print_clients(client_t *head)
{
    int i;
    char *who = malloc(sizeof(char) * 1024);

    if (DEBUG == 1) {
        i = 1;
        printf("\033[35m\nConnected clients:\n\033[0m");
        if (head == NULL) {
            printf("\033[35m[Nobody]\033[0m\n\n");
        }
        while (head != NULL) {
            if (head->isAI == 1) {
                strcpy(who, "\033[44m AI  \033[0m");
            } else {
                strcpy(who, "\033[45m GUI \033[0m");
            }
            printf("\033[35mClient %d:  \033[0m", i);
            printf("\033[37m[%s:%d |%s]\033[0m\n\n",
            inet_ntoa(head->address.sin_addr),
            ntohs(head->address.sin_port), who);
            head = head->next;
            i++;
        }
    }
}

// Fonction qui affiche le client déconnecté dans le serveur si DEBUG == 1
void print_remove(client_t *current)
{
    char *who = malloc(sizeof(char) * 1024);

    if (DEBUG == 1) {
        if (current->isAI == 1) {
            strcpy(who, "\033[44m AI  \033[0m");
        } else {
            strcpy(who, "\033[45m GUI \033[0m");
        }
        printf("\033[31m\nclient_s disconnected: \033[0m");
        printf("\033[37m[%s:%d |%s]\033[0m\n",
        inet_ntoa(current->address.sin_addr),
        ntohs(current->address.sin_port), who);
    }
    free(who);
}

void print_connect(sockaddr_in_t client_addr)
{
    if (DEBUG == 1) {
        printf("\033[32mNew client connected: \033[0m");
        printf("\033[37m[%s:%d]\033[0m\n", inet_ntoa(client_addr.sin_addr),
        ntohs(client_addr.sin_port));
    }
}
