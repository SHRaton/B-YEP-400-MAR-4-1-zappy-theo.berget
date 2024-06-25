/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** queue_process_task
*/

#include "../include/my.h"

double get_time_of_command(server_t *s)
{
    if (strncmp(s->server_net->current->actualTask, "Forward", 7) == 0)
        return (7.0 / (double)s->arg->_frequence);
    if (strncmp(s->server_net->current->actualTask, "Right", 5) == 0)
        return (7.0 / (double)s->arg->_frequence);
    if (strncmp(s->server_net->current->actualTask, "Left", 4) == 0)
        return (7.0 / (double)s->arg->_frequence);
    if (strncmp(s->server_net->current->actualTask, "Look", 4) == 0)
        return (7.0 / (double)s->arg->_frequence);
    if (strncmp(s->server_net->current->actualTask, "Inventory", 9) == 0)
        return (1.0 / (double)s->arg->_frequence);
    return (0.0);
}

double get_time_of_command2(server_t *s)
{
    if (strncmp(s->server_net->current->actualTask, "Broadcast text", 14) == 0)
        return (7.0 / (double)s->arg->_frequence);
    if (strncmp(s->server_net->current->actualTask, "Fork", 4) == 0)
        return (42.0 / (double)s->arg->_frequence);
    if (strncmp(s->server_net->current->actualTask, "Eject", 5) == 0)
        return (7.0 / (double)s->arg->_frequence);
    if (strncmp(s->server_net->current->actualTask, "Take", 4) == 0)
        return (7.0 / (double)s->arg->_frequence);
    if (strncmp(s->server_net->current->actualTask, "Set", 3) == 0)
        return (7.0 / (double)s->arg->_frequence);
    if (strncmp(s->server_net->current->actualTask, "Incantation", 11) == 0)
        return (300.0 / (double)s->arg->_frequence);
    return (0.0);
}

// Assign task
void assign_task(server_t *s)
{
    char *command = malloc(sizeof(char) * 1024);
    double actualTime = 0.0;

    s->server_net->current = s->server_net->cli_head;
    while (s->server_net->current != NULL) {
        if (s->server_net->current->actualTask == NULL &&
            s->server_net->current->command_queue.count > 0) {
            print_commands(&s->server_net->current->command_queue);
            command = dequeue(&s->server_net->current->command_queue);
            actualTime = difftime(time(NULL), s->server_data->launch_time);
            s->server_net->current->actualTask = strdup(command);
            s->server_net->current->endTaskTime = actualTime +
            get_time_of_command(s) + get_time_of_command2(s);
        }
        s->server_net->current = s->server_net->current->next;
    }
    free(command);
}

// Check end task
void check_end_task(server_t *s)
{
    double actualTime = 0.0;

    s->server_net->current = s->server_net->cli_head;
    while (s->server_net->current != NULL) {
        actualTime = difftime(time(NULL), s->server_data->launch_time);
        if (s->server_net->current->endTaskTime <= actualTime &&
            s->server_net->current->actualTask != NULL) {
            s->server_data->command =
            str_to_word_array(s->server_net->current->actualTask, " \t\n\r");
            s->server_net->current->endTaskTime = 0;
            s->server_net->current->actualTask = NULL;
            commands(s);
        }
        s->server_net->current = s->server_net->current->next;
    }
}

void process_commands(server_t *s)
{
    assign_task(s);
    check_end_task(s);
}
