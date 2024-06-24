/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** plv
*/

#include "../../include/my.h"

void plv(server_t *s)
{
    client_t *tmp = s->server_net->current;
    char *sending = malloc(sizeof(char) * 9888);
    if (sending == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    int pnb = 0;

    if (strcmp(s->server_data->command[0], "plv") == 0) {
        strcpy(sending, "plv ");
        strcat(sending, s->server_data->command[1]);
        strcat(sending, " ");
        pnb = atoi(remove_cara(s->server_data->command[1], '#'));
        s->server_net->current = s->server_net->cli_head;
        while (s->server_net->current != NULL) {
            if (s->server_net->current->isAI == 1 &&
            s->server_net->current->player_number == pnb) {
                strcat(sending, int_to_str(s->server_net->current->level));
            }
            s->server_net->current = s->server_net->current->next;
        }
        s->server_net->current = tmp;
        strcat(sending, "\n");
        send_and_print(s, sending, s->server_net->current->socket);
        s->server_data->isCommand = 1;
    }
    free(sending);
}
