/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** msz
*/

#include "../../include/Core.hpp"

void Core::msz()
{
    send_to_server("msz\n");
    receive_from_server();
}
