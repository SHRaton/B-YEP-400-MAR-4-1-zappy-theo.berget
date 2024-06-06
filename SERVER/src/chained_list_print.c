/*
** EPITECH PROJECT, 2024
** B-NWP-400-MAR-4-1-myteams-noam.bouriche
** File description:
** chained_list_print
*/

#include "../my.h"

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

void print_remove(client_t *current)
{
    if (DEBUG == 1) {
        printf("client_s disconnected: ");
        printf("%s:", inet_ntoa(current->address.sin_addr));
        printf("%d\n", ntohs(current->address.sin_port));
    }
}
