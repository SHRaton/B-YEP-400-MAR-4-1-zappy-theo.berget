/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-alexandre.vittenet
** File description:
** handle_connexion_with_fd
*/

#include "../include/my.h"

// Fonction qui ajoute le fd du socket d'écoute au jeu de descripteurs de fichiers.
// Ensuite, elle parcourt la liste de clients connectés et ajoute le fd de chaque client au jeu de descripteurs de fichiers.
void set_the_fd(server_t *s)
{
    s->server_network->max_socket = s->server_network->server_socket;
    FD_ZERO(&s->server_network->readfds);
    FD_SET(s->server_network->server_socket, &s->server_network->readfds);
    s->server_network->current = s->server_network->clients_head;
    while (s->server_network->current != NULL) {
        FD_SET(s->server_network->current->socket, &s->server_network->readfds);
        if (s->server_network->current->socket > s->server_network->max_socket) {
            s->server_network->max_socket = s->server_network->current->socket;
        }
        s->server_network->current = s->server_network->current->next;
    }
}

// Fonction qui met dans result le nombre de descripteurs de fichiers prêts à être lus, écrits ou ayant une exception.
void select_fd(server_t *s)
{
    s->server_network->result = select(s->server_network->max_socket + 1,
    &s->server_network->readfds, NULL, NULL, NULL);
}

// Fonction qui s'occupe d'accepter les clients sur le serveur et d'ajouter les informations du client dans sa structure de donnés
void accept_connexion(server_t *s)
{
    if (FD_ISSET(s->server_network->server_socket, &s->server_network->readfds)) {
        s->server_network->new_socket = accept(s->server_network->server_socket,
        (struct sockaddr*)&s->server_network->client_addr, &s->server_network->client_addr_len);
        if (s->server_network->new_socket == -1) {
            perror("Accept failed");
        } else {
            s->server_network->clients_head = add_client(s->server_network->clients_head,
            s->server_network->new_socket, s->server_network->client_addr);
            print_clients(s->server_network->clients_head);
        }
    }
}

// Fonction qui déconnecte les utilisateurs qui CTRL+C et réceptionne les messages des clients et stocke le contenue dans un tableau d'argument
void recup_input_from_client(server_t *s)
{
    s->server_network->bytes_received = read(s->server_network->current->socket,
    s->server_data->buffer, sizeof(s->server_data->buffer));
    if (s->server_network->bytes_received == 0) {
        close(s->server_network->current->socket);
        s->server_network->clients_head = remove_client(s->server_network->clients_head,
        s->server_network->current->socket);
        print_clients(s->server_network->clients_head);
    }
    if (s->server_network->bytes_received > 0) {
        s->server_data->buffer[s->server_network->bytes_received - 1] = '\0';
        if (DEBUG == 1) {
            printf("Received from client ");
            printf("%s:", inet_ntoa(s->server_network->current->address.sin_addr));
            printf("%d: ", ntohs(s->server_network->current->address.sin_port));
            printf("%s\n", s->server_data->buffer);
        }
        s->server_data->command = str_to_word_array(s->server_data->buffer, " \t\n\r");
        commands(s);
    }
}

// Fonction principale de la boucle du serveur, qui trie les et gère les FD et se met en écoute sur la réception des messages venant des clients
void handle_client(server_t *s)
{
    set_the_fd(s);
    select_fd(s);
    accept_connexion(s);
    s->server_network->current = s->server_network->clients_head;
    while (s->server_network->current != NULL) {
        if (FD_ISSET(s->server_network->current->socket, &s->server_network->readfds)) {
            recup_input_from_client(s);
            break;
        }
        s->server_network->current = s->server_network->current->next;
    }
}
