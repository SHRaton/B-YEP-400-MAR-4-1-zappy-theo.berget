/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-alexandre.vittenet
** File description:
** handle_connexion_with_fd
*/

#include "../include/my.h"

// Fonction qui ajoute le fd du socket d'écoute au jeu de descripteurs de
// fichiers. Ensuite, elle parcourt la liste de clients connectés et ajoute
// le fd de chaque client au jeu de descripteurs de fichiers.
void set_the_fd(server_t *s)
{
    s->server_net->max_socket = s->server_net->server_socket;
    FD_ZERO(&s->server_net->readfds);
    FD_SET(s->server_net->server_socket, &s->server_net->readfds);
    s->server_net->current = s->server_net->cli_head;
    while (s->server_net->current != NULL) {
        FD_SET(s->server_net->current->socket, &s->server_net->readfds);
        if (s->server_net->current->socket > s->server_net->max_socket) {
            s->server_net->max_socket = s->server_net->current->socket;
        }
        s->server_net->current = s->server_net->current->next;
    }
}

// Fonction qui met dans result le nombre de descripteurs de fichiers prêts
// à être lus, écrits ou ayant une exception.
void select_fd(server_t *s)
{
    struct timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    s->server_net->result = select(s->server_net->max_socket + 1,
    &s->server_net->readfds, NULL, NULL, &tv);
    if (s->server_net->result == -1) {
        perror("select");
        exit (84);
    }
}

// Fonction qui s'occupe d'accepter les clients sur le serveur et d'ajouter les
// informations du client dans sa structure de donnés
void accept_connexion(server_t *s)
{
    if (FD_ISSET(s->server_net->server_socket, &s->server_net->readfds)) {
        s->server_net->new_socket = accept(s->server_net->server_socket,
        (struct sockaddr*)&s->server_net->client_addr,
        &s->server_net->client_addr_len);
        if (s->server_net->new_socket == -1) {
            perror("Accept failed");
        } else {
            s->server_net->cli_head = add_client(s->server_net->cli_head,
            s->server_net->new_socket, s->server_net->client_addr, s);
            s->server_data->player_nb += 1;
            send_infos_to_new_client(s);
        }
    }
}

// Fonction qui déconnecte les utilisateurs qui CTRL+C et réceptionne les
// messages des clients et stocke le contenue dans un tableau d'argument
void recup_input_from_client(server_t *s)
{
    char *pdi = malloc(sizeof(char) * 9999);
    if (pdi == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    s->server_net->bytes_received = read(s->server_net->current->socket,
    s->server_data->buffer, sizeof(s->server_data->buffer));
    if (s->server_net->bytes_received == 0) {
        sprintf(pdi, "pdi #%d\n", s->server_net->current->player_number);
        send_and_print(s, pdi, s->server_net->gui->socket);
        close(s->server_net->current->socket);
        s->server_net->cli_head = remove_client(s->server_net->cli_head,
        s->server_net->current->socket);
        print_clients(s->server_net->cli_head);
    }
    if (s->server_net->bytes_received > 0) {
        s->server_data->buffer[s->server_net->bytes_received - 1] = '\0';
        print_received_from_client(s, s->server_data->buffer);
        s->server_data->command = str_to_word_array(s->server_data->buffer,
        " \t\n\r");
        enqueue(&s->server_net->current->command_queue, s->server_data->buffer);
        //print_commands(&s->server_net->current->command_queue);
    }
    free(pdi);
}

// Fonction principale de la boucle du serveur, qui trie les et gère les FD
// et se met en écoute sur la réception des messages venant des clients
void handle_client(server_t *s)
{
    set_the_fd(s);
    select_fd(s);
    accept_connexion(s);
    s->server_net->current = s->server_net->cli_head;
    while (s->server_net->current != NULL) {
        if (FD_ISSET(s->server_net->current->socket, &s->server_net->readfds)){
            recup_input_from_client(s);
            break;
        }
        s->server_net->current = s->server_net->current->next;
    }
    s->server_net->current = s->server_net->cli_head;
    process_commands(s);
}
