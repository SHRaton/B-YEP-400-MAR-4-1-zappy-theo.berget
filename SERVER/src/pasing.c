/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-alexandre.vittenet
** File description:
** pasing
*/

#include "../include/my.h"

void get_pos(char **av, int *flag_pos, int z)
{
    if (strcmp(av[z], "-p") == 0)
        flag_pos[0] = z;
    if (strcmp(av[z], "-x") == 0)
        flag_pos[1] = z;
    if (strcmp(av[z], "-y") == 0)
        flag_pos[2] = z;
    if (strcmp(av[z], "-n") == 0)
        flag_pos[3] = z;
    if (strcmp(av[z], "-c") == 0)
        flag_pos[4] = z;
    if (strcmp(av[z], "-f") == 0)
        flag_pos[5] = z;
}

int *recup_flag_pos(int ac, char **av)
{
    int *flag_pos = malloc(sizeof(int) * 6);
    int z = 1;

    for (int i = 0; i < 6; i++)
        flag_pos[i] = -1;
    while (ac > z) {
        get_pos(av, flag_pos, z);
        z += 1;
    }
    if (flag_pos[0] == -1 || flag_pos[1] == -1 || flag_pos[2] == -1 ||
        flag_pos[3] == -1 || flag_pos[4] == -1 || flag_pos[5] == -1) {
        for (int i = 0; i < 6; i++) {
            flag_pos[i] = 84;
        }
    }
    return flag_pos;
}

int error_handling(int ac, char **av, arg_t *arg, int *flag_pos)
{
    int i = 1;

    if (av[flag_pos[0] + 1] == NULL || av[flag_pos[1] + 1] == NULL ||
        av[flag_pos[2] + 1] == NULL || av[flag_pos[3] + 1] == NULL ||
        av[flag_pos[4] + 1] == NULL || av[flag_pos[5] + 1] == NULL)
        return (84);

    arg->_port = atoi(av[flag_pos[0] + 1]);
    arg->_width = atoi(av[flag_pos[1] + 1]);
    arg->_height = atoi(av[flag_pos[2] + 1]);
    arg->_nb_clients = atoi(av[flag_pos[4] + 1]);
    arg->_frequence = atoi(av[flag_pos[5] + 1]);

    if (arg->_width < 0 || arg->_height < 0 || arg->_frequence == 0 || arg->_nb_clients == 0)
        return (84);

    arg->_names = malloc(sizeof(char *) * 100);
    while (av[flag_pos[3] + i][0] != '-') {
        arg->_names[i - 1] = strdup(av[flag_pos[3] + i]);
        i++;
        if (av[flag_pos[3] + i] == NULL)
            break;
    }
    arg->_names[i + 1] = NULL;

    for (int j = 0; j < i - 1; j++) {
        for (int k = j + 1; k < i - 1; k++) {
            if (strcmp(arg->_names[j], arg->_names[k]) == 0) {
                return (84);
            }
        }
    }

    return (0);
}

int flags_valid(int ac, char **av, arg_t *arg)
{
    int *flag_pos = recup_flag_pos(ac, av);
    int compt = 0;

    if (flag_pos[0] == 84 && flag_pos[1] == 84 && flag_pos[2] == 84 &&
        flag_pos[3] == 84 && flag_pos[4] == 84 && flag_pos[5] == 84) {
        return (84);
    }
    if (error_handling(ac, av, arg, flag_pos) == 84) {
        return (84);
    }
    free(flag_pos);
    return (0);
}

int parsing_argument(int ac, char **av, arg_t *arg)
{
    if (ac == 1) {
        arg->_port = 9001;
        arg->_width = 10;
        arg->_height = 10;
        arg->_names = malloc(sizeof(char *) * 100);
        arg->_names[0] = strdup("team1");
        arg->_names[1] = strdup("team2");
        arg->_nb_clients = 5;
        arg->_frequence = 1;
        return (0);
    }
    if (ac < 12) {
        return 84;
    }
    if (flags_valid(ac, av, arg) == 84) {
        return (84);
    }
    return (0);
}
