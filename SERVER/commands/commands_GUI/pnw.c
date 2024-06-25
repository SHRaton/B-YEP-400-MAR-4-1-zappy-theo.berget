/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** pnw
*/

#include "../../include/my.h"

void pnw(server_t *s)
{
    char *sending = malloc(sizeof(char) * 9888);
    int ret = 0;

    if (sending == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    sprintf(sending, "pnw #%s %s %s %s %s %s\n",
    int_to_str(s->server_net->cli_head->player_number),
    int_to_str(s->server_net->cli_head->pos_x),
    int_to_str(s->server_net->cli_head->pos_y),
    int_to_str(s->server_net->cli_head->orientation),
    int_to_str(s->server_net->cli_head->level),
    remove_cara(s->server_net->cli_head->team_name, '\n'));
    if (s->server_net->gui == NULL) {
        dprintf(1, "GUI not connected. Start it before launching AI\n");
        return;
    }
    ret = update_nb_client(s, remove_cara(s->server_net->cli_head->team_name, '\n'), -1);
    if (ret == 84) {
        send(s->server_net->gui->socket, "dead\n", strlen("dead\n"), 0);
        print_send_to_client_head(s, "dead\n");
        return;
    }
    print_strstr(s->server_data->teams);
    send(s->server_net->gui->socket, sending, strlen(sending), 0);
    print_send_to_client_head(s, remove_cara(sending, '\n'));
    free(sending);
}
