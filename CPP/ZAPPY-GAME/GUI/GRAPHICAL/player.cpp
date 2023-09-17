////////////////////////////////////////////////////////////////////////////
//                                                                        //
//                                [PLAYER]                                //
//                                                                        //
////////////////////////////////////////////////////////////////////////////

#include "graphical.hpp"

Player::Player()
{

}

Player::~Player()
{

}

void Player::initPlayer(std::string uuid, int x, int y, int orientation, int lvl, std::string team, std::string imgPath)
{    
    _uuidPlayer = uuid;
    _xPlayer = x * 116;
    _yPlayer = y * 160;
    _orientation = Up;
    level = lvl;
    _teamName = team;
    _Tplayer.loadFromFile(imgPath);
    _Splayer.setTexture(_Tplayer);
    _Splayer.setScale(0.9f, 0.8f);
    _Splayer.setOrigin(116/ 2.0f, 160 / 2.0f);
    _Splayer.setPosition(_xPlayer, _yPlayer);

    inventory = new Item;
    // Set the default values for the inventory items
    inventory->FOOD = 0;
    inventory->LINEMATE = 0;
    inventory->DERAUMERE = 0;
    inventory->SIBURE = 0;
    inventory->MENDIANE = 0;
    inventory->PHIRAS = 0;
    inventory->THYSTAM = 0;
}

void Player::refreshPlayerList(){}

void Player::getInfoByCross(float cross_x, float cross_y)
{
    // if (cross_x >= _xPlayer && cross_x <= _xPlayer + ) {
    //     if (cross_y >= _yPlayer && cross_y <= _yPlayer +200) {
    //         std::cout << "x P ->" << _xPlayer << " y P ->" << _yPlayer << std::endl;
    //     }
    // }
}
