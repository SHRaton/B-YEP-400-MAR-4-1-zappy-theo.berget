/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** main
*/

#include "../include/Core.hpp"

void Core::loadAssets()
{
    // Toutes les textures chargées
    texture1.loadFromFile("GUI/assets/Menu.png");
    texture2.loadFromFile("GUI/assets/Menu2.png");
    texture3.loadFromFile("GUI/assets/Menu3.png");

    texture4.loadFromFile("GUI/assets/server_menu.jpeg");
    texture5.loadFromFile("GUI/assets/server_menu2.jpeg");

    texture6.loadFromFile("GUI/assets/join_server.jpeg");
    texture7.loadFromFile("GUI/assets/join_server2.jpeg");
    texture8.loadFromFile("GUI/assets/join_server3.png");
    texture9.loadFromFile("GUI/assets/join_server4.png");
    texture10.loadFromFile("GUI/assets/water.jpeg");
    textureNight.loadFromFile("GUI/assets/moon.png");
    textureSunset.loadFromFile("GUI/assets/sunset.png");

    textureHTAG.loadFromFile("GUI/assets/#.png");
    textureA.loadFromFile("GUI/assets/A2.png");
    textureB.loadFromFile("GUI/assets/B2.png");
    textureC.loadFromFile("GUI/assets/C.png");
    textureD.loadFromFile("GUI/assets/D.png");
    textureUP.loadFromFile("GUI/assets/-.png");
    textureDOWN.loadFromFile("GUI/assets/_.png");
    textureRIGHT.loadFromFile("GUI/assets/droite.png");
    textureLEFT.loadFromFile("GUI/assets/gauche.png");
    textureSteve.loadFromFile("GUI/assets/idle.png");

    // Selection Rectangle blanc dans le menu du serveur
    selectionRectangle.setFillColor(sf::Color::Transparent);
    selectionRectangle.setOutlineColor(sf::Color::White);
    selectionRectangle.setOutlineThickness(9);

    // Texture set des sprites
    sprite_menu.setTexture(texture1);
    sprite_server.setTexture(texture4);
    sprite_login.setTexture(texture6);
    sprite_night.setTexture(textureNight);
    sprite_sunset.setTexture(textureSunset);

    sprite_menu.setScale(1920 / sprite_menu.getGlobalBounds().width, 1080 / sprite_menu.getGlobalBounds().height);

    // Toutes les musiques et sons
    menuMusic.openFromFile("GUI/assets/menu.wav");
    menuMusic.setLoop(true);
    menuMusic.play();

    menuGame.openFromFile("GUI/assets/game.wav");
    menuGame.setLoop(true);

    soundBuffer.loadFromFile("GUI/assets/soundbutton.wav");
    soundButton.setBuffer(soundBuffer);

    soundBuffer_zoom.loadFromFile("GUI/assets/zoom.wav");
    sound_zoom.setBuffer(soundBuffer_zoom);
    soundBuffer_dezoom.loadFromFile("GUI/assets/dezoom.wav");
    sound_dezoom.setBuffer(soundBuffer_dezoom);

    soundBuffer_zombie.loadFromFile("GUI/assets/zombie.wav");
    sound_zombie.setBuffer(soundBuffer_zombie);

    ip_str = "";
    port_str = "";
    failed_str = "Connection to server failed...";
    failed_connection = 0;

    //Gestion du Temps
    isDay = true;
    isSunset = false;
    isNight = false;
    timeInterval = sf::seconds(15);

    width = 10;
    height = 10;
    ratio = 1.0;
    indx = 404;
}

void Core::change_ip_port(std::string ip, std::string port)
{
    ip_str = ip;
    port_str = port;
}

int main(int ac, char **av)
{
    std::ofstream file("./LOG/gui.log", std::ios::out | std::ios::trunc);
    file << "Logs :\n\n" << std::endl;
    file.close();

    if (ac != 1 && ac != 5) {
        std::cout << "USAGE : ./zappy_gui -h [IP] -p [PORT]" << std::endl;
        return (84);
    }
    Core core;

    core.change_ip_port("", "");
    if (ac == 5) {
        core.change_ip_port(std::string(av[2]), std::string(av[4]));
    }
    core.Menu();
    return 0;
}
