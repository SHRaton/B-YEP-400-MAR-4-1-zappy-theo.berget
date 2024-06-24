/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** Ressources
*/

#pragma once

#include "includes.hpp"

class ressources {
    public :
    int food;
    int coal;
    int iron;
    int gold;
    int diamond;
    int emerald;
    int netherite;

    sf::Text nb_food;
    sf::Text nb_coal;
    sf::Text nb_iron;
    sf::Text nb_gold;
    sf::Text nb_diamond;
    sf::Text nb_emerald;
    sf::Text nb_netherite;

    ressources(int food = 0, int coal = 0, int iron = 0, int gold = 0, int diamond = 0, int emerald = 0, int netherite = 0)
        : food(food), coal(coal), iron(iron), gold(gold), diamond(diamond), emerald(emerald), netherite(netherite) {}
};
