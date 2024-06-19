/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** infos
*/

#include "../../include/my.h"

void infos(server_t *s)
{
    client_t *tmp = s->server_net->current;
    char *info = malloc(sizeof(char) * 1024);

    if (strcmp(s->server_data->command[0], "/info") == 0) {
        s->server_net->current = s->server_net->cli_head;
        while (s->server_net->current != NULL) {
            sprintf(info, "infos :\n\n""- isAI : (%d)\n- Team_name : (%s)\n\
            - Pos_x : (%d)\n- Pos_y : (%d)\n- Level : (%d)\n- Orientation : \
            (%d)\n- Player_number : (%d)\n",
            s->server_net->current->isAI, s->server_net->current->team_name,
            s->server_net->current->pos_x, s->server_net->current->pos_y,
            s->server_net->current->level, s->server_net->current->orientation,
            s->server_net->current->player_number);
            send_and_print(s, info, tmp->socket);
            s->server_net->current = s->server_net->current->next;
            free(info);
        }
        s->server_net->current = tmp;
        s->server_data->isCommand = 1;
    }
}
