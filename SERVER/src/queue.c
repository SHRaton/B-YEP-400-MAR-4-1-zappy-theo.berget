/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** queue
*/

#include "../include/my.h"

// Ajouter une commande à la file d'attente
void enqueue(queue_t *q, char *command)
{
    if (q->count == 10) {
        printf("La file d'attente est pleine.\n");
        return;
    }
    strcpy(q->commands[q->rear], command);
    q->rear = (q->rear + 1) % 10;
    q->count++;
}

// Supprimer une commande de la file d'attente
char *dequeue(queue_t *q)
{
    if (q->count == 0) {
        printf("La file d'attente est vide.\n");
        return NULL;
    }
    char *command = strdup(q->commands[q->front]);
    q->front = (q->front + 1) % 10;
    q->count--;
    return command;
}

void print_commands(queue_t *q)
{
    if (q->count == 0) {
        printf("La file d'attente est vide.\n");
        return;
    }

    printf("Commandes dans la file d'attente :\n");
    for (int i = q->front; i != q->rear; i = (i + 1) % 10) {
        printf("%s\n", q->commands[i]);
    }
    if (q->front != q->rear) {
        printf("%s\n", q->commands[q->rear]);
    }
}
