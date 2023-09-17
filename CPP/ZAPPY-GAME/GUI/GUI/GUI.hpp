/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** GUI
*/

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <unistd.h>

class GUI {
    public:
        GUI();
        ~GUI(){};
        void text_zone();
        void setColor_GUI();
        void draw_GUI();
        void buttonEvent();
        void run();

        void lunch_action();

        bool _isOn;

        //       WINDOW GUI      //

        sf::RenderWindow _window;

        sf::Texture _backgroundTexture;
        sf::Sprite _backgroundSprite;

        sf::View _view;
        sf::Event _event;
        sf::Font _font;

        //  BOUTON LUNCH    //

        sf::Texture _buttonOnTexture;
        sf::Sprite _buttonOnSprite;

        sf::Texture _buttonOffTexture;
        sf::Sprite _buttonOffSprite;

        bool _isButtonOn;

        // VARRIABLE ZONE DE TEXT //
        sf::RectangleShape _champ1;
        sf::RectangleShape _champ2;
        sf::Text _text1;
        sf::Text _text2;
        bool _isChamp1Selected;
        bool _isChamp2Selected;

        sf::Text _port;
        sf::Text _machineName;

        std::string _portEnter;
        std::string _machineEnter;

        std::string getPort() {
            return _portEnter;
        };

        std::string getName() {
            return _machineEnter;
        };

        sf::Music _music;





    private:



};

