////////////////////////////////////////////////////////////////////////////
//                                                                        //
//                                [MAP]                                   //
//                                                                        //
////////////////////////////////////////////////////////////////////////////

#include "graphical.hpp"

Map::Map()
{


}

Map::~Map()
{

}

void Map::initNewTuileAtPos(int x, int y, int q0, int q1, int q2, int q3, int q4, int q5, int q6, std::string pathTexture)
{
    Tuile *newTuile = new (Tuile);
    newTuile->_items = new(Item);
    newTuile->initTuileByPos(x, y, q0, q1, q2, q3, q4, q5, q6, pathTexture);
    _mapElement.push_back(newTuile);
}

void Map::updateTuileContentAtPos(int x, int y, int q0, int q1, int q2, int q3, int q4, int q5, int q6)
{
    // for (Tuile& tuile : _mapElement) {
    //     if (tuile._xposTuile == x && tuile._yposTuile == y) {
    //         tuile.updateItem(FOOD, q0);
    //         tuile.updateItem(LINEMATE, q1);
    //         tuile.updateItem(DERAUMERE, q2);
    //         tuile.updateItem(SIBURE, q3);
    //         tuile.updateItem(MENDIANE, q4);
    //         tuile.updateItem(PHIRAS, q5);
    //         tuile.updateItem(THYSTAM, q6);
    //         break;
    //     }
    // }
}

Tuile *Map::getTileByXY(int x, int y)
{
    for (int i = 0; i != _mapElement.size(); i++) {
        if (_mapElement[i]->_xposTuile == x && _mapElement[i]->_yposTuile == y)
            return _mapElement[i];
    }
    return NULL;
}


////////////////////////////////////////////////////////////////////////////
//                                                                        //
//                              [ TUILE ]                                  //
//                                                                        //
////////////////////////////////////////////////////////////////////////////



Tuile::Tuile()
{
}

Tuile::~Tuile()
{
}

void Tuile::initTuileByPos(int x, int y, int q0, int q1, int q2, int q3, int q4, int q5, int q6, std::string pathTexture)
{
    _nbEGGS = 0;
    _xposTuile = x;
    _yposTuile = y;
    _items->FOOD = q0;
    _items->LINEMATE = q1;
    _items->DERAUMERE = q2;
    _items->SIBURE = q3;
    _items->MENDIANE = q4;
    _items->PHIRAS = q5;
    _items->THYSTAM = q6;
    if (!_Ttuile.loadFromFile(pathTexture)) {
        std::cout << "ERROR : load Tuile texture" << std::endl;
    }
    float _x = x * 200;
    float _y = y * 200;
    _Stuile.setPosition(_x, _y);
    _Stuile.setTexture(_Ttuile);
    _Stuile.setScale(1.0f, 1.0f);
}