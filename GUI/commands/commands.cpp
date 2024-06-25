/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** commands
*/

#include "../include/Core.hpp"

std::vector<std::string> Core::str_to_word_array(std::string s)
{
    std::istringstream iss(s);
    std::vector<std::string> tokens;
    std::string token;

    while (std::getline(iss, token, ' ')) {
      tokens.push_back(token);
    }
    return tokens;
}

void Core::commands()
{
    try {
        pnw();
        pdi();
        ppo();
        mct();
        pin();
        plv();
    } catch (const std::invalid_argument& e) {
        std::cerr << "\n\033[31m[DEBUG]\033[0m Erreur : " << e.what() << std::endl;
    }
    strcpy(buffer, "");
    sbuffer = std::string(buffer);
    vbuffer[0] = "";
}
