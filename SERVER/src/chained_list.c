/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-alexandre.vittenet
** File description:
** chained_list
*/

#include "../include/my.h"

// Fonction qui ajoute un nouveau client a la liste chainée de client
// connectés et stocke les informations du client
client_t *add_client(client_t *head, int new_s, sockaddr_in_t cli, server_t *s)
{
    client_t *new_client = malloc(sizeof(client_t));
    if (new_client == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    if (new_client == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    new_client->socket = new_s;
    new_client->address = cli;
    new_client->next = head;
    new_client->isLogin = 1;
    srand(time(0));
    new_client->pos_x = rand() % (s->arg->_width - 2) + 1;
    new_client->pos_y = rand() % (s->arg->_height - 2) + 1;
    new_client->level = 1;
    new_client->orientation = 1;
    new_client->player_number = s->server_data->player_nb;
    new_client->inventory = malloc(sizeof(case_t));
    if (new_client->inventory == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    new_client->inventory->food = 0;
    new_client->inventory->linemate = 0;
    new_client->inventory->deraumere = 0;
    new_client->inventory->sibur = 0;
    new_client->inventory->mendiane = 0;
    new_client->inventory->phiras = 0;
    new_client->inventory->thystame = 0;
    new_client->endTaskTime = 0;
    new_client->actualTask = NULL;
    print_connect(cli);
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
