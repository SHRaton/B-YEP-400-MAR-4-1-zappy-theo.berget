/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** server_menu
*/

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "../include/main.hpp"

void Display::handleMouseClick2(const sf::Vector2i& mousePosition)
{
    if (mousePosition.x >= 304 && mousePosition.x <= 1622 && mousePosition.y >= 868 && mousePosition.y <= 1049) {
        soundButton.play();
        server_login();
    }
}

void Display::handleEvents2() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed || 
            (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
            window.close();
        } else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            handleMouseClick2(mousePosition);
        }
    }
}

void Display::update2() {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    if (mousePosition.x >= 304 && mousePosition.x <= 1622 && mousePosition.y >= 868 && mousePosition.y <= 1049) {
        sprite_server.setTexture(texture5);
    } else {
        sprite_server.setTexture(texture4);
    }
}


void Display::render2()
{
    window.clear(sf::Color::Black);
    window.draw(sprite_server);
    window.display();
}

void Display::server_menu()
{
    while (window.isOpen()) {
        handleEvents2();
        update2();
        render2();
    }
}