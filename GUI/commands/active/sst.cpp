/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** sst
*/

#include "../../include/Core.hpp"

void Core::sst()
{
    send_to_server("sst 10\n");
    receive_from_server();
}
