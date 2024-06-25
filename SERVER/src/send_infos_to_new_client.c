/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** transmit_infos_to_new_client
*/

#include "../include/my.h"

// Send WELCOME && Receive TEAM-NAME
void send_welcome_recv_team_name(server_t *s)
{
    sleep(0.1);
    send(s->server_net->cli_head->socket, "WELCOME\n", strlen("WELCOME\n"), 0);
    print_send_to_client_head(s, "WELCOME");
    sleep(0.1);
    s->server_net->bytes_received = read(s->server_net->cli_head->socket,
    s->server_data->buffer, sizeof(s->server_data->buffer));
    if (s->server_net->bytes_received > 0) {
        s->server_data->buffer[s->server_net->bytes_received] = '\0';
    }
    strcpy(s->server_net->cli_head->team_name, s->server_data->buffer);
    print_received_from_client_head(s, remove_cara(s->server_data->buffer,
    '\n'));
}

char *get_client_num(server_t *s, const char *team_name)
{
    int i = 0;
    char *tmp;
    char *nb_client = malloc(sizeof(char) * 9888);
    char *delim;

    if (nb_client == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    while (s->server_data->teams[i] != NULL) {
        tmp = strdup(s->server_data->teams[i]);
        delim = strchr(tmp, ':');
        if (delim != NULL && strncmp(team_name, tmp, delim - tmp) == 0) {
            strcpy(nb_client, delim + 1);
            break;
        }
        free(tmp);
        i++;
    }
    strcat(nb_client, "\n");
    return nb_client;
}

// Send CLIENT-NUM
void send_client_num(server_t *s)
{
    char *nb_client = get_client_num(s, s->server_net->cli_head->team_name);

    if (strcmp(s->server_net->cli_head->team_name, "IamTheGUI\n") != 0) {
        s->server_net->cli_head->isAI = 1;
        sleep(0.1);
        if (strcmp(nb_client, "\n") == 0) {
            send(s->server_net->cli_head->socket, "dead\n", strlen("dead\n"), 0);
            print_send_to_client_head(s, "dead");
        } else {
            send(s->server_net->cli_head->socket, nb_client, strlen(nb_client), 0);
            print_send_to_client_head(s, remove_cara(nb_client, '\n'));
        }
    } else {
        s->server_net->cli_head->isAI = 0;
        s->server_net->gui = s->server_net->cli_head;
    }
    free(nb_client);
}

// Send MAP-SIZE
void send_map_size(server_t *s)
{
    char *map_size = malloc(sizeof(char) * 99);

    if (map_size == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    strcpy(map_size, "");
    strcat(map_size, int_to_str(s->arg->_width));
    strcat(map_size, " ");
    strcat(map_size, int_to_str(s->arg->_height));
    strcat(map_size, "\n");
    sleep(0.1);
    send(s->server_net->cli_head->socket, map_size, strlen(map_size), 0);
    print_send_to_client_head(s, remove_cara(map_size, '\n'));
    free(map_size);
    print_clients(s->server_net->cli_head);
    if (strcmp(s->server_net->cli_head->team_name, "IamTheGUI\n") != 0) {
        pnw(s);
    }
}

void send_infos_to_new_client(server_t *s)
{
    send_welcome_recv_team_name(s);
    send_client_num(s);
    send_map_size(s);
}
