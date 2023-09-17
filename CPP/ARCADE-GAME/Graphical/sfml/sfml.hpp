/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-raphael.de-monchy
** File description:
** sfml.hpp
*/

#pragma once
#include <unistd.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
// #include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include "../include/IDisplayModule.hpp"
#include "../../errorHandling/errorHandling.hpp"
#include "../../utils/utils.hpp"

class sfml : public arc::IDisplayModule
{
    public:
        sfml();
        ~sfml();
        const std::string& getName() const override {
            static const std::string name = "sfml";
            return name;
        };

        //WINDOW//
        // void create_window() override;
        // void close_window() override;
        void init () override;
        void update() override;
        void stop () override;

        //DISPLAY//
        void display_board(board *board) override;
        void display_text(std::string text, int x, int y) override;
        void display_object(arc::Obj Obj);


        //EVENT//
        arc::Input handle_key() override;
        bool gameOver() override;
        bool isOpen() override;
        arc::Input prviousValue;


        //WSIZE//
        int getSizeWindowX() override;
        int getSizeWindowY() override;

    protected:
   //GENERAL
        sf::RenderWindow _window;
        sf::Event _event;
    //MENU BG
        sf::Texture _texture;
        sf::Sprite _sprite;
        sf::Texture _bgText;
        sf::Sprite _menuBgSprite;
        sf::Music _music;

        sf::Font _font;
        sf::Text _score;
    //BOUTON
        sf::Event _clickButton;
        sf::Texture _TsolarFoxB;
        sf::Texture _TSnakeB;

        sf::Sprite _SsolarFoxB;
        sf::Sprite _SsnakeB;

    //SNAKE TEXTURE/SPRITE
        sf::Texture _TsnakeWall;
        sf::Sprite _SsnakeWall;

        sf::Texture _TsnakeBG;
        sf::Sprite _SsnakeBG;

        sf::Texture _TsnakeHead;
        sf::Sprite _SsnakeHead;

        sf::Texture _TsnakeBody;
        sf::Sprite _SsnakeBody;

        sf::Texture _TsnakeFood1;
        sf::Sprite _SsnakeFood1;

        sf::Texture _TsnakeFood2;
        sf::Sprite _SsnakeFood2;

        sf::Texture _TsnakeFood3;
        sf::Sprite _SsnakeFood3;

    //SOLARFOX TEXTURE/SPRITE
};