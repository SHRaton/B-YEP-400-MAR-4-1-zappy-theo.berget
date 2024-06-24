/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** tna
*/

#include "../../include/Core.hpp"

void Core::tna()
{
    send_to_server("tna\n");
    receive_from_server();
}
