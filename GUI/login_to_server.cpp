/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** login_to_server
*/

#include "main.hpp"

void Display::get_map_size()
{
    width = 6;
    height = 6;
    
}

void Display::handleEvents4()
{
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
        if (event.type == sf::Event::KeyPressed) {
            handleKeyboard(event.key);
        }
    }
}

void Display::update4()
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

    if (mousePosition.x >= 526 && mousePosition.x <= 1396 && mousePosition.y >= 619 && mousePosition.y <= 694) {

    }
}

void Display::render4()
{
    int i = 0, y = 0;
    int surplu_x = (window.getSize().x / 2) - ((width * 128) / 2);
    int surplu_y = (window.getSize().y / 2) - ((height * 128) / 2);

    window.clear(sf::Color::Black);
    sprite_water.setTexture(texture10);
    sprite_HTAG.setTexture(textureHTAG);
    sprite_A.setTexture(textureA);
    sprite_B.setTexture(textureB);
    sprite_C.setTexture(textureC);
    sprite_D.setTexture(textureD);
    sprite_UP.setTexture(textureUP);
    sprite_DOWN.setTexture(textureDOWN);
    sprite_RIGHT.setTexture(textureRIGHT);
    sprite_LEFT.setTexture(textureLEFT);
    sprite_steve.setTexture(textureSteve);


    sprite_HTAG.setScale(8, 8);
    sprite_A.setScale(8, 8);
    sprite_B.setScale(8, 8);
    sprite_C.setScale(8, 8);
    sprite_D.setScale(8, 8);
    sprite_UP.setScale(8, 8);
    sprite_DOWN.setScale(8, 8);
    sprite_RIGHT.setScale(8, 8);
    sprite_LEFT.setScale(8, 8);
    sprite_steve.setScale(5, 5);

    if (isDay) {
        window.draw(sprite_water);
    } else if (isSunset) {
        window.draw(sprite_sunset);
    } else {
        window.draw(sprite_night);
    }

    while (map.size() > i) {
        while (map[i].size() > y) {
            if (map[i][y] == '#') {
                sprite_HTAG.setPosition(y * 128 + surplu_x, i * 128 + surplu_y);
                window.draw(sprite_HTAG);
            }
            if (map[i][y] == 'A') {
                sprite_A.setPosition(y * 128 + surplu_x, i * 128 + surplu_y);
                window.draw(sprite_A);
            }
            if (map[i][y] == 'B') {
                sprite_B.setPosition(y * 128 + surplu_x, i * 128 + surplu_y);
                window.draw(sprite_B);
            }
            if (map[i][y] == 'C') {
                sprite_C.setPosition(y * 128 + surplu_x, i * 128 + surplu_y);
                window.draw(sprite_C);
            }
            if (map[i][y] == 'D') {
                sprite_D.setPosition(y * 128 + surplu_x, i * 128 + surplu_y);
                window.draw(sprite_D);
            }
            if (map[i][y] == '-') {
                sprite_UP.setPosition(y * 128 + surplu_x, i * 128 + surplu_y);
                window.draw(sprite_UP);
            }
            if (map[i][y] == '_') {
                sprite_DOWN.setPosition(y * 128 + surplu_x, i * 128 + surplu_y);
                window.draw(sprite_DOWN);
            }
            if (map[i][y] == '<') {
                sprite_LEFT.setPosition(y * 128 + surplu_x, i * 128 + surplu_y);
                window.draw(sprite_LEFT);
            }
            if (map[i][y] == '>') {
                sprite_RIGHT.setPosition(y * 128 + surplu_x, i * 128 + surplu_y);
                window.draw(sprite_RIGHT);
            }
            y++;
        }
        y = 0;
        i++;
    }
    sprite_steve.setPosition(500, 290);
    window.draw(sprite_steve);
    window.display();
}

void Display::client_loop()
{
    get_map_size();
    FD_ZERO(&fd_client);
    FD_SET(client_socket, &fd_client);
    FD_SET(0, &fd_client);
    map = generate_map(width, height);
    int i = 0;
    while (map.size() > i) {
        std::cout << map[i];
        i++;
    }
    struct timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 10000;

    while (window.isOpen()) {
        fd_user = fd_client;
        int retval = select(client_socket + 1, &fd_user, NULL, NULL, &tv);
        if (retval == -1) {
            perror("select()");
            exit(84);
        } else if (retval > 0) {
            if (FD_ISSET(client_socket, &fd_user)) {
                receive_from_server();
            }
            if (FD_ISSET(0, &fd_user)) {
                send_to_server("WELCOME\n");
            }
        }
        handleEvents4();
        update4();

        // Mise à jour de l'état jour/nuit
        if (clock.getElapsedTime() >= timeInterval) {
    if (isSunset) {
        isSunset = false;
        isNight = true;
    } else if (isNight) {
        isNight = false;
        isDay = true;
    } else { // isDay
        isDay = false;
        isSunset = true;
    }
    clock.restart(); // Réinitialise le chronomètre
}


        render4();
        tv.tv_sec = 0;
        tv.tv_usec = 10000;
    }
}



void Display::receive_from_server()
{
    char buffer[1024];
    ssize_t bytes_rcvd;

    bytes_rcvd = read(client_socket, buffer, sizeof(buffer));
    if (bytes_rcvd <= 0) {
        if (bytes_rcvd == 0) {
            printf("Deconnexion du serveur.\n");
        } else {
            perror("Erreur lors de la lecture depuis le serveur");
        }
        exit(84);
    } else {
        buffer[bytes_rcvd] = '\0';
    }
}

void Display::send_to_server(std::string command)
{
    send(client_socket, command.c_str(), strlen(line), 0);
}

int Display::init_socket_client()
{
    int cvd;

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    sockaddrIn.sin_family = AF_INET;
    sockaddrIn.sin_addr.s_addr = inet_addr(ip_str.c_str());
    sockaddrIn.sin_port = htons(atoi(port_str.c_str()));
    cvd = connect(client_socket,
    (struct sockaddr *) &sockaddrIn, sizeof(sockaddrIn));
    if (cvd < 0) {
        return (9);
    }
    client_loop();
    return (0);
}
