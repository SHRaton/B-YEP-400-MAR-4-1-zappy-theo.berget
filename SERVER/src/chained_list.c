/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-alexandre.vittenet
** File description:
** chained_list
*/

#include "../include/my.h"

// Fonction qui ajoute un nouveau client a la liste chainée de client connectés et stocke les informations du client
client_t *add_client(client_t *head, int new_s, sockaddr_in_t client_addr)
{
    client_t *new_client = malloc(sizeof(client_t));

    if (new_client == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    new_client->socket = new_s;
    new_client->address = client_addr;
    new_client->next = head;
    new_client->isLogin = 0;
    if (DEBUG == 1) {
        printf("New client connected: ");
        printf("%s:", inet_ntoa(client_addr.sin_addr));
        printf("%d\n", ntohs(client_addr.sin_port));
    }
    //write(new_client->socket, "WELCOME", strlen("WELCOME"));
    return new_client;
}

// Fonction annexe a remove_client
client_t *remove_client2(client_t *current, client_t *previous, client_t *head)
{
    if (previous != NULL) {
        previous->next = current->next;
    } else {
        head = current->next;
    }
    return (head);
}

// Fonction qui supprime un client de la liste chainée
client_t *remove_client(client_t *head, int socket_to_remove)
{
    client_t *current;
    client_t *previous;

    current = head;
    previous = NULL;
    while (current != NULL) {
        if (current->socket == socket_to_remove) {
            head = remove_client2(current, previous, head);
            print_remove(current);
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
    return head;
}

// Fonction qui libere la mémoire de la liste chainée pour éviter les memory leak
void free_clients(client_t *head)
{
    client_t *current;
    client_t *next;

    current = head;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}
