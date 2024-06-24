/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** pin
*/

#include "../../include/my.h"

char *get_pin(server_t *s, char *ret, int pnb)
{
    client_t *tmp = s->server_net->current;

    s->server_net->current = s->server_net->cli_head;
    while (s->server_net->current != NULL) {
        if (s->server_net->current->isAI == 1 &&
            s->server_net->current->player_number == pnb) {
            strcat(ret, " ");
            strcat(ret, int_to_str(s->server_net->current->pos_x));
            strcat(ret, " ");
            strcat(ret, int_to_str(s->server_net->current->pos_y));
            strcat(ret, " ");
            strcat(ret, int_to_str(s->server_net->current->inventory->food));
            strcat(ret, " ");
            strcat(ret, int_to_str(s->server_net->current->inventory->linemate));
            strcat(ret, " ");
            strcat(ret, int_to_str(s->server_net->current->inventory->deraumere));
            strcat(ret, " ");
            strcat(ret, int_to_str(s->server_net->current->inventory->sibur));
            strcat(ret, " ");
            strcat(ret, int_to_str(s->server_net->current->inventory->mendiane));
            strcat(ret, " ");
            strcat(ret, int_to_str(s->server_net->current->inventory->phiras));
            strcat(ret, " ");
            strcat(ret, int_to_str(s->server_net->current->inventory->thystame));
            strcat(ret, "\n");
        }
        s->server_net->current = s->server_net->current->next;
    }
    s->server_net->current = tmp;
}

void pin(server_t *s)
{
    char *sending = malloc(sizeof(char) * 1024);
    if (sending == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    if (strcmp(s->server_data->command[0], "pin") == 0) {
        sprintf(sending, "pin %s", s->server_data->command[1]);
        get_pin(s, sending, atoi(remove_cara(s->server_data->command[1], '#')));
        send_and_print(s, sending, s->server_net->current->socket);
        s->server_data->isCommand = 1;
    }
    free(sending);
}
