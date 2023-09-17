/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** board.cpp
*/

#include "board.hpp"

board::board()
{
    this->boardMap = std::vector<std::string>(20, std::string(20, ' '));
}

board::~board()
{  
    boardMap.clear();
}

void board::loadBoard(std::vector<std::string> &_board)
{
    this->boardMap = _board;
}

extern "C" void setBoardMap(char *src)
{
    
}