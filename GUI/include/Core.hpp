/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** main
*/

#pragma once

#include "includes.hpp"
#include "Ressources.hpp"
#include "Info_Players.hpp"

class Core {
    public :
        Core() : window(sf::VideoMode(1920, 1080), "Zappy")
        {
            loadAssets();
        };
        ~Core() = default;

        // Display //
        void Menu();
        void server_menu();
        void server_login();
        void change_ip_port(std::string ip, std::string port);

        // main.cpp
        std::vector<std::string> str_to_word_array(std::string s);
        void loadAssets();

        // minecraft_start.cpp
        void handleEvents();
        void handleMouseClick(const sf::Vector2i& mousePosition);
        void update();
        void render();

        // minecraft_menu.cpp
        void handleEvents2();
        void handleMouseClick2(const sf::Vector2i& mousePosition);
        void update2();
        void render2();

        // minecraft_login.cpp
        void handleEvents3();
        void handleMouseClick3(const sf::Vector2i& mousePosition);
        void update3();
        void render3();

        // joining_server.cpp
        void handleEvents4();
        void handleKeyboard(sf::Event::KeyEvent key);
        void handleClick(int mouseX, int mouseY);
        void update4();
        void render4();
        void showPlayerResources();
        void countTotalResources();

        // map.cpp
        void set_map_size(int x, int y);
        std::vector<std::string> generate_map(int x, int y);

       // Commandes
        void commands();
        void pnw();
        void pdi();
        void ppo();
        void mct();
        void pin();
        void plv();

        // Window
        sf::RenderWindow window;

        // Map infos
        int width;
        int height;
        std::vector<std::string> map;
        std::vector<std::vector<ressources>> ressources_grid;
        ressources selectedResources;
        ressources show_inv;

        // All Textures
        sf::Texture texture1;
        sf::Texture texture2;
        sf::Texture texture3;
        sf::Texture texture4;
        sf::Texture texture5;
        sf::Texture texture6;
        sf::Texture texture7;
        sf::Texture texture8;
        sf::Texture texture9;
        sf::Texture texture10;
        sf::Texture textureHTAG;
        sf::Texture textureA;
        sf::Texture textureB;
        sf::Texture textureC;
        sf::Texture textureD;
        sf::Texture textureUP;
        sf::Texture textureDOWN;
        sf::Texture textureRIGHT;
        sf::Texture textureLEFT;
        sf::Texture textureSteve;
        sf::Texture textureDay;
        sf::Texture textureNight;
        sf::Texture textureSunset;
        sf::Texture texture_food;
        sf::Texture texture_coal;
        sf::Texture texture_iron;
        sf::Texture texture_gold;
        sf::Texture texture_diamond;
        sf::Texture texture_emerald;
        sf::Texture texture_netherite;
        sf::Texture texture_player_inventory;
        sf::Texture texture_case_inventory;

        // All Sprites
        sf::Sprite sprite_menu;
        sf::Sprite sprite_server;
        sf::Sprite sprite_login;
        sf::Sprite sprite_water;
        sf::Sprite sprite_HTAG;
        sf::Sprite sprite_A;
        sf::Sprite sprite_B;
        sf::Sprite sprite_C;
        sf::Sprite sprite_D;
        sf::Sprite sprite_UP;
        sf::Sprite sprite_DOWN;
        sf::Sprite sprite_RIGHT;
        sf::Sprite sprite_LEFT;
        sf::Sprite sprite_steve;
        sf::Sprite sprite_day;
        sf::Sprite sprite_night;
        sf::Sprite sprite_sunset;
        sf::Sprite sprite_food;
        sf::Sprite sprite_coal;
        sf::Sprite sprite_iron;
        sf::Sprite sprite_gold;
        sf::Sprite sprite_diamond;
        sf::Sprite sprite_emerald;
        sf::Sprite sprite_netherite;
        sf::Sprite sprite_player_inventory;
        sf::Sprite sprite_case_inventory;

        // All RectangleShape
        sf::RectangleShape selectionRectangle;
        sf::RectangleShape greyRectangle;
        sf::RectangleShape greyRectangle2;

        // All music
        sf::Music menuMusic;
        sf::Music menuGame;
        sf::SoundBuffer soundBuffer;
        sf::Sound soundButton;
        sf::SoundBuffer soundBuffer_zoom;
        sf::Sound sound_zoom;
        sf::SoundBuffer soundBuffer_dezoom;
        sf::Sound sound_dezoom;
        sf::SoundBuffer soundBuffer_zombie;
        sf::Sound sound_zombie;

        // All text
        sf::Font font;
        sf::Text text_ip;
        sf::Text text_port;
        sf::Text text_failed;
        sf::Text text_level;
        sf::Text text_team_name;
        sf::Text resourceText;
        sf::Text mapSizeText;
        sf::Text totalResourcesText;

        // All strings
        std::string ip_str;
        std::string port_str;
        std::string failed_str;
        std::string userInput;

        // All integer
        bool isDay;
        bool isSunset;
        bool isNight;
        int select_button;
        int surplu_x;
        int surplu_y;
        int animation;
        double ratio;
        int indx;
        int pressed;

        // All Clock
        sf::Time timeInterval;
        sf::Clock clock;
        sf::Clock clock_pos;
        sf::Clock clock_mct;
        sf::Clock clock_pin;
        sf::Clock clock_plv;


        // Network //
        void welcome();
        int init_socket_client();
        void receive_from_server();
        void send_to_server(std::string command);
        void client_loop();
        int client_socket;
        struct sockaddr_in sockaddrIn;
        char buffer[9999];
        std::string sbuffer;
        std::vector<std::string> vbuffer;
        char *line;
        char *uuid_s;
        char *name;
        int isLogin;
        fd_set fd_client;
        fd_set fd_user;
        size_t line_size;
        int failed_connection;
        char buff[256];
        // ID (number) des joueurs connectés
        Info_Player info_player;
        // Position du joueur
        std::vector<Info_Player> info_players;
        std::vector<Info_Player> info_players_brut;

};
