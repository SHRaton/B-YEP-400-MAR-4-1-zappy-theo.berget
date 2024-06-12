/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** transmit_infos_to_new_client
*/

#include "../include/my.h"

void send_infos_to_new_client(server_t *s)
{
    // Send WELCOME
    send(s->server_network->clients_head->socket, "WELCOME\n", strlen("WELCOME\n"), 0);
    // Received TEAM-NAME
    s->server_network->bytes_received = read(s->server_network->clients_head->socket,
    s->server_data->buffer, sizeof(s->server_data->buffer));
    if (s->server_network->bytes_received > 0) {
        s->server_data->buffer[s->server_network->bytes_received - 1] = '\0';
    }
    // Send MAP-SIZE
    char *map_size = malloc(sizeof(char) * 99);
    strcpy(map_size, "");
    strcat(map_size, int_to_str(s->arg->_width));
    strcat(map_size, " ");
    strcat(map_size, int_to_str(s->arg->_height));
    strcat(map_size, "\n");
    send(s->server_network->clients_head->socket, map_size, strlen(map_size), 0);
    free(map_size);
    print_clients(s->server_network->clients_head);
}
