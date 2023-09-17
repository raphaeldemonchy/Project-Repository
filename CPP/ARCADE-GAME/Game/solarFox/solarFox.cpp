/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** solarFox.c
*/

#include <stdio.h>
#include <unistd.h>
#include "solarFox.hpp"

void initSolarFox() __attribute__((constructor));
void closeSolarFox() __attribute__((destructor));
extern "C" arc::IGameModule *entryPoint();

void initSolarFox()
{
    // printf("[libSolarFox] Loading SolarFox library...\n");
}

void closeSolarFox()
{
    // printf("[libSolarFox] SolarFox closing.\n");
}

extern "C" arc::IGameModule *entryPoint()
{
    // printf("[libSolarFox] entry point !\n");
    return new solarFox();
}

solarFox::solarFox()
{
    this->gameOver_ = false;
    this->mobUp = true;
    this->mobDown = true;
    this->mobLeft = true;
    this->mobRight = true;
}

solarFox::~solarFox()
{

}

const std::string& solarFox::getName() const
{
    static const std::string name = "solarFox";
                return name;
}

void solarFox::char_to_object(board *board, char ptrChar, int x, int y)
{
    if (ptrChar == 'A') {
        board->_Object.push_back(arc::Obj("SpaceShipUp", spaceShipUp, x + 480, y));
    }
    if (ptrChar == '>') {
        board->_Object.push_back(arc::Obj("SpaceShipRight", spaceShipRight, x + 480, y));
    }
    if (ptrChar == '<') {
        board->_Object.push_back(arc::Obj("SpaceShipLeft", spaceShipLeft, x + 480, y));
    }
    if (ptrChar == 'V') {
        board->_Object.push_back(arc::Obj("SpaceShipDown", spaceShipDown, x + 480, y));
    }

    if (ptrChar == 'H') {
        board->_Object.push_back(arc::Obj("SpaceTurretUp", spaceTurretUp, x + 480, y));
    }
    if (ptrChar == 'T') {
        board->_Object.push_back(arc::Obj("SpaceTurretRight", spaceTurretRight, x + 480, y));
    }
    if (ptrChar == 'J') {
        board->_Object.push_back(arc::Obj("SpaceTurretLeft", spaceTurretLeft, x + 480, y));
    }
    if (ptrChar == 'B') {
        board->_Object.push_back(arc::Obj("SpaceTurretDown", spaceTurretDown, x + 480, y));
    }

    if (ptrChar == '2') {
        board->_Object.push_back(arc::Obj("ammoUp", ammoUp, x + 480, y));
    }
    if (ptrChar == '3') {
        board->_Object.push_back(arc::Obj("ammoRight", ammoRight, x + 480, y));
    }
    if (ptrChar == '4') {
        board->_Object.push_back(arc::Obj("ammoLeft", ammoLeft, x + 480, y));
    }
    if (ptrChar == '1') {
        board->_Object.push_back(arc::Obj("ammoDown", ammoDown, x + 480, y));
    }

    if (ptrChar == 'u') {
        board->_Object.push_back(arc::Obj("ammoUp2", ammoUp2, x + 480, y));
    }
    if (ptrChar == 'l') {
        board->_Object.push_back(arc::Obj("ammoRight2", ammoRight2, x + 480, y));
    }
    if (ptrChar == 'r') {
        board->_Object.push_back(arc::Obj("ammoLeft2", ammoLeft2, x + 480, y));
    }
    if (ptrChar == 'd') {
        board->_Object.push_back(arc::Obj("ammoDown2", ammoDown2, x + 480, y));
    }

    if (ptrChar == 'c') {
        board->_Object.push_back(arc::Obj("coin", coin, x + 480, y));
    }
    if (ptrChar == '$') {
        board->_Object.push_back(arc::Obj("ironWall", ironWall, x + 480, y));
    }

}

void solarFox::init(board *board)
{
    char ptrChar;
    int pos_x = 0;
    int pos_y = 0;
    
    board->_Object.clear();
    for (size_t i = 0; i < board->boardMap.size(); i++) {
        pos_x = 0;
        for (size_t j = 0; j < (board->boardMap[i].size() + 2); j++) {
            ptrChar = board->boardMap[i][j];
            char_to_object(board, ptrChar, pos_x, pos_y);
            pos_x += 50;
        }
        pos_y += 50;
    }
    // - - - //
    for (int i = 0; i < board->boardMap.size(); i += 1) 
        for (int j = 0; j < board->boardMap[i].size(); j += 1)
            if (board->boardMap[i][j] == 'A') {
                this->posY = j;
                this->posY = i;
            }
}

void solarFox::moveLeft(board *board)
{
    for (int i = 0; i < board->boardMap.size(); i += 1)
        for (int j = 0; j < board->boardMap[i].size(); j += 1) {
            if (board->boardMap[i][j] == 'A' || board->boardMap[i][j] == 'V' || board->boardMap[i][j] == '<' || board->boardMap[i][j] == '>') {
                this->posY = i;
                this->posX = j;
            }
        }
    if (board->boardMap[this->posY][this->posX-1] == 'd' || board->boardMap[this->posY][this->posX-1] == 'u' || board->boardMap[this->posY][this->posX-1] == 'r' || board->boardMap[this->posY][this->posX-1] == 'l' || board->boardMap[this->posY][this->posX-1] == '$' || board->boardMap[this->posY][this->posX-1] == 'B' || board->boardMap[this->posY][this->posX-1] == 'H'//
    || board->boardMap[this->posY][this->posX-1] == 'T' || board->boardMap[this->posY][this->posX-1] == 'J') {
        this->collision();
    } else {
        board->boardMap[this->posY][this->posX] = ' ';
        board->boardMap[this->posY][this->posX-1] = '<';
    }  
}

void solarFox::moveRight(board *board)
{
    for (int i = 0; i < board->boardMap.size(); i += 1)
        for (int j = 0; j < board->boardMap[i].size(); j += 1) {
            if (board->boardMap[i][j] == 'A' || board->boardMap[i][j] == 'V' || board->boardMap[i][j] == '<' || board->boardMap[i][j] == '>') {
                this->posY = i;
                this->posX = j;
            }
        }
    if (board->boardMap[this->posY][this->posX+1] == 'd' || board->boardMap[this->posY][this->posX+1] == 'u' || board->boardMap[this->posY][this->posX+1] == 'r' || board->boardMap[this->posY][this->posX+1] == 'l' || board->boardMap[this->posY][this->posX+1] == '$' || board->boardMap[this->posY][this->posX+1] == 'B' || board->boardMap[this->posY][this->posX+1] == 'H' //
    || board->boardMap[this->posY][this->posX+1] == 'T' || board->boardMap[this->posY][this->posX+1] == 'J')
     {
        this->collision();
    } else {
        board->boardMap[this->posY][this->posX] = ' ';
        board->boardMap[this->posY][this->posX+1] = '>';
    }
}


void solarFox::moveUp(board *board)
{    
    for (int i = 0; i < board->boardMap.size(); i += 1)
        for (int j = 0; j < board->boardMap[i].size(); j += 1) {
            if (board->boardMap[i][j] == 'A' || board->boardMap[i][j] == 'V' || board->boardMap[i][j] == '<' || board->boardMap[i][j] == '>') {
                this->posY = i;
                this->posX = j;
            }
        }
    if (board->boardMap[this->posY-1][this->posX] == 'd' || board->boardMap[this->posY-1][this->posX] == 'u' || board->boardMap[this->posY-1][this->posX] == 'r' || board->boardMap[this->posY-1][this->posX] == 'l' || board->boardMap[this->posY-1][this->posX] == '$' || board->boardMap[this->posY-1][this->posX] == 'B' || board->boardMap[this->posY-1][this->posX] == 'H' //
    || board->boardMap[this->posY-1][this->posX] == 'T' || board->boardMap[this->posY-1][this->posX] == 'J') {
        this->collision();
    } else {
        board->boardMap[this->posY][this->posX] = ' ';
        board->boardMap[this->posY-1][this->posX] = 'A';
    }   
}

void solarFox::moveDown(board *board)
{
    for (int i = 0; i < board->boardMap.size(); i += 1)
        for (int j = 0; j < board->boardMap[i].size(); j += 1) {
            if (board->boardMap[i][j] == 'A' || board->boardMap[i][j] == 'V' || board->boardMap[i][j] == '<' || board->boardMap[i][j] == '>') {
                this->posY = i;
                this->posX = j;
            }
        }
    if (board->boardMap[this->posY+1][this->posX] == 'd' || board->boardMap[this->posY+1][this->posX] == 'u' || board->boardMap[this->posY+1][this->posX] == 'r' || board->boardMap[this->posY+1][this->posX] == 'l' || board->boardMap[this->posY+1][this->posX] == '$' || board->boardMap[this->posY+1][this->posX] == 'B' || board->boardMap[this->posY+1][this->posX] == 'H' //
    || board->boardMap[this->posY+1][this->posX] == 'T' || board->boardMap[this->posY+1][this->posX] == 'J') {
        this->collision();
    } else {
        board->boardMap[this->posY][this->posX] = ' ';
        board->boardMap[this->posY+1][this->posX] = 'V';
    }   
}

void solarFox::shoot(board *board)
{
    for (int i = 0; i < board->boardMap.size(); i += 1)
        for (int j = 0; j < board->boardMap[i].size(); j += 1) {
            if (board->boardMap[i][j] == 'A' || board->boardMap[i][j] == 'V' || board->boardMap[i][j] == '<' || board->boardMap[i][j] == '>') {
                this->posY = i;
                this->posX = j;
            }
        }
    if (board->boardMap[this->posY][this->posX] == 'A') {
        if (board->boardMap[this->posY-1][this->posX] != 'B' && board->boardMap[this->posY-1][this->posX] != 'H' && //
        board->boardMap[this->posY-1][this->posX] != 'T' && board->boardMap[this->posY-1][this->posX] != 'J' //
        && board->boardMap[this->posY-1][this->posX]!= '$')
            board->boardMap[this->posY-1][this->posX] = '2';
        if (board->boardMap[this->posY-2][this->posX] != 'B' && board->boardMap[this->posY-2][this->posX] != 'H' && //
        board->boardMap[this->posY-2][this->posX] != 'T' && board->boardMap[this->posY-2][this->posX] != 'J'//
        && board->boardMap[this->posY-2][this->posX]!= '$')
            board->boardMap[this->posY-2][this->posX] = '2';
    }
    else if (board->boardMap[this->posY][this->posX] == 'V') {
        if (board->boardMap[this->posY+1][this->posX] != 'B' && board->boardMap[this->posY+1][this->posX] != 'H' && //
        board->boardMap[this->posY+1][this->posX] != 'T' && board->boardMap[this->posY+1][this->posX] != 'J'//
        && board->boardMap[this->posY+1][this->posX]!= '$')
            board->boardMap[this->posY+1][this->posX] = '1';
        if (board->boardMap[this->posY+2][this->posX] != 'B' && board->boardMap[this->posY+2][this->posX] != 'H' && //
        board->boardMap[this->posY+2][this->posX] != 'T' && board->boardMap[this->posY+2][this->posX] != 'J'//
        && board->boardMap[this->posY+2][this->posX]!= '$')
            board->boardMap[this->posY+2][this->posX] = '1';

    }
    else if (board->boardMap[this->posY][this->posX] == '>') {
        if (board->boardMap[this->posY][this->posX+1] != 'B' && board->boardMap[this->posY][this->posX+1] != 'H' && //
        board->boardMap[this->posY][this->posX+1] != 'T' && board->boardMap[this->posY][this->posX+1] != 'J'//
        && board->boardMap[this->posY][this->posX+1]!= '$')
            board->boardMap[this->posY][this->posX+1] = '3';
        if (board->boardMap[this->posY][this->posX+2] != 'B' && board->boardMap[this->posY][this->posX+2] != 'H' && //
        board->boardMap[this->posY][this->posX+2] != 'T' && board->boardMap[this->posY][this->posX+2] != 'J'//
        && board->boardMap[this->posY][this->posX+2]!= '$')
            board->boardMap[this->posY][this->posX+2] = '3';
    }
    else if (board->boardMap[this->posY][this->posX] == '<') {
        if (board->boardMap[this->posY][this->posX-1] != 'B' && board->boardMap[this->posY][this->posX-1] != 'H' && //
        board->boardMap[this->posY][this->posX-1] != 'T' && board->boardMap[this->posY][this->posX-1] != 'J'//
        && board->boardMap[this->posY][this->posX-1]!= '$')
            board->boardMap[this->posY][this->posX-1] = '4';
                if (board->boardMap[this->posY][this->posX-2] != 'B' && board->boardMap[this->posY][this->posX-2] != 'H' && //
        board->boardMap[this->posY][this->posX-2] != 'T' && board->boardMap[this->posY][this->posX-2] != 'J'//
        && board->boardMap[this->posY][this->posX-2]!= '$')
            board->boardMap[this->posY][this->posX-2] = '4';
    }
}

void solarFox::moveMobUp(board *board)
{
    for (int i = 0; i < board->boardMap.size(); i += 1)
        for (int j = 0; j < board->boardMap[i].size(); j += 1) {
            if (board->boardMap[i][j] == 'H') {
                this->posXmob = j;
                this->posYmob = i;
            }
        }
        if (board->boardMap[this->posYmob][this->posXmob+2] == '$')
            this->mobUp = true;
        if (board->boardMap[this->posYmob][this->posXmob-2] == '$')
            this->mobUp = false;
        if (this->mobUp == true) 
            board->boardMap[this->posYmob][this->posXmob-1] = 'H';
        if (this->mobUp == false) 
            board->boardMap[this->posYmob][this->posXmob+1] = 'H';
        board->boardMap[this->posYmob][this->posXmob] = ' ';
}

void solarFox::moveMobDown(board *board)
{
    for (int i = 0; i < board->boardMap.size(); i += 1)
        for (int j = 0; j < board->boardMap[i].size(); j += 1) {
            if (board->boardMap[i][j] == 'B') {
                this->posXmob = j;
                this->posYmob = i;
            }
        }
        if (board->boardMap[this->posYmob][this->posXmob+2] == '$')
            this->mobDown = true;
        if (board->boardMap[this->posYmob][this->posXmob-2] == '$')
            this->mobDown = false;
        if (this->mobDown == true) 
            board->boardMap[this->posYmob][this->posXmob-1] = 'B';
        if (this->mobDown == false) 
            board->boardMap[this->posYmob][this->posXmob+1] = 'B';
        board->boardMap[this->posYmob][this->posXmob] = ' ';   
}

void solarFox::moveMobLeft(board *board)
{
    for (int i = 0; i < board->boardMap.size(); i += 1)
        for (int j = 0; j < board->boardMap[i].size(); j += 1) {
            if (board->boardMap[i][j] == 'J') {
                this->posXmob = j;
                this->posYmob = i;
            }
        }
        if (board->boardMap[this->posYmob+2][this->posXmob] == '$')
            this->mobLeft = true;
        if (board->boardMap[this->posYmob-2][this->posXmob] == '$')
            this->mobLeft = false;
        if (this->mobLeft == true) 
            board->boardMap[this->posYmob-1][this->posXmob] = 'J';
        if (this->mobLeft == false) 
            board->boardMap[this->posYmob+1][this->posXmob] = 'J';
        board->boardMap[this->posYmob][this->posXmob] = ' ';
}

void solarFox::moveMobRight(board *board)
{
    for (int i = 0; i < board->boardMap.size(); i += 1)
        for (int j = 0; j < board->boardMap[i].size(); j += 1) {
            if (board->boardMap[i][j] == 'T') {
                this->posXmob = j;
                this->posYmob = i;
            }
        }
        if (board->boardMap[this->posYmob+2][this->posXmob] == '$')
            this->mobRight = true;
        if (board->boardMap[this->posYmob-2][this->posXmob] == '$')
            this->mobRight = false;
        if (this->mobRight == true) 
            board->boardMap[this->posYmob-1][this->posXmob] = 'T';
        if (this->mobRight == false) 
            board->boardMap[this->posYmob+1][this->posXmob] = 'T';
        board->boardMap[this->posYmob][this->posXmob] = ' ';  
}

void solarFox::moveMob(board *board)
{
    this->moveMobUp(board);
    this->moveMobDown(board);
    this->moveMobLeft(board);
    this->moveMobRight(board);
}

void solarFox::deleteShoot(board *board)
{
    for (int i = 0; i < board->boardMap.size(); i += 1)
        for (int j = 0; j < board->boardMap[i].size(); j += 1)
            if (board->boardMap[i][j] == '-' || board->boardMap[i][j] == '|')
                board->boardMap[i][j] = ' ';
}

void solarFox::moveMobShootTop(board *board)
{
    bool fire = false;
    for (int i = 0; i < board->boardMap.size(); i += 1)
        for (int j = 0; j < board->boardMap[i].size(); j += 1) 
            if (board->boardMap[i][j] == 'd') {
                this->posXmob = j;
                this->posYmob = i;
                fire = true;
            }
    if (fire == true && board->boardMap[this->posYmob+1][this->posXmob] == ' ') {
        board->boardMap[this->posYmob+1][this->posXmob] = 'd';
        board->boardMap[this->posYmob][this->posXmob] = ' ';
    }
    if (fire == true && board->boardMap[this->posYmob+1][this->posXmob] == 'A' || board->boardMap[this->posYmob+1]//
    [this->posXmob] == 'V' || board->boardMap[this->posYmob+1][this->posXmob] == '<' || board->boardMap[this->posYmob+1][this->posXmob] == '>') {
        this->collision();
    }
    if (fire == true && board->boardMap[this->posYmob+1][this->posXmob] != ' ')
        board->boardMap[this->posYmob][this->posXmob] = ' ';

}

void solarFox::moveMobShootBot(board *board)
{
    bool fire = false;
    for (int i = 0; i < board->boardMap.size(); i += 1)
        for (int j = 0; j < board->boardMap[i].size(); j += 1) 
            if (board->boardMap[i][j] == 'u') {
                this->posXmob = j;
                this->posYmob = i;
                fire = true;
            }
    if (fire == true && board->boardMap[this->posYmob-1][this->posXmob] == ' ') {
        board->boardMap[this->posYmob-1][this->posXmob] = 'u';
        board->boardMap[this->posYmob][this->posXmob] = ' ';
    }
    if (fire == true && board->boardMap[this->posYmob-1][this->posXmob] == 'A' || board->boardMap[this->posYmob-1]//
    [this->posXmob] == 'V' || board->boardMap[this->posYmob-1][this->posXmob] == '<' || board->boardMap[this->posYmob-1][this->posXmob] == '>') {
        this->collision();
    }
    if (fire == true && board->boardMap[this->posYmob-1][this->posXmob] != ' ')
        board->boardMap[this->posYmob][this->posXmob] = ' ';
}

void solarFox::moveMobShootRight(board *board)
{
    bool fire = false;
    for (int i = 0; i < board->boardMap.size(); i += 1)
        for (int j = 0; j < board->boardMap[i].size(); j += 1) 
            if (board->boardMap[i][j] == 'r') {
                this->posXmob = j;
                this->posYmob = i;
                fire = true;
            }
    if (fire == true && board->boardMap[this->posYmob][this->posXmob-1] == ' ') {
        board->boardMap[this->posYmob][this->posXmob-1] = 'r';
        board->boardMap[this->posYmob][this->posXmob] = ' ';
    }
    if (fire == true && board->boardMap[this->posYmob][this->posXmob-1] == 'A' || board->boardMap[this->posYmob]//
    [this->posXmob-1] == 'V' || board->boardMap[this->posYmob][this->posXmob-1] == '<' || board->boardMap[this->posYmob][this->posXmob-1] == '>') {
        this->collision();
    }
    if (fire == true && board->boardMap[this->posYmob][this->posXmob-1] != ' ')
        board->boardMap[this->posYmob][this->posXmob] = ' ';   
}

void solarFox::moveMobShootLeft(board *board)
{
    bool fire = false;
    for (int i = 0; i < board->boardMap.size(); i += 1)
        for (int j = 0; j < board->boardMap[i].size(); j += 1) 
            if (board->boardMap[i][j] == 'l') {
                this->posXmob = j;
                this->posYmob = i;
                fire = true;
            }
    if (fire == true && board->boardMap[this->posYmob][this->posXmob+1] == ' ') {
        board->boardMap[this->posYmob][this->posXmob+1] = 'l';
        board->boardMap[this->posYmob][this->posXmob] = ' ';
    }
    if (fire == true && board->boardMap[this->posYmob][this->posXmob+1] == 'A' || board->boardMap[this->posYmob]//
    [this->posXmob+1] == 'V' || board->boardMap[this->posYmob][this->posXmob+1] == '<' || board->boardMap[this->posYmob][this->posXmob+1] == '>') {
        this->collision();
    }
    if (fire == true && board->boardMap[this->posYmob][this->posXmob+1] != ' ')
        board->boardMap[this->posYmob][this->posXmob] = ' '; 
}

void solarFox::moveMobShoot(board *board)
{
    this->moveMobShootTop(board);
    this->moveMobShootBot(board);
    this->moveMobShootRight(board);
    this->moveMobShootLeft(board);
}

void solarFox::mobShootTop(board *board)
{
    bool fire = false;
    for (int i = 0; i < board->boardMap.size(); i += 1)
        for (int j = 0; j < board->boardMap[i].size(); j += 1) {
            if (board->boardMap[i][j] == 'd') 
                fire = true;
            if (board->boardMap[i][j] == 'H') {
                this->posXmob = j;
                this->posYmob = i;
            }
            if (board->boardMap[i][j] == 'V' || board->boardMap[i][j] == 'A' || board->boardMap[i][j] == '<' || board->boardMap[i][j] == '>') {
                this->posX = j;
                this->posY = i;
            }
        }
    if (this->posXmob == this->posX && fire == false)
        board->boardMap[this->posYmob+1][this->posXmob] = 'd';
}

void solarFox::mobShootBot(board *board)
{
    bool fire = false;
    for (int i = 0; i < board->boardMap.size(); i += 1)
        for (int j = 0; j < board->boardMap[i].size(); j += 1) {
            if (board->boardMap[i][j] == 'u') 
                fire = true;
            if (board->boardMap[i][j] == 'B') {
                this->posXmob = j;
                this->posYmob = i;
            }
            if (board->boardMap[i][j] == 'V' || board->boardMap[i][j] == 'A' || board->boardMap[i][j] == '<' || board->boardMap[i][j] == '>') {
                this->posX = j;
                this->posY = i;
            }
        }
    if (this->posXmob == this->posX && fire == false)
        board->boardMap[this->posYmob-1][this->posXmob] = 'u';
}

void solarFox::mobShootRight(board *board)
{
    bool fire = false;
    for (int i = 0; i < board->boardMap.size(); i += 1)
        for (int j = 0; j < board->boardMap[i].size(); j += 1) {
            if (board->boardMap[i][j] == 'r') 
                fire = true;
            if (board->boardMap[i][j] == 'T') {
                this->posXmob = j;
                this->posYmob = i;
            }
            if (board->boardMap[i][j] == 'V' || board->boardMap[i][j] == 'A' || board->boardMap[i][j] == '<' || board->boardMap[i][j] == '>') {
                this->posX = j;
                this->posY = i;
            }
        }
    if (this->posYmob == this->posY && fire == false)
        board->boardMap[this->posYmob][this->posXmob-1] = 'r';
}

void solarFox::mobShootLeft(board *board)
{
    bool fire = false;
    for (int i = 0; i < board->boardMap.size(); i += 1)
        for (int j = 0; j < board->boardMap[i].size(); j += 1) {
            if (board->boardMap[i][j] == 'l') 
                fire = true;
            if (board->boardMap[i][j] == 'J') {
                this->posXmob = j;
                this->posYmob = i;
            }
            if (board->boardMap[i][j] == 'V' || board->boardMap[i][j] == 'A' || board->boardMap[i][j] == '<' || board->boardMap[i][j] == '>') {
                this->posX = j;
                this->posY = i;
            }
        }
    if (this->posYmob == this->posY && fire == false)
        board->boardMap[this->posYmob][this->posXmob+1] = 'l';
}

void solarFox::mobShoot(board *board)
{
    this->mobShootTop(board);
    this->mobShootBot(board);
    this->mobShootRight(board);
    this->mobShootLeft(board);
}

void solarFox::checkGameWin(board *board)
{
    bool win = false;
    for (int i = 0; i < board->boardMap.size(); i += 1)
        for (int j = 0; j < board->boardMap[i].size(); j += 1)
            if (board->boardMap[i][j] == 'c') 
                win = true;
    if (!win)
        exit(0);
}

void solarFox::update(arc::Input key, board *board)
{
    std::clock_t startTime = std::clock();
    double duration;
    duration = (std::clock() - startTime) / (double) CLOCKS_PER_SEC;
    if (duration < 0.35) {
        std::clock_t sleep_time = (0.35 - duration)* CLOCKS_PER_SEC;
        std::clock_t end_time = std::clock() + sleep_time;
        while (std::clock() < end_time);
    }
    this->moveMob(board);
    this->deleteShoot(board);
    this->mobShoot(board);
    this->moveMobShoot(board);
    this->checkGameWin(board);
    if (key == arc::Input::UP)
        this->moveUp(board);
    else if (key == arc::Input::DOWN)
        this->moveDown(board);
    else if (key == arc::Input::LEFT)
        this->moveLeft(board);
    else if (key == arc::Input::RIGHT)
        this->moveRight(board);
    else if (key == arc::Input::SPACE)
        this->shoot(board);

    board->_Object.clear();


    char ptrChar;
    int pos_x = 0;
    int pos_y = 0;
    
    for (int i = 0; i < board->boardMap.size(); i++) {
        pos_x = 0;
        for (int j = 0; j < (board->boardMap[i].size() + 2); j++) {
            ptrChar = board->boardMap[i][j];
            char_to_object(board, ptrChar, pos_x, pos_y);
            pos_x += 50;
        }
        pos_y += 50;
    }
    
}

bool solarFox::gameOver()
{
    return this->gameOver_;
}

void solarFox::collision()
{
    this->gameOver_ = true;
}