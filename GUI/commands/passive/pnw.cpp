/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** pnw
*/

#include "../../include/Core.hpp"

void Core::pnw()
{
    if (vbuffer[0] == "pnw") {
        Info_Player info;
        info.player_number = std::stoi(vbuffer[1].substr(1));
        info.pos_x = std::stoi(vbuffer[2]);
        info.pos_y = std::stoi(vbuffer[3]);
        info.orientation = std::stoi(vbuffer[4]);
        info.level = std::stoi(vbuffer[5]);
        info.team_name = vbuffer[6];
        info_players.push_back(info);
        info_players_brut.push_back(info);
        sleep(0.1);
    }
}