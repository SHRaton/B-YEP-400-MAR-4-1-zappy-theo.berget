/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** pnw
*/

#include "../../include/my.h"

void pnw(server_t *s)
{
    char *sending = malloc(sizeof(char) * 1024);
    strcpy(sending, "pnw #");

    strcat(sending, int_to_str(s->server_net->cli_head->player_number));
    strcat(sending, " ");
    strcat(sending, int_to_str(s->server_net->cli_head->pos_x));
    strcat(sending, " ");
    strcat(sending, int_to_str(s->server_net->cli_head->pos_y));
    strcat(sending, " ");
    strcat(sending, int_to_str(s->server_net->cli_head->orientation));
    strcat(sending, " ");
    strcat(sending, int_to_str(s->server_net->cli_head->level));
    strcat(sending, " ");
    strcat(sending, remove_cara(s->server_net->cli_head->team_name, '\n'));
    strcat(sending, "\n");
    if (s->server_net->gui == NULL) {
        dprintf(1, "GUI not connected. Start it before launching AI\n");
        return;
    }
    send(s->server_net->gui->socket, sending, strlen(sending), 0);
    print_send_to_client_head(s, remove_cara(sending, '\n'));
    free(sending);
}
