/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** Info_Players
*/

#pragma once

#include "includes.hpp"
#include "Ressources.hpp"

class Info_Player {
    public :
        Info_Player() = default;
        ~Info_Player() = default;
        int player_number;
        int pos_x;
        int pos_y;
        int orientation;
        int animation;
        int level;
        std::string team_name;
        ressources inventory;
};
