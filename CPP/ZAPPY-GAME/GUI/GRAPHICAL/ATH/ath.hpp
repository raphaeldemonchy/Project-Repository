/*
** EPITECH PROJECT, 2023
** inventory
** File description:
** inventory
*/

#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

class INV {
    public:
        INV();
        ~INV();

        void refreshObject(std::string type, std::string uuid, std::string teamName, int level, int posx, int posy, int q0, int q1, int q2, int q3, int q4, int q5, int q6);

        void loadSPRITE(std::string path);
        void setPosSPRITE(float xSPRITE, float ySPRITE);
        void setScaleSPRITE(float xSPRITE, float ySPRITE);


////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void loadTEXT(std::string uuid, std::string teamName,
                      std::string level, std::string posx, std::string posy,
                      std::string q0, std::string q1,
                      std::string q2, std::string q3, 
                      std::string q4, std::string q5, 
                      std::string q6);

        void setPosTEXT(float Xuuid, float Yuuid,
                        float XteamN, float YteamN,
                        float Xlevel,  float Ylevel,
                        float posxX, float posxY,
                        float posyX, float posyY,
                        float q0X, float q0Y,
                        float q1X, float q1Y,
                        float q2X, float q2Y,
                        float q3X, float q3Y,
                        float q4X, float q4Y,
                        float q5X, float q5Y,
                        float q6X, float q6Y);

        void setScaleTEXT(float Xuuid, float Yuuid,
                    float XteamN, float YteamN,
                    float Xlevel,  float Ylevel,
                    float posxX, float posxY,
                    float posyX, float posyY,
                    float q0X, float q0Y,
                    float q1X, float q1Y,
                    float q2X, float q2Y,
                    float q3X, float q3Y,
                    float q4X, float q4Y,
                    float q5X, float q5Y,
                    float q6X, float q6Y);

        void displayINVENTORY(sf::RenderWindow *window);

        sf::Texture _Tinventory;
        sf::Sprite _Sinventory;

        sf::Font _font;

        sf::Text _uuidText;
        sf::Text _teamNameText;
        sf::Text _levelText;

        sf::Text _posxText;
        sf::Text _posyText;

        sf::Text _q0Text;
        sf::Text _q1Text;
        sf::Text _q2Text;
        sf::Text _q3Text;
        sf::Text _q4Text;
        sf::Text _q5Text;
        sf::Text _q6Text;

};

class ATH {
public:
    ATH();
    ~ATH();

    void refreshInventory(std::string type, std::string uuid, std::string teamName, int level, int posx, int posy, int q0, int q1, int q2, int q3, int q4, int q5, int q6);

    void destroyInventory();

    void updateScale(float xScale, float yScale);

    void updatePos(float xPos, float yPos, float centercoeff);

    void displayInventory(sf::RenderWindow *window);

    INV *_actualINV = new(INV);






};
