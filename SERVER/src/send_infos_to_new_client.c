/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** transmit_infos_to_new_client
*/

#include "../include/my.h"

void send_infos_to_new_client(server_t *s)
{
    int i = 0;
    char left[1024];
    char right[1024];
    char *tmp;
    char *nb_client = malloc(sizeof(char) * 1024);
    int nb = 0;
    char *client_num = malloc(sizeof(char) * 1024);
    char *map_size = malloc(sizeof(char) * 99);

    // Send WELCOME
    sleep(0.1);
    send(s->server_network->clients_head->socket, "WELCOME\n", strlen("WELCOME\n"), 0);
    print_send_to_client_head(s, "WELCOME");

    // Received TEAM-NAME
    sleep(0.1);
    s->server_network->bytes_received = read(s->server_network->clients_head->socket,
    s->server_data->buffer, sizeof(s->server_data->buffer));
    if (s->server_network->bytes_received > 0) {
        s->server_data->buffer[s->server_network->bytes_received] = '\0';
    }
    strcpy(s->server_network->clients_head->team_name, s->server_data->buffer);
    print_received_from_client_head(s, remove_cara(s->server_data->buffer, '\n'));

    // Send CLIENT-NUM
    while (s->server_data->teams[i] != NULL) {
        tmp = strdup(s->server_data->teams[i]);
        strcpy(left, "");
        strcpy(right, "");
        char *delim = strchr(tmp, ':');
        if (delim != NULL) {
            strncpy(left, tmp, delim - tmp);
            left[delim - tmp] = '\0';
            strncpy(right, delim + 1, strlen(delim + 1));
            right[strlen(delim + 1)] = '\0';
        }
        if (strncmp(left, s->server_network->clients_head->team_name, strlen(left)) == 0) {
            strcpy(nb_client, right);
        } else {
        }
        free(tmp);
        i++;
    }
    strcat(nb_client, "\n");
    if (strcmp(s->server_network->clients_head->team_name, "Wapeq est boost!\n") != 0) {
        sleep(0.1);
        send(s->server_network->clients_head->socket, nb_client, strlen(nb_client), 0);
        print_send_to_client_head(s, remove_cara(nb_client, '\n'));
    }

    // Send MAP-SIZE
    strcpy(map_size, "");
    strcat(map_size, int_to_str(s->arg->_width));
    strcat(map_size, " ");
    strcat(map_size, int_to_str(s->arg->_height));
    strcat(map_size, "\n");
    sleep(0.1);
    send(s->server_network->clients_head->socket, map_size, strlen(map_size), 0);
    print_send_to_client_head(s, remove_cara(map_size, '\n'));
    free(map_size);
    print_clients(s->server_network->clients_head);
}
