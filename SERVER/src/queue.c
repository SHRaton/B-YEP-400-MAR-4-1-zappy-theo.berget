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

int isEmpty(queue_t *q)
{
    return (q->count == 0);
}

void print_commands(queue_t *q)
{
    if (isEmpty(q)) {
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

double get_time_of_command(server_t *s)
{
    if (strncmp(s->server_net->current->actualTask, "Forward", 7) == 0) {
        return (7.0 / (double)s->arg->_frequence);
    }
    if (strncmp(s->server_net->current->actualTask, "Right", 5) == 0) {
        return (7.0 / (double)s->arg->_frequence);
    }
    if (strncmp(s->server_net->current->actualTask, "Left", 4) == 0) {
        return (7.0 / (double)s->arg->_frequence);
    }
    if (strncmp(s->server_net->current->actualTask, "Look", 4) == 0) {
        return (7.0 / (double)s->arg->_frequence);
    }
    if (strncmp(s->server_net->current->actualTask, "Inventory", 9) == 0) {
        return (1.0 / (double)s->arg->_frequence);
    }
    if (strncmp(s->server_net->current->actualTask, "Broadcast text", 14) == 0) {
        return (7.0 / (double)s->arg->_frequence);
    }
    if (strncmp(s->server_net->current->actualTask, "Fork", 4) == 0) {
        return (42.0 / (double)s->arg->_frequence);
    }
    if (strncmp(s->server_net->current->actualTask, "Eject", 5) == 0) {
        return (7.0 / (double)s->arg->_frequence);
    }
    if (strncmp(s->server_net->current->actualTask, "Take", 4) == 0) {
        return (7.0 / (double)s->arg->_frequence);
    }
    if (strncmp(s->server_net->current->actualTask, "Set", 3) == 0) {
        return (7.0 / (double)s->arg->_frequence);
    }
    if (strncmp(s->server_net->current->actualTask, "Incantation", 11) == 0) {
        return (300.0 / (double)s->arg->_frequence);
    }
    return (0.0);
}

void process_commands(server_t *s)
{
    s->server_net->current = s->server_net->cli_head;
    while (s->server_net->current != NULL) {
        if (s->server_net->current->actualTask == NULL && s->server_net->current->command_queue.count > 0) {
            print_commands(&s->server_net->current->command_queue);
            char *command = dequeue(&s->server_net->current->command_queue);
            double actualTime = difftime(time(NULL), s->server_data->launch_time);
            s->server_net->current->actualTask = strdup(command);
            s->server_net->current->endTaskTime = actualTime + get_time_of_command(s);
            free(command);
        }
        s->server_net->current = s->server_net->current->next;
    }

    // Check end task
    s->server_net->current = s->server_net->cli_head;
    while (s->server_net->current != NULL) {
        double actualTime = difftime(time(NULL), s->server_data->launch_time);
        if (s->server_net->current->endTaskTime <= actualTime && s->server_net->current->actualTask != NULL) {
            s->server_data->command = str_to_word_array(s->server_net->current->actualTask, " \t\n\r");
            s->server_net->current->endTaskTime = 0;
            s->server_net->current->actualTask = NULL;
            commands(s);
        }
        s->server_net->current = s->server_net->current->next;
    }
}
