/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** main
*/

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "main.hpp"

Display::Display() : window(sf::VideoMode(1920, 1080), "Zappy") {
    loadAssets();
}

void Display::loadAssets() {
    texture1.loadFromFile("GUI/assets/Menu.png");
    texture2.loadFromFile("GUI/assets/Menu2.png");
    texture3.loadFromFile("GUI/assets/Menu3.png");

    texture4.loadFromFile("GUI/assets/server_menu.jpeg"); 
    texture5.loadFromFile("GUI/assets/server_menu2.jpeg");

    texture6.loadFromFile("GUI/assets/join_server.jpeg"); 
    texture7.loadFromFile("GUI/assets/join_server2.jpeg"); 
    texture8.loadFromFile("GUI/assets/join_server3.png"); 
    texture9.loadFromFile("GUI/assets/join_server4.png");

    selectionRectangle.setFillColor(sf::Color::Transparent);
    selectionRectangle.setOutlineColor(sf::Color::White);
    selectionRectangle.setOutlineThickness(9);

    sprite_menu.setTexture(texture1);
    sprite_server.setTexture(texture4);
    sprite_login.setTexture(texture6);
    sprite_menu.setScale(1920 / sprite_menu.getGlobalBounds().width, 1080 / sprite_menu.getGlobalBounds().height);

    if (!menuMusic.openFromFile("GUI/assets/menu.wav")) {
        std::cerr << "Erreur lors du chargement de la musique du menu" << std::endl;
        exit(1);
    }
    menuMusic.setLoop(true);
    menuMusic.play();

    if (!soundBuffer.loadFromFile("GUI/assets/soundbutton.wav")) {
        std::cerr << "Erreur lors du chargement du son du bouton" << std::endl;
        exit(1);
    }
    soundButton.setBuffer(soundBuffer);
    ip_str = "";
    port_str = "";
}

void Display::Menu() {
    while (window.isOpen()) {
        handleEvents();
        update();
        render();
    }
}

void Display::handleEvents() {
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

void Display::update() {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    if (mousePosition.x >= 521 && mousePosition.x <= 1395 && mousePosition.y >= 476 && mousePosition.y <= 776) {
        sprite_menu.setTexture(texture2);
    } else if (mousePosition.x >= 515 && mousePosition.x <= 1403 && mousePosition.y >= 843 && mousePosition.y <= 926) {
        sprite_menu.setTexture(texture3);
    } else {
        sprite_menu.setTexture(texture1);
    }
}

void Display::render() {
    window.clear(sf::Color::Black);
    window.draw(sprite_menu);
    window.display();
}

void Display::handleMouseClick(const sf::Vector2i& mousePosition) {
    if (mousePosition.x >= 515 && mousePosition.x <= 1403 && mousePosition.y >= 843 && mousePosition.y <= 926) {
        soundButton.play();
        window.close();
    }
    if (mousePosition.x >= 521 && mousePosition.x <= 1395 && mousePosition.y >= 476 && mousePosition.y <= 776) {
        soundButton.play();
        server_menu();
    }
}

int main(int ac, char **av) {
    Display display;
    display.Menu();
    return 0;
}

