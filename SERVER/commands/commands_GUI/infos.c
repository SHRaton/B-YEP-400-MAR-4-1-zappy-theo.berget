/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** infos
*/

#include "../../include/my.h"

void infos(server_t *s)
{
    if (strcmp(s->server_data->command[0], "/info") == 0) {
        client_t *tmp = s->server_net->current;
        s->server_net->current = s->server_net->cli_head;
        while (s->server_net->current != NULL) {
            char *info = malloc(sizeof(char) * 1024);
            strcpy(info, "infos :\n\n");
            strcat(info, "- isAI : (");
            strcat(info, int_to_str(s->server_net->current->isAI));
            strcat(info, ")\n");
            strcat(info, "- Team_name : (");
            strcat(info, s->server_net->current->team_name);
            strcat(info, ")\n");
            strcat(info, "- Pos_x : (");
            strcat(info, int_to_str(s->server_net->current->pos_x));
            strcat(info, ")\n");
            strcat(info, "- Pos_y : (");
            strcat(info, int_to_str(s->server_net->current->pos_y));
            strcat(info, ")\n");
            strcat(info, "- Level : (");
            strcat(info, int_to_str(s->server_net->current->level));
            strcat(info, ")\n");
            strcat(info, "- Orientation : (");
            strcat(info, int_to_str(s->server_net->current->orientation));
            strcat(info, ")\n");
            strcat(info, "- Socket : (");
            strcat(info, int_to_str(s->server_net->current->socket));
            strcat(info, ")\n");
            strcat(info, "- Player_number : (");
            strcat(info, int_to_str(s->server_net->current->player_number));
            strcat(info, ")\n");
            send(tmp->socket, info, strlen(info), 0);
            print_send_to_client(s, remove_cara(info, '\n'));
            s->server_net->current = s->server_net->current->next;
            free(info);
        }
        s->server_net->current = tmp;
        s->server_data->isCommand = 1;
    }
}
