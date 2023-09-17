/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** board.cpp
*/

#include "board.hpp"

board::board()
{
    this->boardMap = std::vector<std::string>(21, std::string(20, ' '));
}

board::~board()
{  
    this->boardMap.clear();
}

void board::setBoard(std::vector<std::string> myBoard)
{
    this->boardMap = myBoard;
}

void board::setBoardMap(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("Failed to open file: " + filename);
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line))
        lines.push_back(line);
    this->boardMap = lines;
}

std::vector<std::string> board::getBoardMap() 
{
    return this->boardMap;
}