/*
** EPITECH PROJECT, 2023
** inventory
** File description:
** inventory
*/

#include "ath.hpp"

INV::INV()
{    

}

INV::~INV()
{
}

void INV::refreshObject(std::string type, std::string uuid, std::string teamName, int level, int posx, int posy, int q0, int q1, int q2, int q3, int q4, int q5, int q6)
{
    if (type == "Player") {
        loadSPRITE("GRAPHICAL/assets/playerInventory.png");
        loadTEXT(uuid, teamName, std::to_string(level), std::to_string(posx), std::to_string(posy), std::to_string(q0), std::to_string(q1), std::to_string(q2), std::to_string(q3), std::to_string(q4), std::to_string(q5), std::to_string(q6));

    } else if (type == "Ile") {
        loadSPRITE("GRAPHICAL/assets/TuileInventory.png");
        loadTEXT(uuid, teamName, " ", std::to_string(posx), std::to_string(posy), std::to_string(q0), std::to_string(q1), std::to_string(q2), std::to_string(q3), std::to_string(q4), std::to_string(q5), std::to_string(q6));
        
    }
}

void INV::loadSPRITE(std::string path)
{
    if (!_Tinventory.loadFromFile(path)) {
        std::cout << "ERROR : fail load playerInventory" << std::endl;
    }
    _Sinventory.setTexture(_Tinventory);
    _Sinventory.setOrigin(470 / 2, 595 / 2);
}

void INV::setPosSPRITE(float xSPRITE, float ySPRITE)
{
    _Sinventory.setPosition(xSPRITE, ySPRITE);
}


void INV::setScaleSPRITE(float xSPRITE, float ySPRITE)
{
    _Sinventory.setScale(xSPRITE, ySPRITE);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//      TEXT INVENTAIRE     //
std::string addNewlines(const std::string& input, unsigned int maxLength)
{
    std::string result;
    unsigned int length = input.length();
    unsigned int currentPosition = 0;

    while (currentPosition < length)
    {
        result += input.substr(currentPosition, maxLength) + "\n";
        currentPosition += maxLength;
    }

    return result;
}
//////////////////////////////////////////////////////////////////////////////////////////

void INV::loadTEXT(std::string uuid, std::string teamName,
                   std::string level, std::string posx, std::string posy,
                   std::string q0, std::string q1,
                   std::string q2, std::string q3, 
                   std::string q4, std::string q5, 
                   std::string q6)
{
    if (!_font.loadFromFile("GRAPHICAL/assets/Fonts/style.ttf")) {
        std::cout << "ERROR : Fail load font" << std::endl;
    }

    _uuidText.setFont(_font);
    _uuidText.setString(addNewlines(uuid, 20));
    _uuidText.setFillColor(sf::Color::Black);

    _teamNameText.setFont(_font);
    _teamNameText.setString(addNewlines(teamName, 10));
    _teamNameText.setFillColor(sf::Color::Black);

    _levelText.setFont(_font);
    _levelText.setString(level);
    _levelText.setFillColor(sf::Color::Black);

    _posxText.setFont(_font);
    _posxText.setString(posx);
    _posxText.setFillColor(sf::Color::Black);

    _posyText.setFont(_font);
    _posyText.setString(posy);
    _posyText.setFillColor(sf::Color::Black);

    _q0Text.setFont(_font);
    _q0Text.setString(q0);
    _q0Text.setFillColor(sf::Color::Black);

    _q1Text.setFont(_font);
    _q1Text.setString(q1);
    _q1Text.setFillColor(sf::Color::Black);

    _q2Text.setFont(_font);
    _q2Text.setString(q2);
    _q2Text.setFillColor(sf::Color::Black);

    _q3Text.setFont(_font);
    _q3Text.setString(q3);
    _q3Text.setFillColor(sf::Color::Black);

    _q4Text.setFont(_font);
    _q4Text.setString(q4);
    _q4Text.setFillColor(sf::Color::Black);


    _q5Text.setFont(_font);
    _q5Text.setString(q5);
    _q5Text.setFillColor(sf::Color::Black);

    _q6Text.setFont(_font);
    _q6Text.setString(q6);
    _q6Text.setFillColor(sf::Color::Black);

    _uuidText.setCharacterSize(15);
    _teamNameText.setCharacterSize(20);
    _levelText.setCharacterSize(20);

    _posxText.setCharacterSize(20);
    _posyText.setCharacterSize(20);

    _q0Text.setCharacterSize(20);
    _q1Text.setCharacterSize(20);
    _q2Text.setCharacterSize(20);
    _q3Text.setCharacterSize(20);
    _q4Text.setCharacterSize(20);
    _q5Text.setCharacterSize(20);
    _q6Text.setCharacterSize(20);

}


void INV::setPosTEXT(float Xuuid, float Yuuid,
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
                        float q6X, float q6Y)
{
    _uuidText.setPosition(Xuuid, Yuuid);
    _teamNameText.setPosition(XteamN, YteamN);
    _levelText.setPosition(Xlevel, Ylevel);
    
    _posxText.setPosition(posxX, posxY);
    _posyText.setPosition(posyX, posyY);

    _q0Text.setPosition(q0X, q0Y);
    _q1Text.setPosition(q1X, q1Y);
    _q2Text.setPosition(q2X, q2Y);
    _q3Text.setPosition(q3X, q3Y);
    _q4Text.setPosition(q4X, q4Y);
    _q5Text.setPosition(q5X, q5Y);
    _q6Text.setPosition(q6X, q6Y);

}

void INV::setScaleTEXT(float Xuuid, float Yuuid,
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
                    float q6X, float q6Y)
{
    _uuidText.setScale(Xuuid, Yuuid);
    _teamNameText.setScale(XteamN, YteamN);
    _levelText.setScale(Xlevel, Ylevel);
    
    _posxText.setScale(posxX, posxY);
    _posyText.setScale(posyX, posyY);

    _q0Text.setScale(q0X, q0Y);
    _q1Text.setScale(q1X, q1Y);
    _q2Text.setScale(q2X, q2Y);
    _q3Text.setScale(q3X, q3Y);
    _q4Text.setScale(q4X, q4Y);
    _q5Text.setScale(q5X, q5Y);
    _q6Text.setScale(q6X, q6Y);
}

    
void INV::displayINVENTORY(sf::RenderWindow *window)
{
    window->draw(_Sinventory);
    window->draw(_uuidText);
    window->draw(_teamNameText);
    window->draw(_levelText);

    window->draw(_posxText);
    window->draw(_posyText);

    window->draw(_q0Text);
    window->draw(_q1Text);
    window->draw(_q2Text);
    window->draw(_q3Text);
    window->draw(_q4Text);
    window->draw(_q5Text);
    window->draw(_q6Text);
}
