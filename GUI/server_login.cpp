/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** server_menu
*/

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "main.hpp"

void Display::handleMouseClick3(const sf::Vector2i& mousePosition)
{
    if (mousePosition.x >= 526 && mousePosition.x <= 1396 && mousePosition.y >= 619 && mousePosition.y <= 694) {
        soundButton.play();
    }
    if (mousePosition.x >= 517 && mousePosition.x <= 1406 && mousePosition.y >= 272 && mousePosition.y <= 365) {
        //ici
        soundButton.play();
    }
    if (mousePosition.x >= 519 && mousePosition.x <= 1407 && mousePosition.y >= 448 && mousePosition.y <= 545) {
        //ici
        soundButton.play();
    }
}

void Display::handleEvents3() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed || 
            (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
            window.close();
        } else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            std::cout << "Position de la souris : x = " << mousePosition.x << ", y = " << mousePosition.y << std::endl;
            handleMouseClick3(mousePosition);
        }
    }
}

void Display::update3() {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

    if (mousePosition.x >= 526 && mousePosition.x <= 1396 && mousePosition.y >= 619 && mousePosition.y <= 694) {
        sprite_login.setTexture(texture7);
    } else if (mousePosition.x >= 517 && mousePosition.x <= 1406 && mousePosition.y >= 272 && mousePosition.y <= 365) {
        sprite_login.setTexture(texture8);
    } else if (mousePosition.x >= 519 && mousePosition.x <= 1407 && mousePosition.y >= 448 && mousePosition.y <= 545) {
        sprite_login.setTexture(texture9);
    } else {
        sprite_login.setTexture(texture6);
    }
}



void Display::render3() {
    window.clear(sf::Color::Black);
    window.draw(sprite_login);

    font.loadFromFile("GUI/assets/minecraft_font.ttf");
    text.setFont(font); // Supposons que vous avez une variable font contenant votre police de caractères chargée
    text.setString("Big Rats");
    text.setCharacterSize(31); // Taille du texte
    text.setFillColor(sf::Color::White); // Couleur du texte
    text.setPosition(540, 300); // Position du texte
    window.draw(text);
    
    window.display();
}

void Display::server_login()
{
    while (window.isOpen()) {
        handleEvents3();
        update3();
        render3();
    }
}