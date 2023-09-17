/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** IModules.hpp
*/

#pragma once
#include <iostream>
#include <map>
#include <vector>
#include "../../utils/utils.hpp"
#include "../../board/board.hpp"

namespace arc {

    class IDisplayModule
    {
        // protected:
        public:
            virtual ~IDisplayModule() = default;
            virtual const std::string& getName() const = 0;

            //WINDOW//
            virtual void init() = 0;
            virtual void stop() = 0;
            virtual void update() = 0;

            //DISPLAY//
            virtual void display_board(board *board) = 0;
            virtual void display_text(std::string text, int x, int y) = 0;

            //EVENT//
            virtual arc::Input handle_key() = 0;
            virtual bool gameOver() = 0;
            virtual bool isOpen() = 0;

            //WSIZE//
            virtual int getSizeWindowX() = 0;
            virtual int getSizeWindowY() = 0;
    };
};