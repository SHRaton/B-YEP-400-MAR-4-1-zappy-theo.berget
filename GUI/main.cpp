/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** main
*/

#include <SFML/Graphics.hpp>
#include "my.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Ma Fenêtre SFML");
    sf::Texture texture;
    if (!texture.loadFromFile("sky.png")) {
        std::cerr << "Erreur lors du chargement de l'image" << std::endl;
        return -1;
    }

    sf::Sprite sprite;
    sprite.setTexture(texture);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
        }
        window.clear(sf::Color::Black);
        window.draw(sprite);
        window.display();
    }

    return 0;
}
