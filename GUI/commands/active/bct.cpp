/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** bct
*/

#include "../../include/Core.hpp"

void Core::bct()
{
    send_to_server("bct 2 3\n");
    receive_from_server();
}
