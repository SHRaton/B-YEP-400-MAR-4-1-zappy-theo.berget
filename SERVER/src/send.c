/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-alexandre.vittenet
** File description:
** send
*/

#include "../include/my.h"

// Fonction qui send un message a tout les utilisateurs acctuelement connectés au serveur
void send_all_clients(client_t *head, char *msg, client_t *current)
{
    int i;

    i = 1;
    while (head != NULL) {
        if (head != current) {
            send(head->socket, msg, strlen(msg) + 1, 0);
        }
        head = head->next;
        i++;
    }
}

void send_and_print(server_t *s, char *str, int socket)
{
    send(socket, str, strlen(str), 0);
    print_send_to_client(s, str);
}
