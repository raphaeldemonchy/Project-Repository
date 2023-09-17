/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** board.hpp
*/

#pragma once
#include <map>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include "../utils/utils.hpp"

class board
{
    public:
        board();
        ~board();
        void setBoard(std::vector<std::string> myBoard);
        void setBoardMap(const std::string& filename);
        void updateBoard() {};
        std::vector<std::string> getBoardMap();
        std::vector<std::string> boardMap;
        std::vector<arc::Obj> _Object;

        std::string score;

    // protected:
};