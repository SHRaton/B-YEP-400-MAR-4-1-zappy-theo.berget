/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** minecraft_start
*/

#include "../include/Core.hpp"

void Core::Menu()
{
    while (window.isOpen()) {
        handleEvents();
        update();
        render();
    }
}

void Core::handleEvents()
{
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed ||
            (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
            window.close();
        } else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            handleMouseClick(mousePosition);
        }
    }
}

void Core::update()
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    if (mousePosition.x >= 521 && mousePosition.x <= 1395 && mousePosition.y >= 476 && mousePosition.y <= 776) {
        sprite_menu.setTexture(texture2);
    } else if (mousePosition.x >= 515 && mousePosition.x <= 1403 && mousePosition.y >= 843 && mousePosition.y <= 926) {
        sprite_menu.setTexture(texture3);
    } else {
        sprite_menu.setTexture(texture1);
    }
}

void Core::render()
{
    window.clear(sf::Color::Black);
    window.draw(sprite_menu);
    window.display();
}

void Core::handleMouseClick(const sf::Vector2i& mousePosition)
{
    if (mousePosition.x >= 515 && mousePosition.x <= 1403 && mousePosition.y >= 843 && mousePosition.y <= 926) {
        soundButton.play();
        window.close();
    }
    if (mousePosition.x >= 521 && mousePosition.x <= 1395 && mousePosition.y >= 476 && mousePosition.y <= 776) {
        soundButton.play();
        server_menu();
    }
}
