/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-alexandre.vittenet
** File description:
** chained_list_print
*/

#include "../include/my.h"

// Fonction qui affiche dans le serveur la liste de tout les clients connectés si DEBUG == 1
void print_clients(client_t *head)
{
    int i;

    if (DEBUG == 1) {
        i = 1;
        printf("Connected clients:\n");
        while (head != NULL) {
            printf("Client ");
            printf("%d: ", i);
            printf("%s:", inet_ntoa(head->address.sin_addr));
            printf("%d\n", ntohs(head->address.sin_port));
            head = head->next;
            i++;
        }
    }
}

// Fonction qui affiche le client déconnecté dans le serveur si DEBUG == 1
void print_remove(client_t *current)
{
    if (DEBUG == 1) {
        printf("client_s disconnected: ");
        printf("%s:", inet_ntoa(current->address.sin_addr));
        printf("%d\n", ntohs(current->address.sin_port));
    }
}
