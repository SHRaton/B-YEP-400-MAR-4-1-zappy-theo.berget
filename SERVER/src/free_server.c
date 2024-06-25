/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** free_server
*/

#include "../include/my.h"


void free_char_array(char **array)
{
    if (array == NULL) {
        return;
    }
    for (int i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
}

void free_map_content(case_t **map_content)
{
    if (map_content == NULL) {
        return;
    }
    for (int i = 0; map_content[i] != NULL; i++) {
        free(map_content[i]);
    }
    free(map_content);
}

// Fonction qui libere la mémoire de la liste chainée
// pour éviter les memory leak
void free_clients(client_t *head)
{
    client_t *current;
    client_t *next;

    current = head;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

void free_server(server_t *s)
{
    dprintf(1, "\n\033[31mSERVER WAS CLOSED BY CTRL+C\033[0m\n");
    free_char_array(s->arg->_names);
    free_char_array(s->server_data->command);
    free_char_array(s->server_data->map);
    free_map_content(s->server_data->map_content);
    free_char_array(s->server_data->teams);
    free_clients(s->server_net->cli_head);
    exit (0);
}
